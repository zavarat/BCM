/*
*  Copyright 2011, Broadcom Corporation
*
* <:copyright-BRCM:2011:proprietary:standard
* 
*    Copyright (c) 2011 Broadcom 
*    All Rights Reserved
* 
*  This program is the proprietary software of Broadcom and/or its
*  licensors, and may only be used, duplicated, modified or distributed pursuant
*  to the terms and conditions of a separate, written license agreement executed
*  between you and Broadcom (an "Authorized License").  Except as set forth in
*  an Authorized License, Broadcom grants no license (express or implied), right
*  to use, or waiver of any kind with respect to the Software, and Broadcom
*  expressly reserves all rights in and to the Software and all intellectual
*  property rights therein.  IF YOU HAVE NO AUTHORIZED LICENSE, THEN YOU HAVE
*  NO RIGHT TO USE THIS SOFTWARE IN ANY WAY, AND SHOULD IMMEDIATELY NOTIFY
*  BROADCOM AND DISCONTINUE ALL USE OF THE SOFTWARE.
* 
*  Except as expressly set forth in the Authorized License,
* 
*  1. This program, including its structure, sequence and organization,
*     constitutes the valuable trade secrets of Broadcom, and you shall use
*     all reasonable efforts to protect the confidentiality thereof, and to
*     use this information only in connection with your use of Broadcom
*     integrated circuit products.
* 
*  2. TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
*     AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES, REPRESENTATIONS OR
*     WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH
*     RESPECT TO THE SOFTWARE.  BROADCOM SPECIFICALLY DISCLAIMS ANY AND
*     ALL IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY, NONINFRINGEMENT,
*     FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES, ACCURACY OR
*     COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR CORRESPONDENCE
*     TO DESCRIPTION. YOU ASSUME THE ENTIRE RISK ARISING OUT OF USE OR
*     PERFORMANCE OF THE SOFTWARE.
* 
*  3. TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL BROADCOM OR
*     ITS LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL, INCIDENTAL, SPECIAL,
*     INDIRECT, OR EXEMPLARY DAMAGES WHATSOEVER ARISING OUT OF OR IN ANY
*     WAY RELATING TO YOUR USE OF OR INABILITY TO USE THE SOFTWARE EVEN
*     IF BROADCOM HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES;
*     OR (ii) ANY AMOUNT IN EXCESS OF THE AMOUNT ACTUALLY PAID FOR THE
*     SOFTWARE ITSELF OR U.S. $1, WHICHEVER IS GREATER. THESE LIMITATIONS
*     SHALL APPLY NOTWITHSTANDING ANY FAILURE OF ESSENTIAL PURPOSE OF ANY
*     LIMITED REMEDY.
* :>
*/

/*                      Copyright(c) 2008Teknovus, Inc.                      */

////////////////////////////////////////////////////////////////////////////////
/// \file PON Manager
/// \brief Manages PON specific Configuration and detection of PON status
///
///
////////////////////////////////////////////////////////////////////////////////
#include <linux/unistd.h>
#include <linux/string.h>
#include <linux/timer.h>
#include <linux/jiffies.h>
#include <boardparms.h>
#include "PonManager.h"
#include "bcm_epon_cfg.h"
#include "EponUser.h"
#include "rdpa_api.h"
#include "rdpa_types.h"
#include "autogen/rdpa_ag_epon.h"
#include "OntDirector.h"
#include "pmd.h"

#ifdef EPON_MPCP_SUPPORT
#ifdef CONFIG_EPON_CLOCK_TRANSPORT
#include "ClockTransport.h"
#endif
#include "EponStats.h"
#include "OntmMpcp.h"
#endif

#define PonMgrBootDelay     30 //30*100ms = 3s

#define MpcpOamTcont        0
#define UserTrafficTcont    1 

#define PonApiShaperRateUnit    2000
static bdmf_boolean laser_rx_enable;
//To burst or not to burst that is the question.
//We need to remember the previous burstiness accross
//laser TX power ON / OFF:
static rdpa_epon_laser_tx_mode laserTxBurstMode = rdpa_epon_laser_tx_burst;
static rdpa_epon_laser_tx_mode laser_tx_mode;
extern rdpa_epon_mode oam_mode;

static U32 l2size[EponNumL2Queues];
static U8 l2Weight[EponNumL2Queues];
static U8 l2MinWeightPerLink[TkOnuNumTxLlids];
static U32 linksAlive ;
static PonCfgAlarm ponCfgAlm;
static PonMgrRptMode curRptMode;
static U32 LinkQueueInd[TkOnuMaxBiDirLlids];
static PerLinkInfo linkInfo[TkOnuMaxBiDirLlids];
U16 linkBcap[TkOnuMaxBiDirLlids][EponMaxPri];

//Reserved one link for Broadcast
U32 rtMaxRxOnlyLlids  = TkOnuMaxRxOnlyLlids;
U32 rtFirstRxOnlyLlid = TkOnuMaxRxOnlyLlids-TkOnuRsvNumRxOnlyLlids;

#ifdef EPON_MPCP_SUPPORT
static BOOL los = TRUE;//default means los.
static BOOL eponInSync;
static BOOL lastLos = FALSE;
static BOOL lastEponInSync;
static U16 PonLosChkime = 0;
static BOOL ponMgrInSync;
#endif

#define PriCount()      PonMgrRptModeToPri(curRptMode)
#define L2Base(link)    ((link) * PriCount())
#define L2End(link)     (L2Base(link) + PriCount())
#define L2(link, pri)   (L2Base(link) + (pri))

static BOOL shaperInUse[EponUpstreamShaperCount];
//Minimum burst cap.  This is what we want to use to minimise
//the delay to MPCP/OAM frame FIFO when attempting to register.
#define DefaultHardCodedBurstCap  0x400

//Used to record the links that have been started
//add link map that started by PonMgrStartLinks()
//remove link map that stopped by PonMgrStopLinks()
static LinkMap  startedLinks = 0;

#define PonDebug(lvl, args)      eponUsrDebug(lvl, args)
#define PonDebugOff              DebugDisable
#define PonDebugDefault          DebugEpon

static BOOL userTrafficEnable[TkOnuMaxBiDirLlids];
extern BOOL epon_mac_init_done;

extern int pmd_dev_poll_epon_alarm(void);

// 10G RX FEC auto-deteciton is done per 2 second.
// Since PonManagerPoll() is done per 10ms, so 2 sec need 200 times poll.
#define Fec10gDetectInterval 200
// Counter for rx los accumulation.
static U8 fec10gLosCnt = 0;
// FEC 10G auto-switch enable or not.
static BOOL fec10gAutoSwEn = TRUE;


////////////////////////////////////////////////////////////////////////////////
/// \brief enable/disable 10G FEC auto_detection
///
/// \param enable     
///
/// \return
/// none
////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgr10gFecAutoDetSet(BOOL enable)
    {
    fec10gAutoSwEn = enable;
    }

////////////////////////////////////////////////////////////////////////////////
/// \brief get 10G FEC auto_detection enable state
///
/// \return
///  BOOL enable or not
////////////////////////////////////////////////////////////////////////////////
//extern
BOOL PonMgr10gFecAutoDetGet(void)
    {
    return fec10gAutoSwEn;
    }

