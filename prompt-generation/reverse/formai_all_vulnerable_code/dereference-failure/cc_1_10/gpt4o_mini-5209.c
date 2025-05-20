//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a decimal number to binary
void decimalToBinary(int n, char *binary) {
    int index = 0;
    if (n == 0) {
        binary[index++] = '0';
    } else {
        while (n > 0) {
            binary[index++] = (n % 2) + '0';
            n /= 2;
        }
    }
    binary[index] = '\0';
    
    // Reverse the binary string to get the correct order
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - i - 1];
        binary[index - i - 1] = temp;
    }
}

// Function to validate the input
int isValidDecimal(const char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] < '0' || input[i] > '9') {
            return 0; // Invalid character found
        }
    }
    return 1; // Valid input
}

// Dynamic memory allocation for binary string
char* allocateBinaryString(int size) {
    char *binary = (char *)malloc(size + 1);
    if (binary == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return binary;
}

// Main execution function
int main() {
    char input[100];
    int decimalNumber;

    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("Please enter a decimal number (or 'exit' to quit): ");

    while (1) {
        printf("\n> ");
        fgets(input, sizeof(input), stdin);
        
        // Check for exit command
        if (strncmp(input, "exit", 4) == 0) {
            printf("Exiting the program. Thank you!\n");
            break;
        }

        // Remove newline character if present
        input[strcspn(input, "\n")] = 0;

        // Validate input
        if (!isValidDecimal(input)) {
            printf("Invalid input. Please enter a valid decimal number.\n");
            continue;
        }

        // Convert input string to integer
        decimalNumber = atoi(input);
        
        // Allocate memory for binary string
        char *binary = allocateBinaryString(32); // Enough for a 32-bit binary representation

        // Convert decimal to binary
        decimalToBinary(decimalNumber, binary);

        // Display the result
        printf("The binary representation of %d is: %s\n", decimalNumber, binary);

        // Free allocated memory
        free(binary);
    }

    return 0;
}