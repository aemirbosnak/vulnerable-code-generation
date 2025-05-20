//FormAI DATASET v1.0 Category: Fractal Generation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double re;
    double im;
} complex;

complex add(complex a, complex b) {
    complex sum;
    sum.re = a.re + b.re;
    sum.im = a.im + b.im;
    return sum;
}

complex square(complex z) {
    complex sq;
    sq.re = z.re * z.re - z.im * z.im;
    sq.im = 2 * z.re * z.im;
    return sq;
}

int mandelbrot_iterations(complex c, int max_iter) {
    int iter = 0;
    complex z = {0, 0};
    while (iter < max_iter && z.re * z.re + z.im * z.im < 4) {
        z = add(square(z), c);
        iter++;
    }
    return iter;
}

void print_fractal(char **buffer, int width, int height, double x_min, double x_max, double y_min, double y_max, int max_iter) {
    double x_step = (x_max - x_min) / width;
    double y_step = (y_max - y_min) / height;
    complex c;
    int iterations;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            c.re = x_min + x * x_step;
            c.im = y_min + y * y_step;
            iterations = mandelbrot_iterations(c, max_iter);
            if (iterations == max_iter) {
                (*buffer)[y*width+x] = ' ';
            } else {
                (*buffer)[y*width+x] = 'A' + iterations % 26;
            }
        }
    }
}

int main() {
    int width = 80;
    int height = 40;
    double x_min = -2;
    double x_max = 1.5;
    double y_min = -1;
    double y_max = 1;
    int max_iter = 20;
    char *buffer = (char*)malloc(width * height * sizeof(char));
    print_fractal(&buffer, width, height, x_min, x_max, y_min, y_max, max_iter);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            putchar(buffer[y*width+x]);
        }
        putchar('\n');
    }
    free(buffer);
    return 0;
}