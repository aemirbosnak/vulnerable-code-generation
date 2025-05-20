//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a binary number to its decimal equivalent
int binaryToDecimal(char *binary) {
    int decimal = 0;
    int base = 1;
    int length = strlen(binary);

    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }

    return decimal;
}

// Function to convert a decimal number to its binary equivalent
char *decimalToBinary(int decimal) {
    int quotient;
    int remainder;
    char *binary = malloc(sizeof(char) * 33);

    int index = 0;
    while (decimal > 0) {
        quotient = decimal / 2;
        remainder = decimal % 2;
        binary[index++] = remainder + '0';
        decimal = quotient;
    }

    binary[index] = '\0';

    // Reverse the binary string
    char *reversedBinary = malloc(sizeof(char) * 33);
    int j = 0;
    for (int i = strlen(binary) - 1; i >= 0; i--) {
        reversedBinary[j++] = binary[i];
    }
    reversedBinary[j] = '\0';

    free(binary);

    return reversedBinary;
}

int main() {
    // Get the input binary number from the user
    char binary[33];
    printf("Enter a binary number: ");
    scanf("%s", binary);

    // Convert the binary number to its decimal equivalent
    int decimal = binaryToDecimal(binary);

    // Print the decimal equivalent
    printf("The decimal equivalent of %s is %d\n", binary, decimal);

    // Convert the decimal number to its binary equivalent
    char *reversedBinary = decimalToBinary(decimal);

    // Print the binary equivalent
    printf("The binary equivalent of %d is %s\n", decimal, reversedBinary);

    free(reversedBinary);

    return 0;
}