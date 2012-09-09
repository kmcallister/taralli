#include "common.h"

/* This file provides a map which assumes the entire
   rectangular display area is viewable. */

static int width, height;

void map_init(Display *dpy) {
    int screen = DefaultScreen(dpy);
    width  = DisplayWidth (dpy, screen);
    height = DisplayHeight(dpy, screen);
}

void map(int *x, int *y) {
    WRAP(x, 0, width-2);
    WRAP(x, width-1, 1);
    WRAP(y, 0, height-2);
    WRAP(y, height-1, 1);
}
