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

#ifndef _GPON_COMMON_AG_H_
#define _GPON_COMMON_AG_H_


#if defined(_CFE_)
#include "lib_printf.h"
#define pr_err xprintf
#define pr_info xprintf
#else
#include <linux/printk.h>
#endif
#include "bcmtypes.h"
#include "ru.h"
#include "GPON_BLOCKS.h"


#define _1BITS_MAX_VAL_ (1U<<1)
#define _2BITS_MAX_VAL_ (1U<<2)
#define _3BITS_MAX_VAL_ (1U<<3)
#define _4BITS_MAX_VAL_ (1U<<4)
#define _5BITS_MAX_VAL_ (1U<<5)
#define _6BITS_MAX_VAL_ (1U<<6)
#define _7BITS_MAX_VAL_ (1U<<7)
#define _9BITS_MAX_VAL_ (1U<<9)
#define _10BITS_MAX_VAL_ (1U<<10)
#define _11BITS_MAX_VAL_ (1U<<11)
#define _12BITS_MAX_VAL_ (1U<<12)
#define _13BITS_MAX_VAL_ (1U<<13)
#define _14BITS_MAX_VAL_ (1U<<14)
#define _15BITS_MAX_VAL_ (1U<<15)
#define _17BITS_MAX_VAL_ (1U<<17)
#define _18BITS_MAX_VAL_ (1U<<18)
#define _19BITS_MAX_VAL_ (1U<<19)
#define _20BITS_MAX_VAL_ (1U<<20)
#define _21BITS_MAX_VAL_ (1U<<21)
#define _22BITS_MAX_VAL_ (1U<<22)
#define _23BITS_MAX_VAL_ (1U<<23)
#define _24BITS_MAX_VAL_ (1U<<24)
#define _25BITS_MAX_VAL_ (1U<<25)
#define _26BITS_MAX_VAL_ (1U<<26)
#define _27BITS_MAX_VAL_ (1U<<27)
#define _28BITS_MAX_VAL_ (1U<<28)
#define _29BITS_MAX_VAL_ (1U<<29)
#define _30BITS_MAX_VAL_ (1U<<30)
#define _31BITS_MAX_VAL_ (1U<<31)
#define _33BITS_MAX_VAL_ (1lU<<33)
#define _34BITS_MAX_VAL_ (1lU<<34)
#define _35BITS_MAX_VAL_ (1lU<<35)
#define _36BITS_MAX_VAL_ (1lU<<36)
#define _37BITS_MAX_VAL_ (1lU<<37)
#define _38BITS_MAX_VAL_ (1lU<<38)
#define _39BITS_MAX_VAL_ (1lU<<39)
#define _40BITS_MAX_VAL_ (1lU<<40)
#define _41BITS_MAX_VAL_ (1lU<<41)
#define _42BITS_MAX_VAL_ (1lU<<42)
#define _43BITS_MAX_VAL_ (1lU<<43)
#define _44BITS_MAX_VAL_ (1lU<<44)
#define _45BITS_MAX_VAL_ (1lU<<45)
#define _46BITS_MAX_VAL_ (1lU<<46)
#define _47BITS_MAX_VAL_ (1lU<<47)
#define _48BITS_MAX_VAL_ (1lU<<48)
#define _49BITS_MAX_VAL_ (1lU<<49)
#define _50BITS_MAX_VAL_ (1lU<<50)
#define _51BITS_MAX_VAL_ (1lU<<51)
#define _52BITS_MAX_VAL_ (1lU<<52)
#define _53BITS_MAX_VAL_ (1lU<<53)
#define _54BITS_MAX_VAL_ (1lU<<54)
#define _55BITS_MAX_VAL_ (1lU<<55)
#define _56BITS_MAX_VAL_ (1lU<<56)
#define _57BITS_MAX_VAL_ (1lU<<57)
#define _58BITS_MAX_VAL_ (1lU<<58)
#define _59BITS_MAX_VAL_ (1lU<<59)
#define _60BITS_MAX_VAL_ (1lU<<60)
#define _61BITS_MAX_VAL_ (1lU<<61)
#define _62BITS_MAX_VAL_ (1lU<<62)
#define _63BITS_MAX_VAL_ (1lU<<63)


static inline void ag_ru_block_addr_print(int block_idx)
{
	int addr_idx;
	for (addr_idx = 0; addr_idx < RU_GPON_BLOCKS[block_idx]->addr_count; addr_idx++)
	{
		pr_info("block %s[%d] address = 0x%16lx\n", RU_GPON_BLOCKS[block_idx]->name, addr_idx,
			RU_GPON_BLOCKS[block_idx]->addr[addr_idx]);
	}
}

static inline void ag_ru_blocks_data_print(void)
{
	int block_idx;
	for (block_idx = 0; block_idx < RU_BLK_COUNT; block_idx++)
	{
		ag_ru_block_addr_print(block_idx);
	}
}
#endif
