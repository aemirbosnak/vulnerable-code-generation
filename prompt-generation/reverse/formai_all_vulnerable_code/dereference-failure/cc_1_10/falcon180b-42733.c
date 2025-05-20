//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of iterations
#define MAX_ITERATIONS 100

// Define the complex number data type
typedef struct {
    float real;
    float imag;
} Complex;

// Define the function to calculate the fractal
void fractal(Complex z, Complex c, int iterations) {
    Complex z_prev = z;
    Complex temp;

    for (int i = 0; i < iterations; i++) {
        // Calculate the next iteration
        temp.real = z.real * z.real - z.imag * z.imag + c.real;
        temp.imag = 2 * z.real * z.imag + c.imag;
        z.real = temp.real;
        z.imag = temp.imag;

        // Check for convergence
        if (z.real * z.real + z.imag * z.imag > 4) {
            return;
        }
    }

    // Color the pixel based on the number of iterations
    if (iterations == MAX_ITERATIONS) {
        printf("*");
    } else {
        printf(" ");
    }
}

// Define the main function to generate the fractal
void mandelbrot(float xmin, float xmax, float ymin, float ymax, float scale) {
    float x, y;
    int iterations;

    for (y = ymin; y <= ymax; y += scale) {
        for (x = xmin; x <= xmax; x += scale) {
            // Calculate the complex number for the current pixel
            Complex z = {x, y};
            Complex c = {-0.75, 0.0};

            // Calculate the fractal
            iterations = 0;
            fractal(z, c, iterations);
        }
        printf("\n");
    }
}

// Define the main function to run the program
int main(int argc, char* argv[]) {
    // Parse command line arguments for scale and number of iterations
    if (argc < 3) {
        printf("Usage: %s <scale> <iterations>\n", argv[0]);
        return 1;
    }

    float scale = atof(argv[1]);
    int iterations = atoi(argv[2]);

    // Generate the fractal
    mandelbrot(-2.0, 1.0, -1.5, 1.5, scale);

    return 0;
}