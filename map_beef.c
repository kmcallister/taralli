#include "common.h"

/* This file provides a map for a machine with
   the following screen layout:

   ┌────────┐┌─────────────────┐┌────────┐
   │        ││                 ││        │
   │        ││                 ││        │
   │  1200  ││   2560 × 1600   ││  1200  │
   │   ×    ││                 ││   ×    │
   │  1920  ││                 ││  1920  │
   │        │└─────────────────┘│        │
   │        │                   │        │
   └────────┘                   └────────┘
*/

void map_init(Display *dpy) {
}

void map(int *x, int *y) {
    int w = 2560 + 1200*2;
    WRAP(x, 0, w-2);
    WRAP(x, w-1, 1);

    int h = ((*x < 1200) || (*x > 1200+2560)) ? 1920 : 1600;
    WRAP(y, 0, h-2);
    WRAP(y, h-1, 1);
}
