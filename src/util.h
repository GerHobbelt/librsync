/*= -*- c-basic-offset: 4; indent-tabs-mode: nil; -*-
 *
 * librsync -- library for network deltas
 *
 * Copyright (C) 1999, 2000, 2001 by Martin Pool <mbp@sourcefrog.net>
 * Copyright (C) 1999 by Andrew Tridgell <tridge@samba.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

void *rs_alloc_(size_t size, char const *name,
                const char *file, int line, const char *func);
void *rs_realloc_(void *ptr, size_t nsize, char const *name,
                  const char *file, int line, const char *func);
void *rs_alloc_struct0_(size_t size, char const *name,
                        const char *file, int line, const char *func);

void rs_bzero(void *buf, size_t size);


#if (defined(__linux__) ||                                              \
        defined(__APPLE__) ||                                           \
        defined(__Darwin__) ||                                          \
        defined(__NetBSD__) ||                                          \
        defined(__FreeBSD__) ||                                         \
        defined(__OpenBSD__) ||                                         \
        defined(__DragonFly__))
# include <sys/cdefs.h>
#endif

#if !defined(__unused)
# if defined(__lint__) || defined(__LCLINT__) || defined(S_SPLINT_S)
#  define __unused      /*@unused@*/
# else	/* assume GCC, Clang, Solaris Studio C, Intel C, IBM XL C, or compatible... */
#  define __unused	__attribute__((__unused__))
# endif
#endif

/** Allocate and zero-fill an instance of TYPE. */
#define rs_alloc_struct(type)                                           \
    rs_alloc_struct0_(sizeof(type), #type, __FILE__, __LINE__, __FUNCTION__)

#define rs_alloc(size, name)                                            \
    rs_alloc_(size, name, __FILE__, __LINE__, __FUNCTION__)

#define rs_realloc(ptr, nsize, name)                                    \
    rs_realloc_(ptr, nsize, name, __FILE__, __LINE__, __FUNCTION__)