////////////////////////////////////////////////////////////////////////////////
/// \brief set the oam queue index of the link
///
/// \param link     Link index to set
///
/// \return
/// the oam queue index
////////////////////////////////////////////////////////////////////////////////
//extern

static
void PonMgrLinkOamQSet(LinkIndex link, U8 queue)
    {
    //save OAM queue in tracking DB
    linkInfo[link].oamQ = queue;
    }

////////////////////////////////////////////////////////////////////////////////
/// \brief get the oam queue index of the link
///
/// \param link     Link index to get
///
/// \return
/// the oam queue index
////////////////////////////////////////////////////////////////////////////////
//extern
U8 PonMgrLinkOamQGet(LinkIndex link)
    {
    return linkInfo[link].oamQ;
    }

static
void PonMgrLlidDataChannelSet(LinkIndex llid_index, BOOL enable)
    {
    bdmf_object_handle llid_h = NULL;
    bdmf_error_t rc = BDMF_ERR_OK; 
    if (0 == rdpa_llid_get(llid_index, &llid_h))
        {
        rc = rdpa_llid_data_enable_set(llid_h, enable);
        if (BDMF_ERR_OK != rc)
            {
            printk("set llid %d data channels %d fail, Err:%d\n",
                   llid_index, enable, rc);
            }
        bdmf_put(llid_h);
        }
    }


static
void PonMgrLlidCtrlChannelSet(LinkIndex llid_index, BOOL enable)
    {
    bdmf_object_handle llid_h = NULL;
    bdmf_error_t rc = BDMF_ERR_OK;
    
    if (0 == rdpa_llid_get(llid_index, &llid_h))
        {
        rc = rdpa_llid_control_enable_set(llid_h, enable);
        if (BDMF_ERR_OK != rc)
            {
            printk("set llid %d ctrl channels %d fail, Err:%d\n",
                   llid_index, enable, rc);
            }
        bdmf_put(llid_h);
        }
    }

void PonMgrUserTrafficSet(LinkIndex link, BOOL enable)
    {
    if(enable)
        {
        userTrafficEnable[link] = TRUE;
        PonMgrLlidDataChannelSet(link, TRUE);
        }
    else
        {
        userTrafficEnable[link] = FALSE;
        PonMgrLlidDataChannelSet(link, FALSE);
        }
    }


////////////////////////////////////////////////////////////////////////////////
/// \brief  Get user traffic Status(mainly for llid data channel)
///
/// \returnn none.
////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrUserTrafficGet(LinkIndex link, BOOL* state)
    {
    *state = userTrafficEnable[link]; 
    }


////////////////////////////////////////////////////////////////////////////////
/// \brief  enable llid's traffic channels 
///
/// \returnn none.
////////////////////////////////////////////////////////////////////////////////
static
void EnableLinkRunnerQueue(LinkMap links)
    {
    LinkIndex link;
    LinkIndex max = PonMgrGetCurrentMaxLinks();

    for (link = 0; link < max; link++)
        {
        if (TestBitsSet(links, 1UL << link))
            {
            PonMgrLlidCtrlChannelSet(link, TRUE);
            if (userTrafficEnable[link])
                {
                PonMgrLlidDataChannelSet(link, TRUE);
                }
            }
        }
    }

static
void EnableLinkRunnerControlQueue(LinkMap links)
    {
    LinkIndex link;
    LinkIndex max = PonMgrGetCurrentMaxLinks();

    for (link = 0; link < max; link++)
        {
        if (TestBitsSet(links, 1UL << link))
            {
            PonMgrLlidCtrlChannelSet(link, TRUE);
            }
        }
    }


////////////////////////////////////////////////////////////////////////////////
/// \brief  disable llid's traffic channels 
///
/// \returnn none.
////////////////////////////////////////////////////////////////////////////////
static
void DisableLinkRunnerQueue(LinkMap links)
    {
    LinkIndex link;
    LinkIndex max = PonMgrGetCurrentMaxLinks();

    for (link = 0; link < max; link++)
        {
        if (TestBitsSet(links, 1UL << link))
            {
            PonMgrLlidCtrlChannelSet(link, FALSE);
            PonMgrLlidDataChannelSet(link, FALSE);
            }
        }
    }

////////////////////////////////////////////////////////////////////////////////
/// \brief  Get links that have been started
///
/// \return started links
////////////////////////////////////////////////////////////////////////////////
//extern
LinkMap PonMgrStartedLinksGet (void)
    {
    return startedLinks;
    }


////////////////////////////////////////////////////////////////////////////////
/// \brief  Get reporting mode currently provisioned in HW
///
/// \return Report mode currently setup.
////////////////////////////////////////////////////////////////////////////////
//extern
PonMgrRptMode PonMgrReportModeGet (void)
    {
    return curRptMode;
    }


////////////////////////////////////////////////////////////////////////////////
/// \brief  Get maximum number of links for reporting mode
///
/// \param  rptMode     Report mode to get max links for
/// \param  upRate       upstream rate
///
/// \return Max links for reporting mode
////////////////////////////////////////////////////////////////////////////////
static
U8 PonMgrGetMaxLinksForReportMode (PonMgrRptMode rptMode, LaserRate upRate)
    {
    U8 maxLinks;

    switch (rptMode)
        {
        case RptModeFrameAligned:
#if defined(CONFIG_BCM96836) || defined(CONFIG_BCM96846)
            maxLinks = Bcm1gOnuNumBiDirLlids;
#else  
            if (upRate == LaserRate10G)
                {
                maxLinks = Bcm10gOnuNumBiDirLlids;
                }
            else
                {
                maxLinks = Bcm1gOnuNumBiDirLlids;
                }
#endif
            break;
            
        case RptModeMultiPri8:
            maxLinks = Ctc8pOnuNumBiDirLlids;
            break;
            
        case RptModeMultiPri4:
            maxLinks = Ctc4pOnuNumBiDirLlids;
            break;
            
        case RptModeMultiPri3:
            maxLinks = Ctc3pOnuNumBiDirLlids;
            break;
            
        default:
            maxLinks = Ctc8pOnuNumBiDirLlids;
            break;
        }
    
    return maxLinks;
    }


////////////////////////////////////////////////////////////////////////////////
/// \brief  Get current maximum links based on reporting mode
///
/// \return Max links for current report mode
////////////////////////////////////////////////////////////////////////////////
//extern
U8 PonMgrGetCurrentMaxLinks(void)
    {
    return PonMgrGetMaxLinksForReportMode(curRptMode, PonCfgDbGetUpRate());
    }


////////////////////////////////////////////////////////////////////////////////
/// PonMgrSetMpcpTimeTransfer - Set time to transmit next pulse
///
/// This function programs the LIF or XIF transmit time for passthrough and
/// tracked operation.
///
 // Parameters:
/// \param time Time to transmit pulse
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrSetMpcpTimeTransfer (U32 time)
    {
#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM96856)
    //Check for NCO state machine being ready?  
    if (PonCfgDbGetDnRate()==LaserRate10G)
        {
        XifTransportTimeSet(time);
        }
    else
#endif
        {
        LifTransportTimeSet(time); 
        }
    } // PonMgrSetMpcpTimeTransfer


////////////////////////////////////////////////////////////////////////////////
/// PonMgrGetCurMpcpTime - Get current MPCP time
///
/// This function returns the MPCP time of the most recently received downstream
/// packet. It is updated only when a downstream packet is received.
///
 // Parameters:
