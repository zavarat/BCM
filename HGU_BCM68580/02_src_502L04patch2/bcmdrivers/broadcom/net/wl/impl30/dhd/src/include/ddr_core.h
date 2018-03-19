/*
 * BCM5301X Denali DDR2/DDR3 memory controlers.
 *
 * Copyright (C) 2017, Broadcom. All Rights Reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 *
 * <<Broadcom-WL-IPTag/Open:>>
 *
 * $Id$
 */

#ifndef	_DDRC_H
#define	_DDRC_H

#ifndef PAD
#define	_PADLINE(line)	pad ## line
#define	_XSTR(line)	_PADLINE(line)
#define	PAD		_XSTR(__LINE__)
#endif	/* PAD */

#ifdef _LANGUAGE_ASSEMBLY

#define	DDRC_CONTROL00		0x000
#define	DDRC_CONTROL01		0x004
#define	DDRC_CONTROL02		0x008
#define	DDRC_CONTROL03		0x00c
#define	DDRC_CONTROL04		0x010
#define	DDRC_CONTROL05		0x014
#define	DDRC_CONTROL06		0x018
#define	DDRC_CONTROL07		0x01c
#define	DDRC_CONTROL08		0x020
#define	DDRC_CONTROL09		0x024
#define	DDRC_CONTROL10		0x028
#define	DDRC_CONTROL11		0x02c
#define	DDRC_CONTROL12		0x030
#define	DDRC_CONTROL13		0x034
#define	DDRC_CONTROL14		0x038
#define	DDRC_CONTROL15		0x03c
#define	DDRC_CONTROL16		0x040
#define	DDRC_CONTROL17		0x044
#define	DDRC_CONTROL18		0x048
#define	DDRC_CONTROL19		0x04c
#define	DDRC_CONTROL20		0x050
#define	DDRC_CONTROL21		0x054
#define	DDRC_CONTROL22		0x058
#define	DDRC_CONTROL23		0x05c
#define	DDRC_CONTROL24		0x060
#define	DDRC_CONTROL25		0x064
#define	DDRC_CONTROL26		0x068
#define	DDRC_CONTROL27		0x06c
#define	DDRC_CONTROL28		0x070
#define	DDRC_CONTROL29		0x074
#define	DDRC_CONTROL30		0x078
#define	DDRC_CONTROL31		0x07c
#define	DDRC_CONTROL32		0x080
#define	DDRC_CONTROL33		0x084
#define	DDRC_CONTROL34		0x088
#define	DDRC_CONTROL35		0x08c
#define	DDRC_CONTROL36		0x090
#define	DDRC_CONTROL37		0x094
#define	DDRC_CONTROL38		0x098
#define	DDRC_CONTROL39		0x09c
#define	DDRC_CONTROL40		0x0a0
#define	DDRC_CONTROL41		0x0a4
#define	DDRC_CONTROL42		0x0a8
#define	DDRC_CONTROL43		0x0ac
#define	DDRC_CONTROL44		0x0b0
#define	DDRC_CONTROL45		0x0b4
#define	DDRC_CONTROL46		0x0b8
#define	DDRC_CONTROL47		0x0bc
#define	DDRC_CONTROL48		0x0c0
#define	DDRC_CONTROL49		0x0c4
#define	DDRC_CONTROL50		0x0c8
#define	DDRC_CONTROL51		0x0cc
#define	DDRC_CONTROL52		0x0d0
#define	DDRC_CONTROL53		0x0d4
#define	DDRC_CONTROL54		0x0d8
#define	DDRC_CONTROL55		0x0dc
#define	DDRC_CONTROL56		0x0e0
#define	DDRC_CONTROL57		0x0e4
#define	DDRC_CONTROL58		0x0e8
#define	DDRC_CONTROL59		0x0ec
#define	DDRC_CONTROL60		0x0f0
#define	DDRC_CONTROL61		0x0f4
#define	DDRC_CONTROL62		0x0f8
#define	DDRC_CONTROL63		0x0fc
#define	DDRC_CONTROL64		0x100
#define	DDRC_CONTROL65		0x104
#define	DDRC_CONTROL66		0x108
#define	DDRC_CONTROL67		0x10c
#define	DDRC_CONTROL68		0x110
#define	DDRC_CONTROL69		0x114
#define	DDRC_CONTROL70		0x118
#define	DDRC_CONTROL71		0x11c
#define	DDRC_CONTROL72		0x120
#define	DDRC_CONTROL73		0x124
#define	DDRC_CONTROL74		0x128
#define	DDRC_CONTROL75		0x12c
#define	DDRC_CONTROL76		0x130
#define	DDRC_CONTROL77		0x134
#define	DDRC_CONTROL78		0x138
#define	DDRC_CONTROL79		0x13c
#define	DDRC_CONTROL80		0x140
#define	DDRC_CONTROL81		0x144
#define	DDRC_CONTROL82		0x148
#define	DDRC_CONTROL83		0x14c
#define	DDRC_CONTROL84		0x150
#define	DDRC_CONTROL85		0x154
#define	DDRC_CONTROL86		0x158
#define	DDRC_CONTROL87		0x15c
#define	DDRC_CONTROL88		0x160
#define	DDRC_CONTROL89		0x164
#define	DDRC_CONTROL90		0x168
#define	DDRC_CONTROL91		0x16c
#define	DDRC_CONTROL92		0x170
#define	DDRC_CONTROL93		0x174
#define	DDRC_CONTROL94		0x178
#define	DDRC_CONTROL95		0x17c
#define	DDRC_CONTROL96		0x180
#define	DDRC_CONTROL97		0x184
#define	DDRC_CONTROL98		0x188
#define	DDRC_CONTROL99		0x18c
#define	DDRC_CONTROL100		0x190
#define	DDRC_CONTROL101		0x194
#define	DDRC_CONTROL102		0x198
#define	DDRC_CONTROL103		0x19c
#define	DDRC_CONTROL104		0x1a0
#define	DDRC_CONTROL105		0x1a4
#define	DDRC_CONTROL106		0x1a8
#define	DDRC_CONTROL107		0x1ac
#define	DDRC_CONTROL108		0x1b0
#define	DDRC_CONTROL109		0x1b4
#define	DDRC_CONTROL110		0x1b8
#define	DDRC_CONTROL111		0x1bc
#define	DDRC_CONTROL112		0x1c0
#define	DDRC_CONTROL113		0x1c4
#define	DDRC_CONTROL114		0x1c8
#define	DDRC_CONTROL115		0x1cc
#define	DDRC_CONTROL116		0x1d0
#define	DDRC_CONTROL117		0x1d4
#define	DDRC_CONTROL118		0x1d8
#define	DDRC_CONTROL119		0x1dc
#define	DDRC_CONTROL120		0x1e0
#define	DDRC_CONTROL121		0x1e4
#define	DDRC_CONTROL122		0x1e8
#define	DDRC_CONTROL123		0x1ec
#define	DDRC_CONTROL124		0x1f0
#define DDRC_CONTROL125		0x1f4
#define DDRC_CONTROL126		0x1f8
#define DDRC_CONTROL127		0x1fc
#define DDRC_CONTROL128		0x200
#define DDRC_CONTROL129		0x204
#define DDRC_CONTROL130		0x208
#define DDRC_CONTROL131		0x20c
#define DDRC_CONTROL132		0x210
#define DDRC_CONTROL133		0x214
#define DDRC_CONTROL134		0x218
#define DDRC_CONTROL135		0x21c
#define DDRC_CONTROL136		0x220
#define DDRC_CONTROL137		0x224
#define DDRC_CONTROL138		0x228
#define DDRC_CONTROL139		0x22c
#define DDRC_CONTROL140		0x230
#define DDRC_CONTROL141		0x234
#define DDRC_CONTROL142		0x238
#define DDRC_CONTROL143		0x23c
#define DDRC_CONTROL144		0x240
#define DDRC_CONTROL145		0x244
#define DDRC_CONTROL146		0x248
#define DDRC_CONTROL147		0x24c
#define DDRC_CONTROL148		0x250
#define DDRC_CONTROL149		0x254
#define DDRC_CONTROL150		0x258
#define DDRC_CONTROL151		0x25c
#define DDRC_CONTROL152		0x260
#define DDRC_CONTROL153		0x264
#define DDRC_CONTROL154		0x268
#define DDRC_CONTROL155		0x26c
#define DDRC_CONTROL156		0x270
#define DDRC_CONTROL157		0x274
#define DDRC_CONTROL158		0x278
#define DDRC_CONTROL159		0x27c
#define DDRC_CONTROL160		0x280
#define DDRC_CONTROL161		0x284
#define DDRC_CONTROL162		0x288
#define DDRC_CONTROL163		0x28c
#define DDRC_CONTROL164		0x290
#define DDRC_CONTROL165		0x294
#define DDRC_CONTROL166		0x298
#define DDRC_CONTROL167		0x29c
#define DDRC_CONTROL168		0x2a0
#define DDRC_CONTROL169		0x2a4
#define DDRC_CONTROL170		0x2a8
#define DDRC_CONTROL171		0x2ac
#define DDRC_CONTROL172		0x2b0
#define DDRC_CONTROL173		0x2b4
#define DDRC_CONTROL174		0x2b8
#define DDRC_CONTROL175		0x2bc
#define DDRC_CONTROL176		0x2c0
#define DDRC_CONTROL177		0x2c4
#define DDRC_CONTROL178		0x2c8
#define DDRC_CONTROL179		0x2cc
#define DDRC_CONTROL180		0x2d0
#define DDRC_CONTROL181		0x2d4
#define DDRC_CONTROL182		0x2d8
#define DDRC_CONTROL183		0x2dc
#define DDRC_CONTROL184		0x2e0
#define DDRC_CONTROL185		0x2e4
#define DDRC_CONTROL186		0x2e8
#define DDRC_CONTROL187		0x2ec
#define DDRC_CONTROL188		0x2f0
#define DDRC_CONTROL189		0x2f4
#define DDRC_CONTROL190		0x2f8
#define DDRC_CONTROL191		0x2fc
#define DDRC_CONTROL192		0x300
#define DDRC_CONTROL193		0x304
#define DDRC_CONTROL194		0x308
#define DDRC_CONTROL195		0x30c
#define DDRC_CONTROL196		0x310
#define DDRC_CONTROL197		0x314
#define DDRC_CONTROL198		0x318
#define DDRC_CONTROL199		0x31c
#define DDRC_CONTROL200		0x320
#define DDRC_CONTROL201		0x324
#define DDRC_CONTROL202		0x328
#define DDRC_CONTROL203		0x32c
#define DDRC_CONTROL204		0x330
#define DDRC_CONTROL205		0x334
#define DDRC_CONTROL206		0x338
#define DDRC_CONTROL207		0x33c
#define DDRC_CONTROL208		0x340
#define DDRC_CONTROL209		0x344
#define DDRC_CONTROL210		0x348
#define DDRC_CONTROL211		0x34c
#define DDRC_CONTROL212		0x350
#define DDRC_CONTROL213		0x354
#define DDRC_CONTROL214		0x358
#define DDRC_CONTROL215		0x35c
#define DDRC_CONTROL216		0x360
#define DDRC_CONTROL217		0x364
#define DDRC_CONTROL218		0x368
#define DDRC_CONTROL219		0x36c
#define DDRC_CONTROL220		0x370
#define DDRC_CONTROL221		0x374
#define DDRC_CONTROL222		0x378
#define DDRC_CONTROL223		0x37c
#define DDRC_CONTROL224		0x380
#define DDRC_CONTROL225		0x384
#define DDRC_CONTROL226		0x388
#define DDRC_CONTROL227		0x38c
#define DDRC_CONTROL228		0x390
#define DDRC_CONTROL229		0x394
#define DDRC_CONTROL230		0x398
#define DDRC_CONTROL231		0x39c
#define DDRC_CONTROL232		0x3a0
#define DDRC_CONTROL233		0x3a4
#define DDRC_CONTROL234		0x3a8
#define DDRC_CONTROL235		0x3ac
#define DDRC_CONTROL236		0x3b0
#define DDRC_CONTROL237		0x3b4
#define DDRC_CONTROL238		0x3b8
#define DDRC_CONTROL239		0x3bc
#define DDRC_CONTROL240		0x3c0
#define DDRC_CONTROL241		0x3c4
#define DDRC_CONTROL242		0x3c8
#define DDRC_CONTROL243		0x3cc
#define DDRC_CONTROL244		0x3d0
#define DDRC_CONTROL245		0x3d4
#define DDRC_CONTROL246		0x3d8
#define DDRC_CONTROL247		0x3dc
#define DDRC_CONTROL248		0x3e0
#define DDRC_CONTROL249		0x3e4
#define DDRC_CONTROL250		0x3e8
#define DDRC_CONTROL251		0x3ec
#define DDRC_CONTROL252		0x3f0
#define DDRC_CONTROL253		0x3f4
#define DDRC_CONTROL254		0x3f8
#define DDRC_CONTROL255		0x3fc
#define DDRC_CONTROL256		0x400
#define DDRC_CONTROL257		0x404
#define DDRC_CONTROL258		0x408
#define DDRC_CONTROL259		0x40c
#define DDRC_CONTROL260		0x410
#define DDRC_CONTROL261		0x414
#define DDRC_CONTROL262		0x418
#define DDRC_CONTROL263		0x41c
#define DDRC_CONTROL264		0x420
#define DDRC_CONTROL265		0x424
#define DDRC_CONTROL266		0x428
#define DDRC_CONTROL267		0x42c
#define DDRC_CONTROL268		0x430
#define DDRC_CONTROL269		0x434
#define DDRC_CONTROL270		0x438
#define DDRC_CONTROL271		0x43c
#define DDRC_CONTROL272		0x440
#define DDRC_CONTROL273		0x444
#define DDRC_CONTROL274		0x448
#define DDRC_CONTROL275		0x44c
#define DDRC_CONTROL276		0x450
#define DDRC_CONTROL277		0x454
#define DDRC_CONTROL278		0x458
#define DDRC_CONTROL279		0x45c
#define DDRC_CONTROL280		0x460
#define DDRC_CONTROL281		0x464
#define DDRC_CONTROL282		0x468
#define DDRC_CONTROL283		0x46c
#define DDRC_CONTROL284		0x470
#define DDRC_CONTROL285		0x474
#define DDRC_CONTROL286		0x478
#define DDRC_CONTROL287		0x47c
#define DDRC_CONTROL288		0x480
#define DDRC_CONTROL289		0x484
#define DDRC_CONTROL290		0x488
#define DDRC_CONTROL291		0x48c
#define DDRC_CONTROL292		0x490
#define DDRC_CONTROL293		0x494
#define DDRC_CONTROL294		0x498
#define DDRC_CONTROL295		0x49c
#define DDRC_CONTROL296		0x4a0
#define DDRC_CONTROL297		0x4a4
#define DDRC_CONTROL298		0x4a8
#define DDRC_CONTROL299		0x4ac
#define DDRC_CONTROL300		0x4b0
#define DDRC_CONTROL301		0x4b4
#define DDRC_CONTROL302		0x4b8
#define DDRC_CONTROL303		0x4bc
#define DDRC_CONTROL304		0x4c0
#define DDRC_CONTROL305		0x4c4
#define DDRC_CONTROL306		0x4c8
#define DDRC_CONTROL307		0x4cc
#define DDRC_CONTROL308		0x4d0
#define DDRC_CONTROL309		0x4d4
#define DDRC_CONTROL310		0x4d8
#define DDRC_CONTROL311		0x4dc
#define DDRC_CONTROL312		0x4e0
#define DDRC_CONTROL313		0x4e4
#define DDRC_CONTROL314		0x4e8
#define DDRC_CONTROL315		0x4ec
#define DDRC_CONTROL316		0x4f0
#define DDRC_CONTROL317		0x4f4
#define DDRC_CONTROL318		0x4f8
#define DDRC_CONTROL319		0x4fc
#define DDRC_CONTROL320		0x500
#define DDRC_CONTROL321		0x504
#define DDRC_CONTROL322		0x508
#define DDRC_CONTROL323		0x50c
#define DDRC_CONTROL324		0x510
#define DDRC_CONTROL325		0x514
#define DDRC_CONTROL326		0x518
#define DDRC_CONTROL327		0x51c
#define DDRC_CONTROL328		0x520
#define DDRC_CONTROL329		0x524
#define DDRC_CONTROL330		0x528
#define DDRC_CONTROL331		0x52c
#define DDRC_CONTROL332		0x530
#define DDRC_CONTROL333		0x534
#define DDRC_CONTROL334		0x538
#define DDRC_CONTROL335		0x53c
#define DDRC_CONTROL336		0x540
#define DDRC_CONTROL337		0x544
#define DDRC_CONTROL338		0x548
#define DDRC_CONTROL339		0x54c
#define DDRC_CONTROL340		0x550
#define DDRC_CONTROL341		0x554
#define DDRC_CONTROL342		0x558
#define DDRC_CONTROL343		0x55c
#define DDRC_CONTROL344		0x560
#define DDRC_CONTROL345		0x564
#define DDRC_CONTROL346		0x568
#define DDRC_CONTROL347		0x56c
#define DDRC_CONTROL348		0x570
#define DDRC_CONTROL349		0x574
#define DDRC_CONTROL350		0x578
#define DDRC_CONTROL351		0x57c
#define DDRC_CONTROL352		0x580
#define DDRC_CONTROL353		0x584
#define DDRC_CONTROL354		0x588
#define DDRC_CONTROL355		0x58c
#define DDRC_CONTROL356		0x590
#define DDRC_CONTROL357		0x594
#define DDRC_CONTROL358		0x598
#define DDRC_CONTROL359		0x59c
#define DDRC_CONTROL360		0x5a0
#define DDRC_CONTROL361		0x5a4
#define DDRC_CONTROL362		0x5a8
#define DDRC_CONTROL363		0x5ac
#define DDRC_CONTROL364		0x5b0
#define DDRC_CONTROL365		0x5b4
#define DDRC_CONTROL366		0x5b8
#define DDRC_CONTROL367		0x5bc
#define DDRC_CONTROL368		0x5c0
#define DDRC_CONTROL369		0x5c4
#define DDRC_CONTROL370		0x5c8
#define DDRC_CONTROL371		0x5cc
#define DDRC_CONTROL372		0x5d0
#define DDRC_CONTROL373		0x5d4
#define DDRC_CONTROL374		0x5d8
#define DDRC_CONTROL375		0x5dc
#define DDRC_CONTROL376		0x5e0
#define DDRC_CONTROL377		0x5e4
#define DDRC_CONTROL378		0x5e8
#define DDRC_CONTROL379		0x5ec
#define DDRC_CONTROL380		0x5f0
#define DDRC_CONTROL381		0x5f4
#define DDRC_CONTROL382		0x5f8
#define DDRC_CONTROL383		0x5fc
#define DDRC_CONTROL384		0x600
#define DDRC_CONTROL385		0x604
#define DDRC_CONTROL386		0x608
#define DDRC_CONTROL387		0x60c
#define DDRC_CONTROL388		0x610
#define DDRC_CONTROL389		0x614
#define DDRC_CONTROL390		0x618
#define DDRC_CONTROL391		0x61c
#define DDRC_CONTROL392		0x620
#define DDRC_CONTROL393		0x624
#define DDRC_CONTROL394		0x628
#define DDRC_CONTROL395		0x62c
#define DDRC_CONTROL396		0x630
#define DDRC_CONTROL397		0x634
#define DDRC_CONTROL398		0x638
#define DDRC_CONTROL399		0x63c
#define DDRC_CONTROL400		0x640
#define DDRC_CONTROL401		0x644
#define DDRC_CONTROL402		0x648
#define DDRC_CONTROL403		0x64c
#define DDRC_CONTROL404		0x650
#define DDRC_CONTROL405		0x654
#define DDRC_CONTROL406		0x658
#define DDRC_CONTROL407		0x65c
#define DDRC_CONTROL408		0x660
#define DDRC_CONTROL409		0x664
#define DDRC_CONTROL410		0x668
#define DDRC_CONTROL411		0x66c
#define DDRC_CONTROL412		0x670
#define DDRC_CONTROL413		0x674
#define DDRC_CONTROL414		0x678
#define DDRC_CONTROL415		0x67c
#define DDRC_CONTROL416		0x680
#define DDRC_CONTROL417		0x684
#define DDRC_CONTROL418		0x688
#define DDRC_CONTROL419		0x68c
#define DDRC_CONTROL420		0x690
#define DDRC_CONTROL421		0x694
#define DDRC_CONTROL422		0x698
#define DDRC_CONTROL423		0x69c
#define DDRC_CONTROL424		0x6a0
#define DDRC_CONTROL425		0x6a4
#define DDRC_CONTROL426		0x6a8
#define DDRC_CONTROL427		0x6ac
#define DDRC_CONTROL428		0x6b0
#define DDRC_CONTROL429		0x6b4
#define DDRC_CONTROL430		0x6b8
#define DDRC_CONTROL431		0x6bc
#define DDRC_CONTROL432		0x6c0
#define DDRC_CONTROL433		0x6c4
#define DDRC_CONTROL434		0x6c8
#define DDRC_CONTROL435		0x6cc
#define DDRC_CONTROL436		0x6d0
#define DDRC_CONTROL437		0x6d4
#define DDRC_CONTROL438		0x6d8
#define DDRC_CONTROL439		0x6dc
#define DDRC_CONTROL440		0x6e0
#define DDRC_CONTROL441		0x6e4
#define DDRC_CONTROL442		0x6e8
#define DDRC_CONTROL443		0x6ec
#define DDRC_CONTROL444		0x6f0
#define DDRC_CONTROL445		0x6f4
#define DDRC_CONTROL446		0x6f8
#define DDRC_CONTROL447		0x6fc
#define DDRC_CONTROL448		0x700
#define DDRC_CONTROL449		0x704
#define DDRC_CONTROL450		0x708
#define DDRC_CONTROL451		0x70c
#define DDRC_CONTROL452		0x710
#define DDRC_CONTROL453		0x714
#define DDRC_CONTROL454		0x718
#define DDRC_CONTROL455		0x71c
#define DDRC_CONTROL456		0x720
#define DDRC_CONTROL457		0x724
#define DDRC_CONTROL458		0x728
#define DDRC_CONTROL459		0x72c
#define DDRC_CONTROL460		0x730
#define DDRC_CONTROL461		0x734
#define DDRC_CONTROL462		0x738
#define DDRC_CONTROL463		0x73c
#define DDRC_CONTROL464		0x740
#define DDRC_CONTROL465		0x744
#define DDRC_CONTROL466		0x748
#define DDRC_CONTROL467		0x74c
#define DDRC_CONTROL468		0x750
#define DDRC_CONTROL469		0x754
#define DDRC_CONTROL470		0x758
#define DDRC_CONTROL471		0x75c
#define DDRC_CONTROL472		0x760
#define DDRC_CONTROL473		0x764
#define DDRC_CONTROL474		0x768
#define DDRC_CONTROL475		0x76c
#define DDRC_CONTROL476		0x770
#define DDRC_CONTROL477		0x774
#define DDRC_CONTROL478		0x778
#define DDRC_CONTROL479		0x77c
#define DDRC_CONTROL480		0x780
#define DDRC_CONTROL481		0x784
#define DDRC_CONTROL482		0x788
#define DDRC_CONTROL483		0x78c
#define DDRC_CONTROL484		0x790
#define DDRC_CONTROL485		0x794
#define DDRC_CONTROL486		0x798
#define DDRC_CONTROL487		0x79c
#define DDRC_CONTROL488		0x7a0
#define DDRC_CONTROL489		0x7a4
#define DDRC_CONTROL490		0x7a8
#define DDRC_CONTROL491		0x7ac
#define DDRC_CONTROL492		0x7b0
#define DDRC_CONTROL493		0x7b4
#define DDRC_CONTROL494		0x7b8
#define DDRC_CONTROL495		0x7bc
#define DDRC_CONTROL496		0x7c0
#define DDRC_CONTROL497		0x7c4
#define DDRC_CONTROL498		0x7c8
#define DDRC_CONTROL499		0x7cc
#define DDRC_CONTROL500		0x7d0
#define DDRC_CONTROL501		0x7d4
#define DDRC_CONTROL502		0x7d8
#define DDRC_CONTROL503		0x7dc
#define DDRC_CONTROL504		0x7e0
#define DDRC_CONTROL505		0x7e4
#define DDRC_CONTROL506		0x7e8
#define DDRC_CONTROL507		0x7ec
#define DDRC_CONTROL508		0x7f0
#define DDRC_CONTROL509		0x7f4
#define DDRC_CONTROL510		0x7f8
#define DDRC_CONTROL511		0x7fc
#define DDRC_CONTROL512		0x800
#define DDRC_CONTROL513		0x804
#define DDRC_CONTROL514		0x808
#define DDRC_CONTROL515		0x80c
#define DDRC_CONTROL516		0x810
#define DDRC_CONTROL517		0x814
#define DDRC_CONTROL518		0x818
#define DDRC_CONTROL519		0x81c
#define DDRC_CONTROL520		0x820
#define DDRC_CONTROL521		0x824
#define DDRC_CONTROL522		0x828
#define DDRC_CONTROL523		0x82c
#define DDRC_CONTROL524		0x830
#define DDRC_CONTROL525		0x834
#define DDRC_CONTROL526		0x838
#define DDRC_CONTROL527		0x83c
#define DDRC_CONTROL528		0x840
#define DDRC_CONTROL529		0x844
#define DDRC_CONTROL530		0x848
#define DDRC_CONTROL531		0x84c
#define DDRC_CONTROL532		0x850
#define DDRC_CONTROL533		0x854
#define DDRC_CONTROL534		0x858
#define DDRC_CONTROL535		0x85c
#define DDRC_CONTROL536		0x860
#define DDRC_CONTROL537		0x864
#define DDRC_CONTROL538		0x868
#define DDRC_CONTROL539		0x86c
#define DDRC_CONTROL540		0x870
#define DDRC_CONTROL541		0x874
#define DDRC_CONTROL542		0x878
#define DDRC_CONTROL543		0x87c
#define DDRC_CONTROL544		0x880
#define DDRC_CONTROL545		0x884
#define DDRC_CONTROL546		0x888
#define DDRC_CONTROL547		0x88c
#define DDRC_CONTROL548		0x890
#define DDRC_CONTROL549		0x894
#define DDRC_CONTROL550		0x898
#define DDRC_CONTROL551		0x89c
#define DDRC_CONTROL552		0x8a0
#define DDRC_CONTROL553		0x8a4
#define DDRC_CONTROL554		0x8a8
#define DDRC_CONTROL555		0x8ac
#define DDRC_CONTROL556		0x8b0
#define DDRC_CONTROL557		0x8b4
#define DDRC_CONTROL558		0x8b8
#define DDRC_CONTROL559		0x8bc
#define DDRC_CONTROL560		0x8c0
#define DDRC_CONTROL561		0x8c4
#define DDRC_CONTROL562		0x8c8
#define DDRC_CONTROL563		0x8cc
#define DDRC_CONTROL564		0x8d0
#define DDRC_CONTROL565		0x8d4
#define DDRC_CONTROL566		0x8d8
#define DDRC_CONTROL567		0x8dc
#define DDRC_CONTROL568		0x8e0
#define DDRC_CONTROL569		0x8e4
#define DDRC_CONTROL570		0x8e8
#define DDRC_CONTROL571		0x8ec
#define DDRC_CONTROL572		0x8f0
#define DDRC_CONTROL573		0x8f4
#define DDRC_CONTROL574		0x8f8
#define DDRC_CONTROL575		0x8fc
#define DDRC_CONTROL576		0x900
#define DDRC_CONTROL577		0x904
#define DDRC_CONTROL578		0x908
#define DDRC_CONTROL579		0x90c
#define DDRC_CONTROL580		0x910
#define DDRC_CONTROL581		0x914
#define DDRC_CONTROL582		0x918
#define DDRC_CONTROL583		0x91c
#define DDRC_CONTROL584		0x920
#define DDRC_CONTROL585		0x924
#define DDRC_CONTROL586		0x928
#define DDRC_CONTROL587		0x92c
#define DDRC_CONTROL588		0x930
#define DDRC_CONTROL589		0x934
#define DDRC_CONTROL590		0x938
#define DDRC_CONTROL591		0x93c
#define DDRC_CONTROL592		0x940
#define DDRC_CONTROL593		0x944
#define DDRC_CONTROL594		0x948
#define DDRC_CONTROL595		0x94c
#define DDRC_CONTROL596		0x950
#define DDRC_CONTROL597		0x954
#define DDRC_CONTROL598		0x958
#define DDRC_CONTROL599		0x95c
#define DDRC_CONTROL600		0x960
#define DDRC_CONTROL601		0x964
#define DDRC_CONTROL602		0x968
#define DDRC_CONTROL603		0x96c
#define DDRC_CONTROL604		0x970
#define DDRC_CONTROL605		0x974
#define DDRC_CONTROL606		0x978
#define DDRC_CONTROL607		0x97c
#define DDRC_CONTROL608		0x980
#define DDRC_CONTROL609		0x984
#define DDRC_CONTROL610		0x988
#define DDRC_CONTROL611		0x98c
#define DDRC_CONTROL612		0x990
#define DDRC_CONTROL613		0x994
#define DDRC_CONTROL614		0x998
#define DDRC_CONTROL615		0x99c
#define DDRC_CONTROL616		0x9a0
#define DDRC_CONTROL617		0x9a4
#define DDRC_CONTROL618		0x9a8
#define DDRC_CONTROL619		0x9ac
#define DDRC_CONTROL620		0x9b0
#define DDRC_CONTROL621		0x9b4
#define DDRC_CONTROL622		0x9b8
#define DDRC_CONTROL623		0x9bc
#define DDRC_CONTROL624		0x9c0
#define DDRC_CONTROL625		0x9c4
#define DDRC_CONTROL626		0x9c8
#define DDRC_CONTROL627		0x9cc
#define DDRC_CONTROL628		0x9d0
#define DDRC_CONTROL629		0x9d4
#define DDRC_CONTROL630		0x9d8
#define DDRC_CONTROL631		0x9dc
#define DDRC_CONTROL632		0x9e0
#define DDRC_CONTROL633		0x9e4
#define DDRC_CONTROL634		0x9e8
#define DDRC_CONTROL635		0x9ec
#define DDRC_CONTROL636		0x9f0
#define DDRC_CONTROL637		0x9f4
#define DDRC_CONTROL638		0x9f8
#define DDRC_CONTROL639		0x9fc
#define DDRC_CONTROL640		0xa00
#define DDRC_CONTROL641		0xa04
#define DDRC_CONTROL642		0xa08
#define DDRC_CONTROL643		0xa0c
#define DDRC_CONTROL644		0xa10
#define DDRC_CONTROL645		0xa14
#define DDRC_CONTROL646		0xa18
#define DDRC_CONTROL647		0xa1c
#define DDRC_CONTROL648		0xa20
#define DDRC_CONTROL649		0xa24
#define DDRC_CONTROL650		0xa28

