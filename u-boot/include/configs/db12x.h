/*
 * Copyright (C) 2016 Piotr Dymacz <piotr@dymacz.pl>
 *
 * This file contains the configuration parameters
 * for Qualcomm Atheros AR934x based devices
 *
 * Reference designs: AP123, MI124, DB120
 *
 * SPDX-License-Identifier: GPL-2.0
 */

#ifndef _DB12X_H
#define _DB12X_H

#include <config.h>
#include <configs/qca9k_common.h>
#include <soc/soc_common.h>

/*
 * ==================
 * GPIO configuration
 * ==================
 */
#if defined(CONFIG_FOR_ALFA_NETWORK_N5Q)

	#define CONFIG_QCA_GPIO_MASK_LED_ACT_L	GPIO0 | GPIO1  | GPIO2  |\
						GPIO3 | GPIO12 | GPIO18 |\
						GPIO19
	#define CONFIG_QCA_GPIO_MASK_OUT_INIT_L	GPIO16 | GPIO17

#elif defined(CONFIG_FOR_ENGENIUS_ENS202EXT)

	#define CONFIG_QCA_GPIO_MASK_LED_ACT_L	GPIO0  | GPIO14 | GPIO16 |\
						GPIO17 | GPIO18

#elif defined(CONFIG_FOR_GLINET_GL_AR300)

	#define CONFIG_QCA_GPIO_MASK_LED_ACT_L	GPIO13 | GPIO14

#elif defined(CONFIG_FOR_TPLINK_MR3420_V2)

	#define CONFIG_QCA_GPIO_MASK_LED_ACT_L	GPIO11 | GPIO12 | GPIO13 |\
						GPIO14 | GPIO15 | GPIO18 |\
						GPIO19 | GPIO20 | GPIO21
	#define CONFIG_QCA_GPIO_MASK_IN		GPIO16
	#define CONFIG_QCA_GPIO_MASK_OUT_INIT_H	GPIO4

#elif defined(CONFIG_FOR_TPLINK_WA801ND_V2) ||\
      defined(CONFIG_FOR_TPLINK_WA830RE_V2)

	#define CONFIG_QCA_GPIO_MASK_LED_ACT_L	GPIO13 | GPIO14 | GPIO15 |\
						GPIO18
	#define CONFIG_QCA_GPIO_MASK_IN		GPIO16

#elif defined(CONFIG_FOR_TPLINK_WDR3500_V1)

	#define CONFIG_QCA_GPIO_MASK_LED_ACT_L	GPIO11 | GPIO13 | GPIO14 |\
						GPIO15 | GPIO18 | GPIO19 |\
						GPIO20 | GPIO21 | GPIO22
	#define CONFIG_QCA_GPIO_MASK_IN		GPIO17
	#define CONFIG_QCA_GPIO_MASK_OUT_INIT_H	GPIO12

#elif defined(CONFIG_FOR_TPLINK_WDR3600_V1) ||\
      defined(CONFIG_FOR_TPLINK_WDR43X0_V1)

	#define CONFIG_QCA_GPIO_MASK_LED_ACT_L	GPIO11 | GPIO12 | GPIO13 |\
						GPIO14 | GPIO15
	#define CONFIG_QCA_GPIO_MASK_IN		GPIO17
	#define CONFIG_QCA_GPIO_MASK_OUT_INIT_H	GPIO21 | GPIO22

#elif defined(CONFIG_FOR_TPLINK_WR1041N_V2)

	#define CONFIG_QCA_GPIO_MASK_LED_ACT_L	GPIO11 | GPIO12 | GPIO13

#elif defined(CONFIG_FOR_TPLINK_WR841N_V8)

	#define CONFIG_QCA_GPIO_MASK_LED_ACT_L	GPIO12 | GPIO13 | GPIO14 |\
						GPIO15 | GPIO18 | GPIO19 |\
						GPIO20 | GPIO21
	#define CONFIG_QCA_GPIO_MASK_IN		GPIO16

#elif defined(CONFIG_FOR_KISSLINK_NB1210)

	#define CONFIG_QCA_GPIO_MASK_LED_ACT_L	GPIO18

#elif defined(CONFIG_FOR_YUNCORE_CPE870)

	#define CONFIG_QCA_GPIO_MASK_LED_ACT_L	GPIO0 | GPIO1  | GPIO2  |\
						GPIO3 | GPIO13 | GPIO19 |\
						GPIO20

#endif

/*
 * ================
 * Default bootargs
 * ================
 */
#if defined(CONFIG_FOR_ALFA_NETWORK_N5Q)

	#define CONFIG_BOOTARGS	"console=ttyS0,115200 root=31:03 "\
				"rootfstype=jffs2,squashfs init=/sbin/init "\
				"mtdparts=ath-nor0:448k(u-boot),64k(art),1280k(kernel),14528k(rootfs),64k(config)"

#elif defined(CONFIG_FOR_ENGENIUS_ENS202EXT)

	#define CONFIG_BOOTARGS	"console=ttyS0,115200 root=31:04 "\
				"rootfstype=squashfs init=/etc/preinit "\
				"mtdparts=spi0.0:256k(u-boot)ro,64k(u-boot-env),320k(custom),1536k(kernel),12096k(rootfs),2048k(failsafe),64k(art)ro"

