/*= -*- c-basic-offset: 4; indent-tabs-mode: nil; -*-
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

/** \file stats.c stats reporting functions.
 *
 * \todo Other things to show in statistics: number of input and output bytes,
 * number of times we blocked waiting for input or output, number of blocks. */

#include "config.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "librsync.h"
#include "trace.h"

int rs_log_stats(rs_stats_t const *stats)
{
    char buf[1000];

    rs_format_stats(stats, buf, sizeof buf - 1);
    rs_log(RS_LOG_INFO | RS_LOG_NONAME, "%s", buf);
    return 0;
}

char *rs_format_stats(rs_stats_t const *stats, char *buf, size_t size)
{
    char const *op = stats->op;
    int len;
    time_t sec;
    double mbps_in, mbps_out;

    if (!op)
        op = "noop";

    len = snprintf(buf, size, "%s statistics: ", op);
    assert(len > 0);

    if (stats->lit_cmds) {
        len +=
            snprintf(buf + len, size - (size_t) len,
                     "literal[%d cmds, %ju bytes, %ju cmdbytes] ",
                     stats->lit_cmds,
                     (uintmax_t) stats->lit_bytes,
                     (uintmax_t) stats->lit_cmdbytes);
    }

    if (stats->sig_cmds) {
        len +=
            snprintf(buf + len, size - (size_t) len,
                     "in-place-signature[%ju cmds, %ju bytes] ",
                     (uintmax_t) stats->sig_cmds, (uintmax_t) stats->sig_bytes);
    }

    if (stats->copy_cmds || stats->false_matches) {
        len +=
            snprintf(buf + len, size - (size_t) len,
                     "copy[%ju cmds, %ju bytes, %ju cmdbytes, %d false]",
                     (uintmax_t) stats->copy_cmds,
                     (uintmax_t) stats->copy_bytes,
                     (uintmax_t) stats->copy_cmdbytes,
                     stats->false_matches);
    }

    if (stats->sig_blocks) {
        len +=
            snprintf(buf + len, size - (size_t) len,
                     "signature[%ju blocks, %ju bytes per block]",
                     (uintmax_t) stats->sig_blocks,
                     (uintmax_t) stats->block_len);
    }

    sec = (stats->end - stats->start);
    if (sec == 0)
        sec = 1;                // avoid division by zero
    mbps_in = (double) stats->in_bytes / 1e6 / (double) sec;
    mbps_out = (double) stats->out_bytes / 1e6 / (double) sec;
    len +=
        snprintf(buf + len, size - (size_t) len,
                 " speed[%.1f MB (%.1f MB/s) in, %.1f MB (%.1f MB/s) out, %jd sec]",
                 ((double) stats->in_bytes / 1e6), mbps_in,
                 ((double) stats->out_bytes / 1e6), mbps_out, (intmax_t) sec);

    return buf;
}
