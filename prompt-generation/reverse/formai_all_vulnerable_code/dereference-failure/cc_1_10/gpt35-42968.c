//FormAI DATASET v1.0 Category: Fractal Generation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480
#define MAX_ITER 256

// Structure to hold a complex number
typedef struct {
    double real;
    double imag;
} Complex;

// Function to calculate the absolute value of a complex number
double cabs(Complex c) {
    return sqrt((c.real * c.real) + (c.imag * c.imag));
}

// Function to calculate the square of a complex number
Complex csquare(Complex c) {
    Complex result;
    result.real = (c.real * c.real) - (c.imag * c.imag);
    result.imag = 2 * c.real * c.imag;
    return result;
}

// Function to add two complex numbers
Complex cadd(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

// Function to generate the Mandelbrot set
void generateFractal() {
    int x, y, i, k;
    Complex z, c;

    // Allocate memory for the fractal
    int* fractal = (int*) malloc(sizeof(int) * WIDTH * HEIGHT);

    // Loop through each pixel
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {

            // Convert pixel coordinates to complex number
            c.real = ((double) x - (WIDTH / 2)) * 4.0 / WIDTH;
            c.imag = ((double) y - (HEIGHT / 2)) * 4.0 / WIDTH;

            // Initialize z to zero
            z.real = 0;
            z.imag = 0;

            // Iterate until z escapes or maximum number of iterations is reached
            for (i = 0; i < MAX_ITER; i++) {

                // Calculate the next value of z
                z = cadd(csquare(z), c);

                // If z has escaped, color the pixel
                if (cabs(z) > 2) {
                    fractal[y * WIDTH + x] = i;
                    break;
                }
            }

            // If z did not escape, color the pixel black
            if (i == MAX_ITER) {
                fractal[y * WIDTH + x] = 0;
            }
        }
    }

    // Print the fractal to the screen
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            k = fractal[y * WIDTH + x];
            if (k == 0) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }

    // Free memory
    free(fractal);
}

// Main function
int main() {
    generateFractal();
    return 0;
}