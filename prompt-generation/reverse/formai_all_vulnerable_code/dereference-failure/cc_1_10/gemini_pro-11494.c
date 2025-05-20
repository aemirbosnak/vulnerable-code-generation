//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

double max_x = 2.0, max_y = 2.0, min_x = -2.0, min_y = -2.0;

int mandelbrot(double x, double y) {
    int iterations = 0;
    double zx = x, zy = y;
    while (iterations < 100 && zx * zx + zy * zy < 4.0) {
        double tmp = zx * zx - zy * zy + x;
        zy = 2.0 * zx * zy + y;
        zx = tmp;
        iterations++;
    }
    return iterations;
}

void generate_fractal(int **image, int x1, int y1, int x2, int y2) {
    if (x2 - x1 < 2 || y2 - y1 < 2) {
        return;
    }
    double dx = (max_x - min_x) / (x2 - x1);
    double dy = (max_y - min_y) / (y2 - y1);
    for (int x = x1; x < x2; x++) {
        for (int y = y1; y < y2; y++) {
            double cx = min_x + x * dx;
            double cy = min_y + y * dy;
            image[x][y] = mandelbrot(cx, cy);
        }
    }
    generate_fractal(image, x1, y1, (x1 + x2) / 2, (y1 + y2) / 2);
    generate_fractal(image, (x1 + x2) / 2, y1, x2, (y1 + y2) / 2);
    generate_fractal(image, x1, (y1 + y2) / 2, (x1 + x2) / 2, y2);
    generate_fractal(image, (x1 + x2) / 2, (y1 + y2) / 2, x2, y2);
}

int main() {
    int **image = malloc(WIDTH * sizeof(int *));
    for (int i = 0; i < WIDTH; i++) {
        image[i] = malloc(HEIGHT * sizeof(int));
    }
    generate_fractal(image, 0, 0, WIDTH, HEIGHT);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%d ", image[x][y]);
        }
        printf("\n");
    }
    for (int i = 0; i < WIDTH; i++) {
        free(image[i]);
    }
    free(image);
    return 0;
}