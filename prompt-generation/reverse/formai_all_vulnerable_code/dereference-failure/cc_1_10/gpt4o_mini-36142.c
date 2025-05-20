//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 256
#define MAX_BINARY_SIZE (sizeof(int) * 8 + 1) // Max bits for an int + null terminator

// Function to convert decimal to binary
void decimalToBinary(int n, char *binary) {
    int index = MAX_BINARY_SIZE - 2; // Start filling from second last index
    binary[MAX_BINARY_SIZE - 1] = '\0'; // Null terminate the string
    
    // Handle zero case
    if (n == 0) {
        binary[index--] = '0';
    }

    // Iterate and calculate binary representation
    while (n > 0) {
        binary[index--] = (n % 2) + '0'; // Get the last bit
        n /= 2; // Right shift
    }

    // Fill the remaining with '0'
    while (index >= 0) {
        binary[index--] = '0';
    }
}

// Function to read decimal input from user
int readDecimalInput() {
    char input[MAX_INPUT_SIZE];
    int decimal;

    printf("Enter a decimal number: ");
    fgets(input, sizeof(input), stdin);

    // Attempt to convert input to an integer
    char *endptr;
    decimal = strtol(input, &endptr, 10);

    // Check for conversion errors
    if (*endptr != '\n' && *endptr != '\0') {
        fprintf(stderr, "Invalid input. Please enter a valid decimal number.\n");
        exit(EXIT_FAILURE);
    }

    return decimal;
}

// Function to display binary representation
void displayBinaryRepresentation(int decimal) {
    char binary[MAX_BINARY_SIZE];
    decimalToBinary(decimal, binary);
    printf("The binary representation of %d is: %s\n", decimal, binary);
}

// Main function
int main() {
    int decimalInput;

    // Read decimal input from the user
    decimalInput = readDecimalInput();

    // Display binary representation
    displayBinaryRepresentation(decimalInput);

    return 0;
}