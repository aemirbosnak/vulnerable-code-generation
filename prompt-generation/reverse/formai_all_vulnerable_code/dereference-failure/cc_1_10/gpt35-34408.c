//FormAI DATASET v1.0 Category: Fractal Generation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Complex {
    double real;
    double imag;
} Complex;

Complex add(Complex a, Complex b) {
    Complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

Complex mul(Complex a, Complex b) {
    Complex c;
    c.real = a.real * b.real - a.imag * b.imag;
    c.imag = a.real * b.imag + a.imag * b.real;
    return c;
}

int get_iteration(double x0, double y0, int max_iter) {
    Complex z, c;
    z.real = 0;
    z.imag = 0;
    c.real = x0;
    c.imag = y0;
    int iter;
    for (iter = 0; iter < max_iter; iter++) {
        z = add(mul(z, z), c);
        double mod = sqrt(z.real * z.real + z.imag * z.imag);
        if (mod > 2) {
            break;
        }
    }
    return iter;
}

void generate_fractal(double min_x, double max_x, double min_y, double max_y, int width, int height, int max_iter) {
    char *pixels = (char*)malloc(width * height * sizeof(char));
    double x_range = max_x - min_x;
    double y_range = max_y - min_y;
    double x_step = x_range / width;
    double y_step = y_range / height;
    int i, j;
    double x, y;
    for (j = 0; j < height; j++) {
        y = max_y - j * y_step;
        for (i = 0; i < width; i++) {
            x = min_x + i * x_step;
            int iter = get_iteration(x, y, max_iter);
            char pixel = (iter == max_iter) ? ' ' : 32 + iter % 64;
            pixels[j * width + i] = pixel;
        }
    }
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            putchar(pixels[j * width + i]);
        }
        putchar('\n');
    }
    free(pixels);
}

int main() {
    generate_fractal(-2, 2, -2, 2, 80, 40, 100);
    return 0;
}