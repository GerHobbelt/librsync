#! /usr/bin/perl -w

use strict;

# librsync -- the library for network deltas
# $Id$
# 
# Copyright (C) 2000, 2001 by Martin Pool <mbp@samba.org>
# 
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public License
# as published by the Free Software Foundation; either version 2.1 of
# the License, or (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public
# License along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.


                                     # I think if you've ordered
				     # somebody to do something you
				     # should probably resist the urge
				     # to thank them.
				     #    -- http://abc.net.au/thegames/


$#ARGV == 1 or die "Usage: mkprototab.pl TABLE HEADER";

open(TABLE, ">$ARGV[0]") or die "Can't open table $ARGV[0]: $!";
open(HEADER, ">$ARGV[1]") or die "Can't open header $ARGV[1]: $!";


my $cmd_byte = 0;


sub emit_cmd {
  my ($kind, $lit_val, $len1, $len2) = @_;
  my $op;
  
  if ($cmd_byte) {
    # not first
    print TABLE ",\n";
    print HEADER ",\n";
  }
  
  if ($len2) {
    $op = sprintf "RS_OP_%s_N%d_N%d", $kind, $len1, $len2;
  } elsif ($len1) {
    $op = sprintf "RS_OP_%s_N%d", $kind, $len1;
  } elsif ($lit_val) {
    $op = sprintf "RS_OP_%s_%d", $kind, $lit_val;
  } else {
    $op = sprintf "RS_OP_%s", $kind;
  }
  
  push(@_, 0) while @_ < 4; # Avoid run-time warnings.
  printf TABLE "    {RS_KIND_%-10s, %3d, %d, %d } ", @_;
  printf TABLE "     /* %20s = %#4x */", $op, $cmd_byte;
  printf HEADER "   %20s = %#4x", $op, $cmd_byte;
  $cmd_byte++;
}


print TABLE <<EOT;
/* AUTOGENERATED BY $0, DO NOT EDIT */

#include <config.h>

#include <stdlib.h>
#include <stdio.h>

#include "librsync.h"
#include "protocol.h"
#include "command.h"
#include "prototab.h"

/* This file defines an array mapping command IDs to the operation kind,
 * implied literal value, and length of the first and second parameters.
 * The implied value is only used
 * if the first parameter length is zero. */

const struct rs_prototab_ent rs_prototab[] = {
EOT


print HEADER <<EOT;
/* AUTOGENERATED BY $0, DO NOT EDIT */

typedef struct rs_prototab_ent {
    enum rs_op_kind     kind;
    int                 immediate;
    size_t              len_1, len_2;
} rs_prototab_ent_t;

extern const rs_prototab_ent_t rs_prototab[];

enum {
EOT


emit_cmd('END');

my @int_lens = (1, 2, 4, 8);

my ($i, $j);

for ($i = 1; $i <= 64; $i++) {
  emit_cmd('LITERAL', $i);
}

foreach $i (@int_lens) {
  emit_cmd('LITERAL', 0, $i);
}

foreach $i (@int_lens) {
  foreach $j (@int_lens) {
    emit_cmd('COPY', 0, $i, $j);
  }
}

emit_cmd('RESERVED', $cmd_byte, 0, 0) while $cmd_byte <= 255;


print TABLE <<EOT;
};
/* END OF AUTOGENERATED CODE */
EOT

print HEADER <<EOT;
};
/* END OF AUTOGENERATED CODE */
EOT

