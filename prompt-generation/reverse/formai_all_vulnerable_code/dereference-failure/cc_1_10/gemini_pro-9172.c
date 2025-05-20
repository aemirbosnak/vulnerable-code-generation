//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to binary
char* decimalToBinary(int decimal) {
    // Allocate memory for the binary representation
    char* binary = malloc(33 * sizeof(char));

    // Initialize the binary representation to 0
    int index = 0;
    while (decimal > 0) {
        binary[index++] = (decimal % 2) + '0';
        decimal /= 2;
    }

    // Reverse the binary representation
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - 1 - i];
        binary[index - 1 - i] = temp;
    }

    // Add a null terminator to the binary representation
    binary[index] = '\0';

    // Return the binary representation
    return binary;
}

// Function to convert a binary number to decimal
int binaryToDecimal(char* binary) {
    // Initialize the decimal representation to 0
    int decimal = 0;
    int weight = 1;

    // Iterate over the binary representation from right to left
    int length = strlen(binary);
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += weight;
        }
        weight *= 2;
    }

    // Return the decimal representation
    return decimal;
}

// Function to print the binary representation of a decimal number
void printBinary(int decimal) {
    // Convert the decimal number to binary
    char* binary = decimalToBinary(decimal);

    // Print the binary representation
    printf("The binary representation of %d is %s\n", decimal, binary);

    // Free the memory allocated for the binary representation
    free(binary);
}

// Function to prompt the user to enter a decimal number
int promptDecimal() {
    // Prompt the user to enter a decimal number
    printf("Enter a decimal number: ");

    // Read the decimal number from the user
    int decimal;
    scanf("%d", &decimal);

    // Return the decimal number
    return decimal;
}

// Main function
int main() {
    // Prompt the user to enter a decimal number
    int decimal = promptDecimal();

    // Convert the decimal number to binary
    char* binary = decimalToBinary(decimal);

    // Print the binary representation of the decimal number
    printf("The binary representation of %d is %s\n", decimal, binary);

    // Free the memory allocated for the binary representation
    free(binary);

    return 0;
}