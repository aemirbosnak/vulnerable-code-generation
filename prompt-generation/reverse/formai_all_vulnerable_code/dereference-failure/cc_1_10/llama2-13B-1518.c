//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NUMBER_OF_BITS 32
#define MAX_NUMBER_OF_BYTES 4

// Function to convert a binary number to its decimal equivalent
int binaryToDecimal(char *binary) {
    int decimal = 0;
    int i = 0;

    while (binary[i] != '\0') {
        decimal = (decimal * 2) + (binary[i] - '0');
        i++;
    }

    return decimal;
}

// Function to convert a decimal number to its binary equivalent
char *decimalToBinary(int decimal) {
    char *binary = malloc(sizeof(char) * (log10(decimal) + 1));
    int i = 0;

    while (decimal != 0) {
        binary[i] = (decimal % 2) + '0';
        decimal /= 2;
        i++;
    }

    binary[i] = '\0';

    return binary;
}

int main() {
    int number;
    char *binary;

    // Get the number from the user
    printf("Enter a decimal number: ");
    scanf("%d", &number);

    // Convert the decimal number to binary
    binary = decimalToBinary(number);

    // Print the binary number
    printf("Binary: %s\n", binary);

    // Get the binary number from the user
    printf("Enter a binary number: ");
    scanf(" %s", binary);

    // Convert the binary number to decimal
    number = binaryToDecimal(binary);

    // Print the decimal number
    printf("Decimal: %d\n", number);

    return 0;
}