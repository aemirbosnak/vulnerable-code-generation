//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <X11/Xlib.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_DEPTH 10
#define ANGLE 30.0

// Function to draw a fractal tree
void drawTree(Display *display, Window window, int x1, int y1, double angle, int depth) {
    // Base case - if depth is greater than MAX_DEPTH, return
    if (depth > MAX_DEPTH) return;

    // Calculate the end point of the branch
    int x2 = x1 + (int)(cos(angle * M_PI / 180) * (depth * 10));
    int y2 = y1 - (int)(sin(angle * M_PI / 180) * (depth * 10));

    // Draw the line for the branch
    XDrawLine(display, window, DefaultGC(display, 0), x1, y1, x2, y2);

    // Recursive calls to draw the branches
    drawTree(display, window, x2, y2, angle - ANGLE, depth + 1);
    drawTree(display, window, x2, y2, angle + ANGLE, depth + 1);
}

int main() {
    // Open a display
    Display *display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Unable to open X display\n");
        return 1;
    }

    // Create a window
    Window window = XCreateSimpleWindow(display, DefaultRootWindow(display), 
                                         0, 0, WIDTH, HEIGHT, 1, 
                                         BlackPixel(display, 0), 
                                         WhitePixel(display, 0));

    // Set up window properties
    XSetStandardProperties(display, window, "Fractal Tree", "Fractal Tree", 
                           None, NULL, 0, NULL);

    // Show the window
    XMapWindow(display, window);
    XFlush(display);
    
    // Set the background color
    XSetWindowBackground(display, window, WhitePixel(display, 0));
    XClearWindow(display, window);

    // Draw the fractal tree starting from the bottom center
    drawTree(display, window, WIDTH / 2, HEIGHT - 50, -90, 0);

    // Wait for user to close the window
    XEvent event;
    while (1) {
        XNextEvent(display, &event);
        if (event.type == ClientMessage) break;
    }

    // Clean up
    XDestroyWindow(display, window);
    XCloseDisplay(display);

    return 0;
}