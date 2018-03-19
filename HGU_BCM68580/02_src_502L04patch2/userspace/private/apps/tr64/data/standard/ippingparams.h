/*****************************************************************************
//
// Copyright (c) 2005-2012 Broadcom Corporation
// All Rights Reserved
//
// <:label-BRCM:2012:proprietary:standard
// 
//  This program is the proprietary software of Broadcom and/or its
//  licensors, and may only be used, duplicated, modified or distributed pursuant
//  to the terms and conditions of a separate, written license agreement executed
//  between you and Broadcom (an "Authorized License").  Except as set forth in
//  an Authorized License, Broadcom grants no license (express or implied), right
//  to use, or waiver of any kind with respect to the Software, and Broadcom
//  expressly reserves all rights in and to the Software and all intellectual
//  property rights therein.  IF YOU HAVE NO AUTHORIZED LICENSE, THEN YOU HAVE
//  NO RIGHT TO USE THIS SOFTWARE IN ANY WAY, AND SHOULD IMMEDIATELY NOTIFY
//  BROADCOM AND DISCONTINUE ALL USE OF THE SOFTWARE.
// 
//  Except as expressly set forth in the Authorized License,
// 
//  1. This program, including its structure, sequence and organization,
//     constitutes the valuable trade secrets of Broadcom, and you shall use
//     all reasonable efforts to protect the confidentiality thereof, and to
//     use this information only in connection with your use of Broadcom
//     integrated circuit products.
// 
//  2. TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
//     AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES, REPRESENTATIONS OR
//     WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH
//     RESPECT TO THE SOFTWARE.  BROADCOM SPECIFICALLY DISCLAIMS ANY AND
//     ALL IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY, NONINFRINGEMENT,
//     FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES, ACCURACY OR
//     COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR CORRESPONDENCE
//     TO DESCRIPTION. YOU ASSUME THE ENTIRE RISK ARISING OUT OF USE OR
//     PERFORMANCE OF THE SOFTWARE.
// 
//  3. TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL BROADCOM OR
//     ITS LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL, INCIDENTAL, SPECIAL,
//     INDIRECT, OR EXEMPLARY DAMAGES WHATSOEVER ARISING OUT OF OR IN ANY
//     WAY RELATING TO YOUR USE OF OR INABILITY TO USE THE SOFTWARE EVEN
//     IF BROADCOM HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES;
//     OR (ii) ANY AMOUNT IN EXCESS OF THE AMOUNT ACTUALLY PAID FOR THE
//     SOFTWARE ITSELF OR U.S. $1, WHICHEVER IS GREATER. THESE LIMITATIONS
//     SHALL APPLY NOTWITHSTANDING ANY FAILURE OF ESSENTIAL PURPOSE OF ANY
//     LIMITED REMEDY.
// :>
//
******************************************************************************
//
//  Filename:       ippingparams.h
//
******************************************************************************/
#ifndef _IPPINGPARAMS_H
#define _IPPINGPARAMS_H

#define VAR_DiagnosticsState                            0
#define VAR_Interface                                   1
#define VAR_Host                                        2
#define VAR_NumberOfRepetitions                         3
#define VAR_Timeout                                     4
#define VAR_DataBlockSize                               5
#define VAR_DSCP                                        6
#define VAR_SuccessCount                                7
#define VAR_FailureCount                                8
#define VAR_AverageResponseTime                         9
#define VAR_MinimumResponseTime                         10
#define VAR_MaximumResponseTime                         11

int IPPing_GetVar(UFILE *uclient, PService psvc, PAction ac, pvar_entry_t args, int nargs);
int SetDiagnosticsStateIPPing(UFILE *uclient, PService psvc, PAction ac, pvar_entry_t args, int nargs);
int SetInterfaceIPPing(UFILE *uclient, PService psvc, PAction ac, pvar_entry_t args, int nargs);
int SetHostIPPing(UFILE *uclient, PService psvc, PAction ac, pvar_entry_t args, int nargs);
int NumberOfRepetitionsIPPing(UFILE *uclient, PService psvc, PAction ac, pvar_entry_t args, int nargs);
int SetTimeoutIPPing(UFILE *uclient, PService psvc, PAction ac, pvar_entry_t args, int nargs);
int SetDataBlockSizeIPPing(UFILE *uclient, PService psvc, PAction ac, pvar_entry_t args, int nargs);
int SetDSCPIPPing(UFILE *uclient, PService psvc, PAction ac, pvar_entry_t args, int nargs);

#endif /* LANWLANCFGPARAMS_H */
