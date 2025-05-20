//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <X11/Xlib.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 1000

// Function to map a point on the complex plane to pixel coordinates
void drawMandelbrot(Display *display, Window window) {
    unsigned long black, white;
    XGCValues values;
    GC gc;
    black = BlackPixel(display, DefaultScreen(display));
    white = WhitePixel(display, DefaultScreen(display));
    
    // Acquire Graphics Context
    gc = XCreateGC(display, window, 0, &values);
    XSetForeground(display, gc, black);
    
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            double zx = 1.5 * (x - WIDTH / 2) / (0.5 * WIDTH);
            double zy = (y - HEIGHT / 2) / (0.5 * HEIGHT);
            int i = 0;

            while (zx * zx + zy * zy < 4.0 && i < MAX_ITER) {
                double tmp = zx * zx - zy * zy + -0.7;
                zy = 2.0 * zx * zy + 0.27015;
                zx = tmp;
                i++;
            }
            
            // Color based on iterations
            if (i < MAX_ITER) {
                XSetForeground(display, gc, i * 255 / MAX_ITER);
            } else {
                XSetForeground(display, gc, 0);
            }
            XDrawPoint(display, window, gc, x, y);
        }
    }
    
    XFreeGC(display, gc);
}

// Window creation and event handling
void createWindow() {
    Display *display;
    Window window;
    XEvent event;

    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Cannot open display\n");
        exit(1);
    }

    window = XCreateSimpleWindow(display, DefaultRootWindow(display), 0, 0, WIDTH, HEIGHT, 0, BlackPixel(display, 0), WhitePixel(display, 0));
    XSelectInput(display, window, ExposureMask | KeyPressMask);
    XMapWindow(display, window);

    while (1) {
        XNextEvent(display, &event);
        if (event.type == Expose) {
            drawMandelbrot(display, window);
        }
        if (event.type == KeyPress) break;
    }

    XCloseDisplay(display);
}

int main() {
    createWindow();
    return 0;
}