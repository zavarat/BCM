/*
* <:copyright-BRCM:2016:proprietary:gpon
* 
*    Copyright (c) 2016 Broadcom 
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

#ifndef _BCM6858_NGPON_TX_INT_AG_H_
#define _BCM6858_NGPON_TX_INT_AG_H_

#include "access_macros.h"
#include "bcmtypes.h"
#ifdef USE_BDMF_SHELL
#include "bdmf_shell.h"
#endif
typedef struct
{
    uint8_t tx_plm_0;
    uint8_t tx_plm_1;
    uint8_t tx_plm_2;
    uint8_t fe_data_overun;
    uint8_t pd_underun;
    uint8_t pd_overun;
    uint8_t af_err;
    uint8_t rog_dif;
    uint8_t rog_len;
    uint8_t tx_tcont_32_dbr;
    uint8_t tx_tcont_33_dbr;
    uint8_t tx_tcont_34_dbr;
    uint8_t tx_tcont_35_dbr;
    uint8_t tx_tcont_36_dbr;
    uint8_t tx_tcont_37_dbr;
    uint8_t tx_tcont_38_dbr;
    uint8_t tx_tcont_39_dbr;
} ngpon_tx_int_isr1;

typedef struct
{
    uint8_t tx_plm_0;
    uint8_t tx_plm_1;
    uint8_t tx_plm_2;
    uint8_t fe_data_overun;
    uint8_t pd_underun;
    uint8_t pd_overun;
    uint8_t af_err;
    uint8_t rog_dif;
    uint8_t rog_len;
    uint8_t tx_tcont_32_dbr;
    uint8_t tx_tcont_33_dbr;
    uint8_t tx_tcont_34_dbr;
    uint8_t tx_tcont_35_dbr;
    uint8_t tx_tcont_36_dbr;
    uint8_t tx_tcont_37_dbr;
    uint8_t tx_tcont_38_dbr;
    uint8_t tx_tcont_39_dbr;
} ngpon_tx_int_ism1;

typedef struct
{
    uint8_t tx_plm_0;
    uint8_t tx_plm_1;
    uint8_t tx_plm_2;
    uint8_t fe_data_overun;
    uint8_t pd_underun;
    uint8_t pd_overun;
    uint8_t af_err;
    uint8_t rog_dif;
    uint8_t rog_len;
    uint8_t tx_tcont_32_dbr;
    uint8_t tx_tcont_33_dbr;
    uint8_t tx_tcont_34_dbr;
    uint8_t tx_tcont_35_dbr;
    uint8_t tx_tcont_36_dbr;
    uint8_t tx_tcont_37_dbr;
    uint8_t tx_tcont_38_dbr;
    uint8_t tx_tcont_39_dbr;
} ngpon_tx_int_ier1;

typedef struct
{
    uint8_t tx_plm_0;
    uint8_t tx_plm_1;
    uint8_t tx_plm_2;
    uint8_t fe_data_overun;
    uint8_t pd_underun;
    uint8_t pd_overun;
    uint8_t af_err;
    uint8_t rog_dif;
    uint8_t rog_len;
    uint8_t tx_tcont_32_dbr;
    uint8_t tx_tcont_33_dbr;
    uint8_t tx_tcont_34_dbr;
    uint8_t tx_tcont_35_dbr;
    uint8_t tx_tcont_36_dbr;
    uint8_t tx_tcont_37_dbr;
    uint8_t tx_tcont_38_dbr;
    uint8_t tx_tcont_39_dbr;
} ngpon_tx_int_itr1;

int ag_drv_ngpon_tx_int_isr0_set(uint8_t tx_tcont_dbr_idx, uint8_t is_tx_tcont_dbr_int_active);
int ag_drv_ngpon_tx_int_isr0_get(uint8_t tx_tcont_dbr_idx, uint8_t *is_tx_tcont_dbr_int_active);
int ag_drv_ngpon_tx_int_ism0_get(uint8_t tx_tcont_dbr_idx, uint8_t *is_tx_tcont_dbr_int_mask);
int ag_drv_ngpon_tx_int_ier0_set(uint8_t tx_tcont_dbr_idx, uint8_t is_tx_tcont_dbr_int_ena);
int ag_drv_ngpon_tx_int_ier0_get(uint8_t tx_tcont_dbr_idx, uint8_t *is_tx_tcont_dbr_int_ena);
int ag_drv_ngpon_tx_int_itr0_set(uint8_t tx_tcont_dbr_idx, uint8_t is_tx_tcont_dbr_int_test);
int ag_drv_ngpon_tx_int_itr0_get(uint8_t tx_tcont_dbr_idx, uint8_t *is_tx_tcont_dbr_int_test);
int ag_drv_ngpon_tx_int_isr1_set(const ngpon_tx_int_isr1 *isr1);
int ag_drv_ngpon_tx_int_isr1_get(ngpon_tx_int_isr1 *isr1);
int ag_drv_ngpon_tx_int_ism1_get(ngpon_tx_int_ism1 *ism1);
int ag_drv_ngpon_tx_int_ier1_set(const ngpon_tx_int_ier1 *ier1);
int ag_drv_ngpon_tx_int_ier1_get(ngpon_tx_int_ier1 *ier1);
int ag_drv_ngpon_tx_int_itr1_set(const ngpon_tx_int_itr1 *itr1);
int ag_drv_ngpon_tx_int_itr1_get(ngpon_tx_int_itr1 *itr1);

#ifdef USE_BDMF_SHELL
bdmfmon_handle_t ag_drv_ngpon_tx_int_cli_init(bdmfmon_handle_t driver_dir);
#endif


#endif

