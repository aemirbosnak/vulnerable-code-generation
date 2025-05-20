//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a decimal number to binary
char *decimalToBinary(int n) {
    // Create a string to store the binary representation
    char *binary = malloc(33);

    // Check if the number is negative
    if (n < 0) {
        // Convert the number to positive
        n = -n;
        // Set the first bit to 1 to indicate that the number is negative
        binary[0] = '1';
    }

    // Convert the number to binary
    int i = 31;
    while (n > 0) {
        // If the number is odd, set the bit to 1
        if (n % 2 == 1) {
            binary[i] = '1';
        } else {
            // Otherwise, set the bit to 0
            binary[i] = '0';
        }
        // Divide the number by 2
        n /= 2;
        // Decrement the index
        i--;
    }

    // Add a null character to the end of the string
    binary[32] = '\0';

    // Return the binary representation
    return binary;
}

// Function to convert a binary number to decimal
int binaryToDecimal(char *binary) {
    // Initialize the decimal value to 0
    int decimal = 0;

    // Get the length of the binary string
    int len = strlen(binary);

    // Iterate over the binary string from right to left
    for (int i = len - 1; i >= 0; i--) {
        // If the bit is 1, add the corresponding power of 2 to the decimal value
        if (binary[i] == '1') {
            decimal += (1 << (len - 1 - i));
        }
    }

    // Return the decimal value
    return decimal;
}

// Function to print the binary representation of a number
void printBinary(int n) {
    // Convert the number to binary
    char *binary = decimalToBinary(n);

    // Print the binary representation
    printf("%s\n", binary);

    // Free the memory allocated for the binary representation
    free(binary);
}

// Function to test the binary converter
void testBinaryConverter() {
    // Convert some decimal numbers to binary
    printBinary(10);
    printBinary(255);
    printBinary(-123);

    // Convert some binary numbers to decimal
    printf("%d\n", binaryToDecimal("1010"));
    printf("%d\n", binaryToDecimal("11111111"));
    printf("%d\n", binaryToDecimal("11111111111111111111111111111111"));
}

// Main function
int main() {
    // Test the binary converter
    testBinaryConverter();

    return 0;
}