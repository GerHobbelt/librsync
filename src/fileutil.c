/*= -*- c-basic-offset: 4; indent-tabs-mode: nil; -*-
 *
 * librsync -- library for network deltas
 *
 * Copyright (C) 1999, 2000, 2001 by Martin Pool <mbp@sourcefrog.net>
 * Copyright (C) 1999 by Andrew Tridgell <tridge@samba.org>
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

#include "config.h"

#include <sys/stat.h>

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#include "librsync.h"
#include "fileutil.h"
#include "trace.h"

/* Make sure S_ISREG is defined. */
#ifndef S_ISREG
#  define S_ISREG(x) ((x) & _S_IFREG)
#endif

/** Open a file with special handling for '-' or unspecified filenames.
 *
 * \param filename - The filename to open.
 *
 * \param mode - fopen style mode string.
 *
 * \param force - bool to force overwriting of existing files. */
FILE *rs_file_open(char const *filename, char const *mode, int force)
{
    FILE *f;
    int is_write;

    is_write = mode[0] == 'w';

    if (!filename || !strcmp("-", filename)) {
        if (is_write) {
#ifdef _WIN32
            _setmode(_fileno(stdout), _O_BINARY);
#endif
            return stdout;
        } else {
#ifdef _WIN32
            _setmode(_fileno(stdin), _O_BINARY);
#endif
            return stdin;
        }
    }

    if (!force && is_write) {
        if ((f = fopen(filename, "rb"))) {
            // File exists
            rs_error("File exists \"%s\", aborting!", filename);
            fclose(f);
            exit(RS_IO_ERROR);
        }
    }

    if (!(f = fopen(filename, mode))) {
        rs_error("Error opening \"%s\" for %s: %s", filename,
                 is_write ? "write" : "read", strerror(errno));
        exit(RS_IO_ERROR);
    }

    return f;
}

int rs_file_close(FILE *f)
{
    if ((f == stdin) || (f == stdout))
        return 0;
    return fclose(f);
}

void rs_get_filesize(FILE *f, off_t *size)
{
    struct stat st;
    if (size && (fstat(fileno(f), &st) == 0) && (S_ISREG(st.st_mode))) {
        *size = st.st_size;
    }
}

rs_result rs_file_copy_cb(void *arg, rs_long_t pos, size_t *len, void **buf)
{
    size_t got;
    FILE *f = (FILE *)arg;

    if (fseek(f, (off_t) pos, SEEK_SET)) { /* xxx use fseeko() for broken systems? */
        rs_error("seek failed: %s", strerror(errno));
        return RS_IO_ERROR;
    }

    got = fread(*buf, (size_t) 1U, *len, f);
    if (got == 0) {
        rs_error("read error: %s", strerror(errno));
        return RS_IO_ERROR;
    } else if (got < *len) {
        rs_error("unexpected eof on fd%d", fileno(f));
        return RS_INPUT_ENDED;
    } else {
        *len = got;
        return RS_DONE;
    }
}
