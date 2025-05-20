//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <X11/Xlib.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 100
#define ZOOM 1.0
#define MOVE_X 0.0
#define MOVE_Y 0.0

void draw_fractal(Display *display, Window window) {
    GC gc = XCreateGC(display, window, 0, NULL);
    
    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < HEIGHT; y++) {
            double zx = 1.5 * (x - WIDTH / 2) / (0.5 * ZOOM * WIDTH) + MOVE_X;
            double zy = (y - HEIGHT / 2) / (0.5 * ZOOM * HEIGHT) + MOVE_Y;
            int iteration = 0;

            while (zx * zx + zy * zy < 4 && iteration < MAX_ITER) {
                double tmp = zx * zx - zy * zy + 0.355;
                zy = 2.0 * zx * zy + 0.355;
                zx = tmp;
                iteration++;
            }

            int color = iteration == MAX_ITER ? 0 : (iteration * 255 / MAX_ITER);
            XSetForeground(display, gc, 0x000000 | (color << 16) | (color << 8) | color);
            XDrawPoint(display, window, gc, x, y);
        }
    }

    XFreeGC(display, gc);
}

int main(int argc, char **argv) {
    Display *display;
    Window window;
    XEvent event;

    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Cannot open display\n");
        exit(1);
    }

    window = XCreateSimpleWindow(display, DefaultRootWindow(display), 0, 0, WIDTH, HEIGHT, 0,
                                  BlackPixel(display, 0), WhitePixel(display, 0));

    XSelectInput(display, window, ExposureMask | KeyPressMask);
    XMapWindow(display, window);

    while (1) {
        XNextEvent(display, &event);
        if (event.type == Expose) {
            draw_fractal(display, window);
        }
        if (event.type == KeyPress)
            break;
    }

    XDestroyWindow(display, window);
    XCloseDisplay(display);
    return 0;
}