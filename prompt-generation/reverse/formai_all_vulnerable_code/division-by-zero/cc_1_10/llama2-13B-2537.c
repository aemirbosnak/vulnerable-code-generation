//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_BITS 32
#define DECIMAL_PRECISION 10

// Function to convert binary to decimal
int binary_to_decimal(unsigned int binary) {
    int decimal = 0;
    int i = 0;

    while (binary > 0) {
        decimal += (binary % 2) * (i++ * DECIMAL_PRECISION);
        binary /= 2;
    }

    return decimal;
}

// Function to print the conversion process
void print_conversion(unsigned int binary, int decimal) {
    printf("Binary: %08x\n", binary);
    printf("Decimal: %d\n", decimal);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Generate a random binary number
    unsigned int binary = rand() % (1 << MAX_BITS);

    // Convert binary to decimal
    int decimal = binary_to_decimal(binary);

    // Print the conversion process
    print_conversion(binary, decimal);

    // Ask the user for input
    printf("Enter a binary number (or press enter for a random one): ");
    char input[MAX_BITS];
    fgets(input, MAX_BITS, stdin);

    // Convert the user's input to binary
    binary = strtoul(input, NULL, 2);

    // Convert the user's input to decimal
    decimal = binary_to_decimal(binary);

    // Print the result
    printf("Your binary number is %08x, and it corresponds to the decimal number %d.\n", binary, decimal);

    return 0;
}