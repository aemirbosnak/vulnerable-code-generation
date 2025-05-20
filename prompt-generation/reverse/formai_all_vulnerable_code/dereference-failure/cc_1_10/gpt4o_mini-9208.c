//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_BITS 32  // Maximum bits to convert
#define BUFFER_SIZE 128  // Buffer size for input

// Function prototypes
void convertToBinary(unsigned int number, char *binary);
void printBinary(char *binary);

int main() {
    char input[BUFFER_SIZE];
    unsigned int number;
    char binary[MAX_BITS + 1]; // +1 for the null terminator
    
    // Seed for randomness
    srand((unsigned int)time(NULL));

    printf("Welcome to the Binary Converter Program!\n");
    printf("This program converts a decimal number to binary format.\n");

    while (1) {
        // Prompt the user for input
        printf("Please enter a non-negative integer (negative to quit): ");
        if (fgets(input, BUFFER_SIZE, stdin) == NULL) {
            fprintf(stderr, "Error reading input. Please try again.\n");
            continue;
        }

        // Convert string input to unsigned integer
        char *endptr;
        number = strtoul(input, &endptr, 10);

        // Check for input errors
        if (endptr == input || *endptr != '\n') {
            fprintf(stderr, "Invalid input. You must enter a non-negative integer.\n");
            continue;
        }

        // Exit condition for negative input
        if (number > ULONG_MAX) {
            printf("Goodbye! You've exceeded the maximum limit.\n");
            break;
        }

        // Convert the number to binary and print
        convertToBinary(number, binary);
        printBinary(binary);
    }

    return 0;
}

// Function to convert a number to binary
void convertToBinary(unsigned int number, char *binary) {
    // Initialize the binary string with '0's
    memset(binary, '0', MAX_BITS);
    binary[MAX_BITS] = '\0'; // Null-terminate the string
    
    // Fill the binary representation
    for (int i = MAX_BITS - 1; i >= 0; --i) {
        binary[i] = (number & 1) ? '1' : '0';
        number >>= 1; // Shift right for the next bit
    }
}

// Function to print binary representation with formatting
void printBinary(char *binary) {
    printf("Binary representation: ");
    // Print the binary representation in groups of 8 bits for better readability
    for (int i = 0; i < MAX_BITS; ++i) {
        putchar(binary[i]);
        if ((i + 1) % 8 == 0 && i < MAX_BITS - 1) {
            putchar(' '); // Add space every 8 bits
        }
    }
    putchar('\n'); // New line after printing the binary number
}