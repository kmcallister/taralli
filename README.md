# `taralli`: Screen edge pointer wrapping for X

The maximum travel distance between points on a desktop is substantially
reduced if the pointer is allowed to travel off a screen edge and reappear at
the opposite edge.  `taralli` is a tiny standalone program for X Windows which,
while running, implements this functionality.  In other words, it changes the
topology of the desktop to be that of a torus.

`taralli` has been tested on GNU/Linux and is likely portable to other X
platforms.  I would appreciate any bug reports and patches, which you can
submit through GitHub.

For the common case of a rectangular desktop, you can build and run `taralli`
like so:

~~~~
$ ./build.sh rectangular
$ ./taralli_rectangular
~~~~


## Customization

Perhaps you have a non-rectangular desktop, composed of several monitors at
different resolutions.  Or you might have different preferences for where the
mouse pointer goes when it reaches a screen edge.  `taralli` supports a simple
form of customization; see `map_beef.c` for an example.  You define a C
function

~~~~ {.c}
void map(int *x, int *y);
~~~~

which receives pointers to the current mouse coordinates, and is allowed to
modify those coordinates.  A macro `WRAP(var, from, to)` is available; it
expands to (roughly)

~~~~ {.c}
if (*var == from) {
    *var = to;
    return;
}
~~~~

Another function

~~~~ {.c}
void map_init(Display *dpy);
~~~~

will run at program start.

You can build and run the customized program with e.g.

~~~~
$ ./build.sh beef
$ ./taralli_beef
~~~~


## License

`taralli` is available under a BSD license.  See the `LICENSE` file.
