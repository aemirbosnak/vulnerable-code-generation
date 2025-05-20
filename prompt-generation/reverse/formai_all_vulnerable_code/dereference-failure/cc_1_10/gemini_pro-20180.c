//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the complex number structure
typedef struct {
    double real;
    double imaginary;
} complex;

// Define the mandelbrot set function
int mandelbrot(complex c, int max_iterations) {
    complex z = {0, 0};
    int n;
    
    for (n = 0; n < max_iterations; n++) {
        z.real = z.real * z.real - z.imaginary * z.imaginary + c.real;
        z.imaginary = 2 * z.real * z.imaginary + c.imaginary;
        
        if (z.real * z.real + z.imaginary * z.imaginary > 4) {
            return n;
        }
    }
    
    return max_iterations;
}

// Define the main function
int main(int argc, char *argv[]) {
    // Define the image width and height
    int width = 800;
    int height = 600;
    
    // Define the maximum number of iterations
    int max_iterations = 100;
    
    // Create the image array
    int *image = malloc(width * height * sizeof(int));
    
    // Calculate the mandelbrot set for each pixel
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            complex c = {4.0 * (x - width / 2) / width, 4.0 * (y - height / 2) / height};
            image[y * width + x] = mandelbrot(c, max_iterations);
        }
    }
    
    // Write the image to a file
    FILE *fp = fopen("mandelbrot.ppm", "wb");
    fprintf(fp, "P3\n%d %d\n255\n", width, height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int color = 255 * image[y * width + x] / max_iterations;
            fprintf(fp, "%d %d %d ", color, color, color);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    
    // Free the image array
    free(image);
    
    return 0;
}