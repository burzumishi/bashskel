#!@ENV@ bash

# @PACKAGE@-@VERSION@ (libbsk-env.c) #

# Copyright (c) 2014-2015 Antonio Cao (@burzumishi) #

# This is free software;
# You have unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.

# Genetic Environment Library #

# libbsk-env.la: Environment variables and definitions #

### --- Define '@PACKAGE' Environment variables --- ###

# load_core_variables(): loads '@PACKAGE@' required variables #
load_core_variables() {

	# Setup LANG & LC_ALL #
	export LANG=$LANG;
	export LC_ALL=$LC_ALL;


	# Define '@PACKAGE' commands #
	ECHO="echo -e";
	GREP="grep";
	PATCH="patch";
	PING="ping";
	NSLOOKUP="nslookup";
	HOSTCMD="host";
	AWK="awk";
	SORT="sort";
	CAT="cat";
	MV="mv";
	CP="cp";
	LN="ln";
	LS="ls";
	RM="rm";
	CD="cd";
	WC="wc";
	DU="du";
	CHMOD="chmod";
	TOUCH="touch";
	TAIL="tail";
	HEAD="head";
	LESS="less";
	MORE="more";
	FIND="find";
	STRIP="strip";
	MKDIR="mkdir";
	MAKE="make";
	DATE="date";
	TEE="tee";
	SED="sed";
	TAR="tar";
	GZIP="gzip";
	BZIP2="bzip2";
	XZ="xz";
	LDCONFIG="ldconfig";
	ACLOCAL="aclocal";
	LIBTOOLIZE="libtoolize";
	AUTOCONF="autoconf";
	AUTOMAKE="automake";
	SETTERM="setterm";
	UNAME="uname";
	WHOAMI="whoami";
	TRAP="trap";
	SLEEP="sleep";
	TPUT="tput";
	KILL="kill";
	LET="let";
	PIDOF="pidof";
	GETOPT="getopt";
	GETOPTS="getopts";

	# Define (true || false)

	true=0;
	false=1;


	# Define Operating System #
	HOST_OS=$($UNAME -o);
	HOST_OS_VERSION=$($UNAME -r)
	HOST_SYSTEM=$($UNAME -s);
	HOST_MACHINE=$($UNAME -m);
	HOST_PLATFORM=$($UNAME -i);
	HOST_CPU=$($UNAME -p);


	# Define Current User #
	USER="$($WHOAMI)";


	# Define '@PACKAGE@' Log Date Format #
	LOGDATE=$($DATE $DATEFORMAT);


	# Define $BASHSK_LAST_ERROR #
	BASHSK_LAST_ERROR="";

	load_terminal_color_support;

	return $true;
}

