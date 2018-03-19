/***********************************************************************
 *
 *  Copyright (c) 2000-2010  Broadcom Corporation
 *  All Rights Reserved
 *
<:label-BRCM:2011:proprietary:standard

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
 *
************************************************************************/

#ifdef DMP_X_BROADCOM_COM_DNSPROXY_1 /* aka SUPPORT_DNSPROXY */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include "httpd.h"
#include "cgi_main.h"
#include "cms.h"
#include "cms_util.h"
#include "cms_core.h"
#include "cms_dal.h"

void cgiDnsProxyCfg(char *query, FILE *fs) 
{
   char enable[BUFLEN_4];
   char hostname[BUFLEN_16];
   char domainname[BUFLEN_32];
   char path[BUFLEN_1024];
   CmsRet ret = CMSRET_SUCCESS;

   cgiGetValueByName(query, "enblDproxy", enable);
   cgiGetValueByName(query, "hostname", hostname);
   cgiGetValueByName(query, "domainname", domainname);

   if ((ret = dalDnsProxyCfg(enable, hostname, domainname)) != CMSRET_SUCCESS) 
   {
      cmsLog_error("dalDnsProxyCfg failed, ret=%d", ret);
      return;
   }
   else 
   {
      glbSaveConfigNeeded = TRUE;
   }
      makePathToWebPage(path, sizeof(path), "dnsproxycfg.html");
      do_ej(path, fs);
}

void cgiGetDnsProxy(int argc __attribute__((unused)),
                    char **argv __attribute__((unused)),
                    char *varValue)
{
   cmsLog_debug("enter");
   dalGetDnsProxy(varValue);
   cmsLog_debug("info = %s", varValue);
}
#endif