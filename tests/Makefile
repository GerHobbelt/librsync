# -*-makefile-bsdmake-*-

bmake_topdir = ..

.include "${.CURDIR}/${bmake_topdir}/Makefile.inc"

# XXX Apple's BSDmake, Simon's BSDmake, etc., don't support PROGS

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

# XXX this should be built in its own top-level sub-directory
# XXX and then it could be linked to here for running the tests...
PROGS += rdiff
SRCS.rdiff = ../src/rdiff.c
.if defined(POPT_INCLUDE)
.if defined(CPPFLAGS)
CPPFLAGS.rdiff +=	-I${POPT_INCLUDE}
.else
CFLAGS.rdiff +=		-I${POPT_INCLUDE}
.endif
.endif
.if defined(INTL_INCLUDE)
.if defined(CPPFLAGS)
CPPFLAGS.rdiff +=	-I${INTL_INCLUDE}
.else
CFLAGS.rdiff +=		-I${INTL_INCLUDE}
.endif
.endif
.if defined(POPT_LIB)
LDADD.rdiff = -L${POPT_LIB}
.endif
.if defined(INTL_LIB)
LDADD.rdiff += -L${INTL_LIB}
.endif
LDADD.rdiff += -lpopt -lintl
MAN.rdiff =		#empty

regress: .PHONY all
.for _P in ${PROGS}
.if "${_P}" != "rdiff"
	./${_P}
.endif
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

.include <bsd.prog.mk>
.include "${.CURDIR}/${bmake_topdir}/Makefile.compiler"
