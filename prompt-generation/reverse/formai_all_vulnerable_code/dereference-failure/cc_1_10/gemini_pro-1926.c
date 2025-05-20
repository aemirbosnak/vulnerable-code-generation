//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a binary number to its decimal equivalent
int binary_to_decimal(char *binary) {
    int decimal = 0;
    int base = 1;
    int len = strlen(binary);
    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

// Function to convert a decimal number to its binary equivalent
char *decimal_to_binary(int decimal) {
    char *binary = malloc(sizeof(char) * 33);
    int index = 32;
    while (decimal > 0) {
        if (decimal % 2 == 0) {
            binary[index] = '0';
        } else {
            binary[index] = '1';
        }
        decimal /= 2;
        index--;
    }
    binary[32] = '\0';
    return binary;
}

int main() {
    // Get the binary number from the user
    char binary[33];
    printf("Enter a binary number: ");
    scanf("%s", binary);

    // Convert the binary number to its decimal equivalent
    int decimal = binary_to_decimal(binary);

    // Print the decimal equivalent
    printf("The decimal equivalent of %s is %d\n", binary, decimal);

    // Convert the decimal number to its binary equivalent
    char *new_binary = decimal_to_binary(decimal);

    // Print the binary equivalent
    printf("The binary equivalent of %d is %s\n", decimal, new_binary);

    return 0;
}