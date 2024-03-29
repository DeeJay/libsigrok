##
## This file is part of the libsigrok project.
##
## Copyright (C) 2010-2012 Bert Vermeulen <bert@biot.com>
## Copyright (C) 2012 Alexandru Gagniuc <mr.nuke.me@gmail.com>
##
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <http://www.gnu.org/licenses/>.
##

# We require at least autoconf 2.63 (AC_INIT format changed there).
AC_PREREQ([2.63])

# libsigrok package version number (NOT the same as shared lib version!).
m4_define([sr_package_version_major], [0])
m4_define([sr_package_version_minor], [3])
m4_define([sr_package_version_micro], [0])
m4_define([sr_package_version], [sr_package_version_major.sr_package_version_minor.sr_package_version_micro])

AC_INIT([libsigrok], [sr_package_version], [sigrok-devel@lists.sourceforge.net],
	[libsigrok], [http://www.sigrok.org])
AC_CONFIG_HEADER([config.h])
AC_CONFIG_MACRO_DIR([autostuff])
AC_CONFIG_AUX_DIR([autostuff])

# We require at least automake 1.11 (needed for 'silent rules').
AM_INIT_AUTOMAKE([1.11 -Wall -Werror subdir-objects check-news color-tests])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])
m4_ifdef([AM_PROG_AR], [AM_PROG_AR])

