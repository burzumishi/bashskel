#!/bin/sh

aclocal
libtoolize
autoconf
automake -a

#if [ -f "configure" ]; then
	# --prefix /opt/bsk: ./configure --prefix=/opt/bsk --sysconfdir=/opt/bsk/etc --localstatedir=/opt/bsk/var
	# ./configure --prefix=/opt/bsk --sysconfdir=/opt/bsk/etc --localstatedir=/opt/bsk/var

	# --prefix /usr (default)
	# ./configure --prefix=/usr --sysconfdir=/etc --localstatedir=/var
#fi;

# DEVEL DIST CLEAN ALL
# rm -rf aclocal.m4 autom4te.cache config.guess configure config.sub install-sh missing Makefile.in src/Makefile.in Makefile src/Makefile config.log config.status
