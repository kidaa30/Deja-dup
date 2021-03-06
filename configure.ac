# -*- Mode: m4; indent-tabs-mode: nil; tab-width: 2 -*-
#
# This file is part of Déjà Dup.
# For copyright information, see AUTHORS.
#
# Déjà Dup is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# Déjà Dup is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Déjà Dup.  If not, see <http://www.gnu.org/licenses/>.

# Sets up autoconf.
AC_INIT([Déjà Dup],[23.90],[https://bugs.launchpad.net/deja-dup/+filebug],[deja-dup],[https://launchpad.net/deja-dup])
AC_PREREQ(2.64)
AC_CONFIG_SRCDIR(deja-dup/main.vala)
AC_CONFIG_HEADERS([config.h:config.h.in])
AC_CONFIG_MACRO_DIR([m4])

# Sets up automake.
AM_INIT_AUTOMAKE([1.11 foreign tar-ustar dist-xz no-dist-gzip])
AM_SILENT_RULES([yes])

YELP_HELP_INIT
GLIB_GSETTINGS

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_MAKE_SET

LT_PREREQ([2.2.6])
LT_INIT

PKG_PROG_PKG_CONFIG([0.24])

DD_PROG_VALAC([0.16.0], [valac-0.18 valac-0.16 valac])
AS_IF([test "x$(basename $VALAC)" = xvalac-0.16],
  [AC_SUBST(SHARED_VALAFLAGS, ["-D HAVE_VALAC_16"])]
)

# Sets up gettext.
GETTEXT_PACKAGE="$PACKAGE"
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE, "$GETTEXT_PACKAGE", [gettext domain])
AM_GNU_GETTEXT([external])
AM_GNU_GETTEXT_VERSION([0.17])
IT_PROG_INTLTOOL([0.40])

# Sets up a few prefix-relative directories
if test "x${prefix}" = "xNONE"; then
  PREFIX="${ac_default_prefix}"
else
  PREFIX="${prefix}"
fi
AC_DEFINE_UNQUOTED(LOCALE_DIR, "${PREFIX}/${DATADIRNAME}/locale",[Locale directory])
AC_DEFINE_UNQUOTED(THEME_DIR, "${PREFIX}/${DATADIRNAME}/icons",[Icon directory])
AC_DEFINE_UNQUOTED(PKG_DATA_DIR, "${PREFIX}/${DATADIRNAME}/${PACKAGE}",[Package data directory])

GTK_MODULE=gtk+-3.0
GTK_REQ_VER=3.0
GLIB_REQ_VER=2.32
GIO_REQ_VER=$GLIB_REQ_VER
NOTIFY_REQ_VER=0.7

AC_SUBST(GTK_MODULE)

# Check dependencies
PKG_CHECK_MODULES(DUP,
                  $GTK_MODULE >= $GTK_REQ_VER
                  gio-2.0 >= $GIO_REQ_VER
                  gio-unix-2.0 >= $GIO_REQ_VER
                  gnome-keyring-1
                  libpeas-1.0
                  gmodule-2.0 >= $GLIB_REQ_VER
                  libnotify >= $NOTIFY_REQ_VER)

PKG_CHECK_MODULES(PREF,
                  $GTK_MODULE >= $GTK_REQ_VER
                  gio-2.0 >= $GIO_REQ_VER
                  libpeas-1.0)

PKG_CHECK_MODULES(COMMON,
                  gio-2.0 >= $GIO_REQ_VER
                  gio-unix-2.0 >= $GIO_REQ_VER
                  gnome-keyring-1
                  libpeas-1.0
                  gmodule-2.0 >= $GLIB_REQ_VER)

PKG_CHECK_MODULES(WIDGETS,
                  gmodule-2.0 >= $GLIB_REQ_VER
                  $GTK_MODULE >= $GTK_REQ_VER
                  libpeas-1.0
                  libnotify >= $NOTIFY_REQ_VER)

PKG_CHECK_MODULES(MONITOR,
                  gio-2.0 >= $GIO_REQ_VER
                  libpeas-1.0
                  libnotify >= $NOTIFY_REQ_VER)

AC_ARG_WITH([extensiondir],
  [AS_HELP_STRING([--with-extensiondir],
    [use pkg-config extensiondir instead of PREFIX for plugins @<:@default=yes@:>@])],
  [],
  [with_extensiondir=yes])

AC_ARG_WITH([ccpanel],
  [AS_HELP_STRING([--with-ccpanel],
    [build control-center plugin @<:@default=check@:>@])],
  [],
  [with_ccpanel=check])
AS_IF([test "x$with_ccpanel" != xno],
  [PKG_CHECK_MODULES(CCPANEL, libgnome-control-center,
    [dnl Get control center extensions directory
     AS_IF([test "x$with_extensiondir" != xno],
       [CCPANEL_DIR=`$PKG_CONFIG --variable=extensiondir libgnome-control-center`],
       [CCPANEL_DIR="${PREFIX}/lib/control-center-1/panels"])
     AC_SUBST(CCPANEL_DIR)],
    [if test "x$with_ccpanel" != xcheck; then
        AC_MSG_FAILURE(
          [--with-ccpanel was given, but test for libgnome-control-center failed])
      fi
    ]
  )]
)
AM_CONDITIONAL([HAVE_CCPANEL], [test -n "$CCPANEL_LIBS"])

AC_ARG_WITH([nautilus],
  [AS_HELP_STRING([--with-nautilus],
    [build nautilus plugin @<:@default=check@:>@])],
  [],
  [with_nautilus=check])
AS_IF([test "x$with_nautilus" != xno],
  [PKG_CHECK_MODULES(NAUTILUS, libnautilus-extension 
                               glib-2.0 >= $GLIB_REQ_VER,
    [dnl Get nautilus extensions directory
     AS_IF([test "x$with_extensiondir" != xno],
       [NAUTILUS_EXTENSION_DIR=`$PKG_CONFIG --variable=extensiondir libnautilus-extension`],
       [NAUTILUS_EXTENSION_DIR="${PREFIX}/lib/nautilus/extensions-3.0"])
     AC_SUBST(NAUTILUS_EXTENSION_DIR)],
    [if test "x$with_nautilus" != xcheck; then
        AC_MSG_FAILURE(
          [--with-nautilus was given, but test for libnautilus-extension failed])
      fi
    ]
  )]
)
AM_CONDITIONAL([HAVE_NAUTILUS], [test -n "$NAUTILUS_LIBS"])

AH_TEMPLATE([HAVE_UNITY], [whether libunity is available])
AC_ARG_WITH([unity],
  [AS_HELP_STRING([--with-unity],
    [support libunity @<:@default=check@:>@])],
  [],
  [with_unity=check])
AS_IF([test "x$with_unity" != xno],
  [PKG_CHECK_MODULES(UNITY, unity >= 3.4.2,
    [AC_DEFINE(HAVE_UNITY)
     AC_SUBST(UNITY_VALAFLAGS, ["--pkg unity -D HAVE_UNITY"])],
    [if test "x$with_unity" != xcheck; then
        AC_MSG_FAILURE(
          [--with-unity was given, but test for unity failed])
      fi
    ]
  )]
)

# Sets up output files.
AC_CONFIG_FILES([Makefile
                 common/Makefile
                 data/Makefile
                 deja-dup/Makefile
                 help/Makefile
                 man/Makefile
                 monitor/Makefile
                 nautilus/Makefile
                 po/Makefile.in
                 preferences/Makefile
                 tests/Makefile
                 tests/runner/Makefile
                 tests/scripts/Makefile
                 tests/unit/Makefile
                 tools/Makefile
                 tools/duplicity/Makefile
                 vapi/Makefile
                 widgets/Makefile]
                 plugins/Makefile
                 plugins/apps/Makefile)
AC_OUTPUT
