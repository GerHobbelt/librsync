# -*-makefile-bsdmake-*-

bmake_topdir = ..

.include "${.CURDIR}/${bmake_topdir}/Makefile.inc"

# XXX Simon's Bmake doesn't support PROGS
# (It has just singular PROG -- one program per directory, sigh.  Poop!)
# XXX FreeBSD has <bsd.progs.mk>, and though it does silly things, it works.

# XXX we should move each program to its own source directory

PROGS += isprefix_test
proginstall-isprefix_test: .PHONY
SRCS.isprefix_test = isprefix_test.c
MAN.isprefix_test =	# empty

PROGS += rollsum_test
proginstall-rollsum_test: .PHONY
SRCS.rollsum_test = rollsum_test.c
MAN.rollsum_test =	# empty

PROGS += hashtable_test
proginstall-hashtable_test: .PHONY
SRCS.hashtable_test = hashtable_test.c
MAN.hashtable_test =	# empty

PROGS += sumset_test
proginstall-sumset_test: .PHONY
SRCS.sumset_test = sumset_test.c
MAN.sumset_test =	# empty

# XXX this REALLY should be built in its own top-level sub-directory and
# then it could be linked to here for running the tests...
PROGS += rdiff
SRCS.rdiff = rdiff.c
MAN.rdiff =		#empty

rdiff.c: ${.CURDIR}/../src/rdiff.c
	cp ${.CURDIR}/../src/rdiff.c ${.TARGET}
CLEANFILES += rdiff.c

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
.if defined(POPT_LIB)
LDADD.rdiff =	-L${POPT_LIB}
.endif
.if defined(INTL_LIB)
LDADD.rdiff +=	-L${INTL_LIB}
.endif
LDADD.rdiff +=	-lpopt -lintl

# ancient BSDMake required the left hand term to be a variable expansion in
# order for a string comparison to be done...  (and the iterator from a .for
# loop is not really a variable for this use)
#
_OLDBMAKE_HACK = rdiff

regress: .PHONY all ${PROGS}
.for _P in ${PROGS}
. if ${_OLDBMAKE_HACK} != ${_P}
	./${_P:Q}
. endif
.endfor
	sh ${.CURDIR}/rdiff_bad_option.sh
	sh ${.CURDIR}/help.test
	sh ${.CURDIR}/mutate.test
	sh ${.CURDIR}/signature.test
	sh ${.CURDIR}/sources.test
	sh ${.CURDIR}/triple.test
	sh ${.CURDIR}/delta.test
	sh ${.CURDIR}/changes.test
	sh ${.CURDIR}/largefile.test
	@echo "All tests completed A-OK!"

# XXX this works for newer FreeBSDs at least
.if defined(.FreeBSD) && (${.FreeBSD} == true)
. include <bsd.progs.mk>
.else
. include <bsd.prog.mk>
.endif

.include "${.CURDIR}/${bmake_topdir}/Makefile.compiler"
