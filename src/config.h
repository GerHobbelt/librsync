/* comment this out to disable the trace code (slight code and speed savings) */
#define DO_RS_TRACE		/* defined */

/* Define to 1 if you have the <zlib.h> header file. */
//#define HAVE_ZLIB_H 1		// for rdiff.c, if/when compression is implemented

/* Define to 1 if you have the `z' library (-lz). */
//#define HAVE_LIBZ ${ZLIB_FOUND} // for rdiff.c, if/when compression is implemented

/* Define to 1 if you have the <bzlib.h> header file.  */
//#define HAVE_BZLIB_H 1		// for rdiff.c, if/when compression is implemented

/* Define to 1 if you have the `bz2' library (-lbz2). */
//#define HAVE_LIBBZ2 ${BZIP2_FOUND}	// for rdiff.c, if/when compression is implemented

/* Name of package */
#define PACKAGE "librsync"

/* FIXME Enable extensions on AIX 3, Interix.  */
#ifndef _ALL_SOURCE
# define _ALL_SOURCE 1
#endif
/* FIXME Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
# define _GNU_SOURCE 1
#endif
/* FIXME Enable threading extensions on Solaris.  */
#ifndef _POSIX_PTHREAD_SEMANTICS
# define _POSIX_PTHREAD_SEMANTICS 1
#endif
/* FIXME Enable extensions on HP NonStop.  */
#ifndef _TANDEM_SOURCE
# define _TANDEM_SOURCE 1
#endif
/* FIXME Enable general extensions on Solaris.  */
#ifndef __EXTENSIONS__
# define __EXTENSIONS__ 1
#endif

/* newer GCC & Clang will already have these defined... */
#if !(defined(__LITTLE_ENDIAN__) || defined(__BIG_ENDIAN__))

# if !(defined(__BYTE_ORDER__) &&					\
       defined(__ORDER_LITTLE_ENDIAN__) && defined(__ORDER_BIG_ENDIAN__))

#  if (defined(linux) || defined(__linux__) ||                          \
       defined (__gnu_linux__) || defined(__linux))
#   include <endian.h>
#  endif

#  if (defined(BSD) ||                                                  \
       defined(__NetBSD__) ||                                           \
       defined(__FreeBSD__) ||                                          \
       defined(__OpenBSD__) ||                                          \
       defined(__Darwin__) ||                                           \
       defined(__DragonFly__))
#   include <sys/types.h>
#  endif

#  ifdef __SCO__
#   include <sys/types.h>
#   include <sys/byteorder.h>
#  endif

#  ifdef __aix__
#   include <sys/machine.h>
#  endif

#  ifdef __hpux
#   include <machine/param.h>
#  endif

#  ifdef OS2
#   include <machine/endian.h>
#  endif

#  ifdef SVR4
#   if defined(NCR) || defined(Mips) || defined(__sgi)
#    include <sys/endian.h>
#   else
#    if !defined(sun)
#     include <sys/byteorder.h>
#    endif
#   endif
#  endif

/* the above #includes should define one of the following groups... */

#  if !defined(__ORDER_LITTLE_ENDIAN__) && defined(_LITTLE_ENDIAN)
#   define __ORDER_LITTLE_ENDIAN__	_LITTLE_ENDIAN
#  endif
#  if !defined(__ORDER_BIG_ENDIAN__) && defined(_BIG_ENDIAN)
#   define __ORDER_BIG_ENDIAN__		_BIG_ENDIAN
#  endif
#  if !defined(__BYTE_ORDER__) && defined(_BYTE_ORDER)
#   define __BYTE_ORDER__		_BYTE_ORDER
#  endif

#  if !defined(__ORDER_LITTLE_ENDIAN__) && defined(__LITTLE_ENDIAN)
#   define __ORDER_LITTLE_ENDIAN__	__LITTLE_ENDIAN
#  endif
#  if !defined(__ORDER_BIG_ENDIAN__) && defined(__BIG_ENDIAN)
#   define __ORDER_BIG_ENDIAN__		__BIG_ENDIAN
#  endif
#  if !defined(__BYTE_ORDER__) && defined(__BYTE_ORDER)
#   define __BYTE_ORDER__		__BYTE_ORDER
#  endif

/*
 * If we still dont know the target byte order, then we try one last effort.
 *
 * This is based on compiler CPU macros, so for bit-field determination it's no
 * better than those above, but for code wanting to know the word endianness...
 */
#  ifndef __BYTE_ORDER__

/*
 * note: these are the values GCC & Clang use....
 */
#   ifndef __ORDER_LITTLE_ENDIAN__
#    define __ORDER_LITTLE_ENDIAN__	1234
#   endif
#   ifndef __ORDER_BIG_ENDIAN__
#    define __ORDER_BIG_ENDIAN__   	4321
#   endif

#   if defined(i386) || defined(__i386__) || defined(__x86__) ||	\
	defined(vax) || defined(__vax__) ||                             \
	defined(_MIPSEL) ||defined(__MIPSEL) || defined(__MIPSEL__) ||  \
	defined(__ARMEL__) || defined(__THUMBEL__) ||			\
	defined(__AARCH64EL__)
#    define __BYTE_ORDER__	__ORDER_LITTLE_ENDIAN__
#   else
/* assume there is no need to support middle-endian */
#    define __BYTE_ORDER__	__ORDER_BIG_ENDIAN__
#   endif

#   if !defined(__BYTE_ORDER__) && defined(_LITTLE_ENDIAN)
#    define __BYTE_ORDER__	__ORDER_LITTLE_ENDIAN__
#   endif
#   if !defined(__BYTE_ORDER__) && defined(_BIG_ENDIAN)
#    define __BYTE_ORDER__	__ORDER_BIG_ENDIAN__
#   endif

#  endif /* __BYTE_ORDER__ */

# endif /* !(__BYTE_ORDER__ && __ORDER_LITTLE_ENDIAN__ && __ORDER_BIG_ENDIAN__)) */

# if !defined(__BIG_ENDIAN__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#  define __BIG_ENDIAN__
# elif !defined(__LITTLE_ENDIAN__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#  define __LITTLE_ENDIAN__
# endif

#endif /* !(__LITTLE_ENDIAN__) || __BIG_ENDIAN__) */

#if !(defined(__LITTLE_ENDIAN__) || defined(__BIG_ENDIAN__))
# error "one of __LITTLE_ENDIAN__ or __BIG_ENDIAN__ must be defined"
#endif

/* FIXME Enable large inode numbers on Mac OS X 10.5.  */
#ifndef _DARWIN_USE_64_BIT_INODE
# define _DARWIN_USE_64_BIT_INODE 1
#endif

/* FIXME Define to 1 to make fseeko visible on some hosts (e.g. glibc 2.2). */
/* #undef _LARGEFILE_SOURCE */

/* FIXME Define for large files, on AIX-style hosts. */
/* #undef _LARGE_FILES */

/* FIXME Define to 2 if the system does not provide POSIX.1 features except with
   this defined. */
/* #undef _POSIX_1_SOURCE */

/* FIXME Define to 1 if you need to in order for `stat' and other things to work. */
/* #undef _POSIX_SOURCE */

/* FIXME Define to `long int' if <sys/types.h> does not define. */
/* N.B.:  POSIX 1003.1-2004 Issue 6 offers off_t and should be the minimum we use */
/* #undef off_t */
