//FormAI DATASET v1.0 Category: Fractal Generation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 24

// color code
#define BLACK 40
#define WHITE 47

// iteration limit for fractal generation
#define ITER_LIMIT 255

void plot_fractal(char *img, int row, int col, int color) {
    img[row * WIDTH + col] = color;
}

// calculate complex numbers addition
void add_complex(double *a, double *b, double *c) {
    c[0] = a[0] + b[0];
    c[1] = a[1] + b[1];
}

// calculate complex numbers square
void square_complex(double *a, double *b) {
    b[0] = a[0] * a[0] - a[1] * a[1];
    b[1] = 2 * a[0] * a[1];
}

// calculate magnitude of complex number
double magnitude_complex(double *a) {
    return sqrt(a[0] * a[0] + a[1] * a[1]);
}

// main fractal generation function
int mandelbrot(double *c) {
    double z[2] = {0.0, 0.0};
    int i;

    for (i = 0; i < ITER_LIMIT; i++) {
        if (magnitude_complex(z) > 2) {
            return i;
        }
        square_complex(z, z);
        add_complex(z, c, z);
    }
    return ITER_LIMIT;
}

int main() {
    char *image = calloc(WIDTH * HEIGHT, sizeof(char));
    double c[2];
    int row, col, color;

    for (row = 0; row < HEIGHT; row++) {
        for (col = 0; col < WIDTH; col++) {
            // convert pixel coordinates to complex number
            c[0] = (col - WIDTH / 2.0) * 4.0 / WIDTH;
            c[1] = (row - HEIGHT / 2.0) * 4.0 / WIDTH;

            color = BLACK;
            if (mandelbrot(c) == ITER_LIMIT) {
                color = WHITE;
            }
            plot_fractal(image, row, col, color);
        }
    }

    // print fractal image to console
    for (row = 0; row < HEIGHT; row++) {
        for (col = 0; col < WIDTH; col++) {
            if (image[row * WIDTH + col] == BLACK) {
                printf("\033[0;30m ");
            } else {
                printf("\033[0;37m ");
            }
        }
        printf("\n");
    }

    free(image);

    return 0;
}