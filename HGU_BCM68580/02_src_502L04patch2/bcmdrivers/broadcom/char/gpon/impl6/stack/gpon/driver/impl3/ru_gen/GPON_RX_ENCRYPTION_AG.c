/*
   Copyright (c) 2015 Broadcom Corporation
   All Rights Reserved

    <:label-BRCM:2015:DUAL/GPL:standard

    Unless you and Broadcom execute a separate written software license
    agreement governing use of this software, this software is licensed
    to you under the terms of the GNU General Public License version 2
    (the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
    with the following added to such license:

       As a special exception, the copyright holders of this software give
       you permission to link this software with independent modules, and
       to copy and distribute the resulting executable under terms of your
       choice, provided that you also meet, for each linked independent
       module, the terms and conditions of the license of that module.
       An independent module is a module which is not derived from this
       software.  The special exception does not apply to any modifications
       of the software.

    Not withstanding the above, under no circumstances may you combine
    this software in any way with any other Broadcom software provided
    under a license other than the GPL, without Broadcom's express prior
    written consent.

:>
*/

#include "ru.h"
#include "GPON_BLOCKS.h"

#if RU_INCLUDE_FIELD_DB
/******************************************************************************
 * Field: GPON_RX_ENCRYPTION_SF_CNTR_SF_CNTR
 ******************************************************************************/
const ru_field_rec GPON_RX_ENCRYPTION_SF_CNTR_SF_CNTR_FIELD =
{
    "SF_CNTR",
#if RU_INCLUDE_DESC
    "Superframe_Counter",
    "Shows the value of the superframe counter",
#endif
    GPON_RX_ENCRYPTION_SF_CNTR_SF_CNTR_FIELD_MASK,
    0,
    GPON_RX_ENCRYPTION_SF_CNTR_SF_CNTR_FIELD_WIDTH,
    GPON_RX_ENCRYPTION_SF_CNTR_SF_CNTR_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_read
#endif
};

/******************************************************************************
 * Field: GPON_RX_ENCRYPTION_SF_CNTR_RESERVED0
 ******************************************************************************/
const ru_field_rec GPON_RX_ENCRYPTION_SF_CNTR_RESERVED0_FIELD =
{
    "RESERVED0",
#if RU_INCLUDE_DESC
    "",
    "",
#endif
    GPON_RX_ENCRYPTION_SF_CNTR_RESERVED0_FIELD_MASK,
    0,
    GPON_RX_ENCRYPTION_SF_CNTR_RESERVED0_FIELD_WIDTH,
    GPON_RX_ENCRYPTION_SF_CNTR_RESERVED0_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_read
#endif
};

/******************************************************************************
 * Field: GPON_RX_ENCRYPTION_KEY_KEY
 ******************************************************************************/
