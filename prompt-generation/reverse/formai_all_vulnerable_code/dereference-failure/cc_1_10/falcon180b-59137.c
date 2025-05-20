//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000
#define MAX_WIDTH 800
#define MAX_HEIGHT 600

int main() {
    int width = MAX_WIDTH;
    int height = MAX_HEIGHT;
    int max_iterations = MAX_ITERATIONS;
    double xmin = -2.0;
    double xmax = 1.0;
    double ymin = -1.5;
    double ymax = 1.5;
    double xscale = (xmax - xmin) / width;
    double yscale = (ymax - ymin) / height;
    int *pixels = (int*)malloc(width * height * sizeof(int));
    for (int i = 0; i < width * height; i++) {
        pixels[i] = 0x00000000; // black
    }
    for (int y = 0; y < height; y++) {
        double yc = ymin + y * yscale;
        for (int x = 0; x < width; x++) {
            double xc = xmin + x * xscale;
            int c = mandelbrot(xc, yc, max_iterations);
            pixels[(y * width + x) * 4] = c << 16 | c << 8 | c;
        }
    }
    FILE *fp = fopen("fractal.bmp", "wb");
    if (fp == NULL) {
        printf("error: could not open output file\n");
        exit(1);
    }
    fwrite(pixels, 1, width * height * 4, fp);
    fclose(fp);
    free(pixels);
    return 0;
}

int mandelbrot(double xc, double yc, int max_iterations) {
    double x = 0;
    double y = 0;
    int iterations = 0;
    while (iterations < max_iterations && (x * x + y * y) < 4.0) {
        double xtemp = x * x - y * y + xc;
        y = 2 * x * y + yc;
        x = xtemp;
        iterations++;
    }
    return iterations % 8;
}