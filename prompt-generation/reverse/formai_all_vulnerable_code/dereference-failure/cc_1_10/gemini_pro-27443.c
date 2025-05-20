//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to binary
char* decimalToBinary(int n) {
    // Create a pointer to a buffer to store the binary representation
    char* binaryRepresentation = malloc(sizeof(char) * 33);

    // Initialize the buffer to all zeros
    for (int i = 0; i < 32; i++) {
        binaryRepresentation[i] = '0';
    }

    // Initialize the index of the buffer to the end of the string
    int index = 31;

    // While the number is greater than zero, divide it by two and append the remainder to the buffer
    while (n > 0) {
        binaryRepresentation[index--] = (n % 2) + '0';
        n /= 2;
    }

    // Terminate the string with a null character
    binaryRepresentation[32] = '\0';

    // Return the buffer containing the binary representation
    return binaryRepresentation;
}

// Function to convert a binary number to decimal
int binaryToDecimal(char* binaryRepresentation) {
    // Initialize the decimal representation to zero
    int decimalRepresentation = 0;

    // Iterate through the binary representation from right to left
    for (int i = 0; binaryRepresentation[i] != '\0'; i++) {
        // If the current character is a one, add 2^i to the decimal representation
        if (binaryRepresentation[i] == '1') {
            decimalRepresentation += 1 << i;
        }
    }

    // Return the decimal representation
    return decimalRepresentation;
}

// Main function to test the decimalToBinary and binaryToDecimal functions
int main() {
    // Get a decimal number from the user
    int decimalNumber;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Convert the decimal number to binary
    char* binaryRepresentation = decimalToBinary(decimalNumber);

    // Print the binary representation
    printf("Binary representation: %s\n", binaryRepresentation);

    // Convert the binary representation back to decimal
    int decimalRepresentation = binaryToDecimal(binaryRepresentation);

    // Print the decimal representation
    printf("Decimal representation: %d\n", decimalRepresentation);

    // Free the memory allocated for the binary representation
    free(binaryRepresentation);

    return 0;
}