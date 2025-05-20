//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: protected
#include <stdio.h>
#include <math.h>

// Complex number type
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

// Function to multiply two complex numbers
complex multiply_complex(complex a, complex b) {
    complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

// Function to square a complex number
complex square_complex(complex a) {
    return multiply_complex(a, a);
}

// Function to generate a fractal image
void generate_fractal(int width, int height, double xmin, double xmax, double ymin, double ymax, int max_iterations) {
    // Create an image buffer
    unsigned char *image = malloc(width * height);

    // Iterate over each pixel in the image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Compute the complex number corresponding to the pixel
            complex c;
            c.real = xmin + x * (xmax - xmin) / width;
            c.imag = ymin + y * (ymax - ymin) / height;

            // Initialize the complex number z to 0
            complex z;
            z.real = 0;
            z.imag = 0;

            // Iterate the complex number z through the Mandelbrot set formula
            int iterations = 0;
            while (iterations < max_iterations && z.real * z.real + z.imag * z.imag <= 4) {
                z = add_complex(square_complex(z), c);
                iterations++;
            }

            // Set the pixel to the corresponding color based on the number of iterations
            if (iterations == max_iterations) {
                image[y * width + x] = 0; // Black
            } else {
                image[y * width + x] = 255 * (iterations / (double) max_iterations); // Gray
            }
        }
    }

    // Write the image to a file
    FILE *fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", width, height);
    fwrite(image, 1, width * height, fp);
    fclose(fp);

    // Free the image buffer
    free(image);
}

// Main function
int main() {
    // Define the fractal parameters
    int width = 800;
    int height = 600;
    double xmin = -2.0;
    double xmax = 1.0;
    double ymin = -1.5;
    double ymax = 1.5;
    int max_iterations = 1000;

    // Generate the fractal image
    generate_fractal(width, height, xmin, xmax, ymin, ymax, max_iterations);

    return 0;
}