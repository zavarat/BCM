/*  *********************************************************************
    *
    <:copyright-BRCM:2012:proprietary:standard
    
       Copyright (c) 2012 Broadcom 
       All Rights Reserved
    
     This program is the proprietary software of Broadcom and/or its
     licensors, and may only be used, duplicated, modified or distributed pursuant
     to the terms and conditions of a separate, written license agreement executed
     between you and Broadcom (an "Authorized License").  Except as set forth in
     an Authorized License, Broadcom grants no license (express or implied), right
     to use, or waiver of any kind with respect to the Software, and Broadcom
     expressly reserves all rights in and to the Software and all intellectual
     property rights therein.  IF YOU HAVE NO AUTHORIZED LICENSE, THEN YOU HAVE
     NO RIGHT TO USE THIS SOFTWARE IN ANY WAY, AND SHOULD IMMEDIATELY NOTIFY
     BROADCOM AND DISCONTINUE ALL USE OF THE SOFTWARE.
    
     Except as expressly set forth in the Authorized License,
    
     1. This program, including its structure, sequence and organization,
        constitutes the valuable trade secrets of Broadcom, and you shall use
        all reasonable efforts to protect the confidentiality thereof, and to
        use this information only in connection with your use of Broadcom
        integrated circuit products.
    
     2. TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
        AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES, REPRESENTATIONS OR
        WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH
        RESPECT TO THE SOFTWARE.  BROADCOM SPECIFICALLY DISCLAIMS ANY AND
        ALL IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY, NONINFRINGEMENT,
        FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES, ACCURACY OR
        COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR CORRESPONDENCE
        TO DESCRIPTION. YOU ASSUME THE ENTIRE RISK ARISING OUT OF USE OR
        PERFORMANCE OF THE SOFTWARE.
    
     3. TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL BROADCOM OR
        ITS LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL, INCIDENTAL, SPECIAL,
        INDIRECT, OR EXEMPLARY DAMAGES WHATSOEVER ARISING OUT OF OR IN ANY
        WAY RELATING TO YOUR USE OF OR INABILITY TO USE THE SOFTWARE EVEN
        IF BROADCOM HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES;
        OR (ii) ANY AMOUNT IN EXCESS OF THE AMOUNT ACTUALLY PAID FOR THE
        SOFTWARE ITSELF OR U.S. $1, WHICHEVER IS GREATER. THESE LIMITATIONS
        SHALL APPLY NOTWITHSTANDING ANY FAILURE OF ESSENTIAL PURPOSE OF ANY
        LIMITED REMEDY.
    :> 
    ********************************************************************* */

#include "lib_types.h"
#include "bcm63xx_impl2_ddr_cinit.h"
#include "boardparms.h"

