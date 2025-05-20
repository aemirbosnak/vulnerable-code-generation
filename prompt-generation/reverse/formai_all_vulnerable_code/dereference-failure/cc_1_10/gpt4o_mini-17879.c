//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITS 64 // Maximum number of bits for binary representation

// Function to convert decimal to binary
void decimalToBinary(unsigned long long decimalNumber, char *binaryArray) {
    int index = MAX_BITS - 1; // Start from the end of the array
    binaryArray[index] = '\0'; // Null-terminate the string
    index--;

    // Handle the case for zero
    if (decimalNumber == 0) {
        binaryArray[index--] = '0';
    } else {
        while (decimalNumber > 0 && index >= 0) {
            binaryArray[index--] = (decimalNumber % 2) + '0'; // Convert to char
            decimalNumber /= 2; // Divide by 2
        }
    }
    
    // Fill remaining positions with '0'
    while (index >= 0) {
        binaryArray[index--] = '0';
    }
}

// Function to print binary representation
void printBinary(const char *binaryArray) {
    printf("Binary Representation: %s\n", binaryArray);
}

// Function to read user input and validate it
unsigned long long readDecimalInput() {
    unsigned long long number;
    printf("Enter a non-negative decimal number: ");
    char buffer[128]; // Buffer for reading input

    // Read user input
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        char *endptr; // Pointer to check for valid conversion

        // Convert the input to a number
        number = strtoull(buffer, &endptr, 10);

        // Check for invalid input
        if (endptr == buffer || *endptr != '\n') {
            fprintf(stderr, "Invalid input. Please enter a valid non-negative decimal number.\n");
            exit(EXIT_FAILURE);
        }
    } else {
        fprintf(stderr, "Error reading input.\n");
        exit(EXIT_FAILURE);
    }
    
    return number;
}

int main() {
    unsigned long long decimalNumber;
    char binaryRepresentation[MAX_BITS + 1]; // +1 for null terminator

    // Read decimal input from user
    decimalNumber = readDecimalInput();
    
    // Convert decimal to binary
    decimalToBinary(decimalNumber, binaryRepresentation);

    // Print the binary representation
    printBinary(binaryRepresentation);
    
    return 0;
}