///
/// \return
/// Current MPCP time
////////////////////////////////////////////////////////////////////////////////
//extern
U32 PonMgrGetCurMpcpTime (void)
    {
#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM96856)
    if (PonCfgDbGetDnRate()==LaserRate10G)
        {
        return XifMpcpTimeGet();
        }
    else
#endif
        {
        return LifMpcpTimeGet();
        }
    } // PonMgrGetCurMpcpTime


////////////////////////////////////////////////////////////////////////////////
/// \brief Builds a bitmap of L2 queues associated to a given link
///
/// \param link  Link index
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
static
L2Map L2MapOfLinks(LinkMap links)
    {
    LinkIndex link;
    LinkIndex max = PonMgrGetCurrentMaxLinks();
    L2Map l2s = 0;

    for (link = 0; link < max; link++)
        {
        if (TestBitsSet(links, 1UL << link))
            {
            // we have n l2s per link where n is the number of priorities. So
            // the bitmap for a link is a set of n bits left shifted by the link
            l2s |= (((1UL << PriCount()) - 1) << (link * PriCount()));
            }
        }

    return l2s;
    } // L2MapOfLink


////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrL2Cfg(U8 link_num)
    {
    LinkIndex    link = 0;
    U16          endAddress = 0;
    
    while (link < link_num)
        {
        //size tracks the sizing of the L2.  In SharedL2Cfg mode
        //all frames share the same L2 for transmission order so the
        //links zeroth L2 needs to be sized for all link L1s.
        //In non-SharedL2CfgMode all L2s are sized based on the L1s that
        //they report for.
        L2Index l2;
        L2Index end = L2End(link);

        if ((PonCfgDbSchMode() != PonSchModePriorityBased) &&
            (RptModeFrameAligned != curRptMode))
            {
            endAddress = EponSetL2EventQueue (L2Base(link), l2size[L2Base(link)], endAddress);
            EponSetBurstLimit(L2Base(link), 0, 0);
            }
        else
            {
            for (l2 = L2Base(link); l2 < end; l2++)
                {
                
                endAddress = EponSetL2EventQueue (l2, l2size[l2], endAddress);
                EponSetBurstLimit(l2, l2Weight[l2], l2MinWeightPerLink[link]);
                }
            }
        link++;
        }
    }


////////////////////////////////////////////////////////////////////////////////
/// \brief  Return a link index associated to a phy llid
///
/// \param link     Phy LLID
///
/// \return Link index
/// None
////////////////////////////////////////////////////////////////////////////////
//extern
LinkIndex PonMgrPhyLlidToIndex (PhyLlid phy)
    {
#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM96856)
    if (PonCfgDbGetUpRate() == LaserRate10G)
        {
        return XifPhyLlidToIndex (phy);
        }
    else
#endif
        {
        return LifPhyLlidToIndex (phy);
        }
    } // PonMgrPhyLlidToIndex


////////////////////////////////////////////////////////////////////////////////
//extern
LinkIndex PonMgrGetLinkForMac(const MacAddr * mac)
    {
    LinkIndex link;
    MacAddr temp;

    for (link = 0; link < TkOnuNumTxLlids; link++)
        {
        EponGetMac(link, &temp);
        if (0 == memcmp(mac, &temp, sizeof(MacAddr)))
            {
            break;
            }
        }

    return link;
    }


////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrGetMacForLink(LinkIndex link, MacAddr * mac)
    {
    EponGetMac(link, mac);
    }


////////////////////////////////////////////////////////////////////////////////
/// \brief  Sets idle time with target ONU laser ON/OFF
///
/// \param syncTime            sync time      (in TQ)
/// \param targetLaserOn       attempted laser ON time  (in TQ)
/// \param targetLaserOff      attempted laser OFF time (in TQ)
/// \param idleType            is it a discovery idle time or not?
///
/// \return
/// Actual grant overhead provisionned in hardware
////////////////////////////////////////////////////////////////////////////////
static
U16 PonMgrSetIdleTime (MpcpInterval16 syncTime,
                       MpcpInterval16 targetLaserOn,
                       MpcpInterval16 targetLaserOff,
                       IdleTimeType idleType)
    {
    MpcpInterval16 register_req_packet_size_in_tq = 0;
    
    // Cap the target values to the capacity of the ONU
    if (targetLaserOn < PonCfgDbGetLaserOnTime())
        {
        targetLaserOn = PonCfgDbGetLaserOnTime();
        }

    if (targetLaserOff < PonCfgDbGetLaserOffTime())
        {
        targetLaserOff = PonCfgDbGetLaserOffTime();
        }

#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM96856)
    if (idleType == DiscIdleTime)
        {
        XifSetDiscIdleTime ((targetLaserOn + syncTime), targetLaserOff);
        }
    else
        {
        XifSetNonDiscIdleTime ((targetLaserOn + syncTime), targetLaserOff);
        }
#endif
    
    LifSetIdleTime ((targetLaserOn + syncTime), targetLaserOff);

    if (PonCfgDbGetUpRate()==LaserRate10G)
        {
        //This assumes 10G uses FEC and should work for non-FEC cases as 
        //well.  This could possible be improved for non-FEC if so use 5TQ.
        register_req_packet_size_in_tq = 13;
        }
    else // assume 1G upstream, assume FEC to start on 1G links
        {
        //This is the data portion only of the REG_REQ burst size.
        register_req_packet_size_in_tq = 55 + 3;
        }
    
    return EponSetIdleTime ((targetLaserOn + syncTime),
                            targetLaserOff,
                            idleType, register_req_packet_size_in_tq);
    } // PonMgrSetTargetIdleTime


////////////////////////////////////////////////////////////////////////////////
//extern
U16 PonMgrSetTargetIdleTime (MpcpInterval16 syncTime,
                             MpcpInterval16 targetLaserOn,
                             MpcpInterval16 targetLaserOff)
    {
    return PonMgrSetIdleTime (syncTime,
                      targetLaserOn + PonCfgDbIdleTimeOffset(),
                      targetLaserOff,
                      NonDiscIdleTime);
    }


////////////////////////////////////////////////////////////////////////////////
//extern
U16 PonMgrSetDefaultIdleTime (MpcpInterval16 syncTime)
    {
    return PonMgrSetIdleTime (syncTime,
                      PonCfgDbGetLaserOnTime(),
                      PonCfgDbGetLaserOffTime(),
                      DiscIdleTime);
    } // PonMgrSetDefaultIdleTime


////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrEnableL1L2(LinkMap links)
    {
    U32  l2s = L2MapOfLinks(links);
    U32  l1s = l2s;

    // Put L2 FIFO out of reset
    EponClearL2Reset(l2s);

    // Put L1 FIFO out of reset
    EponClearL1Reset(l1s);
    }


////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrDisableL1L2(LinkMap links)
    {
    U32  l2s = L2MapOfLinks(links);
    U32  l1s = l2s;

    //FLush L2 FIFO
    EponRepeatlyFlushL2Fifo(l2s, l1s);

    // Put L1 FIFO into reset
    EponSetL1Reset (l1s);

    // Put L2 FIFO into reset
    EponSetL2Reset (l2s);
    }


////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrPauseLinks(LinkMap links)
    {
    EponUpstreamDisable(links);
    } // PonMgrPauseLink


////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrResumeLinks(LinkMap links)
    {
    EponUpstreamEnable(links);
    } // PonMgrResumeLink