#if defined(_BCM94908_)
#include "mcb/mcb_4908A_533MHz_16b_dev8Gx16_DDR3-1066G.h"
#include "mcb/mcb_4908A_533MHz_32b_dev1Gx16_DDR3-1066G_ssc_1per.h"
#include "mcb/mcb_4908A_533MHz_16b_dev2Gx16_DDR3-1066G_ssc_1per.h"
#include "mcb/mcb_4908A_533MHz_32b_dev2Gx16_DDR3-1066G_ssc_1per.h"
#include "mcb/mcb_4908A_533MHz_16b_dev4Gx16_DDR3-1066G_ssc_1per.h"
#include "mcb/mcb_4908A_533MHz_32b_dev4Gx16_DDR3-1066G_ssc_1per.h"
#include "mcb/mcb_4908A_533MHz_16b_dev8Gx16_DDR3-1066G_ssc_1per.h"
#include "mcb/mcb_4908A_533MHz_32b_dev8Gx16_DDR3-1066G_ssc_1per.h"
#include "mcb/mcb_4908A_800MHz_32b_dev1Gx16_DDR3-1600K_ssc_1per.h"
#include "mcb/mcb_4908A_800MHz_16b_dev2Gx16_DDR3-1600K_ssc_1per.h"
#include "mcb/mcb_4908A_800MHz_32b_dev2Gx16_DDR3-1600K_ssc_1per.h"
#include "mcb/mcb_4908A_800MHz_16b_dev4Gx16_DDR3-1600K_ssc_1per.h"
#include "mcb/mcb_4908A_800MHz_32b_dev4Gx16_DDR3-1600K_ssc_1per.h"
#include "mcb/mcb_4908A_800MHz_16b_dev8Gx16_DDR3-1600K_ssc_1per.h"
#include "mcb/mcb_4908A_800MHz_32b_dev8Gx16_DDR3-1600K_ssc_1per.h"
#include "mcb/mcb_4908A_800MHz_32b_dev4Gx16_DDR3-1600K_ssc_1per_HT_SRT.h"
#include "mcb/mcb_4908A_800MHz_32b_dev4Gx16_DDR3-1600K_ssc_1per_HT_ASR.h"
#elif defined(_BCM96858_)
#include "mcb/mcb_6858A_800MHz_16b_dev8Gx16_DDR3-1600K.h"
#include "mcb/mcb_6858A_1067MHz_16b_dev2Gx16_DDR3-2133N.h"
#include "mcb/mcb_6858A_1067MHz_16b_dev8Gx16_DDR3-2133N.h"
#include "mcb/mcb_6858A_1067MHz_16b_dev4Gx16_DDR3-2133N.h"
#include "mcb/mcb_6858A_1067MHz_32b_dev2Gx16_DDR3-2133N.h"
#include "mcb/mcb_6858A_1067MHz_32b_dev8Gx16_DDR3-2133N.h"
#include "mcb/mcb_6858A_1067MHz_32b_dev4Gx16_DDR3-2133N.h"
/* Please include mcb .h files needed
#include "mcb/mcb_6858A_1067MHz_16b_dev2Gx16_DDR3-2133N_SRT.h"
#include "mcb/mcb_6858A_1067MHz_16b_dev8Gx16_DDR3-2133N_SRT.h"
#include "mcb/mcb_6858A_1067MHz_16b_dev4Gx16_DDR3-2133N_SRT.h"
#include "mcb/mcb_6858A_1067MHz_32b_dev2Gx16_DDR3-2133N_SRT.h"
#include "mcb/mcb_6858A_1067MHz_32b_dev8Gx16_DDR3-2133N_SRT.h"
#include "mcb/mcb_6858A_1067MHz_32b_dev4Gx16_DDR3-2133N_SRT.h"
#include "mcb/mcb_6858A_1067MHz_16b_dev2Gx16_DDR3-2133N_ASR.h"
#include "mcb/mcb_6858A_1067MHz_16b_dev8Gx16_DDR3-2133N_ASR.h"
#include "mcb/mcb_6858A_1067MHz_16b_dev4Gx16_DDR3-2133N_ASR.h"
#include "mcb/mcb_6858A_1067MHz_32b_dev2Gx16_DDR3-2133N_ASR.h"
#include "mcb/mcb_6858A_1067MHz_32b_dev8Gx16_DDR3-2133N_ASR.h"
#include "mcb/mcb_6858A_1067MHz_32b_dev4Gx16_DDR3-2133N_ASR.h"
#include "mcb/mcb_6858A_1000MHz_16b_dev2Gx16_DDR3-2133N.h"
#include "mcb/mcb_6858A_1000MHz_16b_dev4Gx16_DDR3-2133N.h"
#include "mcb/mcb_6858A_1000MHz_16b_dev8Gx16_DDR3-2133N.h"
#include "mcb/mcb_6858A_1000MHz_32b_dev2Gx16_DDR3-2133N.h"
#include "mcb/mcb_6858A_1000MHz_32b_dev8Gx16_DDR3-2133N.h"
#include "mcb/mcb_6858A_1000MHz_32b_dev4Gx16_DDR3-2133N.h"
#include "mcb/mcb_6858A_1000MHz_16b_dev2Gx16_DDR3-2133N_SRT.h"
#include "mcb/mcb_6858A_1000MHz_16b_dev4Gx16_DDR3-2133N_SRT.h"
#include "mcb/mcb_6858A_1000MHz_16b_dev8Gx16_DDR3-2133N_SRT.h"
#include "mcb/mcb_6858A_1000MHz_32b_dev2Gx16_DDR3-2133N_SRT.h"
#include "mcb/mcb_6858A_1000MHz_32b_dev8Gx16_DDR3-2133N_SRT.h"
#include "mcb/mcb_6858A_1000MHz_32b_dev4Gx16_DDR3-2133N_SRT.h"
#include "mcb/mcb_6858A_1000MHz_16b_dev2Gx16_DDR3-2133N_ASR.h"
#include "mcb/mcb_6858A_1000MHz_16b_dev4Gx16_DDR3-2133N_ASR.h"
#include "mcb/mcb_6858A_1000MHz_16b_dev8Gx16_DDR3-2133N_ASR.h"
#include "mcb/mcb_6858A_1000MHz_32b_dev2Gx16_DDR3-2133N_ASR.h"
#include "mcb/mcb_6858A_1000MHz_32b_dev8Gx16_DDR3-2133N_ASR.h"
#include "mcb/mcb_6858A_1000MHz_32b_dev4Gx16_DDR3-2133N_ASR.h"
#include "mcb/mcb_6858A_800MHz_16b_dev2Gx16_DDR3-1600K.h"
#include "mcb/mcb_6858A_800MHz_16b_dev4Gx16_DDR3-1600K.h"
#include "mcb/mcb_6858A_800MHz_32b_dev4Gx16_DDR3-1600K.h"
#include "mcb/mcb_6858A_800MHz_32b_dev2Gx16_DDR3-1600K.h"
#include "mcb/mcb_6858A_800MHz_32b_dev8Gx16_DDR3-1600K.h"
#include "mcb/mcb_6858A_800MHz_16b_dev2Gx16_DDR3-1600K_SRT.h"
#include "mcb/mcb_6858A_800MHz_16b_dev4Gx16_DDR3-1600K_SRT.h"
#include "mcb/mcb_6858A_800MHz_16b_dev8Gx16_DDR3-1600K_SRT.h"
#include "mcb/mcb_6858A_800MHz_32b_dev4Gx16_DDR3-1600K_SRT.h"
#include "mcb/mcb_6858A_800MHz_32b_dev2Gx16_DDR3-1600K_SRT.h"
#include "mcb/mcb_6858A_800MHz_32b_dev8Gx16_DDR3-1600K_SRT.h"
#include "mcb/mcb_6858A_800MHz_16b_dev2Gx16_DDR3-1600K_ASR.h"
#include "mcb/mcb_6858A_800MHz_16b_dev4Gx16_DDR3-1600K_ASR.h"
#include "mcb/mcb_6858A_800MHz_16b_dev8Gx16_DDR3-1600K_ASR.h"
#include "mcb/mcb_6858A_800MHz_32b_dev4Gx16_DDR3-1600K_ASR.h"
#include "mcb/mcb_6858A_800MHz_32b_dev2Gx16_DDR3-1600K_ASR.h"
#include "mcb/mcb_6858A_800MHz_32b_dev8Gx16_DDR3-1600K_ASR.h"
#include "mcb/mcb_6858A_933MHz_16b_dev8Gx16_DDR3-1866M.h"
#include "mcb/mcb_6858A_933MHz_16b_dev4Gx16_DDR3-1866M.h"
#include "mcb/mcb_6858A_933MHz_16b_dev2Gx16_DDR3-1866M.h"
#include "mcb/mcb_6858A_933MHz_32b_dev2Gx16_DDR3-1866M.h"
#include "mcb/mcb_6858A_933MHz_32b_dev8Gx16_DDR3-1866M.h"
#include "mcb/mcb_6858A_933MHz_32b_dev4Gx16_DDR3-1866M.h"
#include "mcb/mcb_6858A_933MHz_16b_dev8Gx16_DDR3-1866M_SRT.h"
#include "mcb/mcb_6858A_933MHz_16b_dev4Gx16_DDR3-1866M_SRT.h"
#include "mcb/mcb_6858A_933MHz_16b_dev2Gx16_DDR3-1866M_SRT.h"
#include "mcb/mcb_6858A_933MHz_32b_dev2Gx16_DDR3-1866M_SRT.h"
#include "mcb/mcb_6858A_933MHz_32b_dev8Gx16_DDR3-1866M_SRT.h"
#include "mcb/mcb_6858A_933MHz_32b_dev4Gx16_DDR3-1866M_SRT.h"
#include "mcb/mcb_6858A_933MHz_16b_dev8Gx16_DDR3-1866M_ASR.h"
#include "mcb/mcb_6858A_933MHz_16b_dev4Gx16_DDR3-1866M_ASR.h"
#include "mcb/mcb_6858A_933MHz_16b_dev2Gx16_DDR3-1866M_ASR.h"
#include "mcb/mcb_6858A_933MHz_32b_dev2Gx16_DDR3-1866M_ASR.h"
#include "mcb/mcb_6858A_933MHz_32b_dev8Gx16_DDR3-1866M_ASR.h"
#include "mcb/mcb_6858A_933MHz_32b_dev4Gx16_DDR3-1866M_ASR.h"
*/
#elif defined(_BCM96836_)
#include "mcb/mcb_6836A_800MHz_16b_dev1Gx16_DDR3-1600K.h"
#include "mcb/mcb_6836A_533MHz_16b_dev1Gx16_DDR3-1066G.h"
#include "mcb/mcb_6836A_800MHz_16b_dev2Gx16_DDR3-1600K.h"
#include "mcb/mcb_6836A_533MHz_16b_dev2Gx16_DDR3-1066G.h"
#include "mcb/mcb_6836A_800MHz_16b_dev4Gx16_DDR3-1600K.h"
#include "mcb/mcb_6836A_533MHz_16b_dev4Gx16_DDR3-1066G.h"
#include "mcb/mcb_6836A_800MHz_16b_dev8Gx16_DDR3-1600K.h"
#include "mcb/mcb_6836A_533MHz_16b_dev8Gx16_DDR3-1066G.h"
#elif defined(_BCM963158_)
#include "mcb/mcb_63158A_533MHz_16b_dev8Gx16_DDR3-1066G.h"
#include "mcb/mcb_63158A_800MHz_16b_dev4Gx16_DDR3-1600K_ssc_1per.h"
#include "mcb/mcb_63158A_800MHz_16b_dev8Gx16_DDR3-1600K_ssc_1per.h"
#include "mcb/mcb_63158A_800MHz_32b_dev2Gx16_DDR3-1600K_ssc_1per.h"
#include "mcb/mcb_63158A_800MHz_32b_dev4Gx8_DDR3-1600K_ssc_1per.h"
#include "mcb/mcb_63158A_800MHz_32b_dev4Gx16_DDR3-1600K_ssc_1per.h"
#include "mcb/mcb_63158A_800MHz_32b_dev8Gx8_DDR3-1600K_ssc_1per.h"
#include "mcb/mcb_63158A_800MHz_32b_dev8Gx16_DDR3-1600K_ssc_1per.h"
#include "mcb/mcb_63158A_933MHz_16b_dev4Gx16_DDR3-1866M_ssc_1per.h"
#include "mcb/mcb_63158A_933MHz_16b_dev8Gx16_DDR3-1866M_ssc_1per.h"
#include "mcb/mcb_63158A_933MHz_32b_dev2Gx16_DDR3-1866M_ssc_1per.h"
#include "mcb/mcb_63158A_933MHz_32b_dev4Gx8_DDR3-1866M_ssc_1per.h"
#include "mcb/mcb_63158A_933MHz_32b_dev4Gx16_DDR3-1866M_ssc_1per.h"
#include "mcb/mcb_63158A_933MHz_32b_dev8Gx8_DDR3-1866M_ssc_1per.h"
#include "mcb/mcb_63158A_933MHz_32b_dev8Gx16_DDR3-1866M_ssc_1per.h"
#include "mcb/mcb_63158A_1067MHz_16b_dev4Gx16_DDR3-2133N_ssc_1per.h"
#include "mcb/mcb_63158A_1067MHz_16b_dev8Gx16_DDR3-2133N_ssc_1per.h"
#include "mcb/mcb_63158A_1067MHz_32b_dev2Gx16_DDR3-2133N_ssc_1per.h"
#include "mcb/mcb_63158A_1067MHz_32b_dev4Gx8_DDR3-2133N_ssc_1per.h"
#include "mcb/mcb_63158A_1067MHz_32b_dev4Gx16_DDR3-2133N_ssc_1per.h"
#include "mcb/mcb_63158A_1067MHz_32b_dev8Gx8_DDR3-2133N_ssc_1per.h"
#include "mcb/mcb_63158A_1067MHz_32b_dev8Gx16_DDR3-2133N_ssc_1per.h"
#include "mcb/mcb_63158A_1067MHz_32b_dev4Gx16_DDR3-2133N_ssc_1per_HT_SRT.h"
#include "mcb/mcb_63158A_1067MHz_32b_dev4Gx16_DDR3-2133N_ssc_1per_HT_ASR.h"
#elif defined(_BCM96846_)
#include "mcb/mcb_6846A_800MHz_16b_dev8Gx16_DDR3-1600K.h"
#include "mcb/mcb_6846A_800MHz_16b_dev4Gx16_DDR3-1600K.h"
#include "mcb/mcb_6846A_800MHz_16b_dev2Gx16_DDR3-1600K.h"
#elif defined(_BCM96856_)
#include "mcb/mcb_6856A_800MHz_16b_dev2Gx16_DDR3-1600K.h"
#include "mcb/mcb_6856A_800MHz_16b_dev4Gx16_DDR3-1600K.h"
#include "mcb/mcb_6856A_800MHz_16b_dev8Gx16_DDR3-1600K.h"
#include "mcb/mcb_6856A_1067MHz_16b_dev2Gx16_DDR3-2133N.h"
#include "mcb/mcb_6856A_1067MHz_16b_dev4Gx16_DDR3-2133N.h"
#include "mcb/mcb_6856A_1067MHz_16b_dev8Gx16_DDR3-2133N.h"
#include "mcb/mcb_6856A_800MHz_32b_dev2Gx16_DDR3-1600K.h"
#include "mcb/mcb_6856A_800MHz_32b_dev4Gx16_DDR3-1600K.h"
#include "mcb/mcb_6856A_1067MHz_32b_dev2Gx16_DDR3-2133N.h"
#include "mcb/mcb_6856A_1067MHz_32b_dev4Gx16_DDR3-2133N.h"
#endif

