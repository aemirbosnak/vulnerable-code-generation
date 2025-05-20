//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: innovative
#include <stdio.h>
#include <stdint.h>

#define MAX_BINARY_LENGTH 64

// Function to convert decimal to binary
char *decimalToBinary(uint64_t decimal) {
    char *binary = calloc(MAX_BINARY_LENGTH, sizeof(char));
    uint64_t quotient = decimal;
    int i = 0;

    while (quotient > 0) {
        binary[i++] = (quotient % 2) + '0';
        quotient /= 2;
    }

    // Reverse the binary string
    char temp;
    for (int j = 0; j < i / 2; j++) {
        temp = binary[j];
        binary[j] = binary[i - j - 1];
        binary[i - j - 1] = temp;
    }

    return binary;
}

// Function to convert binary to decimal
uint64_t binaryToDecimal(char *binary) {
    uint64_t decimal = 0;
    int length = strlen(binary);

    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal += (1 << (length - i - 1));
        }
    }

    return decimal;
}

int main() {
    // Decimal to binary conversion
    uint64_t decimal = 1234567890;
    char *binary = decimalToBinary(decimal);
    printf("Decimal: %llu\nBinary: %s\n", decimal, binary);

    // Binary to decimal conversion
    char *binary2 = "1010101010101010101010101010101010101010101010101010101010101010";
    uint64_t decimal2 = binaryToDecimal(binary2);
    printf("Binary: %s\nDecimal: %llu\n", binary2, decimal2);

    return 0;
}