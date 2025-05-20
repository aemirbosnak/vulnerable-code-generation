//GEMINI-pro DATASET v1.0 Category: Educational ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Custom data type for a complex number
typedef struct {
    double real;
    double imaginary;
} Complex;

// Function to create a new complex number
Complex* new_complex(double real, double imaginary) {
    Complex* c = malloc(sizeof(Complex));
    c->real = real;
    c->imaginary = imaginary;
    return c;
}

// Function to add two complex numbers
Complex* complex_add(Complex* c1, Complex* c2) {
    Complex* c3 = new_complex(0, 0);
    c3->real = c1->real + c2->real;
    c3->imaginary = c1->imaginary + c2->imaginary;
    return c3;
}

// Function to subtract two complex numbers
Complex* complex_subtract(Complex* c1, Complex* c2) {
    Complex* c3 = new_complex(0, 0);
    c3->real = c1->real - c2->real;
    c3->imaginary = c1->imaginary - c2->imaginary;
    return c3;
}

// Function to multiply two complex numbers
Complex* complex_multiply(Complex* c1, Complex* c2) {
    Complex* c3 = new_complex(0, 0);
    c3->real = (c1->real * c2->real) - (c1->imaginary * c2->imaginary);
    c3->imaginary = (c1->real * c2->imaginary) + (c1->imaginary * c2->real);
    return c3;
}

// Function to divide two complex numbers
Complex* complex_divide(Complex* c1, Complex* c2) {
    if (c2->real == 0 && c2->imaginary == 0) {
        printf("Division by zero is undefined.\n");
        return NULL;
    }
    Complex* c3 = new_complex(0, 0);
    double denominator = (c2->real * c2->real) + (c2->imaginary * c2->imaginary);
    c3->real = ((c1->real * c2->real) + (c1->imaginary * c2->imaginary)) / denominator;
    c3->imaginary = ((c1->imaginary * c2->real) - (c1->real * c2->imaginary)) / denominator;
    return c3;
}

// Function to print a complex number
void complex_print(Complex* c) {
    printf("(%f, %f)\n", c->real, c->imaginary);
}

// Main function
int main() {
    // Create two complex numbers
    Complex* c1 = new_complex(3, 4);
    Complex* c2 = new_complex(5, -2);

    // Add the two complex numbers
    Complex* c3 = complex_add(c1, c2);

    // Print the result
    complex_print(c3);

    // Subtract the two complex numbers
    Complex* c4 = complex_subtract(c1, c2);

    // Print the result
    complex_print(c4);

    // Multiply the two complex numbers
    Complex* c5 = complex_multiply(c1, c2);

    // Print the result
    complex_print(c5);

    // Divide the two complex numbers
    Complex* c6 = complex_divide(c1, c2);

    // Print the result
    complex_print(c6);

    // Free the allocated memory
    free(c1);
    free(c2);
    free(c3);
    free(c4);
    free(c5);
    free(c6);

    return 0;
}