////////////////////////////////////////////////////////////////////////////////
// extern
void PonMgrStopLinks(LinkMap links)
    {
    DisableLinkRunnerQueue(links);
    // disable upstream transmission so that no frames are in transit
    PonMgrPauseLinks(links);
    // now that no frames are coming in or going out it is safe to disable the
    // L1/L2 fifos/schedulers
    PonMgrDisableL1L2(links);
    EponBBHUpsHaultStatusClr();
    EponBBHUpsHaultClr();
    startedLinks &= ~(links);
    }


////////////////////////////////////////////////////////////////////////////////
// extern
void PonMgrStartLinks(LinkMap links)
    {
    // flush all fifos on the link to make sure it is clean
    //FifCmdLinkFlush(links);
    // now that we're sure the link is clean, enable the L1/L2 fifos
	
    PonMgrEnableL1L2(links);
    // now that the L1/L2 are back up it's safe to transmit upstream
    PonMgrResumeLinks(links);
   
    EnableLinkRunnerQueue(links);
	
    // Enable system queue
    //FifCmdLinkEnable(links, FifTypeSys);
    //Restart user traffic on all in service links
    //FifCmdLinkEnable(links & UserTrafficRdyLinkMap(), FifTypeUser);
    startedLinks |= links;
    }


////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrResetLinkUpPath(LinkMap links)
    {
    /* for detail of this function, please refer to JIRA SWBCACPE-18596 */
    U32  l2s = L2MapOfLinks(links);
    U32  l1s = l2s;
	
    DisableLinkRunnerQueue(links);
    PonMgrPauseLinks(links);
    EponFlushL2Fifo(l2s, l1s);
    EponSetL2Reset(l2s);
    EponClearL2Reset(l2s);
    PonMgrDisableL1L2(links);
    EponBBHUpsHaultStatusClr();
    EponBBHUpsHaultClr();
    startedLinks &= ~(links);
    PonMgrStartLinks(links);
    PonDebug(PonDebugDefault, ("PonResetLinksUpPath:0x%08x\n",links));
    }

////////////////////////////////////////////////////////////////////////////////
/// \brief set default fec on the link
///
/// \param link index of the link to set fec
///            path rate to set
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrSetDefaultFec(LinkIndex link, FecAppDirection path)
    {
    BOOL enable = FALSE;
    
    if (TestBitsSet(path,FecApp10G))
        enable = TRUE;

    // 10G FEC has auto-deteciton feature as a backup.
    // So 1G FEC setting has higher priority.
    // When set both, we choose 1G.
    if (TestBitsSet(path,FecApp1G))
        enable = FALSE;
    
    (void)FecModeSet(link, enable, enable, path);
    }

////////////////////////////////////////////////////////////////////////////////
/// \brief  Set the weight of a priority
///
/// \param link     Index of link
/// \param pri      Priority on link
/// \param weight   Weight to set
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrSetWeight(LinkIndex link, U8 pri, U8 weight)
    {
    l2Weight[L2(link, pri)] = weight;

    //If we have a new smallest weight that is not equal to zero
    //then we want to track it for use as the base granularity.
    //Note if no weights are used (all 0) this would result in
    //a minimum weight of 100 or no weighting
    if (weight == 0)
        {
        weight = 100;
        }
    l2MinWeightPerLink[link] = (weight < l2MinWeightPerLink[link]) ?
                                    weight : l2MinWeightPerLink[link];
    }


////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrFlushGrants(LinkMap linkMap)
    {
    EponGrantDisable(linkMap);
    DelayUs(200);
    EponFlushGrantFifo(linkMap);
    EponGrantEnable(linkMap);
    }

////////////////////////////////////////////////////////////////////////////////
/// \brief Applies a new burst cap to a link on the fly
///
/// \param link     Link index for burst cap
/// \param bcap     New burst cap values in a array of 16 bytes values
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrSetBurstCap(LinkIndex link, const U16 * bcap)
    {
    U8  pri;
    U32 newBcap;

    for (pri = 0; pri < PriCount(); ++pri)
        {
        if ((bcap == NULL) || (bcap[pri] < DefaultHardCodedBurstCap))
            {
            newBcap = DefaultHardCodedBurstCap;
            }
        else
            {
            newBcap = (U32)bcap[pri];
            }

        // Apply a 10x factor when in 10/10
        if (PonCfgDbGetUpRate() == LaserRate10G)
            {
            newBcap *= 10;
            }
        linkBcap[link][pri] = newBcap;
        EponSetBurstCap (L2(link, pri), newBcap);
        }
    } // PonMgrSetBurstCap


////////////////////////////////////////////////////////////////////////////////
/// \brief  Add shapers for queue map
///
/// \param The map of port queues to associate with the shaper
/// \param The shaper rate
/// \param The shaper max burst size
///
/// \return
/// A handle to the shaper element or PonShaperBad if failed
////////////////////////////////////////////////////////////////////////////////
//extern
PonShaper PonMgrAddShaper (U32 shapedQueueMap,
                              PonShaperRate rate,
                              PonMaxBurstSize mbs)
    {
    EponShpElement shp;
    for (shp = 0; shp < EponUpstreamShaperCount; ++shp)
        {
        if (!shaperInUse[shp])
            {
            U32 rate2 = (U32)rate;
            rate2 = (rate/ FifoRateFactor);
            shaperInUse[shp] = TRUE;
            EponSetShaperRate (shp, (EponShaperRate)rate2);
            EponSetShaperMbs (shp, (EponMaxBurstSize)mbs);
            EponSetShaperL1Map (shp, shapedQueueMap);
            return (PonShaper)shp;
            }
        }
    return PonShaperBad;
    }


////////////////////////////////////////////////////////////////////////////////
/// \brief  Delete a shaper
///
/// \param Shaper to deactivate
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrDelChannelShaper (PonShaper shp)
    {
    if (shp < EponUpstreamShaperCount)
        {
        shaperInUse[shp] = FALSE;
        EponClearShaperConfig ((EponShpElement)shp);
        }
    }


void PonMgrLaserRxPowerGet(bdmf_boolean *on)
    {
    *on = laser_rx_enable;
    }

void PonMgrRxDisable(void)
    {
    laser_rx_enable = 0;
#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM96856)
    XifRxDisable();
#endif
    LifRxDisable();
    DelayNs(1000); // 1 us to ensure all operatiosn are complete (XIF only?)
    }


void PonMgrRxEnable(void)
    {
    laser_rx_enable = 1;
#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM96856)
    XifRxEnable();
#endif
    LifRxEnable();
    }

////////////////////////////////////////////////////////////////////////////////
/// \brief  Return a PhyLlid associated to a link index
///
/// \param link     Logical link number
///
/// \return
/// Physical Llid
////////////////////////////////////////////////////////////////////////////////
//extern
PhyLlid PonMgrGetPhyLlid (LinkIndex link)
    {
#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM96856)
    if(PonCfgDbGetDnRate() == LaserRate10G)
        {
        return XifGetPhyLlid(link);
        }
#endif
    
    return LifGetPhyLlid(link);
    }  // PonMgrGetPhyLlid


void pon_mgr_q_cfg_start (void)
    {
    U8 i;
    
    for (i = 0; i < TkOnuNumTxLlids; i++)
        {
        l2MinWeightPerLink[i] = 100;
        }
    } 