AH_TOP([#ifndef SR_CONFIG_H
#define SR_CONFIG_H    /* To stop multiple inclusions. */])
AH_BOTTOM([#endif /* SR_CONFIG_H */])

# Enable more compiler warnings via -Wall and -Wextra. Add -fvisibility=hidden
# and enforce use of SR_API to explicitly mark all public API functions.
COMMON_FLAGS="$CFLAGS -Wall -Wextra -fvisibility=hidden"
CFLAGS="$COMMON_FLAGS -Wmissing-prototypes"

# Checks for programs.
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S

# Required for per-target flags or subdir-objects with C sources.
AM_PROG_CC_C_O

# Initialize libtool.
LT_INIT

# Initialize pkg-config.
# We require at least 0.22, as "Requires.private" behaviour changed there.
PKG_PROG_PKG_CONFIG([0.22])

# Library version for libsigrok (NOT the same as the package version).
# Carefully read the libtool docs before updating these numbers!
# The algorithm for determining which number to change (and how) is nontrivial!
# http://www.gnu.org/software/libtool/manual/libtool.html#Updating-version-info
SR_LIB_VERSION_CURRENT=2
SR_LIB_VERSION_REVISION=0
SR_LIB_VERSION_AGE=0
SR_LIB_VERSION="$SR_LIB_VERSION_CURRENT:$SR_LIB_VERSION_REVISION:$SR_LIB_VERSION_AGE"
SR_LIB_LDFLAGS="-version-info $SR_LIB_VERSION"
AC_SUBST(SR_LIB_VERSION_CURRENT)
AC_SUBST(SR_LIB_VERSION_REVISION)
AC_SUBST(SR_LIB_VERSION_AGE)
AC_SUBST(SR_LIB_VERSION)
AC_SUBST(SR_LIB_LDFLAGS)

# Hardware support '--enable' options.

AC_ARG_ENABLE(all-drivers, AC_HELP_STRING([--enable-all-drivers],
	[enable all drivers by default [default=yes]]),
	[HW_ENABLED_DEFAULT="$enableval"],
	[HW_ENABLED_DEFAULT="yes"])

AC_ARG_ENABLE(agilent-dmm, AC_HELP_STRING([--enable-agilent-dmm],
	[enable Agilent DMM support [default=yes]]),
	[HW_AGILENT_DMM="$enableval"],
	[HW_AGILENT_DMM=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(appa-55ii, AC_HELP_STRING([--enable-appa-55ii],
	[enable APPA 55II support [default=yes]]),
	[HW_APPA_55II="$enableval"],
	[HW_APPA_55II=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(asix-sigma, AC_HELP_STRING([--enable-asix-sigma],
	[enable ASIX SIGMA/SIGMA2 support [default=yes]]),
	[HW_ASIX_SIGMA="$enableval"],
	[HW_ASIX_SIGMA=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(atten-pps3xxx, AC_HELP_STRING([--enable-atten-pps3xxx],
	[enable Atten PPS3xxx support [default=yes]]),
	[HW_ATTEN_PPS3XXX="$enableval"],
	[HW_ATTEN_PPS3XXX=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(brymen-bm86x, AC_HELP_STRING([--enable-brymen-bm86x],
	[enable Brymen BM86X support [default=yes]]),
	[HW_BRYMEN_BM86X="$enableval"],
	[HW_BRYMEN_BM86X=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(brymen-dmm, AC_HELP_STRING([--enable-brymen-dmm],
	[enable Brymen DMM support [default=yes]]),
	[HW_BRYMEN_DMM="$enableval"],
	[HW_BRYMEN_DMM=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(cem-dt-885x, AC_HELP_STRING([--enable-cem-dt-885x],
	[enable CEM DT-885x support [default=yes]]),
	[HW_CEM_DT_885X="$enableval"],
	[HW_CEM_DT_885X=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(center-3xx, AC_HELP_STRING([--enable-center-3xx],
	[enable Center 3xx support [default=yes]]),
	[HW_CENTER_3XX="$enableval"],
	[HW_CENTER_3XX=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(chronovu-la, AC_HELP_STRING([--enable-chronovu-la],
	[enable ChronoVu LA support [default=yes]]),
	[HW_CHRONOVU_LA="$enableval"],
	[HW_CHRONOVU_LA=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(colead-slm, AC_HELP_STRING([--enable-colead-slm],
	[enable Colead SLM support [default=yes]]),
	[HW_COLEAD_SLM="$enableval"],
	[HW_COLEAD_SLM=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(conrad-digi-35-cpu, AC_HELP_STRING([--enable-conrad-digi-35-cpu],
	[enable Conrad DIGI 35 CPU support [default=yes]]),
	[HW_CONRAD_DIGI_35_CPU="$enableval"],
	[HW_CONRAD_DIGI_35_CPU=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(demo, AC_HELP_STRING([--enable-demo],
	[enable demo driver support [default=yes]]),
	[HW_DEMO="$enableval"],
	[HW_DEMO=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(dpscopese, AC_HELP_STRING([--enable-dpscopese],
	[enable DPScopeSE support [default=yes]]),
	[HW_DPSCOPESE="$enableval"],
	[HW_DPSCOPESE=$HW_ENABLED_DEFAULT])
AM_CONDITIONAL(HW_DPSCOPESE, test x$HW_DPSCOPESE = xyes)
if test "x$HW_DPSCOPESE" = "xyes"; then
	AC_DEFINE(HAVE_HW_DPSCOPESE, 1, [DPScopeSE support])
fi

AC_ARG_ENABLE(fluke-dmm, AC_HELP_STRING([--enable-fluke-dmm],
	[enable Fluke DMM support [default=yes]]),
	[HW_FLUKE_DMM="$enableval"],
	[HW_FLUKE_DMM=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(fx2lafw, AC_HELP_STRING([--enable-fx2lafw],
	[enable fx2lafw support (for FX2 LAs). [default=yes]]),
	[HW_FX2LAFW="$enableval"],
	[HW_FX2LAFW=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(gmc-mh-1x-2x, AC_HELP_STRING([--enable-gmc-mh-1x-2x],
	[enable gmc-mh-1x-2x support [default=yes]]),
	[HW_GMC_MH_1X_2X="$enableval"],
	[HW_GMC_MH_1X_2X=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(hameg-hmo, AC_HELP_STRING([--enable-hameg-hmo],
	[enable Hameg HMO support [default=yes]]),
	[HW_HAMEG_HMO="$enableval"],
	[HW_HAMEG_HMO=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(hantek-dso, AC_HELP_STRING([--enable-hantek-dso],
	[enable Hantek DSO support [default=yes]]),
	[HW_HANTEK_DSO="$enableval"],
	[HW_HANTEK_DSO=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(ikalogic-scanalogic2, AC_HELP_STRING([--enable-ikalogic-scanalogic2],
	[enable IKALOGIC Scanalogic-2 support [default=yes]]),
	[HW_IKALOGIC_SCANALOGIC2="$enableval"],
	[HW_IKALOGIC_SCANALOGIC2=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(ikalogic-scanaplus, AC_HELP_STRING([--enable-ikalogic-scanaplus],
	[enable IKALOGIC ScanaPLUS support [default=yes]]),
	[HW_IKALOGIC_SCANAPLUS="$enableval"],
	[HW_IKALOGIC_SCANAPLUS=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(kecheng-kc-330b, AC_HELP_STRING([--enable-kecheng-kc-330b],
	[enable Kecheng KC-330B support [default=yes]]),
	[HW_KECHENG_KC_330B="$enableval"],
	[HW_KECHENG_KC_330B=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(lascar-el-usb, AC_HELP_STRING([--enable-lascar-el-usb],
	[enable Lascar EL-USB support [default=yes]]),
	[HW_LASCAR_EL_USB="$enableval"],
	[HW_LASCAR_EL_USB=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(mic-985xx, AC_HELP_STRING([--enable-mic-985xx],
	[enable MIC 985xx support [default=yes]]),
	[HW_MIC_985XX="$enableval"],
	[HW_MIC_985XX=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(motech-lps-30x, AC_HELP_STRING([--enable-motech-lps-30x],
	[enable motech-lps-30x support [default=yes]]),
	[HW_MOTECH_LPS_30X="$enableval"],
	[HW_MOTECH_LPS_30X=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(norma-dmm, AC_HELP_STRING([--enable-norma-dmm],
	[enable Norma DMM support [default=yes]]),
	[HW_NORMA_DMM="$enableval"],
	[HW_NORMA_DMM=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(ols, AC_HELP_STRING([--enable-ols],
	[enable OpenBench Logic Sniffer (OLS) support [default=yes]]),
	[HW_OLS="$enableval"],
	[HW_OLS=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(rigol-ds, AC_HELP_STRING([--enable-rigol-ds],
	[enable Rigol DS support [default=yes]]),
	[HW_RIGOL_DS="$enableval"],
	[HW_RIGOL_DS=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(saleae-logic16, AC_HELP_STRING([--enable-saleae-logic16],
	[enable Saleae Logic16 support [default=yes]]),
	[HW_SALEAE_LOGIC16="$enableval"],
	[HW_SALEAE_LOGIC16=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(serial-dmm, AC_HELP_STRING([--enable-serial-dmm],
	[enable serial DMM support [default=yes]]),
	[HW_SERIAL_DMM="$enableval"],
	[HW_SERIAL_DMM=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(sysclk-lwla, AC_HELP_STRING([--enable-sysclk-lwla],
	[enable Sysclk LWLA support [default=yes]]),
	[HW_SYSCLK_LWLA="$enableval"],
	[HW_SYSCLK_LWLA=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(teleinfo, AC_HELP_STRING([--enable-teleinfo],
	[enable Teleinfo support [default=yes]]),
	[HW_TELEINFO="$enableval"],
	[HW_TELEINFO=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(tondaj-sl-814, AC_HELP_STRING([--enable-tondaj-sl-814],
	[enable Tondaj SL-814 support [default=yes]]),
	[HW_TONDAJ_SL_814="$enableval"],
	[HW_TONDAJ_SL_814=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(uni-t-dmm, AC_HELP_STRING([--enable-uni-t-dmm],
	[enable UNI-T DMM support [default=yes]]),
	[HW_UNI_T_DMM="$enableval"],
	[HW_UNI_T_DMM=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(uni-t-ut32x, AC_HELP_STRING([--enable-uni-t-ut32x],
	[enable UNI-T UT32x support [default=yes]]),
	[HW_UNI_T_UT32X="$enableval"],
	[HW_UNI_T_UT32X=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(victor-dmm, AC_HELP_STRING([--enable-victor-dmm],
	[enable victor-dmm support [default=yes]]),
	[HW_VICTOR_DMM="$enableval"],
	[HW_VICTOR_DMM=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(zeroplus-logic-cube,
	AC_HELP_STRING([--enable-zeroplus-logic-cube],
	[enable ZEROPLUS Logic Cube support [default=yes]]),
	[HW_ZEROPLUS_LOGIC_CUBE="$enableval"],
	[HW_ZEROPLUS_LOGIC_CUBE=$HW_ENABLED_DEFAULT])

AC_ARG_ENABLE(libserialport,
	AC_HELP_STRING([--disable-libserialport],
	[disable libserialport support [default=detect]]))

AC_ARG_ENABLE(libftdi,
	AC_HELP_STRING([--disable-libftdi],
	[disable libftdi support [default=detect]]))

AC_ARG_ENABLE(libusb,
	AC_HELP_STRING([--disable-libusb],
	[disable libusb support [default=detect]]))

# Checks for libraries.

case "$host" in
*mingw*)
	# We need to link against the Winsock2 library for SCPI over TCP.
	LIBS="$LIBS -lws2_32";;
esac

# This variable collects the pkg-config names of all detected libs.
# It is then used to construct the "Requires.private:" field in the
# libsigrok.pc file.
SR_PKGLIBS=""

# libm (the standard math library) is always needed.
AC_SEARCH_LIBS([pow], [m])

# RPC is only needed for VXI support.
AC_MSG_CHECKING([for RPC support])
AC_LINK_IFELSE([AC_LANG_PROGRAM([#include <rpc/rpc.h>],
				[CLIENT *rpc_test(void)],
				[{ return clnt_create("", 0, 0, ""); }])],
	       [AC_MSG_RESULT([yes]); have_rpc=1],
	       [AC_MSG_RESULT([no]);  have_rpc=0])
# Define HAVE_RPC in config.h if we found RPC support.
AC_DEFINE_UNQUOTED(HAVE_RPC, [$have_rpc], [Specifies whether we have RPC support.])
# VXI support is only compiled if RPC support was found.
AM_CONDITIONAL(NEED_RPC, test "x$have_rpc" != "x0")

# libglib-2.0 is always needed. Abort if it's not found.
# Note: glib-2.0 is part of the libsigrok API (hard pkg-config requirement).
# We require at least 2.32.0 due to e.g. g_variant_new_fixed_array().
AM_PATH_GLIB_2_0([2.32.0],
	[LIB_CFLAGS="$LIB_CFLAGS $GLIB_CFLAGS"; LIBS="$LIBS $GLIB_LIBS"])

# libzip is always needed. Abort if it's not found.
PKG_CHECK_MODULES([libzip], [libzip >= 0.10],
	[LIB_CFLAGS="$LIB_CFLAGS $libzip_CFLAGS"; LIBS="$LIBS $libzip_LIBS";
	SR_PKGLIBS="$SR_PKGLIBS libzip"])

# libserialport is only needed for some hardware drivers. Disable the
# respective drivers if it is not found.
if test "x$enable_libserialport" != "xno"; then
	PKG_CHECK_MODULES([libserialport], [libserialport >= 0.1.0],
		[have_libserialport="yes"; LIB_CFLAGS="$LIB_CFLAGS $libserialport_CFLAGS";
		LIBS="$LIBS $libserialport_LIBS";
		SR_PKGLIBS="$SR_PKGLIBS libserialport"],
		[have_libserialport="no"])
	if test "x$enable_libserialport$have_libserialport" = "xyesno"; then
		AC_MSG_ERROR([libserialport support requested, but it was not found])
	fi
else
	have_libserialport="no"
fi

# Define HAVE_LIBSERIALPORT in config.h if we found libserialport.
if test "x$have_libserialport" = "xno"; then
	HW_AGILENT_DMM="no"; HW_APPA_55II="no";
	HW_ATTEN_PPS3XXX="no"; HW_BRYMEN_DMM="no"; HW_CEM_DT_885X="no";
	HW_CENTER_3XX="no"; HW_COLEAD_SLM="no"; HW_CONRAD_DIGI_35_CPU="no";
	HW_FLUKE_DMM="no"; HW_GMC_MH_1X_2X="no"; HW_HAMEG_HMO="no";
	HW_MIC_985XX="no"; HW_MOTECH_LPS_30X="no"; HW_NORMA_DMM="no";
	HW_OLS="no"; HW_SERIAL_DMM="no"; HW_TELEINFO="no";
	HW_TONDAJ_SL_814="no";
else
	AC_DEFINE_UNQUOTED(HAVE_LIBSERIALPORT, [1],
		[Specifies whether we have libserialport.])
fi

# Serial port helper code is only compiled in if libserialport was found.
AM_CONDITIONAL(NEED_SERIAL, test "x$have_libserialport" != xno)

PKG_CHECK_MODULES([librevisa], [librevisa >= 0.0.20130812],
	[have_librevisa="yes"; LIB_CFLAGS="$LIB_CFLAGS $librevisa_CFLAGS";
	LIBS="$LIBS $librevisa_LIBS";
	SR_PKGLIBS="$SR_PKGLIBS librevisa"],
	[have_librevisa="no"])

# VISA SCPI backend is only compiled in if librevisa was found.
AM_CONDITIONAL(NEED_VISA, test "x$have_librevisa" != xno)

# Define HAVE_LIBREVISA in config.h if we found librevisa.
if test "x$have_librevisa" != "xno"; then
	AC_DEFINE_UNQUOTED(HAVE_LIBREVISA, [1],
		[Specifies whether we have librevisa.])
fi

# libusb-1.0 is only needed for some hardware drivers. Disable the respective
# drivers if it is not found.
if test "x$enable_libusb" != "xno"; then
	case "$host" in
	*freebsd*)
		# FreeBSD comes with an "integrated" libusb-1.0-style USB API.
		# This means libusb-1.0 is always available, no need to check for it,
		# and no need to (potentially) disable any drivers if it's not found.
		have_libusb1_0="yes"
		;;
	*)
		PKG_CHECK_MODULES([libusb], [libusb-1.0 >= 1.0.16],
			[have_libusb1_0="yes"; LIB_CFLAGS="$LIB_CFLAGS $libusb_CFLAGS";
			LIBS="$LIBS $libusb_LIBS";
			SR_PKGLIBS="$SR_PKGLIBS libusb-1.0"],
			[have_libusb1_0="no"])
		if test "x$enable_libusb$have_libusb1_0" = "xyesno"; then
			AC_MSG_ERROR([libusb support requested, but it was not found])
		fi
		;;
	esac
else
	have_libusb1_0="no"
fi

# Define HAVE_LIBUSB_1_0 in config.h if we found libusb-1.0.
if test "x$have_libusb1_0" = "xno"; then
	HW_BRYMEN_BM86X="no"; HW_FX2LAFW="no";
	HW_HANTEK_DSO="no"; HW_IKALOGIC_SCANALOGIC2="no";
	HW_KECHENG_KC_330B="no"; HW_LASCAR_EL_USB="no";
	HW_SYSCLK_LWLA="no"; HW_UNI_T_DMM="no";
	HW_UNI_T_UT32X="no"; HW_VICTOR_DMM="no";
	HW_ZEROPLUS_LOGIC_CUBE="no"; HW_SALEAE_LOGIC16="no";
else
	AC_DEFINE_UNQUOTED(HAVE_LIBUSB_1_0, [1],
		[Specifies whether we have a libusb.h header.])
fi

# USB + FX2 firmware helper code is only compiled in if libusb-1.0 was found.
AM_CONDITIONAL(NEED_USB, test "x$have_libusb1_0" != xno)

# libftdi is only needed for some hardware drivers. Disable them if not found.
if test "x$enable_libftdi" != "xno"; then
	PKG_CHECK_MODULES([libftdi], [libftdi >= 0.16],
		[have_libftdi="yes"; LIB_CFLAGS="$LIB_CFLAGS $libftdi_CFLAGS";
		LIBS="$LIBS $libftdi_LIBS";
		SR_PKGLIBS="$SR_PKGLIBS libftdi"],
		[PKG_CHECK_MODULES([libftdi1], [libftdi1 >= 1.0],
			[LIB_CFLAGS="$LIB_CFLAGS $libftdi1_CFLAGS";
			LIBS="$LIBS $libftdi1_LIBS";
			SR_PKGLIBS="$SR_PKGLIBS libftdi1"],
			[have_libftdi="no"])])
	if test "x$enable_libftdi$have_libftdi" = "xyesno"; then
		AC_MSG_ERROR([libftdi support requested, but it was not found])
	fi
else
	have_libftdi="no"
fi

if test "x$have_libftdi" = "xno"; then
	HW_ASIX_SIGMA="no"; HW_CHRONOVU_LA="no"; HW_IKALOGIC_SCANAPLUS="no";
fi

# The Check unit testing framework is optional. Disable if not found.
PKG_CHECK_MODULES([check], [check >= 0.9.4],
	[have_check="yes"], [have_check="no"])
AM_CONDITIONAL(HAVE_CHECK, test x"$have_check" = "xyes")

# The OLS driver uses serial port file descriptors directly, and therefore
# will not currently work on Windows.
case "$host" in
*mingw*)
	HW_OLS="no"
	;;
esac

AC_SUBST(SR_PKGLIBS)

CFLAGS="$CFLAGS $LIB_CFLAGS"

# Now set AM_CONDITIONALs and AC_DEFINEs for the enabled/disabled drivers.

AM_CONDITIONAL(HW_AGILENT_DMM, test x$HW_AGILENT_DMM = xyes)
if test "x$HW_AGILENT_DMM" = "xyes"; then
	AC_DEFINE(HAVE_HW_AGILENT_DMM, 1, [Agilent DMM support])
fi

AM_CONDITIONAL(HW_APPA_55II, test x$HW_APPA_55II = xyes)
if test "x$HW_APPA_55II" = "xyes"; then
	AC_DEFINE(HAVE_HW_APPA_55II, 1, [APPA 55II support])
fi

AM_CONDITIONAL(HW_ASIX_SIGMA, test x$HW_ASIX_SIGMA = xyes)
if test "x$HW_ASIX_SIGMA" = "xyes"; then
	AC_DEFINE(HAVE_HW_ASIX_SIGMA, 1, [ASIX SIGMA/SIGMA2 support])
fi

AM_CONDITIONAL(HW_ATTEN_PPS3XXX, test x$HW_ATTEN_PPS3XXX = xyes)
if test "x$HW_ATTEN_PPS3XXX" = "xyes"; then
	AC_DEFINE(HAVE_HW_ATTEN_PPS3XXX, 1, [Atten PPS3xxx support])
fi

AM_CONDITIONAL(HW_BRYMEN_BM86X, test x$HW_BRYMEN_BM86X = xyes)
if test "x$HW_BRYMEN_BM86X" = "xyes"; then
	AC_DEFINE(HAVE_HW_BRYMEN_BM86X, 1, [Brymen BM86X support])
fi

AM_CONDITIONAL(HW_BRYMEN_DMM, test x$HW_BRYMEN_DMM = xyes)
if test "x$HW_BRYMEN_DMM" = "xyes"; then
	AC_DEFINE(HAVE_HW_BRYMEN_DMM, 1, [Brymen DMM support])
fi

AM_CONDITIONAL(HW_CEM_DT_885X, test x$HW_CEM_DT_885X = xyes)
if test "x$HW_CEM_DT_885X" = "xyes"; then
	AC_DEFINE(HAVE_HW_CEM_DT_885X, 1, [CEM DT-885x support])
fi

AM_CONDITIONAL(HW_CENTER_3XX, test x$HW_CENTER_3XX = xyes)
if test "x$HW_CENTER_3XX" = "xyes"; then
	AC_DEFINE(HAVE_HW_CENTER_3XX, 1, [Center 3xx support])
fi

AM_CONDITIONAL(HW_CHRONOVU_LA, test x$HW_CHRONOVU_LA = xyes)
if test "x$HW_CHRONOVU_LA" = "xyes"; then
	AC_DEFINE(HAVE_HW_CHRONOVU_LA, 1, [ChronoVu LA support])
fi

AM_CONDITIONAL(HW_COLEAD_SLM, test x$HW_COLEAD_SLM = xyes)
if test "x$HW_COLEAD_SLM" = "xyes"; then
	AC_DEFINE(HAVE_HW_COLEAD_SLM, 1, [Colead SLM support])
fi

AM_CONDITIONAL(HW_CONRAD_DIGI_35_CPU, test x$HW_CONRAD_DIGI_35_CPU = xyes)
if test "x$HW_CONRAD_DIGI_35_CPU" = "xyes"; then
	AC_DEFINE(HAVE_HW_CONRAD_DIGI_35_CPU, 1, [Conrad DIGI 35 CPU support])
fi

AM_CONDITIONAL(HW_DEMO, test x$HW_DEMO = xyes)
if test "x$HW_DEMO" = "xyes"; then
	AC_DEFINE(HAVE_HW_DEMO, 1, [Demo driver support])
fi

AM_CONDITIONAL(HW_FLUKE_DMM, test x$HW_FLUKE_DMM = xyes)
if test "x$HW_FLUKE_DMM" = "xyes"; then
	AC_DEFINE(HAVE_HW_FLUKE_DMM, 1, [Fluke DMM support])
fi

AM_CONDITIONAL(HW_FX2LAFW, test x$HW_FX2LAFW = xyes)
if test "x$HW_FX2LAFW" = "xyes"; then
	AC_DEFINE(HAVE_HW_FX2LAFW, 1, [fx2lafw support])
fi

AM_CONDITIONAL(HW_GMC_MH_1X_2X, test x$HW_GMC_MH_1X_2X = xyes)
if test "x$HW_GMC_MH_1X_2X" = "xyes"; then
	AC_DEFINE(HAVE_HW_GMC_MH_1X_2X, 1, [gmc-mh-1x-2x support])
fi

AM_CONDITIONAL(HW_HANTEK_DSO, test x$HW_HANTEK_DSO = xyes)
if test "x$HW_HANTEK_DSO" = "xyes"; then
	AC_DEFINE(HAVE_HW_HANTEK_DSO, 1, [Hantek DSO support])
fi

AM_CONDITIONAL(HW_HAMEG_HMO, test x$HW_HAMEG_HMO = xyes)
if test "x$HW_HAMEG_HMO" = "xyes"; then
	AC_DEFINE(HAVE_HW_HAMEG_HMO, 1, [Hameg HMO support])
fi

AM_CONDITIONAL(HW_IKALOGIC_SCANALOGIC2, test x$HW_IKALOGIC_SCANALOGIC2 = xyes)
if test "x$HW_IKALOGIC_SCANALOGIC2" = "xyes"; then
	AC_DEFINE(HAVE_HW_IKALOGIC_SCANALOGIC2, 1, [IKALOGIC Scanalogic-2 support])
fi

AM_CONDITIONAL(HW_IKALOGIC_SCANAPLUS, test x$HW_IKALOGIC_SCANAPLUS = xyes)
if test "x$HW_IKALOGIC_SCANAPLUS" = "xyes"; then
	AC_DEFINE(HAVE_HW_IKALOGIC_SCANAPLUS, 1, [IKALOGIC ScanaPLUS support])
fi

AM_CONDITIONAL(HW_KECHENG_KC_330B, test x$HW_KECHENG_KC_330B = xyes)
if test "x$HW_KECHENG_KC_330B" = "xyes"; then
	AC_DEFINE(HAVE_HW_KECHENG_KC_330B, 1, [Kecheng KC-330B support])
fi

AM_CONDITIONAL(HW_LASCAR_EL_USB, test x$HW_LASCAR_EL_USB = xyes)
if test "x$HW_LASCAR_EL_USB" = "xyes"; then
	AC_DEFINE(HAVE_HW_LASCAR_EL_USB, 1, [Lascar EL-USB support])
fi

AM_CONDITIONAL(HW_MIC_985XX, test x$HW_MIC_985XX = xyes)
if test "x$HW_MIC_985XX" = "xyes"; then
	AC_DEFINE(HAVE_HW_MIC_985XX, 1, [MIC 985xx support])
fi

AM_CONDITIONAL(HW_MOTECH_LPS_30X, test x$HW_MOTECH_LPS_30X = xyes)
if test "x$HW_MOTECH_LPS_30X" = "xyes"; then
	AC_DEFINE(HAVE_HW_MOTECH_LPS_30X, 1, [motech-lps-30x support])
fi

AM_CONDITIONAL(HW_NORMA_DMM, test x$HW_NORMA_DMM = xyes)
if test "x$HW_NORMA_DMM" = "xyes"; then
	AC_DEFINE(HAVE_HW_NORMA_DMM, 1, [Norma DMM support])
fi

AM_CONDITIONAL(HW_OLS, test x$HW_OLS = xyes)
if test "x$HW_OLS" = "xyes"; then
	AC_DEFINE(HAVE_HW_OLS, 1, [OpenBench Logic Sniffer (OLS) support])
fi

AM_CONDITIONAL(HW_RIGOL_DS, test x$HW_RIGOL_DS = xyes)
if test "x$HW_RIGOL_DS" = "xyes"; then
	AC_DEFINE(HAVE_HW_RIGOL_DS, 1, [Rigol DS support])
fi

AM_CONDITIONAL(HW_SALEAE_LOGIC16, test x$HW_SALEAE_LOGIC16 = xyes)
if test "x$HW_SALEAE_LOGIC16" = "xyes"; then
	AC_DEFINE(HAVE_HW_SALEAE_LOGIC16, 1, [Saleae Logic16 support])
fi

AM_CONDITIONAL(HW_SERIAL_DMM, test x$HW_SERIAL_DMM = xyes)
if test "x$HW_SERIAL_DMM" = "xyes"; then
	AC_DEFINE(HAVE_HW_SERIAL_DMM, 1, [Serial DMM support])
fi

AM_CONDITIONAL(HW_SYSCLK_LWLA, test x$HW_SYSCLK_LWLA = xyes)
if test "x$HW_SYSCLK_LWLA" = "xyes"; then
	AC_DEFINE(HAVE_HW_SYSCLK_LWLA, 1, [Sysclk LWLA support])
fi

AM_CONDITIONAL(HW_TELEINFO, test x$HW_TELEINFO = xyes)
if test "x$HW_TELEINFO" = "xyes"; then
	AC_DEFINE(HAVE_HW_TELEINFO, 1, [Teleinfo support])
fi

AM_CONDITIONAL(HW_TONDAJ_SL_814, test x$HW_TONDAJ_SL_814 = xyes)
if test "x$HW_TONDAJ_SL_814" = "xyes"; then
	AC_DEFINE(HAVE_HW_TONDAJ_SL_814, 1, [Tondaj SL-814 support])
fi

AM_CONDITIONAL(HW_UNI_T_DMM, test x$HW_UNI_T_DMM = xyes)
if test "x$HW_UNI_T_DMM" = "xyes"; then
	AC_DEFINE(HAVE_HW_UNI_T_DMM, 1, [UNI-T DMM support])
fi

AM_CONDITIONAL(HW_UNI_T_UT32X, test x$HW_UNI_T_UT32X = xyes)
if test "x$HW_UNI_T_UT32X" = "xyes"; then
	AC_DEFINE(HAVE_HW_UNI_T_UT32X, 1, [UNI-T UT32x support])
fi

AM_CONDITIONAL(HW_VICTOR_DMM, test x$HW_VICTOR_DMM = xyes)
if test "x$HW_VICTOR_DMM" = "xyes"; then
	AC_DEFINE(HAVE_HW_VICTOR_DMM, 1, [Victor DMM support])
fi

AM_CONDITIONAL(HW_ZEROPLUS_LOGIC_CUBE, test x$HW_ZEROPLUS_LOGIC_CUBE = xyes)
if test "x$HW_ZEROPLUS_LOGIC_CUBE" = "xyes"; then
	AC_DEFINE(HAVE_HW_ZEROPLUS_LOGIC_CUBE, 1, [ZEROPLUS Logic Cube support])
fi

# Checks for header files.
# These are already checked: inttypes.h stdint.h stdlib.h string.h unistd.h.

# Checks for typedefs, structures, and compiler characteristics.
AC_C_BIGENDIAN

AC_SUBST(FIRMWARE_DIR, "$datadir/sigrok-firmware")
AC_SUBST(MAKEFLAGS, '--no-print-directory')
AC_SUBST(AM_LIBTOOLFLAGS, '--silent')

SR_PACKAGE_VERSION_MAJOR=sr_package_version_major
SR_PACKAGE_VERSION_MINOR=sr_package_version_minor
SR_PACKAGE_VERSION_MICRO=sr_package_version_micro
SR_PACKAGE_VERSION=sr_package_version

AC_SUBST(SR_PACKAGE_VERSION_MAJOR)
AC_SUBST(SR_PACKAGE_VERSION_MINOR)
AC_SUBST(SR_PACKAGE_VERSION_MICRO)
AC_SUBST(SR_PACKAGE_VERSION)

AC_CONFIG_FILES([Makefile version.h libsigrok.pc])

AC_OUTPUT

echo
echo "libsigrok configuration summary:"
echo
echo "  - Package version (major.minor.micro):    $SR_PACKAGE_VERSION"
echo "  - Library version (current:revision:age): $SR_LIB_VERSION"
echo "  - Prefix: $prefix"
echo "  - Building on: $build"
echo "  - Building for: $host"
echo
echo "Detected libraries:"
echo

# Note: This only works for libs with pkg-config integration.
for lib in "glib-2.0 >= 2.32.0" "libzip >= 0.10" "libserialport >= 0.1.0" "librevisa >= 0.0.20130812" "libusb-1.0 >= 1.0.16" "libftdi >= 0.16" "libftdi1 >= 1.0" "check >= 0.9.4"; do
	optional="OPTIONAL"
	if test "x$lib" = "xglib-2.0 >= 2.32.0"; then optional="REQUIRED"; fi
	if test "x$lib" = "xlibzip >= 0.10"; then optional="REQUIRED"; fi
	if `$PKG_CONFIG --exists $lib`; then
		ver=`$PKG_CONFIG --modversion $lib`
		answer="yes ($ver)"
	else
		answer="no"
	fi
	echo "  - ($optional) $lib: $answer"
done

echo -e "\nEnabled hardware drivers:\n"
echo "  - agilent-dmm..................... $HW_AGILENT_DMM"
echo "  - appa-55ii....................... $HW_APPA_55II"
echo "  - asix-sigma...................... $HW_ASIX_SIGMA"
echo "  - atten-pps3xxx................... $HW_ATTEN_PPS3XXX"
echo "  - brymen-bm86x.................... $HW_BRYMEN_BM86X"
echo "  - brymen-dmm...................... $HW_BRYMEN_DMM"
echo "  - cem-dt-885x..................... $HW_CEM_DT_885X"
echo "  - center-3xx...................... $HW_CENTER_3XX"
echo "  - chronovu-la..................... $HW_CHRONOVU_LA"
echo "  - colead-slm...................... $HW_COLEAD_SLM"
echo "  - conrad-digi-35-cpu.............. $HW_CONRAD_DIGI_35_CPU"
echo "  - demo............................ $HW_DEMO"
echo "  - dpscopese....................... $HW_DPSCOPESE"
echo "  - fluke-dmm....................... $HW_FLUKE_DMM"
echo "  - fx2lafw......................... $HW_FX2LAFW"
echo "  - gmc-mh-1x-2x.................... $HW_GMC_MH_1X_2X"
echo "  - hameg-hmo....................... $HW_HAMEG_HMO"
echo "  - hantek-dso...................... $HW_HANTEK_DSO"
echo "  - ikalogic-scanalogic2............ $HW_IKALOGIC_SCANALOGIC2"
echo "  - ikalogic-scanaplus.............. $HW_IKALOGIC_SCANAPLUS"
echo "  - kecheng-kc-330b................. $HW_KECHENG_KC_330B"
echo "  - lascar-el-usb................... $HW_LASCAR_EL_USB"
echo "  - mic-985xx....................... $HW_MIC_985XX"
echo "  - motech-lps-30x.................. $HW_MOTECH_LPS_30X"
echo "  - norma-dmm....................... $HW_NORMA_DMM"
echo "  - openbench-logic-sniffer......... $HW_OLS"
echo "  - rigol-ds........................ $HW_RIGOL_DS"
echo "  - saleae-logic16.................. $HW_SALEAE_LOGIC16"
echo "  - serial-dmm...................... $HW_SERIAL_DMM"
echo "  - sysclk-lwla..................... $HW_SYSCLK_LWLA"
echo "  - teleinfo........................ $HW_TELEINFO"
echo "  - tondaj-sl-814................... $HW_TONDAJ_SL_814"
echo "  - uni-t-dmm....................... $HW_UNI_T_DMM"
echo "  - uni-t-ut32x..................... $HW_UNI_T_UT32X"
echo "  - victor-dmm...................... $HW_VICTOR_DMM"
echo "  - zeroplus-logic-cube............. $HW_ZEROPLUS_LOGIC_CUBE"
echo

