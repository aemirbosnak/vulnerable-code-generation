//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
char *decimalToBinary(int n) {
    int binaryNum[1000];
    int i = 0;

    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    char *result = malloc(i + 1);
    for (int j = i - 1; j >= 0; j--) {
        result[i - 1 - j] = binaryNum[j] + '0';
    }
    result[i] = '\0';

    return result;
}

// Function to convert binary to decimal
int binaryToDecimal(char *binary) {
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

// Main function
int main() {
    // Declare variables
    int decimalNumber;
    char *binaryNumber;

    // Get the decimal number from the user
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Convert the decimal number to binary
    binaryNumber = decimalToBinary(decimalNumber);

    // Print the binary number
    printf("The binary representation of %d is: %s\n", decimalNumber, binaryNumber);

    // Convert the binary number to decimal
    int decimal = binaryToDecimal(binaryNumber);

    // Print the decimal number
    printf("The decimal representation of %s is: %d\n", binaryNumber, decimal);

    // Free the allocated memory
    free(binaryNumber);

    return 0;
}