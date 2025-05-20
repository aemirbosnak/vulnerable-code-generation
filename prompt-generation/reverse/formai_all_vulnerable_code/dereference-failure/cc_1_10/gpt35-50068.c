//FormAI DATASET v1.0 Category: Fractal Generation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// Macros
#define WIDTH 80
#define HEIGHT 40
#define MAX_ITERATIONS 100
#define ESCAPE_RADIUS 2

// Function prototypes
void generate_fractal(int **fractal);
void print_fractal(int **fractal);

// Main function
int main() {
    // Allocate memory for the fractal array
    int **fractal = (int**) malloc(sizeof(int*) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        fractal[i] = (int*) malloc(sizeof(int) * WIDTH);
    }

    // Generate the fractal
    generate_fractal(fractal);

    // Print the fractal
    print_fractal(fractal);

    // Free the memory
    for (int i = 0; i < HEIGHT; i++) {
        free(fractal[i]);
    }
    free(fractal);

    return 0;
}

// Generates the fractal
void generate_fractal(int **fractal) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Convert pixel coordinates to complex number
            double real = (double) x / WIDTH * 3.5 - 2.5;
            double imag = (double) y / HEIGHT * 2.0 - 1.0;
            double complex_num_real = real;
            double complex_num_imag = imag;

            int iterations = 0;
            while (iterations < MAX_ITERATIONS) {
                // Calculate the value of the complex number
                double complex_num_mod = sqrt(complex_num_real * complex_num_real +
                                              complex_num_imag * complex_num_imag);
                if (complex_num_mod > ESCAPE_RADIUS) {
                    // The complex number has escaped, set the pixel value
                    fractal[y][x] = iterations;
                    break;
                }

                // Calculate the next value of the complex number
                double temp_real = complex_num_real * complex_num_real - complex_num_imag * complex_num_imag + real;
                double temp_imag = 2 * complex_num_real * complex_num_imag + imag;
                complex_num_real = temp_real;
                complex_num_imag = temp_imag;

                iterations++;
            }

            if (iterations >= MAX_ITERATIONS) {
                // The complex number did not escape, set the pixel value to 0
                fractal[y][x] = 0;
            }
        }
    }
}

// Prints the fractal to the console
void print_fractal(int **fractal) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Scale the pixel value to a char value (0-255)
            char c = (char) ((double) fractal[y][x] / MAX_ITERATIONS * CHAR_MAX);

            // Print the char to the console
            if (c < CHAR_MAX / 3) {
                printf(" ");
            } else if (c < 2 * CHAR_MAX / 3) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}