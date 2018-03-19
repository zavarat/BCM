/*---------------------------------------------------------------------------

<:copyright-BRCM:2013:proprietary:standard 

   Copyright (c) 2013 Broadcom 
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
 ------------------------------------------------------------------------- */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/ioctl.h>
#include <asm/uaccess.h>
#include <laser.h>
#include <boardparms.h>
#include <board.h>
#include <bcmsfp_i2c.h>
#include <opticaldet.h>


#if defined(CONFIG_BCM_I2C_BUS) || defined(CONFIG_BCM_I2C_BUS_MODULE)
// 6816 limits i2c data blocks to a max of 32 bytes, but requires   
// the first byte to be the offset.
#define MAX_I2C_MSG_SIZE                    32 /* BCM6816 limit */
#else
#define MAX_I2C_MSG_SIZE                    64 /* arbitrary limit */
#endif

/* character major device number */

#define LASER_DEV_MAJOR   3014
#define LASER_DEV_CLASS   "laser_dev"

#define LASER_DEV_NP_TX_PWR_MSB_OFFSET         102
#define LASER_DEV_NP_TX_PWR_LSB_OFFSET         103
#define LASER_DEV_NP_TX_PWR_OFFSET             LASER_DEV_NP_TX_PWR_MSB_OFFSET
#define LASER_DEV_NP_RX_PWR_MSB_OFFSET         104
#define LASER_DEV_NP_RX_PWR_LSB_OFFSET         105
#define LASER_DEV_NP_RX_PWR_OFFSET             LASER_DEV_NP_RX_PWR_MSB_OFFSET
#define LASER_DEV_NP_TEMP_LSB_OFFSET           97
#define LASER_DEV_NP_TEMP_MSB_OFFSET           96
#define LASER_DEV_NP_TEMP_OFFSET               LASER_DEV_NP_TEMP_MSB_OFFSET
#define LASER_DEV_NP_VOTAGE_LSB_OFFSET         99
#define LASER_DEV_NP_VOTAGE_MSB_OFFSET         98
#define LASER_DEV_NP_VOTAGE_OFFSET             LASER_DEV_NP_VOTAGE_MSB_OFFSET
#define LASER_DEV_NP_BIAS_CURRENT_LSB_OFFSET   101
#define LASER_DEV_NP_BIAS_CURRENT_MSB_OFFSET   100
#define LASER_DEV_NP_BIAS_CURRENT_OFFSET       LASER_DEV_NP_BIAS_CURRENT_MSB_OFFSET

#define LASER_DEV_MS_RX_PWR_MSB_OFFSET      0x50
#define LASER_DEV_MS_RX_PWR_LSB_OFFSET      0x51
#define LASER_DEV_MS_TX_PWR_MSB_OFFSET      0x56
#define LASER_DEV_MS_TX_PWR_LSB_OFFSET      0x57

struct mutex laser_mutex;
int i2c_bus = -1;

static int i2c_sfp_cb(struct notifier_block *nb, unsigned long action, void *data);
static struct notifier_block i2c_sfp_nb = {
    .notifier_call = i2c_sfp_cb,
};
int nb_registered = 0;

u16 (*Laser_Dev_Ioctl_Get_Tx_Optical_Pwr)(void);
u16 (*Laser_Dev_Ioctl_Get_Rx_Optical_Pwr)(void);
u16 (*Laser_Dev_Ioctl_Get_Temp)(void);
u16 (*Laser_Dev_Ioctl_Get_Votage)(void);
u16 (*Laser_Dev_Ioctl_Get_Bias_Current)(void);


static int i2c_sfp_cb(struct notifier_block *nb, unsigned long action, void *data)
{
    if( opticaldet_get_xpon_i2c_bus_num(&i2c_bus) != OPTICALDET_SUCCESS )
        i2c_bus = -1;

    return NOTIFY_OK;
}

/******************************************************************************
* Function    :   Laser_Dev_File_Open
*             :
* Description :   This routine implements the device open function but currently
*             :   is just a stub.
*             :
* Params      :   None
*             :
* Returns     :   0
******************************************************************************/
static int Laser_Dev_File_Open(struct inode *inode, struct file *file)
{
    return 0;
}

/******************************************************************************
* Function    :   Laser_Dev_File_Release
*             :
* Description :   This routine implements the device release function but 
*             :   currently is just a stub.
*             :
* Params      :   None
*             :
* Returns     :   0
******************************************************************************/
static int Laser_Dev_File_Release(struct inode *inode, struct file *file)
{
    return 0;
}


