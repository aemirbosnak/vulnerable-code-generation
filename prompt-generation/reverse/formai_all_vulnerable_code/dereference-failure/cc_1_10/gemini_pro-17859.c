//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: portable
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

// Function to calculate the Mandelbrot set for a given point
int mandelbrot(complex c, int max_iterations) {
    int iterations = 0;
    complex z = {0, 0};

    while (iterations < max_iterations && z.real * z.real + z.imag * z.imag <= 4) {
        z = add(multiply(z, z), c);
        iterations++;
    }

    return iterations;
}

// Function to generate a Mandelbrot set image
void generate_image(int width, int height, int max_iterations) {
    // Create an image buffer
    int *image = malloc(width * height * sizeof(int));

    // Iterate over each pixel in the image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Calculate the complex number for the pixel
            double real = (x - width / 2.0) / (width / 4.0);
            double imag = (y - height / 2.0) / (height / 4.0);
            complex c = {real, imag};

            // Calculate the number of iterations for the pixel
            int iterations = mandelbrot(c, max_iterations);

            // Set the pixel color based on the number of iterations
            image[y * width + x] = iterations;
        }
    }

    // Save the image to a file
    FILE *fp = fopen("mandelbrot.ppm", "wb");
    fprintf(fp, "P3\n%d %d\n255\n", width, height);
    for (int i = 0; i < width * height; i++) {
        int color = image[i];
        fprintf(fp, "%d %d %d\n", color, color, color);
    }
    fclose(fp);

    // Free the image buffer
    free(image);
}

int main() {
    // Generate a Mandelbrot set image with a width of 1024, a height of 768, and a maximum of 1000 iterations
    generate_image(1024, 768, 1000);

    return 0;
}