const ru_field_rec GPON_RX_ENCRYPTION_KEY_KEY_FIELD =
{
    "KEY",
#if RU_INCLUDE_DESC
    "Key",
    "Decryption key",
#endif
    GPON_RX_ENCRYPTION_KEY_KEY_FIELD_MASK,
    0,
    GPON_RX_ENCRYPTION_KEY_KEY_FIELD_WIDTH,
    GPON_RX_ENCRYPTION_KEY_KEY_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

/******************************************************************************
 * Field: GPON_RX_ENCRYPTION_SWITCH_TIME_SW_TIME
 ******************************************************************************/
const ru_field_rec GPON_RX_ENCRYPTION_SWITCH_TIME_SW_TIME_FIELD =
{
    "SW_TIME",
#if RU_INCLUDE_DESC
    "Switch_Time",
    "The superframe counter value at which the new key is put to use."
    "This field should not be changed while waiting for key switch (ARM bit is set).",
#endif
    GPON_RX_ENCRYPTION_SWITCH_TIME_SW_TIME_FIELD_MASK,
    0,
    GPON_RX_ENCRYPTION_SWITCH_TIME_SW_TIME_FIELD_WIDTH,
    GPON_RX_ENCRYPTION_SWITCH_TIME_SW_TIME_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

/******************************************************************************
 * Field: GPON_RX_ENCRYPTION_SWITCH_TIME_ARM
 ******************************************************************************/
const ru_field_rec GPON_RX_ENCRYPTION_SWITCH_TIME_ARM_FIELD =
{
    "ARM",
#if RU_INCLUDE_DESC
    "Switch_mechanism_arm",
    "Allows putting the new key to use when the received superframe counter matches the SW_TIME."
    "The mechanism is armed by writing 1 to this bit."
    "After arming, the bit is cleared by hardware right after the new key was put to use. SW can monitor this bit to determine when the switch occurred - after the switch occurred the bit will be cleared to 0."
    "This bit should be set only after the KEY registers were updated and the SWITCH_TIME field is valid.",
#endif
    GPON_RX_ENCRYPTION_SWITCH_TIME_ARM_FIELD_MASK,
    0,
    GPON_RX_ENCRYPTION_SWITCH_TIME_ARM_FIELD_WIDTH,
    GPON_RX_ENCRYPTION_SWITCH_TIME_ARM_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

/******************************************************************************
 * Field: GPON_RX_ENCRYPTION_SWITCH_TIME_RESERVED0
 ******************************************************************************/
const ru_field_rec GPON_RX_ENCRYPTION_SWITCH_TIME_RESERVED0_FIELD =
{
    "RESERVED0",
#if RU_INCLUDE_DESC
    "",
    "",
#endif
    GPON_RX_ENCRYPTION_SWITCH_TIME_RESERVED0_FIELD_MASK,
    0,
    GPON_RX_ENCRYPTION_SWITCH_TIME_RESERVED0_FIELD_WIDTH,
    GPON_RX_ENCRYPTION_SWITCH_TIME_RESERVED0_FIELD_SHIFT,
#if RU_INCLUDE_ACCESS
    ru_access_rw
#endif
};

#endif /* RU_INCLUDE_FIELD_DB */

/******************************************************************************
 * Register: GPON_RX_ENCRYPTION_SF_CNTR
 ******************************************************************************/
#if RU_INCLUDE_FIELD_DB
static const ru_field_rec *GPON_RX_ENCRYPTION_SF_CNTR_FIELDS[] =
{
    &GPON_RX_ENCRYPTION_SF_CNTR_SF_CNTR_FIELD,
    &GPON_RX_ENCRYPTION_SF_CNTR_RESERVED0_FIELD,
};

#endif /* RU_INCLUDE_FIELD_DB */

const ru_reg_rec GPON_RX_ENCRYPTION_SF_CNTR_REG = 
{
    "SF_CNTR",
#if RU_INCLUDE_DESC
    "SUPERFRAME_COUNTER Register",
    "Shows the value of the received superframe counter",
#endif
    GPON_RX_ENCRYPTION_SF_CNTR_REG_OFFSET,
    0,
    0,
    109,
#if RU_INCLUDE_ACCESS
    ru_access_read,
#endif
#if RU_INCLUDE_FIELD_DB
    2,
    GPON_RX_ENCRYPTION_SF_CNTR_FIELDS,
#endif /* RU_INCLUDE_FIELD_DB */
    ru_reg_size_32
};

/******************************************************************************
 * Register: GPON_RX_ENCRYPTION_KEY
 ******************************************************************************/
#if RU_INCLUDE_FIELD_DB
static const ru_field_rec *GPON_RX_ENCRYPTION_KEY_FIELDS[] =
{
    &GPON_RX_ENCRYPTION_KEY_KEY_FIELD,
};

#endif /* RU_INCLUDE_FIELD_DB */

const ru_reg_rec GPON_RX_ENCRYPTION_KEY_REG = 
{
    "KEY",
#if RU_INCLUDE_DESC
    "DECRYPTION_KEY %i Register",
    "Sets the value of the 128 bit decryption key. Array of 4 32 bir registers. Registr 0 in the array sets the MSB, register 3 sets the LSB."
    "These registers should not be changed while waiting for a key-switch (the ARM bit in the SWITCH_TIME register is set).",
#endif
    GPON_RX_ENCRYPTION_KEY_REG_OFFSET,
    GPON_RX_ENCRYPTION_KEY_REG_RAM_CNT,
    4,
    110,
#if RU_INCLUDE_ACCESS
    ru_access_rw,
#endif
#if RU_INCLUDE_FIELD_DB
    1,
    GPON_RX_ENCRYPTION_KEY_FIELDS,
#endif /* RU_INCLUDE_FIELD_DB */
    ru_reg_size_32
};

/******************************************************************************
 * Register: GPON_RX_ENCRYPTION_SWITCH_TIME
 ******************************************************************************/
#if RU_INCLUDE_FIELD_DB
static const ru_field_rec *GPON_RX_ENCRYPTION_SWITCH_TIME_FIELDS[] =
{
    &GPON_RX_ENCRYPTION_SWITCH_TIME_SW_TIME_FIELD,
    &GPON_RX_ENCRYPTION_SWITCH_TIME_ARM_FIELD,
    &GPON_RX_ENCRYPTION_SWITCH_TIME_RESERVED0_FIELD,
};

#endif /* RU_INCLUDE_FIELD_DB */

const ru_reg_rec GPON_RX_ENCRYPTION_SWITCH_TIME_REG = 
{
    "SWITCH_TIME",
#if RU_INCLUDE_DESC
    "KEY_SWITCH_TIME Register",
    "Sets the superframe counter value at which the new key is put to use",
#endif
    GPON_RX_ENCRYPTION_SWITCH_TIME_REG_OFFSET,
    0,
    0,
    111,
#if RU_INCLUDE_ACCESS
    ru_access_rw,
#endif
#if RU_INCLUDE_FIELD_DB
    3,
    GPON_RX_ENCRYPTION_SWITCH_TIME_FIELDS,
#endif /* RU_INCLUDE_FIELD_DB */
    ru_reg_size_32
};

/******************************************************************************
 * Block: GPON_RX_ENCRYPTION
 ******************************************************************************/
static const ru_reg_rec *GPON_RX_ENCRYPTION_REGS[] =
{
    &GPON_RX_ENCRYPTION_SF_CNTR_REG,
    &GPON_RX_ENCRYPTION_KEY_REG,
    &GPON_RX_ENCRYPTION_SWITCH_TIME_REG,
};

unsigned long GPON_RX_ENCRYPTION_ADDRS[] =
{
#if defined(CONFIG_BCM963158)
    0x80150700,
#elif defined(CONFIG_BCM96836) || defined(CONFIG_BCM96846) || defined(CONFIG_BCM96856)
    0x82db1700,
#else
    #error "GPON_RX_ENCRYPTION base address not defined"
#endif
};

const ru_block_rec GPON_RX_ENCRYPTION_BLOCK = 
{
    "GPON_RX_ENCRYPTION",
    GPON_RX_ENCRYPTION_ADDRS,
    1,
    3,
    GPON_RX_ENCRYPTION_REGS
};

/* End of file BCM6836_A0GPON_RX_ENCRYPTION.c */