void pon_mgr_add_link_q(U8 link, U8 pri, U8 qId, U32 size)
    {
    
    } 


////////////////////////////////////////////////////////////////////////////////
/// \brief  Config Link Queue
///
/// \param *cfg    epon mac queue  config
///
/// \return void
/// None
////////////////////////////////////////////////////////////////////////////////
extern
void PonMgrLinkQueueConfig(epon_mac_q_cfg_t *cfg)
{
    U8 i=0;
    memset(LinkQueueInd, 0, sizeof(LinkQueueInd));
    if (oam_mode == rdpa_epon_dpoe || oam_mode == rdpa_epon_bcm)
        {
        for (i = 0; (i < cfg->link_num) && (i<TkOnuMaxBiDirLlids); i++)
            {
            U8 oamQ = i;
            U8 dataQ = i;

            PonMgrLinkOamQSet(i, oamQ);
            LinkQueueInd[i] |= (1 << oamQ) | (1 << dataQ);
            PonMgrSetWeight(i, cfg->q_cfg[0].level, cfg->q_cfg[0].weight);
            }
        }
    else
        {
        U8 oamQ = 0;
        U8 dataQ[CtcSLlidTotalDataQNum] = {1,2,3,4,5,6,7};
            
        // for oam queue
        PonMgrLinkOamQSet(0, oamQ);
        LinkQueueInd[0] |= (1 << oamQ);
        PonMgrSetWeight(0, cfg->q_cfg[0].level, cfg->q_cfg[0].weight);
        // for data queue
        for (i = 0; i < CtcSLlidTotalDataQNum; i++)
            {
            LinkQueueInd[0] |= 1 << dataQ[i];
            PonMgrSetWeight(0, cfg->q_cfg[i + CtcSLlidDataQMinIndex].level,
                cfg->q_cfg[i + CtcSLlidDataQMinIndex].weight);
            }
        }
}

////////////////////////////////////////////////////////////////////////////////
/// \brief Tells if a given link keeps receiving gates
///
/// \param link Index of the link we query
///
/// \return
/// TRUE if link is alive
////////////////////////////////////////////////////////////////////////////////
//extern
BOOL PonMgrLinkAlive (LinkIndex link)
    {
    return ((linksAlive & (1UL << link)) != 0);
    } // PonMgrLinkAlive

void PonMgrSetLaserStatus (rdpa_epon_laser_tx_mode mode)
    {
    laser_tx_mode = mode;
    if (mode != rdpa_epon_laser_tx_off)
        {
        laserTxBurstMode = mode;
        }
    else
        {
        /*when disable LIF tx, we must stop all user traffic. Not only from 
         * runner but all the data path between runner and epon mac. As anything 
         * stuck in LIF tx RAM would cause problem
         * */
        PonMgrUserTrafficSet(0, FALSE);
#ifdef EPON_MPCP_SUPPORT        
        StartRegisteringNewLink(0);
#endif
        }
#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM96856)   
    XifLaserTxModeSet (laser_tx_mode);
#endif
    LifLaserTxModeSet(laser_tx_mode);
    } 

rdpa_epon_laser_tx_mode PonMgrGetLaserStatus (void)
    {
    return laser_tx_mode;
    } 

rdpa_epon_laser_tx_mode PonMgrGetLaserBurstStatus (void)
    {
    return laserTxBurstMode;
    }

#ifdef EPON_MPCP_SUPPORT
////////////////////////////////////////////////////////////////////////////////
/// \brief Remove all resources needed to register a link
///
/// \param link index of the link to destroy
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrDestroyLink (LinkIndex link)
    {
#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM96856)
    XifDeleteLink (link);
#endif
    LifDeleteLink (link);

    if (link < TkOnuFirstRxOnlyLlid)
        {
        // disable grants while not in use, we shouldn't receive any while the
        // LLID is disabled, but this ensures the hardware is in a known state
        // and aids debugging
        EponGrantDisable(1UL << link);
        // safely shut down reporting
        PonMgrStopLinks(1UL << link);
        // now that the link is totally shut down, put the grant fifo in reset
        // this is potentially unnecessary, but ensures the link starts in a
        // known state the next time we use it
        EponGrantReset(1UL << link);
      // Default FEC on link
        PonMgrSetDefaultFec(link, FecApp1G);
        }
    } // PonMgrDestroyLink


////////////////////////////////////////////////////////////////////////////////
/// \brief Configure all resources needed to register a link
///
/// \param link index of the link
/// \param llid physical LLID value
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrCreateLink (LinkIndex link, PhyLlid  llid)
    {
    // make sure the link is in a good state before setting it up
    PonMgrDestroyLink(link);
 
    if (link < TkOnuNumBiDirLlids)
        { 
        // Default Bcap
        PonMgrSetBurstCap(link, NULL); 	
        //Default FEC
        PonMgrSetDefaultFec(link, FecApp1G);

        if (EncryptModeGet(link) != EncryptModeDisable)
            {
            (void)EncryptLinkSet(link, EncryptModeDisable, EncryptOptNone);
            }
            
        // bring up reporting while we are guaranteed to not be processing any
        // grants
        PonMgrStartLinks(1UL << link);
        // now that the reporting hardware is up, enable grants
        EponGrantClearReset(1UL << link);
        EponGrantEnable(1UL << link);
        }

    LifCreateLink (link, llid);
#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM96856)
    XifCreateLink (link, llid);
#endif
    } // PonMgrCreateLink

///////////////////////////////////////////////////////////////////////////////
/// \brief Get Data Queue L1 Map
///
///
/// \return L1 Map
/// 
////////////////////////////////////////////////////////////////////////////////
//extern
U32 PonMgrDataQueueL1MapGet(LinkIndex link)
{
    U8 i;
    U8 linkNum;
    U32 l1Map = 0;
    if(link == LinkIndexAll)
        {
        linkNum = OntmMpcpGetNumLinks();
        for (i = 0; i < linkNum; i++)
            {
            l1Map |= LinkQueueInd[i];
            }
        }
    else
        {
            l1Map |= LinkQueueInd[link];
        }
    return l1Map; 
}

int PonMgrActToWanState(LinkIndex link, BOOL enable)
    {
    if(enable)
        {
        if(OnuOsAssertGet(OsAstAlmLinkRegSucc,link))
            {
            PonMgrUserTrafficSet(link,TRUE);
            return 0;
            }
        }
    else
        {
        if(!OnuOsAssertGet(OsAstAlmLinkRegSucc,link))
            {
            if (link < OntmMpcpGetNumLinks())
                {   
                PonMgrUserTrafficSet(link,FALSE);
                StartRegisteringNewLink(link);
                }
            return 0;
            }
        }
    return -1;
    }
////////////////////////////////////////////////////////////////////////////////
/// EponGetRxOptState : The overhead for AES depends on the AES mode
///
 // Parameters:
/// \param  None
///
/// \return
/// the state of the Rx Optical
////////////////////////////////////////////////////////////////////////////////
//extern
PonMgrRxOpticalState PonMgrGetRxOptState (void)
    {
    PonMgrRxOpticalState  state = PonMgrRxOpticalStateNum;

    if (los)
        {
        state = PonMgrRxOpticalLos;
        }
    else
        {
        state = PonMgrRxOpticalLock;
        }

    return state;
    } // PonMgrGetRxOptState

