#!/bin/sh

if [ -z "$1" ]; then
    cat >&2 <<EOF
Usage: $0 foo
  compiles  map_foo.c
  into      taralli_foo

\$CC overrides the choice of C compiler.
EOF
    exit 1
fi

set -xe

${CC:-cc} -O2 -Wall -std=c99 -pedantic             \
  -I/usr/local/include -L/usr/local/lib -lX11 -lXi \
  -o taralli_$1 main.c map_$1.c
