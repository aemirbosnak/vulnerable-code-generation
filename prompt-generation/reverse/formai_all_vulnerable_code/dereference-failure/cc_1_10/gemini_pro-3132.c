//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: rigorous
// C Binary Converter
// Converts decimal numbers to binary and vice versa.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a decimal number to binary.
char *decimalToBinary(int decimalNumber) {
    int binaryNumber[100];
    int i = 0;
    while (decimalNumber > 0) {
        binaryNumber[i] = decimalNumber % 2;
        decimalNumber /= 2;
        i++;
    }

    char *binaryString = malloc(i + 1);
    for (int j = i - 1; j >= 0; j--) {
        binaryString[i - 1 - j] = binaryNumber[j] + '0';
    }
    binaryString[i] = '\0';

    return binaryString;
}

// Function to convert a binary number to decimal.
int binaryToDecimal(char *binaryString) {
    int decimalNumber = 0;
    int length = strlen(binaryString);
    for (int i = 0; i < length; i++) {
        decimalNumber += (binaryString[i] - '0') * pow(2, length - 1 - i);
    }

    return decimalNumber;
}

// Main function.
int main() {
    // Get the input number from the user.
    int decimalNumber;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Convert the decimal number to binary.
    char *binaryString = decimalToBinary(decimalNumber);

    // Print the binary representation of the number.
    printf("Binary representation: %s\n", binaryString);

    // Convert the binary number back to decimal.
    int convertedDecimalNumber = binaryToDecimal(binaryString);

    // Print the converted decimal number.
    printf("Converted decimal number: %d\n", convertedDecimalNumber);

    // Free the allocated memory.
    free(binaryString);

    return 0;
}