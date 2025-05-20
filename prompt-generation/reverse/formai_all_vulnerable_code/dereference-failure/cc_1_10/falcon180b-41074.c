//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 1000

int mandelbrot(double x, double y) {
    double real = 0;
    double imag = 0;
    int iter = 0;

    while (iter < MAX_ITER && (real * real + imag * imag) < 4) {
        double temp_real = real * real - imag * imag + x;
        imag = 2 * real * imag + y;
        real = temp_real;
        iter++;
    }

    return iter;
}

void render_fractal(int *pixels, int width, int height) {
    double xmin = -2;
    double xmax = 1;
    double ymin = -1.5;
    double ymax = 1.5;

    double xscale = (xmax - xmin) / width;
    double yscale = (ymax - ymin) / height;

    for (int i = 0; i < width; i++) {
        double x = xmin + i * xscale;

        for (int j = 0; j < height; j++) {
            double y = ymin + j * yscale;

            int iter = mandelbrot(x, y);
            int color = iter % 8 * 32;

            pixels[(j * width + i) * 3] = color;
            pixels[(j * width + i) * 3 + 1] = color;
            pixels[(j * width + i) * 3 + 2] = color;
        }
    }
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int *pixels = malloc(WIDTH * HEIGHT * 3 * sizeof(int));

    render_fractal(pixels, WIDTH, HEIGHT);

    FILE *fp = fopen("fractal.ppm", "wb");
    if (fp == NULL) {
        printf("Error: Could not create file.\n");
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, 255);

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        fprintf(fp, "%d %d %d ", pixels[i * 3], pixels[i * 3 + 1], pixels[i * 3 + 2]);
    }

    fclose(fp);

    free(pixels);

    return 0;
}