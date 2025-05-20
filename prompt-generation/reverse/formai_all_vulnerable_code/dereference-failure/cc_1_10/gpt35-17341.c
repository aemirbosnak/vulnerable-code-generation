//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 120
#define HEIGHT 60
#define MAX_ITERATIONS 1000

typedef struct {
    double re;
    double im;
} complex_t;

void print_fractal(double *data) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            putchar(data[x + y * WIDTH] < MAX_ITERATIONS ? '#' : '.');
        }
        putchar('\n');
    }
}

int iterate_mandelbrot(complex_t c) {
    complex_t z = {0, 0};
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        if (z.re * z.re + z.im * z.im > 4) {
            return i;
        }
        complex_t new_z = {z.re * z.re - z.im * z.im + c.re, 2 * z.re * z.im + c.im};
        z = new_z;
    }
    return MAX_ITERATIONS;
}

void generate_mandelbrot(double *data) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double re = (double)x / WIDTH * 4 - 2;
            double im = (double)y / HEIGHT * 4 - 2;
            complex_t c = {re, im};
            data[x + y * WIDTH] = iterate_mandelbrot(c);
        }
    }
}

int main() {
    double *data = malloc(sizeof(double) * WIDTH * HEIGHT);
    generate_mandelbrot(data);
    print_fractal(data);
    free(data);
    return 0;
}