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

#include "ru.h"
#include "GPON_BLOCKS.h"


#if RU_INCLUDE_FIELD_DB
/******************************************************************************
 * Field: GPON_RX_GENERAL_CONFIG_RCVR_STATUS_LOF
 ******************************************************************************/
const ru_field_rec GPON_RX_GENERAL_CONFIG_RCVR_STATUS_LOF_FIELD =
{
    "LOF",
#if RU_INCLUDE_DESC
    "LOF_State",
    "Indicates the LOF state",
#endif
    GPON_RX_GENERAL_CONFIG_RCVR_STATUS_LOF_FIELD_MASK,
    0,
    GPON_RX_GENERAL_CONFIG_RCVR_STATUS_LOF_FIELD_WIDTH,
    GPON_RX_GENERAL_CONFIG_RCVR_STATUS_LOF_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_read
#endif
};

/******************************************************************************
 * Field: GPON_RX_GENERAL_CONFIG_RCVR_STATUS_FEC_STATE
 ******************************************************************************/
const ru_field_rec GPON_RX_GENERAL_CONFIG_RCVR_STATUS_FEC_STATE_FIELD =
{
    "FEC_STATE",
#if RU_INCLUDE_DESC
    "FEC_state",
    "The contents of this bit reflect the FEC state received in the Ident field of the incoming DS frame."
    "0 - FEC is disabled"
    "1 - FEC is enabled",
#endif
    GPON_RX_GENERAL_CONFIG_RCVR_STATUS_FEC_STATE_FIELD_MASK,
    0,
    GPON_RX_GENERAL_CONFIG_RCVR_STATUS_FEC_STATE_FIELD_WIDTH,
    GPON_RX_GENERAL_CONFIG_RCVR_STATUS_FEC_STATE_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_read
#endif
};

/******************************************************************************
 * Field: GPON_RX_GENERAL_CONFIG_RCVR_STATUS_LCDG_STATE
 ******************************************************************************/
const ru_field_rec GPON_RX_GENERAL_CONFIG_RCVR_STATUS_LCDG_STATE_FIELD =
{
    "LCDG_STATE",
#if RU_INCLUDE_DESC
    "Loss_of_GEM_Delineation",
    "Indicates whether the GEM SAR is synced to the incoming stream of GEM fragments",
#endif
    GPON_RX_GENERAL_CONFIG_RCVR_STATUS_LCDG_STATE_FIELD_MASK,
    0,
    GPON_RX_GENERAL_CONFIG_RCVR_STATUS_LCDG_STATE_FIELD_WIDTH,
    GPON_RX_GENERAL_CONFIG_RCVR_STATUS_LCDG_STATE_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_read
#endif
};

/******************************************************************************
 * Field: GPON_RX_GENERAL_CONFIG_RCVR_STATUS_RESERVED0
 ******************************************************************************/
const ru_field_rec GPON_RX_GENERAL_CONFIG_RCVR_STATUS_RESERVED0_FIELD =
{
    "RESERVED0",
#if RU_INCLUDE_DESC
    "",
    "",
#endif
    GPON_RX_GENERAL_CONFIG_RCVR_STATUS_RESERVED0_FIELD_MASK,
    0,
    GPON_RX_GENERAL_CONFIG_RCVR_STATUS_RESERVED0_FIELD_WIDTH,
    GPON_RX_GENERAL_CONFIG_RCVR_STATUS_RESERVED0_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_read
#endif
};

/******************************************************************************
 * Field: GPON_RX_GENERAL_CONFIG_RCVR_STATUS_BIT_ALIGN
 ******************************************************************************/
const ru_field_rec GPON_RX_GENERAL_CONFIG_RCVR_STATUS_BIT_ALIGN_FIELD =
{
    "BIT_ALIGN",
#if RU_INCLUDE_DESC
    "Frame_bit_alignment",
    "Indicates the bit alignment in which the frame is received. Possible values are 0 to 15 bits.",
#endif
    GPON_RX_GENERAL_CONFIG_RCVR_STATUS_BIT_ALIGN_FIELD_MASK,
    0,
    GPON_RX_GENERAL_CONFIG_RCVR_STATUS_BIT_ALIGN_FIELD_WIDTH,
    GPON_RX_GENERAL_CONFIG_RCVR_STATUS_BIT_ALIGN_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_read
#endif
};

