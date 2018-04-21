# -*-makefile-bsdmake-*-

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

DOXYGEN ?=	doxygen
docs: .PHONY all Doxyfile
	env CURDIR=${.CURDIR:Q} ${DOXYGEN} Doxyfile

.include <bsd.prog.mk>
.include "${.CURDIR}/${bmake_topdir}/Makefile.compiler"
