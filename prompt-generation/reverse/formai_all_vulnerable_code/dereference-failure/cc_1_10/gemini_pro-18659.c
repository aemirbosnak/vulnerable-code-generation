//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a complex number
typedef struct complex {
    double real;
    double imaginary;
} complex;

// Function to initialize a complex number
complex c_init(double real, double imaginary) {
    complex c;
    c.real = real;
    c.imaginary = imaginary;
    return c;
}

// Function to add two complex numbers
complex c_add(complex a, complex b) {
    complex c;
    c.real = a.real + b.real;
    c.imaginary = a.imaginary + b.imaginary;
    return c;
}

// Function to multiply two complex numbers
complex c_multiply(complex a, complex b) {
    complex c;
    c.real = a.real * b.real - a.imaginary * b.imaginary;
    c.imaginary = a.real * b.imaginary + a.imaginary * b.real;
    return c;
}

// Function to calculate the absolute value of a complex number
double c_abs(complex c) {
    return sqrt(c.real * c.real + c.imaginary * c.imaginary);
}

// Function to generate a fractal image
void generate_fractal(int width, int height, double xmin, double xmax, double ymin, double ymax, int max_iterations) {
    // Create a 2D array to store the fractal values
    int **fractal = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        fractal[i] = malloc(sizeof(int) * width);
    }

    // Iterate over each pixel in the image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Calculate the complex number corresponding to the pixel
            complex c = c_init(xmin + (xmax - xmin) * x / width, ymin + (ymax - ymin) * y / height);

            // Initialize the iteration count
            int iterations = 0;

            // Iterate until the complex number escapes the Mandelbrot set or the maximum number of iterations is reached
            while (iterations < max_iterations && c_abs(c) < 2) {
                // Calculate the next complex number in the sequence
                c = c_add(c, c_multiply(c, c));

                // Increment the iteration count
                iterations++;
            }

            // Set the pixel value based on the number of iterations
            fractal[y][x] = iterations;
        }
    }

    // Write the fractal image to a file
    FILE *fp = fopen("fractal.ppm", "w");
    fprintf(fp, "P3\n%d %d\n255\n", width, height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int color = 255 * fractal[y][x] / max_iterations;
            fprintf(fp, "%d %d %d\n", color, color, color);
        }
    }
    fclose(fp);

    // Free the memory allocated for the fractal array
    for (int i = 0; i < height; i++) {
        free(fractal[i]);
    }
    free(fractal);
}

int main() {
    // Define the parameters of the fractal
    int width = 1024;
    int height = 768;
    double xmin = -2.0;
    double xmax = 1.0;
    double ymin = -1.5;
    double ymax = 1.5;
    int max_iterations = 1000;

    // Generate the fractal image
    generate_fractal(width, height, xmin, xmax, ymin, ymax, max_iterations);

    return 0;
}