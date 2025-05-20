//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 100

int mandelbrot(int x, int y) {
    double real = x / WIDTH * 4 - 2;
    double imag = y / HEIGHT * 3 - 1;
    double zx = 0, zy = 0, zx2 = 0, zy2 = 0;
    int iter = 0;

    while (zx2 + zy2 < 4 && iter < MAX_ITER) {
        zx2 = zx * zx - zy * zy + real;
        zy2 = 2 * zx * zy + imag;
        zx = zx2;
        zy = zy2;
        iter++;
    }

    if (iter == MAX_ITER) {
        return 0;
    } else {
        return iter;
    }
}

void draw_fractal(int *buffer) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int c = mandelbrot(x, y);
            if (c == 0) {
                buffer[y * WIDTH + x] = 0;
            } else {
                buffer[y * WIDTH + x] = c % 8 + 1;
            }
        }
    }
}

int main() {
    int *buffer = malloc(WIDTH * HEIGHT * sizeof(int));
    draw_fractal(buffer);

    FILE *fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);

    for (int y = HEIGHT - 1; y >= 0; y--) {
        fwrite(buffer + y * WIDTH, sizeof(int), WIDTH, fp);
    }

    fclose(fp);
    free(buffer);
    return 0;
}