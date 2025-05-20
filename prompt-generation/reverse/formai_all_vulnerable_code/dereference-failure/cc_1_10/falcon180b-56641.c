//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000
#define THRESHOLD 4.0

typedef struct {
    int x;
    int y;
    int iterations;
} Point;

void init(int *img, int w, int h) {
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            img[i * h + j] = 0;
        }
    }
}

void set_pixel(int *img, int x, int y, int color) {
    img[(y * WIDTH) + x] = color;
}

int mandelbrot(double x, double y) {
    int iterations = 0;
    double real = 0, imag = 0;

    while (iterations < MAX_ITERATIONS && abs(real) + abs(imag) <= THRESHOLD) {
        double temp_real = real * real - imag * imag + x;
        imag = 2 * real * imag + y;
        real = temp_real;
        iterations++;
    }

    return iterations;
}

void generate_fractal(int *img, int w, int h) {
    double xmin = -2.0, xmax = 1.0, ymin = -1.5, ymax = 1.5;
    double xscale = (xmax - xmin) / WIDTH;
    double yscale = (ymax - ymin) / HEIGHT;

    srand(time(NULL));

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            double x = xmin + i * xscale;
            double y = ymin + j * yscale;

            int iterations = mandelbrot(x, y);
            int color = iterations % 8 * 32;

            set_pixel(img, i, j, color);
        }
    }
}

int main() {
    int *img = malloc(WIDTH * HEIGHT * sizeof(int));
    init(img, WIDTH, HEIGHT);
    generate_fractal(img, WIDTH, HEIGHT);

    FILE *fp = fopen("fractal.bmp", "wb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    fwrite(img, sizeof(int), WIDTH * HEIGHT, fp);
    fclose(fp);

    printf("Fractal generated successfully!\n");

    return 0;
}