void PonLosCheckTimeSet(U16 time)
    {
    PonLosChkime = time;
    PonDebug(PonDebugDefault, ("Epon los time %d\n", time));
    return;
    }


U16 PonLosCheckTimeGet(void)
    {
    return PonLosChkime;
    }

////////////////////////////////////////////////////////////////////////////////
/// \brief Check Los
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
static
BOOL Los (void)
    {
#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM96856)
    if (PonCfgDbGetDnRate() == LaserRate10G)
        {
        return !XifLocked();
        }
    else
#endif
        {
        return !LifLocked(); 
        }
    }

////////////////////////////////////////////////////////////////////////////////
/// \brief Pon los check handle
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
static
BOOL PonLosCheckHandle(BOOL enable)
    {
    U8 i = 3;
    BOOL ret = FALSE;
    U16 time = PonLosCheckTimeGet();

    //no configu any check time or no stats change or no los happen
    if ((time == 0) || (enable == lastLos) || (enable == FALSE))
        {
        lastLos = enable;
        return TRUE;
        }
    DelayMs(time);
    //clear first
    (void)Los();
    while(i-- > 0)
        {
        if (Los())
            {
            ret = TRUE;
            }
        }
    lastLos = enable;
    return (ret);
    }

////////////////////////////////////////////////////////////////////////////////
/// \brief Gate los check handle
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
BOOL GateLosCheckHandle(BOOL sync)
    {
    BOOL ret = FALSE;
    U16 time = GateLosCheckTimeGet();

    if (time > PonLosCheckTimeGet())
        time = time - PonLosCheckTimeGet();
    else
        time = 0;

    //do not need continue check
    if ((time == 0) || (sync == lastEponInSync) || (sync == TRUE))
        {
        lastEponInSync = sync;
        return TRUE;
        }

    //check sync if lost
    while (!EponInSync(los))
        {
        if (time == 0)
            {
            ret = TRUE;
            break;
            }
        DelayMs(1);
        time--;
        }
    //StopPolledTimer ();
    lastEponInSync = sync;
    return ret;
    }

////////////////////////////////////////////////////////////////////////////////
/// \brief  Cleanup PON side when in LOS
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
static
void LosCleanUp (void)
    {
    PonMgrRxDisable();
    // reset the Serdes Rx
    //SerDesPonLosCleanup (PonCfgDbGetActivePon());
    PonMgrRxEnable();
    }

////////////////////////////////////////////////////////////////////////////////
/// \brief Do we have a signal?
///
/// \return
/// TRUE if loss of signal, FALSE otherwise
////////////////////////////////////////////////////////////////////////////////
//extern
BOOL PonMgrLos (void)
    {
    return los;
    } // PonMgrLos


////////////////////////////////////////////////////////////////////////////////
/// \brief 10G FEC mode switch automically.
///          RX and TX mode always keep the same.
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgr10gFecAutoSwitch(void)
    {
    U8 link;
    BOOL enable = TRUE;
    BOOL retVal = TRUE;
    LinkMap  oldStartedLinks = 0;
    
    oldStartedLinks = PonMgrStartedLinksGet();
 
    enable = FecRxLinkState(0);
    enable = (!enable);
    
    PonMgrStopLinks(AllLinks);

    for (link = 0; link < TkOnuFirstRxOnlyLlid; link++)   
        retVal = retVal? FecModeSet(link, enable, enable, FecApp10G) : retVal;

    PonMgrStartLinks(oldStartedLinks);

    PonDebug(PonDebugDefault, ("10G FEC auto switch to %u, ret:%u \n", enable, retVal));
    }


////////////////////////////////////////////////////////////////////////////////
/// \brief During PON signal detection this will trigger the next attempt to
/// sync
///
/// Configures
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
//extern
//static
void PonManagerPoll (EponTimerModuleId moduleId)
    {
    BOOL  inSync; // Does the low level tell us we are in sync?
    static BOOL lastInSync = TRUE;
    static U8 debounce = 0; // 0 means it has been debounced.

    if (!epon_mac_init_done)
        return;

    // Update event driven variable.
    los = Los ();
    eponInSync = EponInSync (los);
    linksAlive = EponRcvdGrants () | (linksAlive & (~EponMissedGrants ()));
    // I think I am in sync if epon tells me so and if I don't have LOS
    inSync = eponInSync && (!los);

    if (los)
        {
        LosCleanUp();
        DelayMs(1);
        (void)Los();
        //mpcpGateNum = 0;
        }

    // 10G RX FEC auto-detection.
    // Only done when rx rate is 10G and no link is online.
    if (PonCfgDbGetDnRate() == LaserRate10G && fec10gAutoSwEn)
        {
        fec10gLosCnt = los? (fec10gLosCnt+1) : 0;
        
        if (OntmMpcpLinksRegistered() == 0 && fec10gLosCnt >= Fec10gDetectInterval)
            {
            PonMgr10gFecAutoSwitch();
            fec10gLosCnt = 0;
            }
        }

    //capture optical los happen
    //invalid los detection if los resume between(ctc3.0).
    if (PonLosCheckHandle(los)== FALSE)
        {
        return ;
        }

    //capture sync los happen
    //invalid sync los detection if sysn resume between some time(ctc3.0)
    if (GateLosCheckHandle(eponInSync) == FALSE)
        {
        return ;
        }

    // If someone needs to alter my perception of the sync state
    if (PonCfgDbGetRegCb() != NULL)
        {
        inSync = (PonCfgDbGetRegCb())(los, eponInSync);
        }

    // Debouncing
    if (inSync != lastInSync)
        {
        debounce = 0xFF;
        lastInSync = inSync;
        }
    else if (debounce != 0)
        {
        debounce--;
        }
    else
        {
        ;
        }

    // Only do something if we have a transition or when the ONU is boot up
    if (inSync != ponMgrInSync) 
        {
        if (!inSync)
            {
            // inform MPCP module of de-sync
            if (PonCfgDbGetMpcpCb() != NULL)
                {
                (PonCfgDbGetMpcpCb())();
                }
            //Set Alarm for LoS
            OsAstMsgQSet(OsAstAlmEponLos, 0, 0);	
            ponMgrInSync = FALSE;
            PonDebug(PonDebugDefault, ("PonLoS\n"));
            }
        else if (debounce == 0)
            {
            //clear alarm for Los
            OsAstMsgQClr(OsAstAlmEponLos, 0, 0);
            ponMgrInSync = TRUE;

#ifdef CONFIG_EPON_CLOCK_TRANSPORT
            ClkInit ();
#endif
            }
        else
            {
            ;
            }
        }
    } // PonManagerPoll

////////////////////////////////////////////////////////////////////////////////
/// OntmMpcpHandleTimer:  Background checking on links
///
 // Parameters:
