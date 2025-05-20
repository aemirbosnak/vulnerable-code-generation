//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000

int mandelbrot(double x, double y) {
    int iter = 0;
    double real = 0, imag = 0;

    while (iter < MAX_ITER && abs(real) + abs(imag) <= 2) {
        double temp_real = real * real - imag * imag + x;
        imag = 2 * real * imag + y;
        real = temp_real;
        iter++;
    }

    return iter;
}

void generate_fractal(int *pixels) {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            double real = (double)x / WIDTH * 3.5 - 2.5;
            double imag = (double)y / HEIGHT * 2 - 1;

            int value = mandelbrot(real, imag);

            if (value == MAX_ITER) {
                pixels[y * WIDTH + x] = 0; // black
            } else {
                int r = value % 8 * 32;
                int g = value % 16 * 16;
                int b = value % 32 * 8;

                pixels[y * WIDTH + x] = r << 16 | g << 8 | b; // RGB
            }
        }
    }
}

int main() {
    int *pixels = malloc(WIDTH * HEIGHT * sizeof(int));
    generate_fractal(pixels);

    FILE *fp = fopen("mandelbrot.bmp", "wb");
    if (fp == NULL) {
        printf("Error: Could not create file.\n");
        exit(1);
    }

    fwrite("BM", 2, 1, fp);
    fwrite(&(int){ 0 }, 4, 1, fp);
    fwrite(&(int){ 54 + 40 * 3 }, 4, 1, fp);
    fwrite(&(int){ WIDTH }, 4, 1, fp);
    fwrite(&(int){ HEIGHT }, 4, 1, fp);
    fwrite(&(int){ 24 }, 4, 1, fp);

    for (int i = 0; i < HEIGHT; i++) {
        fwrite(pixels + i * WIDTH, 3, WIDTH, fp);
    }

    fclose(fp);
    free(pixels);

    return 0;
}