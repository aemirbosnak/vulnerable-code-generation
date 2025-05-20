//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a struct to represent a complex number
typedef struct {
    int real;
    int imag;
} complex;

// Define a function to convert a string to a complex number
complex stringToComplex(char *str) {
    int i, real, imag;
    char *token;

    // Tokenize the string into real and imaginary parts
    token = strtok(str, " +-");
    real = atoi(token);
    token = strtok(NULL, " +-");
    imag = atoi(token);

    // Create a complex number object and return it
    return (complex) {real, imag};
}

// Define a function to perform addition and multiplication of complex numbers
complex add(complex a, complex b) {
    complex res;

    // Calculate the sum of the real and imaginary parts
    res.real = a.real + b.real;
    res.imag = a.imag + b.imag;

    return res;
}

complex mul(complex a, complex b) {
    complex res;

    // Calculate the product of the real and imaginary parts
    res.real = a.real * b.real - a.imag * b.imag;
    res.imag = a.real * b.imag + a.imag * b.real;

    return res;
}

int main() {
    // Create some complex numbers to play with
    complex c1 = stringToComplex("3 + 4i");
    complex c2 = stringToComplex("2 - 5i");
    complex c3 = add(c1, c2);
    complex c4 = mul(c1, c2);

    // Print the results
    printf("c1 + c2 = %c + %ci\n", c3.real, c3.imag);
    printf("c1 * c2 = %c + %ci\n", c4.real, c4.imag);

    return 0;
}