//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: single-threaded
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000

// Function to map complex point to pixel coordinates 
void mandelbrot_set(Display *display, Window window) {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            double zx = 1.5 * (x - WIDTH / 2) / (0.5 * WIDTH);
            double zy = (y - HEIGHT / 2) / (0.5 * HEIGHT);
            int i = MAX_ITER;
            while (zx * zx + zy * zy < 4 && i > 0) {
                double tmp = zx * zx - zy * zy + -0.7; // real part
                zy = 2.0 * zx * zy + 0.27015; // imaginary part
                zx = tmp;
                i--;
            }

            // Convert i to a color
            int color = (255 * (MAX_ITER - i)) / MAX_ITER;
            XSetForeground(display, DefaultGC(display, 0), color);
            XDrawPoint(display, window, DefaultGC(display, 0), x, y);
        }
    }
}

int main() {
    Display *display;
    Window window;

    // Open the connection to the X server
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Unable to open X display\n");
        return -1;
    }

    // Create a simple window
    window = XCreateSimpleWindow(display, DefaultRootWindow(display), 0, 0, WIDTH, HEIGHT, 0, 0, 0);
    XMapWindow(display, window);
    XFlush(display);
    sleep(1); // Wait for window to open

    // Generate the Mandelbrot set
    mandelbrot_set(display, window);

    // Wait for a few seconds to display the fractal
    sleep(5);

    // Clean up
    XDestroyWindow(display, window);
    XCloseDisplay(display);
    return 0;
}