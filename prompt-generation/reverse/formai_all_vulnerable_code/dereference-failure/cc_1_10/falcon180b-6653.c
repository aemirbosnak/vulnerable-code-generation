//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert binary to decimal
int binaryToDecimal(char* binary) {
    int decimal = 0, i;
    int base = 1;
    int length = strlen(binary);

    // Iterate over each character in the binary string
    for (i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }

    return decimal;
}

// Function to convert decimal to binary
char* decimalToBinary(int decimal) {
    char* binary = (char*) malloc(33 * sizeof(char));
    int i, j;
    int remainder;

    // Initialize the binary string with leading zeros
    for (i = 0; i < 32; i++) {
        binary[i] = '0';
    }
    binary[32] = '\0';

    // Convert decimal to binary
    remainder = decimal % 2;
    for (i = 0, j = 31; i < 32; i++, j--) {
        binary[j] = remainder + '0';
        remainder /= 2;
    }

    return binary;
}

int main() {
    char* binary;
    int decimal;

    // Prompt user to enter a binary number
    printf("Enter a binary number: ");
    scanf("%s", &binary);

    // Convert binary to decimal
    decimal = binaryToDecimal(binary);

    // Display the decimal equivalent of the binary number
    printf("The decimal equivalent of %s is %d\n", binary, decimal);

    // Convert decimal to binary
    binary = decimalToBinary(decimal);

    // Display the binary equivalent of the decimal number
    printf("The binary equivalent of %d is %s\n", decimal, binary);

    return 0;
}