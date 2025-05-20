//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000000 // Maximum size of input string

typedef struct {
    char *binary; // Binary representation of input string
    int size; // Size of binary representation
} BinaryConverter;

void initialize(BinaryConverter *converter) {
    converter->binary = calloc(MAX_SIZE, sizeof(char)); // Initialize binary representation with null characters
    converter->size = 0; // Initialize size of binary representation to zero
}

void destroy(BinaryConverter *converter) {
    free(converter->binary); // Free memory allocated for binary representation
}

void convert(BinaryConverter *converter, char *input) {
    int i = 0;
    while (input[i]!= '\0') { // Iterate through input string until null character is reached
        if (isalnum(input[i])) { // If character is alphanumeric
            if (isalpha(input[i])) { // If character is alphabetic
                converter->binary[converter->size] = input[i] - 'A' + 1; // Convert character to binary representation
            } else { // If character is numeric
                converter->binary[converter->size] = input[i] - '0'; // Convert character to binary representation
            }
        } else { // If character is not alphanumeric
            converter->binary[converter->size] = 0; // Add null character to binary representation
        }
        i++;
        converter->size++; // Increment size of binary representation
    }
}

void print(BinaryConverter *converter) {
    printf("Binary representation: ");
    for (int i = 0; i < converter->size; i++) { // Iterate through binary representation
        printf("%c", converter->binary[i]); // Print each character in binary representation
    }
    printf("\n");
}

int main() {
    BinaryConverter converter;
    initialize(&converter); // Initialize binary converter
    char input[MAX_SIZE];
    printf("Enter string to convert to binary: ");
    fgets(input, MAX_SIZE, stdin); // Read input string from user
    input[strcspn(input, "\n")] = '\0'; // Remove newline character from input string
    convert(&converter, input); // Convert input string to binary representation
    print(&converter); // Print binary representation
    destroy(&converter); // Free memory allocated for binary representation
    return 0;
}