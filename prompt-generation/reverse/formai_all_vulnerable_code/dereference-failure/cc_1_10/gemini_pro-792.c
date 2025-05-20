//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Complex number structure
typedef struct {
    double real;
    double imag;
} complex;

// Function to add two complex numbers
complex add_complex(complex a, complex b) {
    complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

// Function to square a complex number
complex square_complex(complex a) {
    complex result;
    result.real = a.real * a.real - a.imag * a.imag;
    result.imag = 2 * a.real * a.imag;
    return result;
}

// Function to generate a fractal image
void generate_fractal(int width, int height, double center_x, double center_y, double zoom, int max_iterations) {
    // Create an image buffer
    unsigned char *image = malloc(width * height * 3);

    // Set the default pixel value to black
    for (int i = 0; i < width * height * 3; i++) {
        image[i] = 0;
    }

    // Iterate over each pixel in the image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Convert pixel coordinates to complex number
            double c_real = (x - width / 2) * zoom / width + center_x;
            double c_imag = (y - height / 2) * zoom / height + center_y;
            complex c = {c_real, c_imag};

            // Initialize the complex number z
            complex z = {0, 0};

            // Iterate the complex number z
            int iteration = 0;
            while (iteration < max_iterations && z.real * z.real + z.imag * z.imag < 4) {
                z = add_complex(z, square_complex(z));
                iteration++;
            }

            // Set the pixel color based on the number of iterations
            int color = 255 * iteration / max_iterations;
            image[(y * width + x) * 3] = color; // Red
            image[(y * width + x) * 3 + 1] = color; // Green
            image[(y * width + x) * 3 + 2] = color; // Blue
        }
    }

    // Save the image to a file
    FILE *file = fopen("fractal.ppm", "wb");
    fprintf(file, "P3\n%d %d\n255\n", width, height);
    fwrite(image, width * height * 3, 1, file);
    fclose(file);

    // Free the image buffer
    free(image);
}

// Main function
int main() {
    // Set the fractal parameters
    int width = 1024;
    int height = 768;
    double center_x = -0.5;
    double center_y = 0;
    double zoom = 1;
    int max_iterations = 1000;

    // Generate the fractal image
    generate_fractal(width, height, center_x, center_y, zoom, max_iterations);

    return 0;
}