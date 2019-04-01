# -*- makefile-bsdmake -*-

bmake_topdir = ..

.include "${.CURDIR}/${bmake_topdir}/Makefile.inc"

Doxyfile: ${.CURDIR}/Doxyfile.in
	sed -e 's/@FULLNAME@/lib${LIB}/' \
	    -e 's/@LIB@/${LIB}/' \
	    -e 's/@LIBRSYNC_MAJOR@/${LIBRSYNC_MAJOR}/' \
	    -e 's/@LIBRSYNC_MINOR@/${LIBRSYNC_MINOR}/' \
	    -e 's/@LIBRSYNC_MICRO@/${LIBRSYNC_MICRO}/' \
	    -e 's/@LIBRSYNC_VERSION@/${LIBRSYNC_VERSION}/' \
	    -e 's|@PREFIX@|${PREFIX}|' \
	    -e 's|@INCSDIR@|${INCSDIR}|' \
	    -e 's|@LIBDIR@|${LIBDIR}|' \
	< ${.CURDIR}/Doxyfile.in > ${.TARGET}

CLEANFILES += Doxyfile

# If you have "doxygen" installed then this creates 'html', 'latex-, and 'man'
# sub-directories with generated documentation.
#
# XXX with different versions of BSDMake we end up needing ${.CURDIR} or similar
# in the environment but we're safest to do that explicitly on the command line,
# and also some (older) versions of doxygen don't allow "." in environment
# variable names, so we have to be careful how we do it.
#
DOXYGEN ?=	doxygen
docs: .PHONY all Doxyfile
	${DOXYGEN} -v >/dev/null && env MAKEOBJDIRPREFIX=$(MAKEOBJDIRPREFIX:Q) CURDIR=${.CURDIR:Q} ${DOXYGEN} Doxyfile

afterinstall: .PHONY install-docs

install-docs: .PHONY beforeinstall .WAIT docs
	cp ${.CURDIR:Q}/../AUTHORS ${.CURDIR:Q}/../CONTRIBUTING.md ${.CURDIR:Q}/../COPYING ${.CURDIR:Q}/../NEWS.md ${.CURDIR:Q}/../README.md ${.CURDIR:Q}/../THANKS ${.CURDIR:Q}/../TODO.md ${DESTDIR}${SHAREDIR}/doc/lib${PACKAGE}/
	-cp -R html ${DESTDIR}${SHAREDIR}/doc/lib${PACKAGE}/
	-cp -R latex ${DESTDIR}${SHAREDIR}/doc/lib${PACKAGE}/
	-cp -R man ${DESTDIR}${SHAREDIR}/

MAN =	rdiff.1
MAN +=	librsync.3

# XXX FreeBSD seems to have a buggy <bsd.man.mk> (as of 12.0)
#
CLEANFILES += rdiff.1.gz
CLEANFILES += librsync.3.gz

.include <bsd.prog.mk>
.include "${.CURDIR}/${bmake_topdir}/Makefile.compiler"
