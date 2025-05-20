//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000
#define THRESHOLD 4.0

// Function to calculate the Mandelbrot value for a given complex number
double mandelbrot(double real, double imag) {
    double zx = 0, zy = 0, zx_squared = 0, zy_squared = 0;
    int iterations = 0;

    while (iterations < MAX_ITERATIONS && zx_squared + zy_squared <= THRESHOLD) {
        double temp_real = zx_squared - zy_squared + real;
        zy = 2 * zx * zy + imag;
        zx = temp_real;
        zx_squared = zx * zx;
        zy_squared = zy * zy;
        iterations++;
    }

    return iterations;
}

// Function to generate the fractal image and save it to a file
void generate_fractal(char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    unsigned char *buffer = (unsigned char *)malloc(WIDTH * HEIGHT * 3);
    if (buffer == NULL) {
        printf("Error allocating memory for buffer\n");
        exit(1);
    }

    double xmin = -2.0, xmax = 1.0, ymin = -1.5, ymax = 1.5;
    double dx = (xmax - xmin) / WIDTH;
    double dy = (ymax - ymin) / HEIGHT;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double c_real = xmin + x * dx;
            double c_imag = ymin + y * dy;
            int value = mandelbrot(c_real, c_imag);

            double r = value / MAX_ITERATIONS;
            double g = 0;
            double b = 0;

            if (value == MAX_ITERATIONS) {
                r = g = b = 1.0;
            }

            int index = (y * WIDTH + x) * 3;
            buffer[index] = (unsigned char)(r * 255.0);
            buffer[index + 1] = (unsigned char)(g * 255.0);
            buffer[index + 2] = (unsigned char)(b * 255.0);
        }
    }

    fwrite(buffer, 1, WIDTH * HEIGHT * 3, fp);
    fclose(fp);
    free(buffer);
}

int main() {
    char filename[100] = "mandelbrot.bmp";
    generate_fractal(filename);
    printf("Fractal image saved as %s\n", filename);
    return 0;
}