/// None
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
//static
void PonMgrAlmHandleTimer (EponTimerModuleId moduleId)
    {
    U64 BULK eponRx;
    U64 BULK eponTx;
    static U64 BULK eponRxLast = 0;
    static U64 BULK eponTxLast = 0;

    if (!epon_mac_init_done)
        return;

    if (EponAnyFatalEvent())
        {
        //////////Reset All Upstream DataPath
        PonDebug(PonDebugDefault, ("Epon fatal event happens, reboot...\n"));
        //OsAstMsgQSet(OsAstAlmLinkFailSafeReset, 0, 1);
        }
	
    // Pon up/dn rate detection
    if (OntmMpcpLinksRegistered() != 0)
        {
        OsAstMsgQSet (ponCfgAlm.regUp, 0, 0);
        OsAstMsgQSet (ponCfgAlm.regDn, 0, 0);
        }
    else
        {
        OsAstMsgQClr (ponCfgAlm.regUp, 0, 0);
        OsAstMsgQClr (ponCfgAlm.regDn, 0, 0);
        }

    // Pon up/dn activity detection
    (void)StatsGetEpon(StatIdTotalFramesRx, &eponRx);
    (void)StatsGetEpon(StatIdTotalFramesTx, &eponTx);
    if (eponTx != eponTxLast)
        {
        eponTxLast = eponTx;
        OsAstMsgQSet (ponCfgAlm.actUp, 0, 0);
        }
    else
        {
        OsAstMsgQClr (ponCfgAlm.actUp, 0, 0);
        }
    if (eponRx != eponRxLast)
        {
        eponRxLast = eponRx;
        OsAstMsgQSet (ponCfgAlm.actDn, 0, 0);
        }
    else
        {
        OsAstMsgQClr (ponCfgAlm.actDn, 0, 0);
        }
    }

////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrFlushL1L2(LinkIndex link)
    {
    LinkMap linkmap = 1UL << link;
    U32  l2s = L2MapOfLinks(linkmap);
    U32  l1s = l2s;

    // disable runner queue so no packet willenter l1/l2
    DisableLinkRunnerQueue(linkmap);
    // disable upstream transmission so that no frames are in transit
    PonMgrPauseLinks(linkmap);
    
    // now that no frames are coming in or going out it is safe to disable the
    // L1/L2 fifos/schedulers
    
    // only flush data l2 queues in ctc
    if (PonMgrReportModeGet() == RptModeMultiPri8)
        {
        l2s = l2s & 0xFE;
        l1s = l2s;
        }
    
    //FLush L2 FIFO
    EponRepeatlyFlushL2Fifo(l2s, l1s);
    EponSetL1Reset (l1s);
    EponSetL2Reset (l2s);

    EponBBHUpsHaultStatusClr();
    EponBBHUpsHaultClr();
    startedLinks &= ~(linkmap);

    // now that we're sure the link is clean, enable the L1/L2 fifos
    PonMgrEnableL1L2(linkmap);
    // now that the L1/L2 are back up it's safe to transmit upstream
    PonMgrResumeLinks(linkmap);
   
    EnableLinkRunnerControlQueue(linkmap);
	startedLinks |= linkmap;

    }

#endif

////////////////////////////////////////////////////////////////////////////////
/// \brief Register the alarm id for each pon alarm
///
/// Initial configuration for PON.
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
static
void PonMgrAlmReg (void)
    {
    if (PonCfgDbGetUpRate () == LaserRate10G)
        {
        ponCfgAlm.regUp = OsAstAlmOnt10GUpRegistered;
        ponCfgAlm.actUp = OsAstAlmOnt10GUpActivity;
        }
    else
        {
        ponCfgAlm.regUp = OsAstAlmOnt1GUpRegistered;
        ponCfgAlm.actUp = OsAstAlmOnt1GUpActivity;
        }

    if (PonCfgDbGetDnRate () == LaserRate10G)
        {
        ponCfgAlm.regDn = OsAstAlmOnt10GDnRegistered;
        ponCfgAlm.actDn = OsAstAlmOnt10GDnActivity;
        }
    else
        {
        ponCfgAlm.regDn = OsAstAlmOnt1GDnRegistered;
        ponCfgAlm.actDn = OsAstAlmOnt1GDnActivity;
        }
    }//PonMgrAlmReg


////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrActivePonSet(PortInstance pon)
    {
    if (pon < NumPonIf)
        {
        PonCfgDbActivePonSet(pon);
        PonMgrRxDisable();
        PonMgrFlushGrants(AllLinks);          
        PonMgrRxEnable();
        }
    }


////////////////////////////////////////////////////////////////////////////////
/// \brief Setup XIF/LIF for TX-to-RX loopback
///
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrTxToRxLoopback (void)
    {
    if (LaserRate10G == PonCfgDbGetDnRate())
        {
        
        }
    else
        {
        LifTxToRxLoopback ();
        }
    }


////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrSetReporting (PonMgrRptMode rptMode)
    {
    U8 i;
    U32 size;
    curRptMode = rptMode;
    EponSetNumPri(PonMgrRptModeToPri(rptMode),
                  PonCfgDbSchMode() );

    if (PonCfgDbGetUpRate() == LaserRate10G)
        {
        size = Com10gL2DefSize;
        }
    else
        {
        if (curRptMode == RptModeFrameAligned)
            {
            
            size = BcmRpt1gL2DefSize;
            }
        else
            {
            size = CtcRpt1gL2DefSize;
            }
        }
    
    for (i = 0; i < EponNumL2Queues; ++i)
        {
        l2size[i] = size;
        }
    }


////////////////////////////////////////////////////////////////////////////////
/// \brief Set L1 queue byte limit.
///
///
/// \return
/// True:success; False:fail
////////////////////////////////////////////////////////////////////////////////
//extern
BOOL PonMgrL1ByteLimitSet(U8 queue, U8 limit)
    {
    return TRUE;
    }


///////////////////////////////////////////////////////////////////////////////
/// \brief Get L1 queue byte limit.
///
///
/// \return
/// True:success; False:fail
////////////////////////////////////////////////////////////////////////////////
//extern
BOOL PonMgrL1ByteLimitGet(U8 queue, U8* limit)
    {
    *limit = 0;
    
    return TRUE;
    }

///////////////////////////////////////////////////////////////////////////////
/// \brief Get Link FlowId by link and queue
///
///
/// \return FlowId
/// 
////////////////////////////////////////////////////////////////////////////////
//extern
U16 PonMgrLinkFlowGet(U32 link, U32 queue)
    {
    U16 flow = link;
    
    return flow;
    }

////////////////////////////////////////////////////////////////////////////////
/// PonPmdAlmHandleTimer:  Check for PMD alarms
///
 // Parameters:
/// None
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
//static
void PonPmdAlmHandleTimer (EponTimerModuleId moduleId)
    {
    uint16_t OpticsType;
    uint32_t alarms;
    
    BpGetGponOpticsType(&OpticsType);
    
    if (OpticsType == BP_GPON_OPTICS_TYPE_PMD )
        alarms = pmd_dev_poll_epon_alarm();
    }


////////////////////////////////////////////////////////////////////////////////
/// \brief Set received max frame size of epon mac
///
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrMaxFrameSizeSet(U16 maxFrameSize)
    {
    EponSetMaxFrameSize(maxFrameSize);
    }


