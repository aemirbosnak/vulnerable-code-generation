//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the complex number structure
typedef struct {
    double real;
    double imaginary;
} complex;

// Create a new complex number
complex *create_complex(double real, double imaginary) {
    complex *c = (complex *)malloc(sizeof(complex));
    c->real = real;
    c->imaginary = imaginary;
    return c;
}

// Print a complex number
void print_complex(complex *c) {
    printf("%f + %fi\n", c->real, c->imaginary);
}

// Add two complex numbers
complex *add_complex(complex *c1, complex *c2) {
    complex *c = create_complex(0, 0);
    c->real = c1->real + c2->real;
    c->imaginary = c1->imaginary + c2->imaginary;
    return c;
}

// Subtract two complex numbers
complex *subtract_complex(complex *c1, complex *c2) {
    complex *c = create_complex(0, 0);
    c->real = c1->real - c2->real;
    c->imaginary = c1->imaginary - c2->imaginary;
    return c;
}

// Multiply two complex numbers
complex *multiply_complex(complex *c1, complex *c2) {
    complex *c = create_complex(0, 0);
    c->real = c1->real * c2->real - c1->imaginary * c2->imaginary;
    c->imaginary = c1->real * c2->imaginary + c1->imaginary * c2->real;
    return c;
}

// Divide two complex numbers
complex *divide_complex(complex *c1, complex *c2) {
    complex *c = create_complex(0, 0);
    double denominator = c2->real * c2->real + c2->imaginary * c2->imaginary;
    c->real = (c1->real * c2->real + c1->imaginary * c2->imaginary) / denominator;
    c->imaginary = (c1->imaginary * c2->real - c1->real * c2->imaginary) / denominator;
    return c;
}

// Calculate the magnitude of a complex number
double magnitude_complex(complex *c) {
    return sqrt(c->real * c->real + c->imaginary * c->imaginary);
}

// Calculate the phase of a complex number
double phase_complex(complex *c) {
    return atan2(c->imaginary, c->real);
}

// Get the real part of a complex number
double real_complex(complex *c) {
    return c->real;
}

// Get the imaginary part of a complex number
double imaginary_complex(complex *c) {
    return c->imaginary;
}

// Set the real part of a complex number
void set_real_complex(complex *c, double real) {
    c->real = real;
}

// Set the imaginary part of a complex number
void set_imaginary_complex(complex *c, double imaginary) {
    c->imaginary = imaginary;
}

// Main function
int main() {
    // Create two complex numbers
    complex *c1 = create_complex(1, 2);
    complex *c2 = create_complex(3, 4);

    // Print the two complex numbers
    printf("c1 = ");
    print_complex(c1);
    printf("c2 = ");
    print_complex(c2);

    // Add the two complex numbers
    complex *c3 = add_complex(c1, c2);

    // Print the sum of the two complex numbers
    printf("c1 + c2 = ");
    print_complex(c3);

    // Subtract the two complex numbers
    complex *c4 = subtract_complex(c1, c2);

    // Print the difference of the two complex numbers
    printf("c1 - c2 = ");
    print_complex(c4);

    // Multiply the two complex numbers
    complex *c5 = multiply_complex(c1, c2);

    // Print the product of the two complex numbers
    printf("c1 * c2 = ");
    print_complex(c5);

    // Divide the two complex numbers
    complex *c6 = divide_complex(c1, c2);

    // Print the quotient of the two complex numbers
    printf("c1 / c2 = ");
    print_complex(c6);

    // Calculate the magnitude of the first complex number
    double magnitude = magnitude_complex(c1);

    // Print the magnitude of the first complex number
    printf("Magnitude of c1 = %f\n", magnitude);

    // Calculate the phase of the first complex number
    double phase = phase_complex(c1);

    // Print the phase of the first complex number
    printf("Phase of c1 = %f\n", phase);

    // Get the real part of the first complex number
    double real = real_complex(c1);

    // Print the real part of the first complex number
    printf("Real part of c1 = %f\n", real);

    // Get the imaginary part of the first complex number
    double imaginary = imaginary_complex(c1);

    // Print the imaginary part of the first complex number
    printf("Imaginary part of c1 = %f\n", imaginary);

    // Set the real part of the first complex number
    set_real_complex(c1, 5);

    // Print the first complex number after setting the real part
    printf("c1 after setting the real part = ");
    print_complex(c1);

    // Set the imaginary part of the first complex number
    set_imaginary_complex(c1, 6);

    // Print the first complex number after setting the imaginary part
    printf("c1 after setting the imaginary part = ");
    print_complex(c1);

    // Free the memory allocated for the complex numbers
    free(c1);
    free(c2);
    free(c3);
    free(c4);
    free(c5);
    free(c6);

    return 0;
}