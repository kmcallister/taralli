#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(taralli, 1.0, bugs@debian.org)
AC_CONFIG_SRCDIR([main.c])
AC_CONFIG_FILES([Makefile])
AM_INIT_AUTOMAKE([taralli], [1.0])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([X11],[XOpenDisplay],[],[
         echo "X11 library is required for this program"
         exit -1])
AC_CHECK_LIB([Xi],[XGrabDevice],[],[
         echo "XInput devel library is missing. XInput is required for this program"
         exit -1])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h X11/X.h X11/extensions/XInput2.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([memset])

# Map-type
export map_type=rectangular

# Args to decide which map should be used
AC_ARG_ENABLE(custom-map,
	[  --enable-custom-map[=(map type)] Use another map:
        	rectangular [default] The default map
        	beef [alt] The beefy screen map
        	(mapname) [ext] Alternative map type],
 	[if test "x$enableval" = "def"; then
		echo "Using default map..."
		echo
		export map_type=rectangular
   	else
      		echo "Using map $enableval"
		echo
		export map_type=$enableval
   	fi
])

echo "============ MAP TYPE ============"
echo "This build will use map $map_type!"
echo "To change this, run ./configure"
echo "Again, but with --enable-custom-map"
echo "Set to your desired screen map."
echo "=================================="

# Pass map_type
AC_SUBST([map_type], [$map_type])
# Makefile.am workaround (Lazyness)
mkdir .deps
touch .deps/map_$map_type.Po

AC_OUTPUT
