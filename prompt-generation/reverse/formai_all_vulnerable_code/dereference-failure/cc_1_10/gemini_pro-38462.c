//GEMINI-pro DATASET v1.0 Category: Educational ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Defining a custom data structure for representing complex numbers
typedef struct {
    double real;
    double imaginary;
} ComplexNumber;

// Function to create a new complex number
ComplexNumber* createComplexNumber(double real, double imaginary) {
    ComplexNumber* number = malloc(sizeof(ComplexNumber));
    number->real = real;
    number->imaginary = imaginary;
    return number;
}

// Function to add two complex numbers
ComplexNumber* addComplexNumbers(ComplexNumber* a, ComplexNumber* b) {
    return createComplexNumber(a->real + b->real, a->imaginary + b->imaginary);
}

// Function to subtract two complex numbers
ComplexNumber* subtractComplexNumbers(ComplexNumber* a, ComplexNumber* b) {
    return createComplexNumber(a->real - b->real, a->imaginary - b->imaginary);
}

// Function to multiply two complex numbers
ComplexNumber* multiplyComplexNumbers(ComplexNumber* a, ComplexNumber* b) {
    double real = a->real * b->real - a->imaginary * b->imaginary;
    double imaginary = a->real * b->imaginary + a->imaginary * b->real;
    return createComplexNumber(real, imaginary);
}

// Function to divide two complex numbers
ComplexNumber* divideComplexNumbers(ComplexNumber* a, ComplexNumber* b) {
    double denominator = b->real * b->real + b->imaginary * b->imaginary;
    double real = (a->real * b->real + a->imaginary * b->imaginary) / denominator;
    double imaginary = (a->imaginary * b->real - a->real * b->imaginary) / denominator;
    return createComplexNumber(real, imaginary);
}

// Function to print a complex number in the form a + bi
void printComplexNumber(ComplexNumber* number) {
    printf("%f + %fi\n", number->real, number->imaginary);
}

int main() {
    // Creating two complex numbers
    ComplexNumber* a = createComplexNumber(1, 2);
    ComplexNumber* b = createComplexNumber(3, 4);

    // Performing operations on the complex numbers
    ComplexNumber* sum = addComplexNumbers(a, b);
    ComplexNumber* difference = subtractComplexNumbers(a, b);
    ComplexNumber* product = multiplyComplexNumbers(a, b);
    ComplexNumber* quotient = divideComplexNumbers(a, b);

    // Printing the results
    printf("Sum: ");
    printComplexNumber(sum);
    printf("Difference: ");
    printComplexNumber(difference);
    printf("Product: ");
    printComplexNumber(product);
    printf("Quotient: ");
    printComplexNumber(quotient);

    // Freeing the allocated memory
    free(a);
    free(b);
    free(sum);
    free(difference);
    free(product);
    free(quotient);

    return 0;
}