////////////////////////////////////////////////////////////////////////////////
/// \brief Init tc to queue setting for epon upstream
///
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
//extern
static void PonMgrEponInitTcToQ(void)
    {
    int rc = 0;
    U8 i = 0;
    bdmf_object_handle tc_to_q_obj = NULL;
    BDMF_MATTR(qos_mattrs, rdpa_tc_to_queue_drv());
    rdpa_tc_to_queue_table_set(qos_mattrs, 0);
    rdpa_tc_to_queue_dir_set(qos_mattrs, rdpa_dir_us);
    
    if ((rc = bdmf_new_and_set(
        rdpa_tc_to_queue_drv(), NULL, qos_mattrs, &tc_to_q_obj)))
        {
        BCM_LOG_ERROR(BCM_LOG_ID_EPON, "bdmf_new_and_set tc_to_queue obj failed, rc(%d) \n",rc);
        }
    else
        {
        for (i = 0; i < 8; i++)
            { 
            if ((rc = rdpa_tc_to_queue_tc_map_set(tc_to_q_obj, i, i)))
                {
                BCM_LOG_ERROR(BCM_LOG_ID_EPON, "rdpa_tc_to_queue_tc_map_set failed,"
                    "q(%u) rc(%d) \n", i, rc);
                break;
                }
            }
        }
    }


////////////////////////////////////////////////////////////////////////////////
/// \brief Init Epon Mac Queue Config
///
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrEponMacQueueConfigInit(epon_mac_q_cfg_t *cfg)
    {
    switch (oam_mode)
        {   
        case rdpa_epon_dpoe:
            /* fall through */
        case rdpa_epon_bcm:
            {
            cfg->rpt_mode = RptModeFrameAligned;

#if defined(CONFIG_BCM96836) || defined(CONFIG_BCM96846)
            cfg->link_num = Bcm1gOnuNumBiDirLlids;
#else
            if (PonCfgDbGetUpRate() == LaserRate10G)
                {
                cfg->link_num = Bcm10gOnuNumBiDirLlids-TkOnuRsvNumRxOnlyLlids;
                }
            else
                {
                cfg->link_num = Bcm1gOnuNumBiDirLlids-TkOnuRsvNumRxOnlyLlids;
                }
#endif

            break;    
            }
        default:
            {
            cfg->link_num = DefLinkNum;
            cfg->rpt_mode = RptModeMultiPri8;
            break;
            }
        }
    
    PonMgrEponInitTcToQ();
    }


////////////////////////////////////////////////////////////////////////////////
/// \brief set rdpa llid fec overhead 
///
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrRdpaLlidFecSet(LinkIndex link,BOOL enable)
    {
    bdmf_object_handle llid_h = NULL;
    bdmf_error_t rc = BDMF_ERR_OK; 
    if (0 == rdpa_llid_get(link, &llid_h))
        {
        rc = rdpa_llid_fec_overhead_set(llid_h, enable);
        if (BDMF_ERR_OK != rc)
            {
            printk("set llid %u fec set %d fail, Err:%d\n",
                   link, enable, rc);
            }
        bdmf_put(llid_h);
        }
    }

////////////////////////////////////////////////////////////////////////////////
/// \brief set rdpa llid 8021AE overhead 
///
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrRdpaLlid8021AESet(LinkIndex link,BOOL enable)
    {
    bdmf_object_handle llid_h = NULL;
    bdmf_error_t rc = BDMF_ERR_OK; 
    if (0 == rdpa_llid_get(link, &llid_h))
        {
        rc = rdpa_llid_q_802_1ae_set(llid_h, enable);
        if (BDMF_ERR_OK != rc)
            {
            printk("set llid %u fec set %d fail, Err:%d\n",
                   link, enable, rc);
            }
        bdmf_put(llid_h);
        }
    }


////////////////////////////////////////////////////////////////////////////////
/// \brief set rdpa llid SCI overhead 
///
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrRdpaLlidSciSet(LinkIndex link,BOOL enable)
    {
    bdmf_object_handle llid_h = NULL;
    bdmf_error_t rc = BDMF_ERR_OK; 
    if (0 == rdpa_llid_get(link, &llid_h))
        {
        rc = rdpa_llid_sci_overhead_set(llid_h, enable);
        if (BDMF_ERR_OK != rc)
            {
            printk("set llid %u fec set %d fail, Err:%d\n",
                   link, enable, rc);
            }
        bdmf_put(llid_h);
        }
    }

////////////////////////////////////////////////////////////////////////////////
/// \brief Initialization of Pon Configuration
///
/// Initial configuration for PON.
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
//extern
void PonMgrInit (void)
    {
    U8 idx;
    LinkIndex link;
    MacAddr baseEponMac;
    U16 macLow16;
    
    FecInit();
	
    memset(userTrafficEnable, 0, sizeof(userTrafficEnable));
    PonMgrUserTrafficSet(0, FALSE);
    //EponTopSpeedInit (PonCfgDbGetUpRate(), PonCfgDbGetDnRate());
    
    EponEpnInit (PonCfgDbGetMaxFrameSize(),
        PonCfgDbGetPreDraft2Dot1(),
        PonCfgDbGetNttReporting(),
        PonCfgDbGetUpRate()); 

    if (PonCfgDbGetUpRate() < LaserRate10G)
    	{
        LifInit (PonCfgDbGetOffTimeOffset(), PonCfgDbGettxOffIdle() ,
                PonCfgDbGetUpPolarity(), PonCfgDbGetUpRate(), 
                PonCfgDbGetDnRate());
        rtMaxRxOnlyLlids  = Bcm1gOnuNumBiDirLlids;
        rtFirstRxOnlyLlid = Bcm1gOnuNumBiDirLlids-TkOnuRsvNumRxOnlyLlids;
    	}

#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM96856)
    if (PonCfgDbGetDnRate() == LaserRate10G)
    	{
        XifInit (PonCfgDbGetOffTimeOffset(), PonCfgDbGettxOffIdle() ,
                 PonCfgDbGetUpPolarity(), PonCfgDbGetUpRate(), 
                 PonCfgDbGetDnRate());
    	}
#endif
    
    PonMgrAlmReg ();

    for (idx = 0; idx < EponNumL2Queues; ++idx)
        {
        if (PonCfgDbGetUpRate() == LaserRate10G)
            {
            l2size[idx] = Com10gL2DefSize;
            }
        else
            {
            l2size[idx] = CtcRpt1gL2DefSize;   
            }
        }
    
    memset(linkBcap,0,sizeof(linkBcap));

    // Whether to enable/disable the IPG for Shaper.
    for (idx = 0; idx < EponUpstreamShaperCount; ++idx)
        {
        shaperInUse[idx] = FALSE;
        EponSetShaperIpg (idx, PonCfgDbGetIpg());
        }

    memcpy (&baseEponMac, PonCfgDbGetBaseMacAddr(), sizeof(baseEponMac));
    
    // We need to load the MAC addresses for the links
    for (link = 0; link < TkOnuNumTxLlids; link++)
        {
        EponSetMac(link, &baseEponMac);

        /* baseEponMac.word[2]++ */
        macLow16 = EPON_NTOHS(baseEponMac.word[2]);
        macLow16++;
        baseEponMac.word[2] = EPON_HTONS(macLow16);
        }
#ifdef EPON_MPCP_SUPPORT    
    if(EponGetMacMode() == EPON_MAC_NORMAL_MODE)
        {
        //register timer to check gates
        EponUsrModuleTimerRegister(EPON_TIMER_TO1,
                      PonPollingTimer,PonManagerPoll);
        //Event monitor timer.
        EponUsrModuleTimerRegister(EPON_TIMER_TO1,
                      PonEventTimer,PonMgrAlmHandleTimer);
        //PMD timer.
        /*EponUsrModuleTimerRegister(EPON_TIMER_TO1,
                PonPmdPollingTimer,PonPmdAlmHandleTimer);    */
        }
#endif    
    } // PonMgrInit
// end of PonManager.c