#elif defined(CONFIG_FOR_GLINET_GL_AR300)

	#define CONFIG_BOOTARGS	"console=ttyATH0,115200 root=31:02 "\
				"rootfstype=squashfs init=/sbin/init "\
				"mtdparts=ath-nor0:256k(u-boot),64k(u-boot-env),16000k(firmware),64k(art)ro"

#elif defined(CONFIG_FOR_TPLINK_WDR3500_V1) ||\
      defined(CONFIG_FOR_TPLINK_WDR3600_V1) ||\
      defined(CONFIG_FOR_TPLINK_WDR43X0_V1)

	#define CONFIG_BOOTARGS	"console=ttyS0,115200 root=31:02 "\
				"rootfstype=squashfs init=/sbin/init "\
				"mtdparts=ath-nor0:256k(u-boot),64k(u-boot-env),6336k(rootfs),1408k(uImage),64k(mib0),64k(art)"

#elif defined(CONFIG_FOR_YUNCORE_CPE870)

	#define CONFIG_BOOTARGS	"console=ttyS0,115200 root=31:02 "\
				"rootfstype=squashfs,jffs2 init=/sbin/init "\
				"mtdparts=ath-nor0:64k(u-boot),64k(u-boot-env),6528k(rootfs),1408K(uImage)"\
				",7936k@0x20000(firmware),64k(NVRAM),64k(ART),8128k@0x00000(firmware2)"

#else

	#define CONFIG_BOOTARGS	"console=ttyS0,115200 root=31:02 "\
				"rootfstype=squashfs init=/sbin/init "\
				"mtdparts=ath-nor0:128k(u-boot),1024k(kernel),2816k(rootfs),64k(config),64k(art)"

#endif

/*
 * =============================
 * Load address and boot command
 * =============================
 */
#if defined(CONFIG_FOR_ALFA_NETWORK_N5Q)

	#define CFG_LOAD_ADDR		0x9F080000

#elif defined(CONFIG_FOR_ENGENIUS_ENS202EXT)

	#define CFG_LOAD_ADDR		0x9F0A0000

#elif defined(CONFIG_FOR_GLINET_GL_AR300)

	#define CFG_LOAD_ADDR		0x9F050000

#elif defined(CONFIG_FOR_YUNCORE_CPE870)

	#define CFG_LOAD_ADDR		0x9F680000

#else

	#define CFG_LOAD_ADDR		0x9F020000

#endif

#define CONFIG_BOOTCOMMAND	"bootm " MK_STR(CFG_LOAD_ADDR)

/*
 * =========================
 * Environment configuration
 * =========================
 */
#if defined(CONFIG_FOR_ALFA_NETWORK_N5Q)

	#define CFG_ENV_ADDR		0x9F060000
	#define CFG_ENV_SIZE		0x10000

#elif defined(CONFIG_FOR_ENGENIUS_ENS202EXT)

	#define CFG_ENV_ADDR		0x9F040000
	#define CFG_ENV_SIZE		0x10000
	#define CFG_ENV_SECT_SIZE	0x10000

#elif defined(CONFIG_FOR_GLINET_GL_AR300)

	#define CFG_ENV_ADDR		0x9F040000
	#define CFG_ENV_SIZE		0xFC00
	#define CFG_ENV_SECT_SIZE	0x10000

#elif defined(CONFIG_FOR_YUNCORE_CPE870)

	#define CFG_ENV_ADDR		0x9F020000
	#define CFG_ENV_SIZE		0xFC00
	#define CFG_ENV_SECT_SIZE	0x10000

#else

	#define CFG_ENV_ADDR		0x9F01EC00
	#define CFG_ENV_SIZE		0x1000
	#define CFG_ENV_SECT_SIZE	0x10000

#endif

/*
 * ===========================
 * List of available baudrates
 * ===========================
 */
#define CFG_BAUDRATE_TABLE	\
		{ 600,    1200,   2400,    4800,    9600,    14400, \
		  19200,  28800,  38400,   56000,   57600,   115200 }

/*
 * ==================================================
 * MAC address/es, model and WPS pin offsets in FLASH
 * ==================================================
 */
#if defined(CONFIG_FOR_ALFA_NETWORK_N5Q)

	#define OFFSET_MAC_DATA_BLOCK		0x70000
	#define OFFSET_MAC_DATA_BLOCK_LENGTH	0x10000
	#define OFFSET_MAC_ADDRESS		0x00000

#elif defined(CONFIG_FOR_GLINET_GL_AR300) ||\
      defined(CONFIG_FOR_YUNCORE_CPE870)

	#define OFFSET_MAC_DATA_BLOCK		0xFF0000
	#define OFFSET_MAC_DATA_BLOCK_LENGTH	0x010000
	#define OFFSET_MAC_ADDRESS		0x000000

