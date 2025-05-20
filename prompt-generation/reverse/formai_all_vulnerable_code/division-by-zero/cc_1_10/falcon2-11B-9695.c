//Falcon2-11B DATASET v1.0 Category: Arithmetic ; Style: innovative
#include <stdio.h>

// Define the maximum value of an unsigned int
#define MAX_UINT 4294967295

// Define a function to calculate the sum of two unsigned integers
unsigned int add(unsigned int a, unsigned int b) {
    return a + b;
}

// Define a function to calculate the product of two unsigned integers
unsigned int multiply(unsigned int a, unsigned int b) {
    return a * b;
}

// Define a function to calculate the difference between two unsigned integers
unsigned int subtract(unsigned int a, unsigned int b) {
    return a - b;
}

// Define a function to calculate the quotient of two unsigned integers
unsigned int divide(unsigned int a, unsigned int b) {
    return a / b;
}

int main() {
    // Get the first unsigned integer from the user
    unsigned int num1;
    printf("Enter the first unsigned integer: ");
    scanf("%u", &num1);

    // Get the second unsigned integer from the user
    unsigned int num2;
    printf("Enter the second unsigned integer: ");
    scanf("%u", &num2);

    // Calculate the sum of the two unsigned integers
    unsigned int sum = add(num1, num2);

    // Calculate the product of the two unsigned integers
    unsigned int product = multiply(num1, num2);

    // Calculate the difference between the two unsigned integers
    unsigned int difference = subtract(num1, num2);

    // Calculate the quotient of the two unsigned integers
    unsigned int quotient = divide(num1, num2);

    // Print the results
    printf("Sum: %u\n", sum);
    printf("Product: %u\n", product);
    printf("Difference: %u\n", difference);
    printf("Quotient: %u\n", quotient);

    return 0;
}