/******************************************************************************
* Function    :   Laser_Dev_Ioctl_Get_Nphtncs_Tx_Optical_Pwr
*             :
* Description :   This routine performs the function of getting the tx optical 
*             :   power when the optics device is NEOPHOTONICS.  This device
*             :   uses internal calibration and stores the value in its final
*             :   form, so no calc or manipulation is required.
*             :
* Params      :   None
*             :
* Returns     :   Unsigned short representation of the Tx power value [micro-watts]
******************************************************************************/
static u16 Laser_Dev_Ioctl_Get_Nphtncs_Tx_Optical_Pwr(void)
{
     u16 TxPwr = -1;

     bcmsfp_read_word(i2c_bus, 1, LASER_DEV_NP_TX_PWR_OFFSET, &TxPwr);
     return TxPwr;
}

/******************************************************************************
* Function    :   Laser_Dev_Ioctl_Get_Nphtncs_Rx_Optical_Pwr
*             :
* Description :   This routine performs the function of getting the rx optical 
*             :   power when the optics device is NEOPHOTONICS.  This device
*             :   uses internal calibration and stores the value in its final
*             :   form, so no calc or manipulation is required.
*             :
* Params      :   None
*             :
* Returns     :   Unsigned short representation of the Rx power value [micro-watts]
******************************************************************************/
static u16 Laser_Dev_Ioctl_Get_Nphtncs_Rx_Optical_Pwr(void)
{    
    u16 RxPwr = -1;

    bcmsfp_read_word(i2c_bus, 1, LASER_DEV_NP_RX_PWR_OFFSET, &RxPwr);
    return RxPwr;
}

/******************************************************************************
* Function    :   Laser_Dev_Ioctl_Get_Nphtncs_Laser_Temp
*             :
* Description :   This routine performs the function of returning the laser 
*             :   temperature when the optics device is NEOPHOTONICS.  This 
*             :   device uses internal calibration and stores the value in its 
*             :   final form, so no calc or manipulation is required.
*             :
* Params      :   None
*             :
* Returns     :   Unsigned short representation of the Temperature [c]
******************************************************************************/
static u16 Laser_Dev_Ioctl_Get_Nphtncs_Laser_Temp(void)
{
    u16 Tmp = -1;

    bcmsfp_read_word(i2c_bus, 1, LASER_DEV_NP_TEMP_OFFSET, &Tmp);
    return Tmp;    
}

/******************************************************************************
* Function    :   Laser_Dev_Ioctl_Get_Nphtncs_Laser_Votage
*             :
* Description :   This routine performs the function of returning the laser 
*             :   votage when the optics device is NEOPHOTONICS.  This 
*             :   device uses internal calibration and stores the value in its 
*             :   final form, so no calc or manipulation is required.
*             :
* Params      :   None
*             :
* Returns     :   unsigned short representation of the Voltage [mV].
******************************************************************************/
static u16 Laser_Dev_Ioctl_Get_Nphtncs_Laser_Votage(void)
{
    u16 Votage = -1;

    bcmsfp_read_word(i2c_bus, 1, LASER_DEV_NP_VOTAGE_OFFSET, &Votage);
    return Votage;     
}

/******************************************************************************
* Function    :   Laser_Dev_Ioctl_Get_Nphtncs_Laser_Bias_Current
*             :
* Description :   This routine performs the function of returning the laser 
*             :   bias current when the optics device is NEOPHOTONICS.  This 
*             :   device uses internal calibration and stores the value in its 
*             :   final form, so no calc or manipulation is required.
*             :
* Params      :   None
*             :
* Returns     :   unsigned short representation of the Bias [uA].
******************************************************************************/
static u16 Laser_Dev_Ioctl_Get_Nphtncs_Laser_Bias_Current(void)
{
    u16 Bias = -1;

    bcmsfp_read_word(i2c_bus, 1, LASER_DEV_NP_BIAS_CURRENT_OFFSET, &Bias);
    return Bias;
}