#else

	#define OFFSET_MAC_DATA_BLOCK		0x010000
	#define OFFSET_MAC_DATA_BLOCK_LENGTH	0x010000
	#define OFFSET_MAC_ADDRESS		0x00FC00
	#define OFFSET_ROUTER_MODEL		0x00FD00
	#define OFFSET_PIN_NUMBER		0x00FE00

#endif

/*
 * =========================
 * Custom changes per device
 * =========================
 */

/*
 * YunCore CPE870 is limited to 64 KB only,
 * disable some commands
 */
#if defined(CONFIG_FOR_YUNCORE_CPE870)

	#undef CONFIG_CMD_DHCP
	#undef CONFIG_CMD_IMI
	#undef CONFIG_CMD_LOADB
	#undef CONFIG_CMD_MAC
	#undef CONFIG_CMD_SNTP
	#undef CONFIG_UPG_SCRIPTS_FW
	#undef CONFIG_UPG_SCRIPTS_UBOOT

#endif

/*
 * ===========================
 * HTTP recovery configuration
 * ===========================
 */
#if defined(CONFIG_FOR_YUNCORE_CPE870)

	#define WEBFAILSAFE_UPLOAD_KERNEL_ADDRESS	CFG_FLASH_BASE + 0x20000

#else

	#define WEBFAILSAFE_UPLOAD_KERNEL_ADDRESS	CFG_LOAD_ADDR

#endif

#if defined(CONFIG_FOR_ALFA_NETWORK_N5Q)

	#define WEBFAILSAFE_UPLOAD_ART_ADDRESS	(CFG_FLASH_BASE + 0x70000)

#endif

/* Firmware size limit */
#if defined(CONFIG_FOR_ALFA_NETWORK_N5Q)

	#define WEBFAILSAFE_UPLOAD_LIMITED_AREA_IN_BYTES	(512 * 1024)

#elif defined(CONFIG_FOR_ENGENIUS_ENS202EXT)

	#define WEBFAILSAFE_UPLOAD_LIMITED_AREA_IN_BYTES	(2752 * 1024)

#elif defined(CONFIG_FOR_GLINET_GL_AR300)

	#define WEBFAILSAFE_UPLOAD_LIMITED_AREA_IN_BYTES	(384 * 1024)

#elif defined(CONFIG_FOR_YUNCORE_CPE870)

	#define WEBFAILSAFE_UPLOAD_LIMITED_AREA_IN_BYTES	(256 * 1024)

#else

	#define WEBFAILSAFE_UPLOAD_LIMITED_AREA_IN_BYTES	(192 * 1024)

#endif

/*
 * ========================
 * PLL/Clocks configuration
 * ========================
 */
#define CONFIG_QCA_PLL	QCA_PLL_PRESET_550_400_200

#if defined(CONFIG_FOR_ALFA_NETWORK_N5Q)

	#define CONFIG_QCA_PLL_IN_FLASH_BLOCK_OFFSET	0x70000
	#define CONFIG_QCA_PLL_IN_FLASH_BLOCK_SIZE	0x10000

#elif defined(CONFIG_FOR_GLINET_GL_AR300)

	#define CONFIG_QCA_PLL_IN_FLASH_BLOCK_OFFSET	0x40000
	#define CONFIG_QCA_PLL_IN_FLASH_BLOCK_SIZE	0x10000

#elif defined(CONFIG_FOR_TPLINK_MR3420_V2)  ||\
      defined(CONFIG_FOR_TPLINK_WA801ND_V2) ||\
      defined(CONFIG_FOR_TPLINK_WA830RE_V2) ||\
      defined(CONFIG_FOR_TPLINK_WDR3500_V1) ||\
      defined(CONFIG_FOR_TPLINK_WDR3600_V1) ||\
      defined(CONFIG_FOR_TPLINK_WDR43X0_V1) ||\
      defined(CONFIG_FOR_TPLINK_WR1041N_V2) ||\
      defined(CONFIG_FOR_TPLINK_WR841N_V8)  ||\
      defined(CONFIG_FOR_KISSLINK_NB1210)  ||\
      defined(CONFIG_FOR_YUNCORE_CPE870)

	#define CONFIG_QCA_PLL_IN_FLASH_BLOCK_OFFSET	0x10000
	#define CONFIG_QCA_PLL_IN_FLASH_BLOCK_SIZE	0x10000

#endif

/*
 * ==================================
 * For upgrade scripts in environment
 * ==================================
 */
#if !defined(CONFIG_FOR_ALFA_NETWORK_N5Q)   &&\
    !defined(CONFIG_FOR_ENGENIUS_ENS202EXT) &&\
    !defined(CONFIG_FOR_GLINET_GL_AR300)    &&\
    !defined(CONFIG_FOR_YUNCORE_CPE870)

	#define CONFIG_UPG_UBOOT_SIZE_BACKUP_HEX	0x20000

#endif

#if defined(CONFIG_FOR_YUNCORE_CPE870)

	#define CONFIG_UPG_SCRIPTS_FW_ADDR_HEX	0x9F020000

#endif

/*
 * ===================
 * Other configuration
 * ===================
 */

/* Cache lock for stack */
#define CONFIG_INIT_SRAM_SP_OFFSET	0xbd007000

#endif /* _DB12X_H */
