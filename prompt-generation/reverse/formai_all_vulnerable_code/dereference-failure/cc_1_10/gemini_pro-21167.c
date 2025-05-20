//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

// Function to convert a decimal number to its binary representation
char *decimalToBinary(int num) {
    // Check if the number is negative
    if (num < 0) {
        return NULL;
    }

    // Create a string to store the binary representation
    char *binary = (char *)malloc(sizeof(char) * 33);

    // Initialize the binary string to all 0s
    memset(binary, '0', 32);

    // Keep dividing the number by 2 and appending the remainder to the binary string
    int i = 31;
    while (num > 0) {
        binary[i--] = num % 2 + '0';
        num /= 2;
    }

    // Add the null terminator to the binary string
    binary[32] = '\0';

    // Return the binary string
    return binary;
}

// Function to convert a binary number to its decimal representation
int binaryToDecimal(char *binary) {
    // Check if the binary string is valid
    if (strlen(binary) > 32) {
        return -1;
    }

    // Initialize the decimal number to 0
    int decimal = 0;

    // Iterate over the binary string and convert each bit to a decimal digit
    for (int i = 0; i < strlen(binary); i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            return -1;
        }

        decimal += (binary[i] - '0') * (1 << (strlen(binary) - i - 1));
    }

    // Return the decimal number
    return decimal;
}

// Function to check if a number is a power of 2
bool isPowerOfTwo(int num) {
    // Check if the number is 0 or negative
    if (num <= 0) {
        return false;
    }

    // Check if the number has only one bit set
    return (num & (num - 1)) == 0;
}

// Function to find the largest power of 2 that is less than or equal to a given number
int findLargestPowerOfTwo(int num) {
    // Check if the number is 0 or negative
    if (num <= 0) {
        return -1;
    }

    // Find the highest bit set using log2()
    int highestBitSet = (int)log2(num);

    // Return the value of 2 raised to the power of the highest bit set
    return 1 << highestBitSet;
}

// Function to test the binary converter functions
void testBinaryConverter() {
    // Test decimalToBinary()
    printf("Decimal 10 = Binary %s\n", decimalToBinary(10));
    printf("Decimal 255 = Binary %s\n", decimalToBinary(255));
    printf("Decimal -1 = Binary NULL\n");

    // Test binaryToDecimal()
    printf("Binary 1010 = Decimal %d\n", binaryToDecimal("1010"));
    printf("Binary 11111111 = Decimal %d\n", binaryToDecimal("11111111"));
    printf("Binary 1010101010 = Decimal -1\n");

    // Test isPowerOfTwo()
    printf("16 is a power of 2: %s\n", isPowerOfTwo(16) ? "true" : "false");
    printf("15 is a power of 2: %s\n", isPowerOfTwo(15) ? "true" : "false");

    // Test findLargestPowerOfTwo()
    printf("Largest power of 2 less than or equal to 100: %d\n", findLargestPowerOfTwo(100));
    printf("Largest power of 2 less than or equal to 128: %d\n", findLargestPowerOfTwo(128));
}

int main() {
    testBinaryConverter();

    return 0;
}