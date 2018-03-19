/*
*  Copyright 2011, Broadcom Corporation
*
* <:copyright-BRCM:2011:proprietary:epon
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


////////////////////////////////////////////////////////////////////////////////
// \file Nco.c 
// \brief Numerically Control Oscillator module definition
//
// This module implements the Numerically Control Oscillator which is used to
// drive the clock transport feature.
//
////////////////////////////////////////////////////////////////////////////////

#include "Teknovus.h"
#include "Nco.h"
#include "drv_epon_nco_addr_ag.h"

// NCO gains: - use higher gains when unsynced to let NCO move faster
//            - use lower gains when synced because the NCO needn't move quickly
//              to follow the OLT and low gains minimizes our own drift in case
//              of missed or infrequent sync messages.
#define UnsyncedNcoIntGainVal   0x1c0
#define UnsyncedNcoPropGainVal  0xc
#define SyncedNcoIntGainVal     0x70  // x/4 for now
#define SyncedNcoPropGainVal    0x3   // x/4 for now


U32 NcoGetCurPeriodCount(void)
    {
    U32 periodcnt;
    bdmf_error_t drv_error = BDMF_ERR_OK;

    drv_error += ag_drv_nco_addr_nco_period_cnt_get(&periodcnt);
    return periodcnt;
    }


void NcoSetCfgReset(Bool flag)
    {
    nco_addr_nco_cfg nco_cfg;
    bdmf_error_t drv_error = BDMF_ERR_OK;

    drv_error += ag_drv_nco_addr_nco_cfg_get(&nco_cfg);
    
    if (flag)
        nco_cfg.cfgncoclr = TRUE;
    else
        nco_cfg.cfgncoclr = FALSE;

    drv_error += ag_drv_nco_addr_nco_cfg_set(&nco_cfg);
    }


void NcoKeepIntPerInt(void)
    {
    }


void NcoSetIntPerInt(U32 value)
    {
    bdmf_error_t drv_error = BDMF_ERR_OK;
    
    drv_error += ag_drv_nco_addr_nco_center_frequency_set(value);
    }


void NcoSetGainSync(BOOL sync)
    {
    U16 ncoIntGainVal = UnsyncedNcoIntGainVal;
    U16 ncoPropGainVal = UnsyncedNcoPropGainVal;
    bdmf_error_t drv_error = BDMF_ERR_OK;

    if (sync)
        {
        ncoIntGainVal = SyncedNcoIntGainVal;
        ncoPropGainVal = SyncedNcoPropGainVal;
        }

    drv_error += ag_drv_nco_addr_nco_int_gain_set(ncoIntGainVal);
    drv_error += ag_drv_nco_addr_nco_pro_gain_set(ncoPropGainVal);
    }

////////////////////////////////////////////////////////////////////////////////
/// clearSyncInterrupt
/// \brief clears the Sync Interrupt
///
/// Parameters:
/// \param none
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
void ClearSyncInterrupt(void)
    {
    bdmf_boolean intnoncosync;
    bdmf_boolean intnoxifpps;
    bdmf_boolean intnolifpps;
    bdmf_error_t drv_error = BDMF_ERR_OK;
    
    drv_error += ag_drv_nco_addr_nco_int_get(&intnoncosync, &intnoxifpps, &intnolifpps);

    intnoncosync = TRUE;
    drv_error += ag_drv_nco_addr_nco_int_set(intnoncosync, intnoxifpps, intnolifpps);
    }


////////////////////////////////////////////////////////////////////////////////
/// syncLocked
/// \brief test the NcoInterrupt register to determine whether we are in sync
///
/// Note: the NcoInterrupt register goes high when sync is not locked.
///
/// Parameters:
/// \param none
///
/// \return
/// Bool true if sync has not been lost.
////////////////////////////////////////////////////////////////////////////////
BOOL SyncLocked(void)
    {
    bdmf_boolean intnoncosync;
    bdmf_boolean intnoxifpps;
    bdmf_boolean intnolifpps;
    bdmf_error_t drv_error = BDMF_ERR_OK;
    
    drv_error += ag_drv_nco_addr_nco_int_get(&intnoncosync, &intnoxifpps, &intnolifpps);

    if (intnoncosync)
        {
        return FALSE;
        }
    else
        {
        return TRUE;
        }
    }


////////////////////////////////////////////////////////////////////////////////
/// NcoSet1PpsHalfPeriod - Set 1PPS half period value
///
/// This function programs the half period (duty cycle) of the of the 1PPS.
/// The duty cycle is the amount of time in 100ns increments the pulse should
/// be high for each 1 second clock.
///
 // Parameters:
/// \param period Half period value in 100ns time quanta
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
//extern
void NcoSet1PpsHalfPeriod (U32 period)
    {
    bdmf_error_t drv_error = BDMF_ERR_OK;
    
    drv_error += ag_drv_nco_addr_nco_1pps_half_set(period);
    } // NcoSet1PpsHalfPeriod

////////////////////////////////////////////////////////////////////////////////
/// NcoInit - Initialize NCO Module
///
/// This function initialized the Numerically Control Oscillator module,
/// disabling the module by default and holding it in reset.
///
 // Parameters:
///
/// \return
/// None
////////////////////////////////////////////////////////////////////////////////
//extern
void NcoInit (NcoSrc input)
    {
    // We only want this code to be called once.  After the NCO has been put
    // into XIF mode we do not want to take it out or the NCO will kick on
    // and cause the clock to drift.  When the NCO gain is corrected this
    // function can be called every init cycle.  ASIC is supposed to add a
    // function to block the clock output, having that feature would also
    // allow this function to be called in all cases.
    nco_addr_nco_cfg nco_cfg;
    bdmf_error_t drv_error = BDMF_ERR_OK;

    nco_cfg.cfgbypass = 0;
    nco_cfg.cfgsrcout = NcoSrcNco;
    nco_cfg.cfgsrcin = input;
    nco_cfg.cfgncoclr = TRUE;
    nco_cfg.cfgsrcout10mhz = 0;

    drv_error += ag_drv_nco_addr_nco_cfg_set(&nco_cfg);
    } // NcoInit

// End of file Nco.c
