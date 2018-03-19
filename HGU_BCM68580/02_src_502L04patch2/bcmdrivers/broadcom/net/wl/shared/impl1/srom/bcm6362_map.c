#include <typedefs.h>
#if defined(CONFIG_BCM96362)
/* second level patch by wlanPaInfo in boardparms.c, third level patch from flash by nvramUpdate */
#if 0
/* 6362 with EXTERNAL PA */
uint16 wl_srom_map_6362[220] = {	
/* PA values MUST be calibrated and refilled for the actual EEPROM/SROM-less design*/
/* 2.4GHz PA does not need to be recalibrated on per board basis */
/* MAC address are zero'ed */
/* CRC here is not recalculated, do not program this to EEPROM/SROM, this is for EEPROM/SROM-less use only */
/*  srom[000]: */ 0x2801, 0x0000, 0x04f4, 0x14e4, 0x0078, 0xedbe, 0x0000, 0x2bc4, 
/*  srom[008]: */ 0x2a64, 0x2964, 0x2c64, 0x3ce7, 0x46ff, 0x47ff, 0x0c00, 0x0820, 
/*  srom[016]: */ 0x0030, 0x1002, 0x1f2f, 0x7d75, 0x8080, 0x0032, 0x0100, 0x8400, 
/*  srom[024]: */ 0xd700, 0x01c7, 0x0083, 0x8500, 0x2010, 0xffff, 0x0000, 0xffff, 
/*  srom[032]: */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
/*  srom[040]: */ 0xffff, 0xffff, 0x1010, 0x0005, 0xffff, 0xffff, 0xffff, 0xffff, 
/*  srom[048]: */ 0x4354, 0x8000, 0x0002, 0x0000, 0x1f30, 0x1800, 0x0000, 0x0000, 
/*  srom[056]: */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
/*  srom[064]: */ 0x5372, 0x1100, 0x0200, 0x0000, 0x0000, 0x0002, 0x0000, 0x0000, 
/*  srom[072]: */ 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0x0303, 0x0202, 
/*  srom[080]: */ 0xffff, 0x0033, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0319, 
/*  srom[088]: */ 0x030d, 0x7800, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
/*  srom[096]: */ 0x2058, 0xfe6f, 0x1785, 0xfa21, 0x3e28, 0x3a28, 0xfe75, 0x0f64, 
/*  srom[104]: */ 0xfbdf, 0xfe87, 0x1637, 0xfa8e, 0xfead, 0x11aa, 0xfb9c, 0x0000, 
/*  srom[112]: */ 0x2058, 0xfe77, 0x17e0, 0xfa16, 0x3e28, 0x3a28, 0xfed0, 0x0ee4, 
/*  srom[120]: */ 0xfc20, 0xfe9a, 0x1591, 0xfabc, 0xfebc, 0x0ef3, 0xfbfe, 0x0000, 
/*  srom[128]: */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
/*  srom[136]: */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
/*  srom[144]: */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
/*  srom[152]: */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
/*  srom[160]: */ 0x0000, 0x5555, 0x5555, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*  srom[168]: */ 0x0000, 0x5555, 0x5555, 0x5555, 0x5555, 0x3333, 0x3333, 0x3333, 
/*  srom[176]: */ 0x3333, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*  srom[184]: */ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*  srom[192]: */ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*  srom[200]: */ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 
/*  srom[208]: */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
/*  srom[216]: */ 0xffff, 0xffff, 0xffff, 0xb908, 
};
#else
/* 6362B0 with INTERNAL PA */
uint16 wl_srom_map_6362[220] = {	
/* PA values MUST be calibrated and refilled for the actual EEPROM/SROM-less design*/
/* 2.4GHz PA does not need to be recalibrated on per board basis */
/* MAC address are zero'ed */
/* CRC here is not recalculated, do not program this to EEPROM/SROM, this is for EEPROM/SROM-less use only */
/*  srom[000]: */ 0x2801, 0x0000, 0x0566, 0x14e4, 0x0078, 0xedbe, 0x0000, 0x2bc4, 
/*  srom[008]: */ 0x2a64, 0x2964, 0x2c64, 0x3ce7, 0x46ff, 0x47ff, 0x0c00, 0x0820, 
/*  srom[016]: */ 0x0030, 0x1002, 0x1f2f, 0x7d75, 0x8080, 0x0032, 0x0100, 0x8400, 
/*  srom[024]: */ 0xd700, 0x01c7, 0x0083, 0x8500, 0x2010, 0xffff, 0x0000, 0xffff, 
/*  srom[032]: */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
/*  srom[040]: */ 0xffff, 0xffff, 0x1010, 0x0005, 0xffff, 0xffff, 0xffff, 0xffff, 
/*  srom[048]: */ 0x4354, 0x8000, 0x0002, 0x0000, 0x1f30, 0x1800, 0x0000, 0x0000, 
/*  srom[056]: */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
/*  srom[064]: */ 0x5372, 0x1230, 0x0200, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*  srom[072]: */ 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0x0303, 0x0202, 
/*  srom[080]: */ 0xff02, 0x0033, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0315, 
/*  srom[088]: */ 0x0315, 0x7800, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff, 
/*  srom[096]: */ 0x2038, 0xFFB5, 0x175C, 0xFB09, 0x3e30, 0x403c, 0xfe35, 0x10cf, 
/*  srom[104]: */ 0xfb89, 0xfeac, 0x12dd, 0xfb7f, 0xfe4a, 0x10fe, 0xfb95, 0x0000, 
/*  srom[112]: */ 0x2038, 0xFF9F, 0x1758, 0xFAF5, 0x3e30, 0x403c, 0xfedc, 0x1246, 
/*  srom[120]: */ 0xfbc4, 0xff44, 0x135b, 0xfbfd, 0xfebb, 0x127b, 0xfba3, 0x0000, 
/*  srom[128]: */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
/*  srom[136]: */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
/*  srom[144]: */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
/*  srom[152]: */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
/*  srom[160]: */ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*  srom[168]: */ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*  srom[176]: */ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*  srom[184]: */ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*  srom[192]: */ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*  srom[200]: */ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 
/*  srom[208]: */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
/*  srom[216]: */ 0xffff, 0xffff, 0xffff, 0xb908, 
};
#endif
#endif /* defined(CONFIG_BCM96362) */
#if defined(CONFIG_BCM963268)
/* BCM963168VX P102 with EXTERNAL PA */
uint16 wl_srom_map_6362[220] = {	
/* PA values MUST be calibrated and refilled for the actual EEPROM/SROM-less design*/
/* 2.4GHz PA does not need to be recalibrated on per board basis */
/* MAC address are zero'ed */
/* CRC here is not recalculated, do not program this to EEPROM/SROM, this is for EEPROM/SROM-less use only */
/*  srom[000]: */ 0x2801, 0x0000, 0x05a8, 0x14e4, 0x0078, 0xedbe, 0x0000, 0x2bc4,
/*  srom[008]: */ 0x2a64, 0x2964, 0x2c64, 0x3ce7, 0x46ff, 0x47ff, 0x0c00, 0x0820,
/*  srom[016]: */ 0x0030, 0x1002, 0x1f2f, 0x7d75, 0x8080, 0x0032, 0x0100, 0x8400,
/*  srom[024]: */ 0xd700, 0x01c7, 0x0083, 0x8500, 0x2010, 0xffff, 0x0000, 0xffff,
/*  srom[032]: */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/*  srom[040]: */ 0xffff, 0xffff, 0x1010, 0x0005, 0xffff, 0xffff, 0xffff, 0xffff,
/*  srom[048]: */ 0x4354, 0x8000, 0x0002, 0x0000, 0x1f30, 0x1800, 0x0000, 0x0000,
/*  srom[056]: */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/*  srom[064]: */ 0x5372, 0x1102, 0x0200, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/*  srom[072]: */ 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0x0003, 0x0000,
/*  srom[080]: */ 0x0000, 0x0033, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0x0313,
/*  srom[088]: */ 0x0313, 0x7800, 0xffff, 0xffff, 0xffff, 0xffff, 0x001e, 0xffff,
/*  srom[096]: */ 0x2054, 0xfe97, 0x189e, 0xfa0c, 0x3e30, 0x403c, 0xff43, 0x1317,
/*  srom[104]: */ 0xfb23, 0xfea2, 0x149a, 0xfafc, 0xff43, 0x1317, 0xfb23, 0x0000,
/*  srom[112]: */ 0x2054, 0xfe8b, 0x187b, 0xfa0a, 0x3e30, 0x403c, 0xff80, 0x12f0,
/*  srom[120]: */ 0xfb15, 0xfebe, 0x1478, 0xfb1a, 0xff80, 0x12f0, 0xfb15, 0x0000,
/*  srom[128]: */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/*  srom[136]: */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/*  srom[144]: */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/*  srom[152]: */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/*  srom[160]: */ 0x0000, 0x4444, 0x4444, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/*  srom[168]: */ 0x0000, 0x4444, 0x4444, 0x4444, 0x4444, 0x0000, 0x0000, 0x0000,
/*  srom[176]: */ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/*  srom[184]: */ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/*  srom[192]: */ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/*  srom[200]: */ 0x0000, 0x0000, 0x0000, 0x0006, 0x0000, 0xffff, 0xffff, 0xffff,
/*  srom[208]: */ 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
/*  srom[216]: */ 0xffff, 0xffff, 0xffff, 0xb908,
};
#endif  /* defined(CONFIG_BCM963268) */

