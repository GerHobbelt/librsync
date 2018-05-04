# Installing librsync {#page_install}

## Requirements

To build librsync you will need:

* A C compiler and appropriate headers and libraries

* [BSDMake] -- i.e. any *BSD Make (NetBSD, FreeBSD, OpenBSD, etc.), old
  OSX bsdmake, pkgsrc bmake, or Simon Gerraty's Bmake & Mk-files.

* [popt] command line parsing library

* [Doxygen] - optional, to build docs

[popt]: http://rpm5.org/files/popt/
[BMake]: http://www.crufty.net/help/sjg/bmake.html
[pkgsrc]: https://pkgsrc.org/
[pkgsrc/devel/bmake]: http://cdn.NetBSD.org/pub/pkgsrc/current/pkgsrc/devel/bmake/
[pkgsrc/pkgtools/bootstrap-mk-files]: http://cdn.NetBSD.org/pub/pkgsrc/current/pkgsrc/pkgtools/bootstrap-mk-files/
[pkgsrc/devel/popt]: http://cdn.NetBSD.org/pub/pkgsrc/current/pkgsrc/devel/popt/
[Doxygen]: https://www.stack.nl/~dimitri/doxygen

## Building

Generate the Makefile by running

    $ mkdir -p build && make MAKEOBJDIRPREFIX=$(pwd)/build

To build the documentation:

    $ make doc

To build and run the tests:

    $ make MAKEOBJDIRPREFIX=$(pwd)/build regress

To install:

    # make MAKEOBJDIRPREFIX=$(pwd)/build DESTDIR=$(pwd)/dist install


## Portability

librsync should be widely portable.  Patches to fix portability bugs are
welcome.

If you are using GNU libc, you might like to use

    MALLOC_CHECK_=2 ./rdiff

to detect some allocation bugs.

librsync has annotations for the SPLINT static checking tool.

