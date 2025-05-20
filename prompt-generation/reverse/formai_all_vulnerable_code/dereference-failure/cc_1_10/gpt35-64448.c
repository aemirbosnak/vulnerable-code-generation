//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants for the fractal generation
#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000
#define BAILOUT 2.0

// Define the complex number struct
typedef struct {
    double real;
    double imag;
} Complex;

// Function to create a complex number from real and imaginary parts
Complex create_complex(double real, double imag) {
    Complex c;
    c.real = real;
    c.imag = imag;
    return c;
}

// Function to square a complex number
Complex square_complex(Complex c) {
    Complex result;
    result.real = (c.real * c.real) - (c.imag * c.imag);
    result.imag = 2 * (c.real * c.imag);
    return result;
}

// Function to add two complex numbers
Complex add_complex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

// Function to calculate the absolute value of a complex number
double abs_complex(Complex c) {
    return sqrt((c.real * c.real) + (c.imag * c.imag));
}

// Function to generate a fractal image
void generate_fractal_image() {
    // Allocate memory for the image
    int *image = (int*)malloc(WIDTH * HEIGHT * sizeof(int));

    // Define the range of the fractal
    double x_min = -2.0;
    double x_max = 2.0;
    double y_min = -2.0;
    double y_max = 2.0;

    // Loop through each pixel in the image
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Convert the pixel coordinates to complex coordinates
            double x_scaled = x * (x_max - x_min) / WIDTH + x_min;
            double y_scaled = y * (y_max - y_min) / HEIGHT + y_min;
            Complex c = create_complex(x_scaled, y_scaled);

            // Perform the Mandelbrot iteration
            Complex z = create_complex(0, 0);
            int i;
            for (i = 0; i < MAX_ITER && abs_complex(z) <= BAILOUT; i++) {
                z = add_complex(square_complex(z), c);
            }

            // Set the color of the pixel based on the iteration count
            if (i == MAX_ITER) {
                image[(y * WIDTH) + x] = 0; // Black
            } else {
                image[(y * WIDTH) + x] = 255; // White
            }
        }
    }

    // Output the fractal image in PGM format
    printf("P2\n");
    printf("%d %d\n", WIDTH, HEIGHT);
    printf("255\n");
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        printf("%d\n", image[i]);
    }
    free(image);
}

// Main function
int main() {
    generate_fractal_image();
    return 0;
}