/* define an array of supported MCBs. The first one must be the safe mode MCB. */
mcbindex MCB[]  = {
#if defined(_BCM94908_)
    /* safe mode MCB, use largest supported size  */
    { 
        BP_DDR_SPEED_533_8_8_8 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK,
        mcb_4908A_533MHz_16b_dev8Gx16_DDR3_1066G
    },
    { 
        BP_DDR_SPEED_533_8_8_8 | BP_DDR_TOTAL_SIZE_256MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_4908A_533MHz_16b_dev2Gx16_DDR3_1066G_ssc_1per
    },
    { 
        BP_DDR_SPEED_533_8_8_8 | BP_DDR_TOTAL_SIZE_256MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_4908A_533MHz_32b_dev1Gx16_DDR3_1066G_ssc_1per
    },
    { 
        BP_DDR_SPEED_533_8_8_8 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_4908A_533MHz_16b_dev4Gx16_DDR3_1066G_ssc_1per
    },
    { 
        BP_DDR_SPEED_533_8_8_8 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_4908A_533MHz_32b_dev2Gx16_DDR3_1066G_ssc_1per
    },
    { 
        BP_DDR_SPEED_533_8_8_8 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_4908A_533MHz_16b_dev8Gx16_DDR3_1066G_ssc_1per
    },
    { 
        BP_DDR_SPEED_533_8_8_8 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_4908A_533MHz_32b_dev4Gx16_DDR3_1066G_ssc_1per
    },
    { 
        BP_DDR_SPEED_533_8_8_8 | BP_DDR_TOTAL_SIZE_2048MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_4908A_533MHz_32b_dev8Gx16_DDR3_1066G_ssc_1per
    },
    { 
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_256MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_4908A_800MHz_32b_dev1Gx16_DDR3_1600K_ssc_1per
    },
    { 
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_256MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_4908A_800MHz_16b_dev2Gx16_DDR3_1600K_ssc_1per
    },
    { 
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_4908A_800MHz_16b_dev4Gx16_DDR3_1600K_ssc_1per
    },
    { 
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_4908A_800MHz_32b_dev2Gx16_DDR3_1600K_ssc_1per
    },
    { 
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_4908A_800MHz_16b_dev8Gx16_DDR3_1600K_ssc_1per
    },
    { 
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_4908A_800MHz_32b_dev4Gx16_DDR3_1600K_ssc_1per
    },
    { 
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1 | BP_DDR_TEMP_EXTENDED_SRT,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK | BP_DDR_TEMP_MASK,
        mcb_4908A_800MHz_32b_dev4Gx16_DDR3_1600K_ssc_1per_HT_SRT
    },
    { 
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1 | BP_DDR_TEMP_EXTENDED_ASR,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK | BP_DDR_TEMP_MASK,
        mcb_4908A_800MHz_32b_dev4Gx16_DDR3_1600K_ssc_1per_HT_ASR
    },
    { 
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_2048MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_4908A_800MHz_32b_dev8Gx16_DDR3_1600K_ssc_1per
    },
#elif defined(_BCM96858_)
    // 1067MHz
    {
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK,
        mcb_6858A_800MHz_16b_dev8Gx16_DDR3_1600K
    },
    {
        BP_DDR_SPEED_1067_14_14_14 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK,
        mcb_6858A_1067MHz_16b_dev8Gx16_DDR3_2133N
    },
    {
        BP_DDR_SPEED_1067_14_14_14 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK,
        mcb_6858A_1067MHz_16b_dev4Gx16_DDR3_2133N
    },
    {
        BP_DDR_SPEED_1067_14_14_14 | BP_DDR_TOTAL_SIZE_256MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK,
        mcb_6858A_1067MHz_16b_dev2Gx16_DDR3_2133N
    },
    {
        BP_DDR_SPEED_1067_14_14_14 | BP_DDR_TOTAL_SIZE_2048MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK,
        mcb_6858A_1067MHz_32b_dev8Gx16_DDR3_2133N
    },
    {
        BP_DDR_SPEED_1067_14_14_14 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK,
        mcb_6858A_1067MHz_32b_dev4Gx16_DDR3_2133N
    },
    {
        BP_DDR_SPEED_1067_14_14_14 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK,
        mcb_6858A_1067MHz_32b_dev2Gx16_DDR3_2133N
    },
#elif defined(_BCM96836_)
    {
        BP_DDR_SPEED_533_8_8_8 | BP_DDR_TOTAL_SIZE_128MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK,
        mcb_6836A_533MHz_16b_dev1Gx16_DDR3_1066G
    },
    {
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_128MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK,
        mcb_6836A_800MHz_16b_dev1Gx16_DDR3_1600K
    },
    {
        BP_DDR_SPEED_533_8_8_8 | BP_DDR_TOTAL_SIZE_256MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK,
        mcb_6836A_533MHz_16b_dev2Gx16_DDR3_1066G
    },
    {
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_256MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK,
        mcb_6836A_800MHz_16b_dev2Gx16_DDR3_1600K
    },
    {
        BP_DDR_SPEED_533_8_8_8 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK,
        mcb_6836A_533MHz_16b_dev8Gx16_DDR3_1066G
    },
    {
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK,
        mcb_6836A_800MHz_16b_dev8Gx16_DDR3_1600K
    },
    {
        BP_DDR_SPEED_533_8_8_8 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK,
        mcb_6836A_533MHz_16b_dev4Gx16_DDR3_1066G
    },
    {
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK,
        mcb_6836A_800MHz_16b_dev4Gx16_DDR3_1600K
    },
#elif defined(_BCM963158_)
    {
        BP_DDR_SPEED_533_8_8_8 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK,
        mcb_63158A_533MHz_16b_dev8Gx16_DDR3_1066G
    },
    { 
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_63158A_800MHz_32b_dev2Gx16_DDR3_1600K_ssc_1per
    },
    { 
        BP_DDR_SPEED_1067_14_14_14 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_63158A_1067MHz_32b_dev2Gx16_DDR3_2133N_ssc_1per
    },
    { 
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_63158A_800MHz_16b_dev4Gx16_DDR3_1600K_ssc_1per
    },
    { 
        BP_DDR_SPEED_1067_14_14_14 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_63158A_1067MHz_16b_dev4Gx16_DDR3_2133N_ssc_1per
    },
    { 
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_63158A_800MHz_32b_dev4Gx16_DDR3_1600K_ssc_1per
    },
    { 
        BP_DDR_SPEED_933_13_13_13 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_63158A_933MHz_32b_dev4Gx16_DDR3_1866M_ssc_1per
    },
    { 
        BP_DDR_SPEED_1067_14_14_14 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_63158A_1067MHz_32b_dev4Gx16_DDR3_2133N_ssc_1per
    },
    { 
        BP_DDR_SPEED_1067_14_14_14 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1 | BP_DDR_TEMP_EXTENDED_SRT,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK | BP_DDR_TEMP_MASK,
        mcb_63158A_1067MHz_32b_dev4Gx16_DDR3_2133N_ssc_1per_HT_SRT
    },
    { 
        BP_DDR_SPEED_1067_14_14_14 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1 | BP_DDR_TEMP_EXTENDED_ASR,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK | BP_DDR_TEMP_MASK,
        mcb_63158A_1067MHz_32b_dev4Gx16_DDR3_2133N_ssc_1per_HT_ASR
    },
    { 
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_63158A_800MHz_16b_dev8Gx16_DDR3_1600K_ssc_1per
    },
    { 
        BP_DDR_SPEED_1067_14_14_14 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_63158A_1067MHz_16b_dev8Gx16_DDR3_2133N_ssc_1per
    },
    { 
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_2048MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_63158A_800MHz_32b_dev8Gx16_DDR3_1600K_ssc_1per
    },
    { 
        BP_DDR_SPEED_1067_14_14_14 | BP_DDR_TOTAL_SIZE_2048MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_63158A_1067MHz_32b_dev8Gx16_DDR3_2133N_ssc_1per
    },
    { 
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_2048MB| BP_DDR_DEVICE_WIDTH_8 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_63158A_800MHz_32b_dev4Gx8_DDR3_1600K_ssc_1per
    },
    { 
        BP_DDR_SPEED_933_13_13_13 | BP_DDR_TOTAL_SIZE_2048MB| BP_DDR_DEVICE_WIDTH_8 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_63158A_933MHz_32b_dev4Gx8_DDR3_1866M_ssc_1per
    },
    { 
        BP_DDR_SPEED_1067_14_14_14 | BP_DDR_TOTAL_SIZE_2048MB| BP_DDR_DEVICE_WIDTH_8 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_63158A_1067MHz_32b_dev4Gx8_DDR3_2133N_ssc_1per
    },
    { 
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_4096MB| BP_DDR_DEVICE_WIDTH_8 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_63158A_800MHz_32b_dev8Gx8_DDR3_1600K_ssc_1per
    },
    { 
        BP_DDR_SPEED_1067_14_14_14 | BP_DDR_TOTAL_SIZE_4096MB| BP_DDR_DEVICE_WIDTH_8 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_63158A_1067MHz_32b_dev8Gx8_DDR3_2133N_ssc_1per
    },
#elif defined(_BCM96846_)
    {
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK,
        mcb_6846A_800MHz_16b_dev8Gx16_DDR3_1600K
    },
    {
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK,
        mcb_6846A_800MHz_16b_dev4Gx16_DDR3_1600K
    },
    {
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_256MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK,
        mcb_6846A_800MHz_16b_dev2Gx16_DDR3_1600K
    },
#elif defined(_BCM96856_)
    {
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_6856A_800MHz_16b_dev8Gx16_DDR3_1600K
    },
    {
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_6856A_800MHz_16b_dev4Gx16_DDR3_1600K
    },
    {
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_256MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_6856A_800MHz_16b_dev2Gx16_DDR3_1600K
    },
    {
        BP_DDR_SPEED_1067_14_14_14 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_6856A_1067MHz_16b_dev8Gx16_DDR3_2133N
    },
    {
        BP_DDR_SPEED_1067_14_14_14 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_6856A_1067MHz_16b_dev4Gx16_DDR3_2133N
    },
    {
        BP_DDR_SPEED_1067_14_14_14 | BP_DDR_TOTAL_SIZE_256MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_16BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_6856A_1067MHz_16b_dev2Gx16_DDR3_2133N
    },
    {
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_6856A_800MHz_32b_dev4Gx16_DDR3_1600K
    },
    {
        BP_DDR_SPEED_800_11_11_11 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_6856A_800MHz_32b_dev2Gx16_DDR3_1600K
    },
    {
        BP_DDR_SPEED_1067_14_14_14 | BP_DDR_TOTAL_SIZE_1024MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_6856A_1067MHz_32b_dev4Gx16_DDR3_2133N
    },
    {
        BP_DDR_SPEED_1067_14_14_14 | BP_DDR_TOTAL_SIZE_512MB| BP_DDR_DEVICE_WIDTH_16 | BP_DDR_TOTAL_WIDTH_32BIT | BP_DDR_SSC_CONFIG_1,
        BP_DDR_SPEED_MASK | BP_DDR_TOTAL_SIZE_MASK | BP_DDR_DEVICE_WIDTH_MASK | BP_DDR_TOTAL_WIDTH_MASK | BP_DDR_SSC_CONFIG_MASK,
        mcb_6856A_1067MHz_32b_dev2Gx16_DDR3_2133N
    },
#endif
    {
        0,0,NULL
    }
};

