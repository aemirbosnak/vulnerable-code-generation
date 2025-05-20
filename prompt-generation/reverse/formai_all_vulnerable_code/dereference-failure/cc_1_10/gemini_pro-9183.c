//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: modular
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Defines the maximum number of bits in the binary representation
#define MAX_BITS 32

// Function to convert a decimal integer to its binary representation
char *decimal_to_binary(int decimal) {
    // Allocate memory for the binary representation
    char *binary = malloc(MAX_BITS + 1);

    // Initialize the binary representation to all zeros
    for (int i = 0; i < MAX_BITS; i++) {
        binary[i] = '0';
    }

    // Convert the decimal integer to binary one bit at a time
    int index = MAX_BITS - 1;
    while (decimal > 0) {
        if (decimal % 2 == 1) {
            binary[index] = '1';
        }

        decimal /= 2;
        index--;
    }

    // Add the null-terminator to the binary representation
    binary[MAX_BITS] = '\0';

    // Return the binary representation
    return binary;
}

// Function to convert a binary representation to its decimal equivalent
int binary_to_decimal(char *binary) {
    // Initialize the decimal equivalent to 0
    int decimal = 0;

    // Convert the binary representation to decimal one bit at a time
    int index = 0;
    while (binary[index] != '\0') {
        if (binary[index] == '1') {
            decimal += 1 << (MAX_BITS - 1 - index);
        }

        index++;
    }

    // Return the decimal equivalent
    return decimal;
}

// Function to test the decimal_to_binary and binary_to_decimal functions
void test_conversion_functions() {
    // Test the conversion of a few decimal integers to binary
    int decimal_numbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 11; i++) {
        char *binary = decimal_to_binary(decimal_numbers[i]);
        printf("%d = %s\n", decimal_numbers[i], binary);
        free(binary);
    }

    // Test the conversion of a few binary representations to decimal
    char *binary_representations[] = {"0", "1", "10", "11", "100", "101", "110", "111", "1000", "1001", "1010"};
    for (int i = 0; i < 11; i++) {
        int decimal = binary_to_decimal(binary_representations[i]);
        printf("%s = %d\n", binary_representations[i], decimal);
    }
}

int main() {
    // Test the conversion functions
    test_conversion_functions();

    return 0;
}