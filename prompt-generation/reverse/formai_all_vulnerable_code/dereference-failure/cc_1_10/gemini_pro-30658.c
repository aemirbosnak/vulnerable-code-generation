//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a binary number to decimal
int binaryToDecimal(char *binary) {
    int decimal = 0;
    int base = 1;
    int len = strlen(binary);

    // Loop through the binary string from right to left
    for (int i = len - 1; i >= 0; i--) {
        // If the current character is '1', add the corresponding decimal value to the result
        if (binary[i] == '1') {
            decimal += base;
        }
        // Multiply the base by 2 for the next iteration
        base *= 2;
    }

    return decimal;
}

// Function to convert a decimal number to binary
char *decimalToBinary(int decimal) {
    // Allocate memory for the binary string
    char *binary = malloc(33 * sizeof(char));

    // Initialize the binary string to all zeros
    memset(binary, '0', 33);

    // Loop through the binary string from right to left
    int i = 32;
    while (decimal > 0) {
        // If the decimal number is odd, set the current character to '1'
        if (decimal % 2 == 1) {
            binary[i] = '1';
        }

        // Divide the decimal number by 2 and move to the next character in the binary string
        decimal /= 2;
        i--;
    }

    return binary;
}

// Function to test the binary converter
void testBinaryConverter() {
    // Test case 1
    char *binary1 = "101010";
    int decimal1 = binaryToDecimal(binary1);
    printf("Binary: %s, Decimal: %d\n", binary1, decimal1);

    // Test case 2
    int decimal2 = 123;
    char *binary2 = decimalToBinary(decimal2);
    printf("Decimal: %d, Binary: %s\n", decimal2, binary2);
}

int main() {
    // Test the binary converter
    testBinaryConverter();

    return 0;
}