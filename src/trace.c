/*= -*- c-basic-offset: 4; indent-tabs-mode: nil; -*-
 *
 * librsync -- library for network deltas
 *
 * Copyright (C) 2000, 2001 by Martin Pool <mbp@sourcefrog.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

                                     /*=
                                      | Finality is death.
                                      | Perfection is finality.
                                      | Nothing is perfect.
                                      | There are lumps in it.
                                      */

/** \file trace.c logging and debugging output.
 *
 * \todo Have a bit set in the log level that says not to include the function
 * name. */

#include "config.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>
#include <unistd.h>                     /* for write(), POSIX-only for now */

#include "librsync.h"
#include "util.h"
#include "trace.h"

rs_trace_fn_t *rs_trace_impl = rs_trace_stderr;

int rs_trace_level = RS_LOG_INFO;

/*
 * XXX for older versions of NetBSD and OpenBSD (and probably FreeBSD), we would
 * need to include <sys/param.h> and do additional tests in order to be safe.
 *  && (__NetBSD_Version__+0 >= ?????))	        aka: __NetBSD_Prereq__(M,m,p)
 *  && (OpenBSD+0 >= 201311))
 */
#if !defined(HAVE_GETPROGNAME) &&                                       \
	(defined(__NetBSD__) ||                                         \
	defined(__minix) ||                                             \
	defined(__OpenBSD__) ||                                         \
	defined(__FreeBSD__) ||                                         \
	defined(__DragonFly__) ||                                       \
	defined(__APPLE__))
# define HAVE_GETPROGNAME		/* defined */
#endif

#ifndef HAVE_GETPROGNAME
static char *
getprogname(void)
{
# ifdef __linux__
	return program_invocation_short_name;
# else
	static char *argv0 = "librsync";

	/*
	 * xxx if we included <sys/param.h>, then on any BSD we could know if we
	 * have this:
	 *
	 * #ifdef BSD4_4
	 *	extern const char *__progname;
	 * #endif
	 */

	return argv0;
# endif
}
#endif

static void rs_log_va(int level, char const *fn, char const *fmt, va_list va);

/** Log severity strings, if any. Must match ordering in ::rs_loglevel. */
static const char *rs_severities[] = {
    "EMERGENCY! ", "ALERT! ", "CRITICAL! ", "ERROR: ", "Warning: ",
    "", "", ""
};

/** Set the destination of trace information.
 *
 * The callback scheme allows for use within applications that may have their
 * own particular ways of reporting errors: log files for a web server,
 * perhaps, and an error dialog for a browser.
 *
 * \todo Do we really need such fine-grained control, or just yes/no tracing? */
void rs_trace_to(rs_trace_fn_t *new_impl)
{
    rs_trace_impl = new_impl;
}

void rs_trace_set_level(rs_loglevel level)
{
    rs_trace_level = level;
}

static void rs_log_va(int flags, char const *fn, char const *fmt, va_list va)
{
    int level = flags & RS_LOG_PRIMASK;

    if (rs_trace_impl && level <= rs_trace_level) {
        char buf[1000];
        char full_buf[1000];

        /* xxx vasprintf() ???  C99 has vsnprintf(), but GNU libc has vasprintf() */
        vsnprintf(buf, sizeof buf - 1, fmt, va);

        if (flags & RS_LOG_NONAME) {
            snprintf(full_buf, sizeof full_buf - 1, "%s: %s%s\n",
                     getprogname(),
                     rs_severities[level], buf);
        } else {
            snprintf(full_buf, sizeof full_buf - 1, "%s: %s(%s) %s\n",
                     getprogname(),
                     rs_severities[level], fn, buf);
        }

        rs_trace_impl(level, full_buf);
    }
}

/* Called by a macro, used on platforms where we can't determine the calling
   function name. */
void rs_log0_nofn(int level, char const *fmt, ...)
{
    va_list va;

    va_start(va, fmt);
    rs_log_va(level, PACKAGE, fmt, va);
    va_end(va);
}

/* Called by a macro that prepends the calling function name, etc. */
void rs_log0(int level, char const *fn, char const *fmt, ...)
{
    va_list va;

    va_start(va, fmt);
    rs_log_va(level, fn, fmt, va);
    va_end(va);
}

void
rs_trace_stderr(rs_loglevel level __unused, char const *msg)
{
    /* NOTE NO TRAILING NUL */
    write(STDERR_FILENO, msg, strlen(msg));
}

/* This is called directly if the machine doesn't allow varargs macros. */
void rs_fatal0(char const *s, ...)
{
    va_list va;

    va_start(va, s);
    rs_log_va(RS_LOG_CRIT, PACKAGE, s, va);
    va_end(va);
    abort();
}

/* This is called directly if the machine doesn't allow varargs macros. */
void rs_error0(char const *s, ...)
{
    va_list va;

    va_start(va, s);
    rs_log_va(RS_LOG_ERR, PACKAGE, s, va);
    va_end(va);
}

/* This is called directly if the machine doesn't allow varargs macros. */
void rs_trace0(char const *s, ...)
{
#ifdef DO_RS_TRACE
    va_list va;

    va_start(va, s);
    rs_log_va(RS_LOG_DEBUG, PACKAGE, s, va);
    va_end(va);
#else
    (void) s;
#endif /* !DO_RS_TRACE */
}

int rs_supports_trace(void)
{
#ifdef DO_RS_TRACE
    return 1;
#else
    return 0;
#endif                          /* !DO_RS_TRACE */
}
