//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000

int mandelbrot(int x, int y, int max_iterations) {
    double real = (double)x / WIDTH * 4.0 - 2.0;
    double imag = (double)y / HEIGHT * 3.0 - 1.5;

    int iterations = 0;
    double zx = 0, zy = 0;

    while (iterations < max_iterations && zx * zx + zy * zy <= 4.0) {
        double temp = zx * zx - zy * zy + real;
        zy = 2.0 * zx * zy + imag;
        zx = temp;
        iterations++;
    }

    return iterations;
}

void generate_fractal(int *pixels) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int iterations = mandelbrot(x, y, MAX_ITERATIONS);
            int color = iterations % 8 * 32;

            pixels[y * WIDTH + x] = color;
        }
    }
}

int main() {
    int *pixels = malloc(WIDTH * HEIGHT * sizeof(int));

    generate_fractal(pixels);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int color = pixels[y * WIDTH + x];
            printf("#%02X%02X%02X ", (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
        }
        printf("\n");
    }

    free(pixels);

    return 0;
}