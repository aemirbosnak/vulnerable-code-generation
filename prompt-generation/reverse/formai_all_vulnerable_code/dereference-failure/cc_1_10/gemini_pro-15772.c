//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Complex number structure
typedef struct {
    double real;
    double imag;
} complex;

// Function to add two complex numbers
complex add(complex a, complex b) {
    complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

// Function to multiply two complex numbers
complex multiply(complex a, complex b) {
    complex c;
    c.real = a.real * b.real - a.imag * b.imag;
    c.imag = a.real * b.imag + a.imag * b.real;
    return c;
}

// Function to calculate the next iteration of the Mandelbrot set
complex mandelbrot(complex z, complex c) {
    return add(multiply(z, z), c);
}

// Function to generate a Mandelbrot set image
void generate_mandelbrot(int width, int height, double xmin, double xmax, double ymin, double ymax) {
    // Create an image array
    unsigned char *image = malloc(width * height * sizeof(unsigned char));

    // Iterate over each pixel in the image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Calculate the corresponding complex number for the pixel
            complex c;
            c.real = xmin + (xmax - xmin) * x / width;
            c.imag = ymin + (ymax - ymin) * y / height;

            // Initialize the complex number for the pixel
            complex z;
            z.real = 0.0;
            z.imag = 0.0;

            // Iterate over the maximum number of iterations
            int max_iterations = 256;

            // Check if the pixel is in the Mandelbrot set
            int in_set = 1;
            for (int i = 0; i < max_iterations; i++) {
                // Calculate the next iteration of the Mandelbrot set
                z = mandelbrot(z, c);

                // Check if the pixel is outside the Mandelbrot set
                if (z.real * z.real + z.imag * z.imag > 4.0) {
                    in_set = 0;
                    break;
                }
            }

            // Set the pixel color based on whether it is in the Mandelbrot set
            image[y * width + x] = in_set ? 0 : 255;
        }
    }

    // Write the image to a file
    FILE *file = fopen("mandelbrot.ppm", "wb");
    fprintf(file, "P6\n%d %d\n255\n", width, height);
    fwrite(image, width * height * sizeof(unsigned char), 1, file);
    fclose(file);

    // Free the image array
    free(image);
}

int main() {
    // Set the image parameters
    int width = 1024;
    int height = 768;
    double xmin = -2.0;
    double xmax = 1.0;
    double ymin = -1.5;
    double ymax = 1.5;

    // Generate the Mandelbrot set image
    generate_mandelbrot(width, height, xmin, xmax, ymin, ymax);

    return 0;
}