/******************************************************************************
 * Field: GPON_RX_GENERAL_CONFIG_RCVR_STATUS_RESERVED1
 ******************************************************************************/
const ru_field_rec GPON_RX_GENERAL_CONFIG_RCVR_STATUS_RESERVED1_FIELD =
{
    "RESERVED1",
#if RU_INCLUDE_DESC
    "",
    "",
#endif
    GPON_RX_GENERAL_CONFIG_RCVR_STATUS_RESERVED1_FIELD_MASK,
    0,
    GPON_RX_GENERAL_CONFIG_RCVR_STATUS_RESERVED1_FIELD_WIDTH,
    GPON_RX_GENERAL_CONFIG_RCVR_STATUS_RESERVED1_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_read
#endif
};

/******************************************************************************
 * Field: GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_DES_DISABLE
 ******************************************************************************/
const ru_field_rec GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_DES_DISABLE_FIELD =
{
    "DES_DISABLE",
#if RU_INCLUDE_DESC
    "Descrambler_Disable",
    "Bypasses the descrambler so that the incoming data is passed as-is to the internal units."
    "This field can be changed on-the-fly during operation.",
#endif
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_DES_DISABLE_FIELD_MASK,
    0,
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_DES_DISABLE_FIELD_WIDTH,
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_DES_DISABLE_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

/******************************************************************************
 * Field: GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_FEC_DISABLE
 ******************************************************************************/
const ru_field_rec GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_FEC_DISABLE_FIELD =
{
    "FEC_DISABLE",
#if RU_INCLUDE_DESC
    "FEC_Disable",
    "Disables the FEC decoder even if DS FEC is enabled."
    "This field  can be changed only while the receiver is disabled.",
#endif
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_FEC_DISABLE_FIELD_MASK,
    0,
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_FEC_DISABLE_FIELD_WIDTH,
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_FEC_DISABLE_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

/******************************************************************************
 * Field: GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_RX_DISABLE
 ******************************************************************************/
const ru_field_rec GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_RX_DISABLE_FIELD =
{
    "RX_DISABLE",
#if RU_INCLUDE_DESC
    "Receiver_Enable",
    "Enables/Disables the entire receiver unit."
    "This field  can be changed on-the-fly during operation. Changes go into effect on frame boundaries.",
#endif
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_RX_DISABLE_FIELD_MASK,
    0,
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_RX_DISABLE_FIELD_WIDTH,
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_RX_DISABLE_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

/******************************************************************************
 * Field: GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_LOOPBACK_ENABLE
 ******************************************************************************/
const ru_field_rec GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_LOOPBACK_ENABLE_FIELD =
{
    "LOOPBACK_ENABLE",
#if RU_INCLUDE_DESC
    "Loopback_Enable",
    "Enables/Disables the RX-TX loopback."
    "This field can be changed on-the-fly during operation.",
#endif
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_LOOPBACK_ENABLE_FIELD_MASK,
    0,
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_LOOPBACK_ENABLE_FIELD_WIDTH,
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_LOOPBACK_ENABLE_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

/******************************************************************************
 * Field: GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_FEC_FORCE
 ******************************************************************************/
const ru_field_rec GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_FEC_FORCE_FIELD =
{
    "FEC_FORCE",
#if RU_INCLUDE_DESC
    "FEC_Force",
    "Forces FEC decoding on DS regardless of the bit in the Ident field."
    "This field can be changed only while the receiver is disabled.",
#endif
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_FEC_FORCE_FIELD_MASK,
    0,
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_FEC_FORCE_FIELD_WIDTH,
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_FEC_FORCE_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

/******************************************************************************
 * Field: GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_FEC_ST_DISC
 ******************************************************************************/
const ru_field_rec GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_FEC_ST_DISC_FIELD =
{
    "FEC_ST_DISC",
#if RU_INCLUDE_DESC
    "FEC_State_Disconnect",
    "Prevents the RX Unit from making the FEC transitions autonomously."
    "This field should not be used (always write 1 to this field).",
#endif
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_FEC_ST_DISC_FIELD_MASK,
    0,
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_FEC_ST_DISC_FIELD_WIDTH,
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_FEC_ST_DISC_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

/******************************************************************************
 * Field: GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_SQUELCH_DIS
 ******************************************************************************/
const ru_field_rec GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_SQUELCH_DIS_FIELD =
{
    "SQUELCH_DIS",
#if RU_INCLUDE_DESC
    "Squelch_Disable",
    "Neutralizes the FEC State Transition fix."
    "This field should not be used (always write 1 to this field).",
#endif
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_SQUELCH_DIS_FIELD_MASK,
    0,
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_SQUELCH_DIS_FIELD_WIDTH,
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_SQUELCH_DIS_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

/******************************************************************************
 * Field: GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_SOP_RESET
 ******************************************************************************/
const ru_field_rec GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_SOP_RESET_FIELD =
{
    "SOP_RESET",
#if RU_INCLUDE_DESC
    "SOP_Reset",
    "Resets all flows to SOP (Start Of Packet) State. Should only be applied when the module is in LOF or Rx_Disable states."
    "This field should not be used (always write 0 to this field).",
#endif
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_SOP_RESET_FIELD_MASK,
    0,
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_SOP_RESET_FIELD_WIDTH,
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_SOP_RESET_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

/******************************************************************************
 * Field: GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_DIN_POLARITY
 ******************************************************************************/
const ru_field_rec GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_DIN_POLARITY_FIELD =
{
    "DIN_POLARITY",
#if RU_INCLUDE_DESC
    "RX_data_in_polarity",
    "This bit controls the polarity of the GPON RX data input",
#endif
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_DIN_POLARITY_FIELD_MASK,
    0,
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_DIN_POLARITY_FIELD_WIDTH,
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_DIN_POLARITY_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

/******************************************************************************
 * Field: GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_RESERVED0
 ******************************************************************************/
const ru_field_rec GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_RESERVED0_FIELD =
{
    "RESERVED0",
#if RU_INCLUDE_DESC
    "",
    "",
#endif
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_RESERVED0_FIELD_MASK,
    0,
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_RESERVED0_FIELD_WIDTH,
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_RESERVED0_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

/******************************************************************************
 * Field: GPON_RX_GENERAL_CONFIG_LOF_PARAMS_DELTA
 ******************************************************************************/
const ru_field_rec GPON_RX_GENERAL_CONFIG_LOF_PARAMS_DELTA_FIELD =
{
    "DELTA",
#if RU_INCLUDE_DESC
    "Delta_value",
    "The number of consecutive incorrect Psync values required for assertion of the LOF alarm."
    "This field should be changed only when the receiver is disabled.",
#endif
    GPON_RX_GENERAL_CONFIG_LOF_PARAMS_DELTA_FIELD_MASK,
    0,
    GPON_RX_GENERAL_CONFIG_LOF_PARAMS_DELTA_FIELD_WIDTH,
    GPON_RX_GENERAL_CONFIG_LOF_PARAMS_DELTA_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

/******************************************************************************
 * Field: GPON_RX_GENERAL_CONFIG_LOF_PARAMS_ALPHA
 ******************************************************************************/
const ru_field_rec GPON_RX_GENERAL_CONFIG_LOF_PARAMS_ALPHA_FIELD =
{
    "ALPHA",
#if RU_INCLUDE_DESC
    "Alpha_value",
    "The number of consecutive correct Psync values required for de-assertion of the LOF alarm."
    "This value should be changed only when the receiver is disabled.",
#endif
    GPON_RX_GENERAL_CONFIG_LOF_PARAMS_ALPHA_FIELD_MASK,
    0,
    GPON_RX_GENERAL_CONFIG_LOF_PARAMS_ALPHA_FIELD_WIDTH,
    GPON_RX_GENERAL_CONFIG_LOF_PARAMS_ALPHA_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

/******************************************************************************
 * Field: GPON_RX_GENERAL_CONFIG_LOF_PARAMS_RESERVED0
 ******************************************************************************/
const ru_field_rec GPON_RX_GENERAL_CONFIG_LOF_PARAMS_RESERVED0_FIELD =
{
    "RESERVED0",
#if RU_INCLUDE_DESC
    "",
    "",
#endif
    GPON_RX_GENERAL_CONFIG_LOF_PARAMS_RESERVED0_FIELD_MASK,
    0,
    GPON_RX_GENERAL_CONFIG_LOF_PARAMS_RESERVED0_FIELD_WIDTH,
    GPON_RX_GENERAL_CONFIG_LOF_PARAMS_RESERVED0_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

/******************************************************************************
 * Field: GPON_RX_GENERAL_CONFIG_RANDOMSD_RANDOMSD
 ******************************************************************************/
const ru_field_rec GPON_RX_GENERAL_CONFIG_RANDOMSD_RANDOMSD_FIELD =
{
    "RANDOMSD",
#if RU_INCLUDE_DESC
    "Random_Seed",
    "Contains a random 32 bit number which changes constantly",
#endif
    GPON_RX_GENERAL_CONFIG_RANDOMSD_RANDOMSD_FIELD_MASK,
    0,
    GPON_RX_GENERAL_CONFIG_RANDOMSD_RANDOMSD_FIELD_WIDTH,
    GPON_RX_GENERAL_CONFIG_RANDOMSD_RANDOMSD_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_read
#endif
};

#endif /* RU_INCLUDE_FIELD_DB */

/******************************************************************************
 * Register: GPON_RX_GENERAL_CONFIG_RCVR_STATUS
 ******************************************************************************/
#if RU_INCLUDE_FIELD_DB
static const ru_field_rec *GPON_RX_GENERAL_CONFIG_RCVR_STATUS_FIELDS[] =
{
    &GPON_RX_GENERAL_CONFIG_RCVR_STATUS_LOF_FIELD,
    &GPON_RX_GENERAL_CONFIG_RCVR_STATUS_FEC_STATE_FIELD,
    &GPON_RX_GENERAL_CONFIG_RCVR_STATUS_LCDG_STATE_FIELD,
    &GPON_RX_GENERAL_CONFIG_RCVR_STATUS_RESERVED0_FIELD,
    &GPON_RX_GENERAL_CONFIG_RCVR_STATUS_BIT_ALIGN_FIELD,
    &GPON_RX_GENERAL_CONFIG_RCVR_STATUS_RESERVED1_FIELD,
};

#endif /* RU_INCLUDE_FIELD_DB */

const ru_reg_rec GPON_RX_GENERAL_CONFIG_RCVR_STATUS_REG = 
{
    "RCVR_STATUS",
#if RU_INCLUDE_DESC
    "RECEIVER_STATUS Register",
    "This registers shows the status of different receiver sub-units",
#endif
    GPON_RX_GENERAL_CONFIG_RCVR_STATUS_REG_OFFSET,
    0,
    0,
    87,
#if RU_INCLUDE_ACCESS
    ru_access_read,
#endif
#if RU_INCLUDE_FIELD_DB
    6,
    GPON_RX_GENERAL_CONFIG_RCVR_STATUS_FIELDS,
#endif /* RU_INCLUDE_FIELD_DB */
    ru_reg_size_32
};

/******************************************************************************
 * Register: GPON_RX_GENERAL_CONFIG_RCVR_CONFIG
 ******************************************************************************/
#if RU_INCLUDE_FIELD_DB
static const ru_field_rec *GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_FIELDS[] =
{
    &GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_DES_DISABLE_FIELD,
    &GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_FEC_DISABLE_FIELD,
    &GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_RX_DISABLE_FIELD,
    &GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_LOOPBACK_ENABLE_FIELD,
    &GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_FEC_FORCE_FIELD,
    &GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_FEC_ST_DISC_FIELD,
    &GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_SQUELCH_DIS_FIELD,
    &GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_SOP_RESET_FIELD,
    &GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_DIN_POLARITY_FIELD,
    &GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_RESERVED0_FIELD,
};

#endif /* RU_INCLUDE_FIELD_DB */

const ru_reg_rec GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_REG = 
{
    "RCVR_CONFIG",
#if RU_INCLUDE_DESC
    "RECEIVER_GENERAL_CONFIGURATION Register",
    "This register controls several general parameters of the receiver:"
    "* Descrambler override"
    "* Receiver enable/disable"
    "* Loopback enable/disable",
#endif
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_REG_OFFSET,
    0,
    0,
    88,
#if RU_INCLUDE_ACCESS
    ru_access_rw,
#endif
#if RU_INCLUDE_FIELD_DB
    10,
    GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_FIELDS,
#endif /* RU_INCLUDE_FIELD_DB */
    ru_reg_size_32
};

/******************************************************************************
 * Register: GPON_RX_GENERAL_CONFIG_LOF_PARAMS
 ******************************************************************************/
#if RU_INCLUDE_FIELD_DB
static const ru_field_rec *GPON_RX_GENERAL_CONFIG_LOF_PARAMS_FIELDS[] =
{
    &GPON_RX_GENERAL_CONFIG_LOF_PARAMS_DELTA_FIELD,
    &GPON_RX_GENERAL_CONFIG_LOF_PARAMS_ALPHA_FIELD,
    &GPON_RX_GENERAL_CONFIG_LOF_PARAMS_RESERVED0_FIELD,
};

#endif /* RU_INCLUDE_FIELD_DB */

const ru_reg_rec GPON_RX_GENERAL_CONFIG_LOF_PARAMS_REG = 
{
    "LOF_PARAMS",
#if RU_INCLUDE_DESC
    "LOSS_OF_FRAME_PARAMETERS Register",
    "This registers controls the Alpha and Delta values which indicate the number of correct/incorrect framing patterns required for assertion/de-assertion of the LOF alarm",
#endif
    GPON_RX_GENERAL_CONFIG_LOF_PARAMS_REG_OFFSET,
    0,
    0,
    89,
#if RU_INCLUDE_ACCESS
    ru_access_rw,
#endif
#if RU_INCLUDE_FIELD_DB
    3,
    GPON_RX_GENERAL_CONFIG_LOF_PARAMS_FIELDS,
#endif /* RU_INCLUDE_FIELD_DB */
    ru_reg_size_32
};

/******************************************************************************
 * Register: GPON_RX_GENERAL_CONFIG_RANDOMSD
 ******************************************************************************/
#if RU_INCLUDE_FIELD_DB
static const ru_field_rec *GPON_RX_GENERAL_CONFIG_RANDOMSD_FIELDS[] =
{
    &GPON_RX_GENERAL_CONFIG_RANDOMSD_RANDOMSD_FIELD,
};

#endif /* RU_INCLUDE_FIELD_DB */

const ru_reg_rec GPON_RX_GENERAL_CONFIG_RANDOMSD_REG = 
{
    "RANDOMSD",
#if RU_INCLUDE_DESC
    "RANDOM_SEED Register",
    "This register contains a random 32 bit number which changes constantly",
#endif
    GPON_RX_GENERAL_CONFIG_RANDOMSD_REG_OFFSET,
    0,
    0,
    90,
#if RU_INCLUDE_ACCESS
    ru_access_read,
#endif
#if RU_INCLUDE_FIELD_DB
    1,
    GPON_RX_GENERAL_CONFIG_RANDOMSD_FIELDS,
#endif /* RU_INCLUDE_FIELD_DB */
    ru_reg_size_32
};

/******************************************************************************
 * Block: GPON_RX_GENERAL_CONFIG
 ******************************************************************************/
static const ru_reg_rec *GPON_RX_GENERAL_CONFIG_REGS[] =
{
    &GPON_RX_GENERAL_CONFIG_RCVR_STATUS_REG,
    &GPON_RX_GENERAL_CONFIG_RCVR_CONFIG_REG,
    &GPON_RX_GENERAL_CONFIG_LOF_PARAMS_REG,
    &GPON_RX_GENERAL_CONFIG_RANDOMSD_REG,
};

unsigned long GPON_RX_GENERAL_CONFIG_ADDRS[] =
{
#ifndef CONFIG_BCM96858
    0x130f9000,
#else
    0x80150000,
#endif
};

const ru_block_rec GPON_RX_GENERAL_CONFIG_BLOCK = 
{
    "GPON_RX_GENERAL_CONFIG",
    GPON_RX_GENERAL_CONFIG_ADDRS,
    1,
    4,
    GPON_RX_GENERAL_CONFIG_REGS
};

/* End of file BCM6858_A0GPON_RX_GENERAL_CONFIG.c */
