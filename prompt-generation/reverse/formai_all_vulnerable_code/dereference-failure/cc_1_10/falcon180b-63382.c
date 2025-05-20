//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 1000

int mandelbrot(int x, int y) {
    double real = (double)x / WIDTH * 3.0 - 2.0;
    double imag = (double)y / HEIGHT * 2.0 - 1.0;

    int iter = 0;
    double zx = 0, zy = 0;

    while (iter < MAX_ITER && zx * zx + zy * zy < 4) {
        double tmp = zx * zx - zy * zy + real;
        zy = 2 * zx * zy + imag;
        zx = tmp;
        iter++;
    }

    return iter;
}

int main() {
    int **buffer = malloc(HEIGHT * sizeof(int*));
    for (int i = 0; i < HEIGHT; i++) {
        buffer[i] = malloc(WIDTH * sizeof(int));
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int value = mandelbrot(x, y);
            if (value == MAX_ITER) {
                buffer[y][x] = 0;
            } else {
                buffer[y][x] = value % 8;
            }
        }
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%d ", buffer[y][x]);
        }
        printf("\n");
    }

    for (int i = 0; i < HEIGHT; i++) {
        free(buffer[i]);
    }
    free(buffer);

    return 0;
}