//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 100
#define MAX_WIDTH 800
#define MAX_HEIGHT 600
#define MAX_COLOR 255

int mandelbrot(int x, int y, int max_iterations) {
    int iterations = 0;
    double real = 0.0, imag = 0.0;
    double temp_real, temp_imag;

    for (int i = 0; i < max_iterations; i++) {
        temp_real = real * real - imag * imag + x;
        temp_imag = 2.0 * real * imag + y;
        real = temp_real;
        imag = temp_imag;

        if (real * real + imag * imag > 4.0) {
            break;
        }
    }

    return iterations;
}

void generate_fractal(int width, int height, int max_iterations) {
    FILE *fp = fopen("fractal.ppm", "wb");

    fprintf(fp, "P6\n%d %d\n%d\n", width, height, MAX_COLOR);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int value = mandelbrot(x, y, max_iterations);
            int color = (MAX_COLOR - value) * 3;

            fprintf(fp, "%c%c%c", (char)color, (char)color, (char)color);
        }
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    int width = MAX_WIDTH;
    int height = MAX_HEIGHT;
    int max_iterations = MAX_ITERATIONS;

    if (argc >= 4) {
        width = atoi(argv[1]);
        height = atoi(argv[2]);
        max_iterations = atoi(argv[3]);
    }

    generate_fractal(width, height, max_iterations);

    return 0;
}