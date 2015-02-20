CLEANFILES = libbsk.la libbsk-debug.la libbsk-env.la libbsk-log.la bsk$(EXEEXT) *~

do_subst = sed -e 's,[@]sharedstatedir[@],$(sharedstatedir),g' \
		-e 's,[@]localstatedir[@],$(localstatedir),g' \
		-e 's,[@]sysconfdir[@],$(sysconfdir),g' \
		-e 's,[@]prefix[@],$(prefix),g' \
		-e 's,[@]bindir[@],$(bindir),g' \
		-e 's,[@]sbindir[@],$(sbindir),g' \
		-e 's,[@]libdir[@],$(libdir),g' \
		-e 's,[@]mandir[@],$(mandir),g' \
		-e 's,[@]PERL[@],$(PERL),g' \
		-e 's,[@]ENV[@],$(ENV),g' \
		-e 's,[@]BASH[@],$(BASH),g' \
		-e 's,[@]PACKAGE[@],$(PACKAGE),g' \
		-e 's,[@]VERSION[@],$(VERSION),g' \
		-e 's,[@]DESCRIPTION[@],$(DESCRIPTION),g'

bsk_SOURCES = bsk.c libbsk.c libbsk-debug.c libbsk-env.c libbsk-log.c

sbin_PROGRAMS = bsk$(EXEEXT)

libbskdir = $(libdir)
libbsk_DATA = libbsk.la libbsk-debug.la libbsk-log.la libbsk-env.la

libbsk.la: libbsk.c Makefile
	$(do_subst) < $(srcdir)/libbsk.c > libbsk.la; \
	chmod +x libbsk.la

libbsk-debug.la: libbsk-debug.c Makefile
	$(do_subst) < $(srcdir)/libbsk-debug.c > libbsk-debug.la; \
	chmod +x libbsk-debug.la

libbsk-env.la: libbsk-env.c Makefile
	$(do_subst) < $(srcdir)/libbsk-env.c > libbsk-env.la; \
	chmod +x libbsk-env.la

libbsk-log.la: libbsk-log.c Makefile
	$(do_subst) < $(srcdir)/libbsk-log.c > libbsk-log.la; \
	chmod +x libbsk-log.la

bsk$(EXEEXT): bsk.c Makefile
	$(do_subst) < $(srcdir)/bsk.c > bsk$(EXEEXT); \
	chmod +x bsk$(EXEEXT);

all-local: libbsk.la libbsk-debug.la libbsk-env.la libbsk-log.la bsk$(EXEEXT)
