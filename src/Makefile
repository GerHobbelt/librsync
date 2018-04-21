# -*-makefile-bsdmake-*-

bmake_topdir = ..

# this must be set first to avoid the top-level LDADD
LIB =	rsync

.include "${.CURDIR}/${bmake_topdir}/Makefile.inc"

.include <bsd.own.mk>

# If these are set blank then no shared library is built, and so on OSX even
# Pkgsrc bmake can then complete a successful build.
#
SHLIB_MAJOR ?=   ${LIBRSYNC_MAJOR}
SHLIB_MINOR ?=   ${LIBRSYNC_MINOR}
SHLIB_TEENY ?=   ${LIBRSYNC_MICRO}

#WARNS =	3

.if defined(CPPFLAGS)
CPPFLAGS +=	-I${.CURDIR}/blake2
.else
CFLAGS +=	-I${.CURDIR}/blake2
.endif

SRCS +=	base64.c
SRCS +=	blake2/blake2b-ref.c
SRCS +=	buf.c
SRCS +=	checksum.c
SRCS +=	command.c
SRCS +=	delta.c
SRCS +=	emit.c
SRCS +=	fileutil.c
SRCS +=	hashtable.c
SRCS +=	hex.c
SRCS +=	isprefix.c
SRCS +=	job.c
SRCS +=	mdfour.c
SRCS +=	mksum.c
SRCS +=	msg.c
SRCS +=	netint.c
SRCS +=	patch.c
SRCS +=	prototab.c
SRCS +=	rdiff.c
SRCS +=	readsums.c
SRCS +=	rollsum.c
SRCS +=	scoop.c
SRCS +=	stats.c
SRCS +=	stream.c
SRCS +=	sumset.c
SRCS +=	trace.c
SRCS +=	tube.c
SRCS +=	util.c
SRCS +=	version.c
SRCS +=	whole.c

.if defined(POPT_INCLUDE)
.if defined(CPPFLAGS)
CPPFLAGS +=	-I${POPT_INCLUDE}
.else
CFLAGS +=	-I${POPT_INCLUDE}
.endif
.endif
.if defined(INTL_INCLUDE)
.if defined(CPPFLAGS)
CPPFLAGS +=	-I${INTL_INCLUDE}
.else
CFLAGS +=	-I${INTL_INCLUDE}
.endif
.endif

CFLAGS +=	--std=c99
MKLINT =	no

.if defined(POPT_LIB)
LDFLAGS +=	-L${POPT_LIB}
.endif
.if defined(INTL_LIB)
LDFLAGS +=	-L${INTL_LIB}
.endif
LDFLAGS +=	-lpopt -lintl

FILES +=			librsync.pc
FILESDIR_librsync.pc =		${PKGCONFIGDIR}
FILESBUILD_librsync.pc =	yes
librsync.pc: ${.CURDIR}/librsync.pc.in
	sed -e 's/@FULLNAME@/lib${LIB}/' \
	    -e 's/@LIB@/${LIB}/' \
	    -e 's/@LIBRSYNC_MAJOR@/${LIBRSYNC_MAJOR}/' \
	    -e 's/@LIBRSYNC_MINOR@/${LIBRSYNC_MINOR}/' \
	    -e 's/@LIBRSYNC_MICRO@/${LIBRSYNC_MICRO}/' \
	    -e 's|@PREFIX@|${PREFIX}|' \
	    -e 's|@INCSDIR@|${INCSDIR}|' \
	    -e 's|@LIBDIR@|${LIBDIR}|' \
	< ${.CURDIR}/librsync.pc.in > ${.TARGET}

librsync.pc: ${.CURDIR}/Makefile
librsync.pc: ${.CURDIR}/${bmake_topdir}/Makefile.inc

beforedepend: ${.OBJDIR}/blake2

${.OBJDIR}/blake2:
	mkdir ${.TARGET}

# here we do a little trick to pre-create a symlink to a unique name for the
# static library so that on systems which don't allow full static linking, but
# where static linking to some libraries is desired, these unique static names
# can be selected.  This is also done in building the companion binaries for
# this project in order to ensure they can be tested without requiring an
# annoying configuration dance with the dynamic runtime linker.
#
# Note:  This is an example of BSD Make's need for phony targets with no action
# rules being used to trigger phony dependencies with action rules.  If the
# intermediate dependency had action rules, then it would become a target, phony
# or not.
#
# Note also this makes the link before the libary may exist.
#
afterdepend: _bmake_static_lib_build_symlink
afterinstall: _bmake_static_lib_install_symlink

_bmake_static_lib_build_symlink:	.PHONY
	ln -fs lib$(LIB).a lib$(LIB)_s.a

CLEANFILES += lib$(LIB)_s.a

_bmake_static_lib_install_symlink: 	.PHONY
	ln -fs lib$(LIB).a ${DESTDIR}${LIBDIR}/lib$(LIB)_s.a

.include <bsd.lib.mk>

# set additional compiler and linker flags, especially additional warnings
#
.include "${.CURDIR}/${bmake_topdir}/Makefile.compiler"