# load_terminal_color_support(): '@PACKAGE@' Terminal Color Support #
load_terminal_color_support() {

	### --- '@PACKAGE@' Terminal Color Support --- ###

	if test "$ENABLE_COLOR" == "yes"; then
		# Define Shell Colors #
		color_blk="\e[0;30m";  # Black - Regular #
		color_red="\e[0;31m";  # Red #
		color_grn="\e[0;32m";  # Green #
		color_ylw="\e[0;33m";  # Yellow #
		color_blu="\e[0;34m";  # Blue #
		color_pur="\e[0;35m";  # Purple #
		color_cyn="\e[0;36m";  # Cyan #
		color_wht="\e[0;37m";  # White #

		color_bblk="\e[1;30m"; # Black - Bold #
		color_bred="\e[1;31m"; # Red #
		color_bgrn="\e[1;32m"; # Green #
		color_bylw="\e[1;33m"; # Yellow #
		color_bblu="\e[1;34m"; # Blue #
		color_bpur="\e[1;35m"; # Purple #
		color_bcyn="\e[1;36m"; # Cyan #
		color_bwht="\e[1;37m"; # White #

		color_ublk="\e[4;30m"; # Black - Underline #
		color_ured="\e[4;31m"; # Red #
		color_ugrn="\e[4;32m"; # Green #
		color_uylw="\e[4;33m"; # Yellow #
		color_ublu="\e[4;34m"; # Blue #
		color_upur="\e[4;35m"; # Purple #
		color_ucyn="\e[4;36m"; # Cyan #
		color_uwht="\e[4;37m"; # White #

		color_bkblk="\e[40m";  # Black - Background #
		color_bkred="\e[41m";  # Red #
		color_bdgrn="\e[42m";  # Green #
		color_bkylw="\e[43m";  # Yellow #
		color_bkblu="\e[44m";  # Blue #
		color_bkpur="\e[45m";  # Purple #
		color_bkcyn="\e[46m";  # Cyan #
		color_bkwht="\e[47m";  # White #

		color_reset="\e[0m";   # Text Reset #

		# Define Shell Color Messages #
		OK="${color_bgrn}[---]${color_reset}";
		ERROR="${color_bred}[@@@]${color_reset}";
		WARNING="${color_bylw}[!!!]${color_reset}";
		DEBUG="${color_bred}[%%%]${color_reset}";
		INFO="${color_bwht}[***]${color_reset}";
		BUILD="${color_bcyn}[###]${color_reset}";
		QUESTION="${color_bgrn}[¿*?]${color_reset}";
		SELECT="[+++]";
		SPIN1="${color_bblu}[${color_bylw}(|)${color_bblu}]${color_reset}";
		SPIN2="${color_bblu}[${color_bylw}(/)${color_bblu}]${color_reset}";
		SPIN3="${color_bblu}[${color_bylw}(-)${color_bblu}]${color_reset}";
		SPIN4="${color_bblu}[${color_bylw}(\\)${color_bblu}]${color_reset}";
		FINISHED="\\b\\b\\b\\b ... ${color_grn}finished!${color_reset}";
		FAILED="\\b\\b\\b\\b ... ${color_red}failed!${color_reset}";

		# User Screen Color Messages #

		# @PACKAGE@ version #
		@PACKAGE@_VERSION="$INFO ${color_bylw}@DESCRIPTION@ ${color_bblu}[${color_bwht}@PACKAGE@ ${color_bcyn}(${color_bwht}@VERSION@${color_bcyn})${color_bblu}] ${color_reset}running on ${color_bcyn}(${color_bwht}$HOST_MACHINE${color_bcyn}) ${color_bcyn}'${color_bgrn}$HOST_OS${color_bcyn}'${color_reset}.";

		# @PACKAGE@ help #	
		HELP="$INFO ${color_bgrn}Usage:${color_reset} ${color_bwht}@PACKAGE@ ${color_bcyn}--option1 --option2 'args' ... ${color_bwht}--command|-c 'file'

$INFO Commands:

	${color_bwht}[-h] --help
	${color_bwht}[-v] --version

$INFO Options:

	${color_bcyn}     --color
	${color_bcyn}     --verbose
	${color_bcyn}     --force

$INFO Try ${color_bwht}'${color_bgrn}man @PACKAGE@.(1)${color_bwht}'${color_reset} for more information.";

	else # Define Shell RAW Messages (no color) #

		# Define Shell Messages #
		OK="[---]";
		ERROR="[@@@]";
		WARNING="[!!!]";
		DEBUG="[%%%]";
		INFO="[***]";
		BUILD="[###]";
		QUESTION="[¿*?]";
		SELECT="[+++]";
		SPIN1="[(|)]";
		SPIN2="[(/)]";
		SPIN3="[(-)]";
		SPIN4="[(\\)]";
		FINISHED="\\b\\b\\b\\b ... finished!";
		FAILED="\\b\\b\\b\\b ... failed!";

		# User Screen Color Messages #

		# @PACKAGE@ version #
		@PACKAGE@_VERSION="$INFO @DESCRIPTION@ [@PACKAGE@ (@VERSION@)] running on ($HOST_MACHINE) '$HOST_OS'.";

		# @PACKAGE@ help #
		  	HELP="$INFO Usage: @PACKAGE@ --option1 --option2 'arg' ... --command|-c 'file'

$INFO Commands:

	[-h] --help
	[-v] --version

$INFO Options:

	     --color
	     --verbose
	     --force

$INFO Try 'man @PACKAGE@.(1)' for more information.";
	fi;

	return $true;
}

