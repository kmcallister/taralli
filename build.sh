#!/bin/sh

if [ -z "$1" ]; then
    echo "Usage: $0 foo" >&2
    echo "  compiles  map_foo.c" >&2
    echo "  into      taralli_foo" >&2
    exit 1
fi

set -xe

gcc -O2 -Wall -std=c99 -pedantic -o taralli_$1 main.c map_$1.c -lX11 -lXi
