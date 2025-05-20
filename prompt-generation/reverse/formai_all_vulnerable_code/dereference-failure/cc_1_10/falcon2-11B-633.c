//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Set up parameters
    int width = 800;
    int height = 800;
    double x_min = -2.0;
    double x_max = 1.0;
    double y_min = -1.5;
    double y_max = 1.5;
    int max_iterations = 1000;

    // Initialize image buffer
    double *image = (double*)malloc(width * height * sizeof(double));
    for (int i = 0; i < width * height; i++) {
        image[i] = 0.0;
    }

    // Generate the Mandelbrot set
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double x_coord = x - width / 2.0;
            double y_coord = y - height / 2.0;

            // Calculate the complex number for this pixel
            double c_real = x_coord * cos(y_coord);
            double c_imag = y_coord * sin(y_coord);

            // Iterate the complex number up to max_iterations
            double z_real = 0.0;
            double z_imag = 0.0;
            int iteration = 0;
            while (z_real * z_real + z_imag * z_imag < 4.0 && iteration < max_iterations) {
                double temp_real = z_real * z_real - z_imag * z_imag + c_real;
                double temp_imag = 2.0 * z_real * z_imag + c_imag;
                z_real = temp_real;
                z_imag = temp_imag;
                iteration++;
            }

            // Set the pixel value based on the number of iterations
            int color = iteration / max_iterations;
            image[y * width + x] = color;
        }
    }

    // Print the image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int color = image[y * width + x];
            printf("%d ", color);
        }
        printf("\n");
    }

    // Free memory
    free(image);

    return 0;
}