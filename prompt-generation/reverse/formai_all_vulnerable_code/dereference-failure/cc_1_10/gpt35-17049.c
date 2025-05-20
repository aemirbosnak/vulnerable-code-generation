//FormAI DATASET v1.0 Category: Fractal Generation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_ITER 500 // Maximum number of iterations
#define WIDTH 500 // Width of the image
#define HEIGHT 500 // Height of the image

typedef struct Complex Complex;

struct Complex {
    float real;
    float imag;
};

/**
 * Function to generate a Mandelbrot fractal image
 */
void generateMandelbrotFractal(int max_iter, int width, int height) {
    // Allocate memory for the image
    int *img = calloc(width * height, sizeof(int));

    // Define the range for the complex plane
    float real_min = -2.0;
    float real_max = 1.0;
    float imag_min = -1.0;
    float imag_max = 1.0;

    // Calculate the step size for each pixel
    float real_step = (real_max - real_min) / (width - 1);
    float imag_step = (imag_max - imag_min) / (height - 1);

    // Loop through each pixel and calculate its Mandelbrot value
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Complex c = {real_min + j * real_step, imag_min + i * imag_step};
            Complex z = {0, 0};
            int iter = 0;

            while (iter < max_iter && z.real * z.real + z.imag * z.imag < 4.0) {
                // Do the Mandelbrot iteration
                Complex zz = {z.real * z.real - z.imag * z.imag, 2 * z.real * z.imag};
                z.real = zz.real + c.real;
                z.imag = zz.imag + c.imag;
                iter++;
            }

            // Set the color of the pixel based on the Mandelbrot value
            if (iter == max_iter) {
                img[i * width + j] = 0; // black
            } else {
                img[i * width + j] = iter % 256; // grayscale
            }
        }
    }

    // Write the image to a file
    FILE *f = fopen("mandelbrot.pgm", "w");
    fprintf(f, "P2\n%d %d\n255\n", width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(f, "%d ", img[i * width + j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);

    // Free the memory
    free(img);
}

/**
 * Function to generate a Julia fractal image
 */
void generateJuliaFractal(int max_iter, int width, int height) {
    // Allocate memory for the image
    int *img = calloc(width * height, sizeof(int));

    // Define the constant value for the Julia set
    Complex c = {-0.8, 0.156};

    // Define the range for the complex plane
    float real_min = -2.0;
    float real_max = 2.0;
    float imag_min = -2.0;
    float imag_max = 2.0;

    // Calculate the step size for each pixel
    float real_step = (real_max - real_min) / (width - 1);
    float imag_step = (imag_max - imag_min) / (height - 1);

    // Loop through each pixel and calculate its Mandelbrot value
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Complex z = {real_min + j * real_step, imag_min + i * imag_step};
            int iter = 0;

            while (iter < max_iter && z.real * z.real + z.imag * z.imag < 4.0) {
                // Do the Julia iteration
                Complex zz = {z.real * z.real - z.imag * z.imag, 2 * z.real * z.imag};
                z.real = zz.real + c.real;
                z.imag = zz.imag + c.imag;
                iter++;
            }

            // Set the color of the pixel based on the Mandelbrot value
            if (iter == max_iter) {
                img[i * width + j] = 0; // black
            } else {
                img[i * width + j] = iter % 256; // grayscale
            }
        }
    }

    // Write the image to a file
    FILE *f = fopen("julia.pgm", "w");
    fprintf(f, "P2\n%d %d\n255\n", width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(f, "%d ", img[i * width + j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);

    // Free the memory
    free(img);
}

int main() {
    generateMandelbrotFractal(MAX_ITER, WIDTH, HEIGHT);
    generateJuliaFractal(MAX_ITER, WIDTH, HEIGHT);

    return 0;
}