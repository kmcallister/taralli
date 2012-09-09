#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/X.h>
#include <X11/extensions/XInput2.h>

#define WRAP(_var, _from, _to) do { \
    if (*_var == (_from)) {         \
        *_var = (_to);              \
        return;                     \
    }                               \
} while (0)

void map_init(Display *dpy);
void map(int *x, int *y);
