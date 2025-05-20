//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: medieval
// Declare thy realm where fractals shall dwell
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the canvas where colors shall dance
struct Canvas {
    int width;
    int height;
    char *buffer;
};

// Create a new canvas, a masterpiece waiting
struct Canvas *canvas_new(int width, int height) {
    struct Canvas *canvas = malloc(sizeof(struct Canvas));
    canvas->width = width;
    canvas->height = height;
    canvas->buffer = malloc(width * height * sizeof(char));
    return canvas;
}

// Dispatch thy fractal warriors to render their wonders
void fractal_render(struct Canvas *canvas,
                     double x1, double y1, double x2, double y2,
                     double zoom, int maxIter) {
    // Calculate the scaling coefficients
    double dx = (x2 - x1) / canvas->width;
    double dy = (y2 - y1) / canvas->height;

    // For each pixel, embark on a perilous quest
    for (int x = 0; x < canvas->width; x++) {
        for (int y = 0; y < canvas->height; y++) {
            double cr = x * dx + x1;
            double ci = y * dy + y1;
            double zr = 0;
            double zi = 0;

            int iter = 0;
            // Solve the quadratic equation to determine its fate
            while (zr * zr + zi * zi < 4 && iter < maxIter) {
                double temp = zr;
                zr = zr * zr - zi * zi + cr;
                zi = 2 * temp * zi + ci;
                iter++;
            }

            // Paint the pixel according to its journey's end
            char c = iter < maxIter ? iter % 16 : ' ';
            canvas->buffer[y * canvas->width + x] = c;
        }
    }
}

// Unveil the tapestry, revealing its hidden beauty
void canvas_print(struct Canvas *canvas) {
    for (int y = 0; y < canvas->height; y++) {
        for (int x = 0; x < canvas->width; x++) {
            printf("%c", canvas->buffer[y * canvas->width + x]);
        }
        printf("\n");
    }
}

// Prepare the stage, setting the parameters for the fractal
int main() {
    // Declare the canvas, a vast expanse of parchment
    struct Canvas *canvas = canvas_new(80, 24);

    // Define the parameters that guide the fractal's creation
    double x1 = -2.0;
    double y1 = -1.4;
    double x2 = 1.0;
    double y2 = 1.4;
    double zoom = 1.0;
    int maxIter = 1000;

    // Command the fractal to render, bringing it to life
    fractal_render(canvas, x1, y1, x2, y2, zoom, maxIter);

    // Present the tapestry, a testament to the power of code
    canvas_print(canvas);

    // Release the canvas, its duty fulfilled
    free(canvas->buffer);
    free(canvas);

    return 0;
}