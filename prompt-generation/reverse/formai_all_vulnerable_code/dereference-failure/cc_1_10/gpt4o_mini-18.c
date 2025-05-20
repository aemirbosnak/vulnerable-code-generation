//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 256

// Cyberpunk colors
unsigned long color_palette[MAX_ITER];

void generate_color_palette() {
    for (int i = 0; i < MAX_ITER; i++) {
        int r = (i * 5) % 256;
        int g = (i * 10) % 256;
        int b = (i * 15) % 256;
        color_palette[i] = (r << 16) | (g << 8) | b; // RGB color format
    }
}

int mandelbrot(double real, double imag) {
    double z_real = 0, z_imag = 0;
    int n;
    
    for (n = 0; n < MAX_ITER; n++) {
        if (z_real * z_real + z_imag * z_imag > 4.0) break;
        double temp_real = z_real * z_real - z_imag * z_imag + real;
        z_imag = 2 * z_real * z_imag + imag;
        z_real = temp_real;
    }
    
    return n;
}

void draw_fractal(Display *display, Window window) {
    GC gc = XCreateGC(display, window, 0, NULL);
    XSetForeground(display, gc, 0x000000); // Black background
    XFillRectangle(display, window, gc, 0, 0, WIDTH, HEIGHT);

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            double real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            double imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
            int iter = mandelbrot(real, imag);
            XSetForeground(display, gc, color_palette[iter]);
            XDrawPoint(display, window, gc, x, y);
        }
    }

    XFreeGC(display, gc);
}

void handle_input(Display *display) {
    XEvent event;
    while (1) {
        XNextEvent(display, &event);
        if (event.type == KeyPress) {
            KeySym key = XLookupKeysym(&event.xkey, 0);
            if (key == XK_Escape) break; // Exit on Esc key
        }
    }
}

int main() {
    // Setting up the X11 window
    Display *display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Cannot open display\n");
        exit(1);
    }

    Window window = XCreateSimpleWindow(display, DefaultRootWindow(display), 0, 0, WIDTH, HEIGHT, 1, 0x000000, 0xFFFFFF);
    XSelectInput(display, window, ExposureMask | KeyPressMask);
    XMapWindow(display, window);
    
    // Generate the cyberpunk color palette
    generate_color_palette();

    // Draw the fractal
    draw_fractal(display, window);
    
    // Handle keyboard input
    handle_input(display);

    // Clean up
    XDestroyWindow(display, window);
    XCloseDisplay(display);
    return 0;
}