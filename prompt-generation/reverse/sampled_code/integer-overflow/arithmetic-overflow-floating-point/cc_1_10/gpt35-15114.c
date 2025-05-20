//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: expert-level
#include<stdio.h>
#include<math.h>

#define PI 3.14159

typedef struct {
    float real;
    float imag;
} complex;

// Function to calculate the magnitude of a complex number
float magnitude(complex c) {
    return sqrt(pow(c.real, 2) + pow(c.imag, 2));
}

// Function to calculate the phase of a complex number in degrees
float phase(complex c) {
    return atan(c.imag / c.real) * (180 / PI);
}

// Function to add two complex numbers
complex add(complex c1, complex c2) {
    complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

// Function to multiply two complex numbers
complex multiply(complex c1, complex c2) {
    complex result;
    result.real = (c1.real * c2.real) - (c1.imag * c2.imag);
    result.imag = (c1.real * c2.imag) + (c1.imag * c2.real);
    return result;
}

int main() {
    // Example usage of the functions above
    complex c1 = {3, 4};
    complex c2 = {1, -2};

    printf("Magnitude of c1: %.2f\n", magnitude(c1)); // Expected output: 5.00
    printf("Phase of c2: %.2f degrees\n", phase(c2)); // Expected output: -63.43 degrees

    complex addition = add(c1, c2);
    printf("Result of addition: %.2f + %.2fi\n", addition.real, addition.imag); // Expected output: 4.00 + 2.00i

    complex multiplication = multiply(c1, c2);
    printf("Result of multiplication: %.2f + %.2fi\n", multiplication.real, multiplication.imag); // Expected output: 11.00 - 2.00i
    
    return 0;
}