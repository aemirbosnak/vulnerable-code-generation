//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <X11/Xlib.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000

// Function to compute the color based on the number of iterations
int get_color(int iterations) {
    if (iterations == MAX_ITER) {
        return 0; // Black for points in the set
    }
    return (255 * iterations) / MAX_ITER; // Gradient shading
}

// Main function to generate and display the Mandelbrot fractal
int main() {
    Display *display;
    Window window;
    GC gc;

    // Open a connection to the X server
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Could not open X display\n");
        return EXIT_FAILURE;
    }

    // Create a window
    window = XCreateSimpleWindow(display, DefaultRootWindow(display), 0, 0, WIDTH, HEIGHT, 1, 0, 0);
    XSetStandardProperties(display, window, "Mandelbrot Set", "Mandelbrot", None, NULL, 0, NULL);
    
    // Create a graphics context
    gc = XCreateGC(display, window, 0, NULL);
    XSetBackground(display, gc, 0);
    XSetForeground(display, gc, 255); // Initially set to white

    // Make the window visible
    XMapWindow(display, window);
    
    // Listen for events, but we are focusing on displaying the fractal here
    XFlush(display);
    
    // Mandelbrot fractal generation
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            double real = (x - WIDTH / 2.0) * 4.0 / WIDTH; // Scale to [-2.0, 2.0]
            double imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT; // Scale to [-2.0, 2.0]

            double z_real = 0;
            double z_imag = 0;
            int iterations = 0;

            while ((z_real * z_real + z_imag * z_imag <= 4.0) && (iterations < MAX_ITER)) {
                double z_real_temp = z_real * z_real - z_imag * z_imag + real;
                z_imag = 2.0 * z_real * z_imag + imag;
                z_real = z_real_temp;
                iterations++;
            }

            // Get the color for the pixel
            int color = get_color(iterations);
            XSetForeground(display, gc, color * 0x010101); // Convert to grayscale
            
            // Draw the pixel
            XDrawPoint(display, window, gc, x, y);
        }
    }

    // Keep the window open until it's closed by the user
    XEvent event;
    while (1) {
        XNextEvent(display, &event);
        if (event.type == DestroyNotify) {
            break;
        }
    }

    // Cleanup resources
    XFreeGC(display, gc);
    XDestroyWindow(display, window);
    XCloseDisplay(display);

    return EXIT_SUCCESS;
}