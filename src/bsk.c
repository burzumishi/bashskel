#!@ENV@ bash

# @PACKAGE@-@VERSION@ (@DESCRIPTION@) #

# Copyright (c) 2014-2015 Antonio Cao (@burzumishi) #

# This is free software; 
# You have unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.

# @PACKAGE@ @VERSION@ (@DESCRIPTION@) #

# Load @PACKAGE@ Configuration Files and Setups #

# Import @PACKAGE@ Main Config File #
source @sysconfdir@/@PACKAGE@/@PACKAGE@.conf;

# Import @PACKAGE@ Dinamic Config Files (conf.d) #
if test -d "@sysconfdir@/@PACKAGE@/conf.d"; then
  CONFD=$(find @sysconfdir@/@PACKAGE@/conf.d -iname "*.conf");
  for confd in $CONFD; do
    source $confd;
  done
fi;

# Load @PACKAGE@ Libraries #

# Load @PACKAGE@ Environment Definitions #
source @libdir@/libbsk-env.la;

# Load @PACKAGE@ Logger Functions #
source @libdir@/libbsk-log.la;

# Load @PACKAGE@ Core Functions #
source @libdir@/libbsk.la;

# Load @PACKAGE@ environment debug #
source @libdir@/libbsk-debug.la;


# Start '@PACKAGE@' #

main "$@";

# End '@PACKAGE@' #