/******************************************************************************
* Function    :   Laser_Dev_File_Ioctl
*             :
* Description :   This routine catches all of the IOCTL calls made to this char
*             :   device after it has been opened.
*             :
* Params      :   struct file *file           :
*             :   [IN]unsigned int cmd        : indicates the operation to be 
*             :                                 performed
*             :   [IN/OUT]unsigned long arg   : pointer to user args for i/o
*             :
* Returns     :   Result of IOCTL call
******************************************************************************/
static long Laser_Dev_File_Ioctl(struct file *file, unsigned int cmd,
    unsigned long arg)
{

    uint32_t *pPwr = (uint32_t *)arg;
    long Ret=0;
    
    if( i2c_bus == -1 ) {
        printk("\nLaser_Dev: optical module not present!\n" );
        Ret = -1;
        return Ret;
    }

    mutex_lock(&laser_mutex);

    switch (cmd) 
    {
        case LASER_IOCTL_GET_RX_PWR:
        {           
            *pPwr = Laser_Dev_Ioctl_Get_Rx_Optical_Pwr();
            break;
        }
        case LASER_IOCTL_GET_TX_PWR:
        {
            *pPwr = Laser_Dev_Ioctl_Get_Tx_Optical_Pwr();
            break;
        }
        case LASER_IOCTL_GET_TEMPTURE:
        {
            *pPwr = Laser_Dev_Ioctl_Get_Temp();
            break;
        }
        case LASER_IOCTL_GET_VOTAGE:
        {
            if (Laser_Dev_Ioctl_Get_Votage)
                *pPwr = Laser_Dev_Ioctl_Get_Votage();
            break;
        }
        case LASER_IOCTL_GET_BIAS_CURRENT:
        {
            if (Laser_Dev_Ioctl_Get_Bias_Current)
                *pPwr = Laser_Dev_Ioctl_Get_Bias_Current();
            break;
        }
        default:
            printk("\nLaser_Dev: operation not supported\n" );
            Ret = -1;
           break;
    }
    mutex_unlock(&laser_mutex);

    return Ret;
}


static const struct file_operations laser_file_ops = {
    .owner =        THIS_MODULE,
    .open =         Laser_Dev_File_Open,
    .release =      Laser_Dev_File_Release,
    .unlocked_ioctl =   Laser_Dev_File_Ioctl,
#if defined(CONFIG_COMPAT)
    .compat_ioctl = Laser_Dev_File_Ioctl,
#endif
};

/****************************************************************************
* Function    :   Laser_Dev_Init
*             :
* Description :   Performs a registration operation for the char device Laser 
*             :   Dev, plus initializes function pointers based on the
*             :
* Params      :   None
*             :
* Returns     :   status indicating whether error occurred getting gpon optics 
*             :   or during registration
****************************************************************************/
static int Laser_Dev_Init(void)
{
    int ret=0;
    u16 BosaFlag = 0;    

    if( opticaldet_get_xpon_i2c_bus_num(&i2c_bus) != OPTICALDET_SUCCESS )
        i2c_bus = -1;

    if ( 0 == (ret = BpGetGponOpticsType(&BosaFlag)))
    {
    	/* exit the module if pmd device exist */
    	if (BP_GPON_OPTICS_TYPE_PMD == BosaFlag)
        {
            printk(KERN_ERR "PMD exist on board \n");
            return 0;
        }

    	ret = register_chrdev(LASER_DEV_MAJOR, LASER_DEV_CLASS, &laser_file_ops);
        if (ret >= 0) 
        {
            // assign the function pointers here...
            Laser_Dev_Ioctl_Get_Tx_Optical_Pwr  = Laser_Dev_Ioctl_Get_Nphtncs_Tx_Optical_Pwr;
            Laser_Dev_Ioctl_Get_Rx_Optical_Pwr  = Laser_Dev_Ioctl_Get_Nphtncs_Rx_Optical_Pwr;
            Laser_Dev_Ioctl_Get_Temp            = Laser_Dev_Ioctl_Get_Nphtncs_Laser_Temp;
            Laser_Dev_Ioctl_Get_Votage          = Laser_Dev_Ioctl_Get_Nphtncs_Laser_Votage;
            Laser_Dev_Ioctl_Get_Bias_Current    = Laser_Dev_Ioctl_Get_Nphtncs_Laser_Bias_Current;

            bcm_i2c_sfp_register_notifier(&i2c_sfp_nb);
            nb_registered = 1;

            mutex_init(&laser_mutex);
        }
        else
        {
            printk(KERN_ERR "%s: can't register major %d\n",LASER_DEV_CLASS, LASER_DEV_MAJOR);
        }
    }
    else
    {        
        printk(KERN_ERR "%s: board profile not configured and status of BOSA optics cannot be determined.\n", LASER_DEV_CLASS);
    }

    return ret;
}

/****************************************************************************
* Function    :   Laser_Dev_Exit
*             :
* Description :   Performs an un register operation for the char device Laser 
*             :   Dev
*             :
* Params      :   None
*             :
* Returns     :   None
****************************************************************************/
static void Laser_Dev_Exit(void)
{
    if( nb_registered )
        bcm_i2c_sfp_unregister_notifier(&i2c_sfp_nb);
    unregister_chrdev(LASER_DEV_MAJOR, LASER_DEV_CLASS);
}

module_init(Laser_Dev_Init);
module_exit(Laser_Dev_Exit);

MODULE_AUTHOR("Tim Sharp tsharp@broadcom.com");
MODULE_DESCRIPTION("Generic Laser Device driver");
MODULE_LICENSE("Proprietary");