#define DDRC_PHY_CONFIG			0x400
#define DDRC_PCONTROL_REV		0x800
#define DDRC_PCONTROL_PM_CONTROL	0x804
#define DDRC_PCONTROL_PLL_STATUS	0x810
#define DDRC_PCONTROL_PLL_CONFIG	0x814
#define DDRC_PCONTROL_PLL_CONTROL	0x818
#define DDRC_PCONTROL_PLL_DIVIDERS	0x81c
#define DDRC_PCONTROL_AUX_CONTROL	0x820

#define DDRC_PCONTROL_ZQ_PVT_COMPCTL	0x83c
#define DDRC_PCONTROL_VDL_CALIBRATE	0x848
#define DDRC_PHY_STRP_STAT		0x8b8
#define DDRC_PHY_LN0_WR_PREMB_MODE	0xbac

#else	/* !_LANGUAGE_ASSEMBLY */

#define DDRC_MAXREG		209

typedef struct ddrcregs {
	uint32	control[DDRC_MAXREG];		/* 0x000 -- 0x340 */
	uint32	PAD[47];
	uint32	phy_config;			/* 0x400 */
	uint32	PAD[255];
	uint32	phy_control_rev;		/* 0x800 */
	uint32	phy_control_pmcontrol;		/* 0x804 */
	uint32	PAD[2];
	uint32	phy_control_pllstatus;		/* 0x810 */
	uint32	phy_control_pllconfig;		/* 0x814 */
	uint32	phy_control_pllcontrol;		/* 0x818 */
	uint32	phy_control_plldividers;	/* 0x81c */
	uint32	phy_control_auxcontrol;		/* 0x820 */
	uint32	PAD[4];
	uint32	phy_control_vdl_ovride_bitctl;	/* 0x834 */
	uint32	PAD[1];
	uint32	phy_control_zq_pvt_compctl;	/* 0x83c */
	uint32	PAD[2];
	uint32	phy_control_vdl_calibrate;	/* 0x848 */
	uint32	phy_control_vdl_calibsts;	/* 0x84c */
	uint32	PAD[26];
	uint32	phy_strp_stat;			/* 0x8b8 */
	uint32	PAD[81];
	uint32	phy_ln0_vdl_ovride_byte_rd_en;		/* 0xa00 */
	uint32	phy_ln0_vdl_ovride_byte0_w;		/* 0xa04 */
	uint32	phy_ln0_vdl_ovride_byte0_r_p;		/* 0xa08 */
	uint32	phy_ln0_vdl_ovride_byte0_r_n;		/* 0xa0c */
	uint32	phy_ln0_vdl_ovride_byte0_bit0_w;	/* 0xa10 */
	uint32	phy_ln0_vdl_ovride_byte0_bit1_w;	/* 0xa14 */
	uint32	phy_ln0_vdl_ovride_byte0_bit2_w;	/* 0xa18 */
	uint32	phy_ln0_vdl_ovride_byte0_bit3_w;	/* 0xa1c */
	uint32	phy_ln0_vdl_ovride_byte0_bit4_w;	/* 0xa20 */
	uint32	phy_ln0_vdl_ovride_byte0_bit5_w;	/* 0xa24 */
	uint32	phy_ln0_vdl_ovride_byte0_bit6_w;	/* 0xa28 */
	uint32	phy_ln0_vdl_ovride_byte0_bit7_w;	/* 0xa2c */
	uint32	phy_ln0_vdl_ovride_byte0_dm_w;		/* 0xa30 */
	uint32	PAD[16];
	uint32	phy_ln0_vdl_ovride_byte0_bit_rd_en;	/* 0xa74 */
	uint32	PAD[11];
	uint32	phy_ln0_vdl_ovride_byte1_w;		/* 0xaa4 */
	uint32	phy_ln0_vdl_ovride_byte1_r_p;		/* 0xaa8 */
	uint32	phy_ln0_vdl_ovride_byte1_r_n;		/* 0xaac */
	uint32	phy_ln0_vdl_ovride_byte1_bit0_w;	/* 0xab0 */
	uint32	phy_ln0_vdl_ovride_byte1_bit1_w;	/* 0xab4 */
	uint32	phy_ln0_vdl_ovride_byte1_bit2_w;	/* 0xab8 */
	uint32	phy_ln0_vdl_ovride_byte1_bit3_w;	/* 0xabc */
	uint32	phy_ln0_vdl_ovride_byte1_bit4_w;	/* 0xac0 */
	uint32	phy_ln0_vdl_ovride_byte1_bit5_w;	/* 0xac4 */
	uint32	phy_ln0_vdl_ovride_byte1_bit6_w;	/* 0xac8 */
	uint32	phy_ln0_vdl_ovride_byte1_bit7_w;	/* 0xacc */
	uint32	phy_ln0_vdl_ovride_byte1_dm_w;		/* 0xad0 */
	uint32	PAD[16];
	uint32	phy_ln0_vdl_ovride_byte1_bit_rd_en;	/* 0xb14 */
	uint32	PAD[18];
	uint32	phy_ln0_rddata_dly;		/* 0xb60 */
	uint32	PAD[18];
	uint32	phy_ln0_wr_premb_mode;		/* 0xbac */
} _ddrcregs_t;

typedef volatile _ddrcregs_t ddrcregs_t;

#endif	/* _LANGUAGE_ASSEMBLY */

#define DDR_TABLE_END		0xffffffff

#define DDRC00_START		0x00000001
#define DDR_INT_INIT_DONE	0x200

#define DDR_PHY_DMP_OFFSET	0x00001000

#define DDR_TYPE_MASK		(0x1 << 0)
#define DDR_STAT_DDR3		0x00000001	/* bit 0 of iostatus */

#define DDR_PHY_CONTROL_REGS_REVISION	0x18010800
#define DDR_S1_IDM_RESET_CONTROL		0x18108800
#define DDR_S1_IDM_IO_CONTROL_DIRECT	0x18108408
#define DDR_S2_IDM_RESET_CONTROL		0x18109800

#endif	/* _DDRC_H */
