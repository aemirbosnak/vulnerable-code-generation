//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000

// Function to calculate the fractal
void mandelbrot(int x, int y, int max_iterations, unsigned char* buffer) {
    int iter = 0;
    double real = x / WIDTH * 4.0 - 2.0;
    double imag = y / HEIGHT * 3.0 - 1.5;

    while (iter < max_iterations && pow(real, 2.0) + pow(imag, 2.0) < 4.0) {
        double new_real = pow(real, 2.0) - imag + x / WIDTH * 4.0 - 2.0;
        double new_imag = 2.0 * real * imag + y / HEIGHT * 3.0 - 1.5;
        real = new_real;
        imag = new_imag;
        iter++;
    }

    if (iter == max_iterations) {
        buffer[y * WIDTH + x] = 0;
    } else {
        buffer[y * WIDTH + x] = iter % 8;
    }
}

// Function to generate the fractal image
void generate_fractal() {
    unsigned char* buffer = (unsigned char*)malloc(WIDTH * HEIGHT);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            mandelbrot(x, y, MAX_ITERATIONS, buffer);
        }
    }

    FILE* fp = fopen("fractal.bmp", "wb");
    if (fp == NULL) {
        printf("Error creating fractal.bmp\n");
        exit(1);
    }

    fwrite(buffer, 1, WIDTH * HEIGHT * 3, fp);

    fclose(fp);
}

int main() {
    generate_fractal();
    return 0;
}