//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a character to its ASCII equivalent in a string
void charToASCII(char ch, char* buffer) {
    sprintf(buffer, "%d ", (int)ch); // Store ASCII value
}

// Function to convert a string to ASCII art
void stringToASCIIArt(const char* input) {
    int length = strlen(input);
    char** asciiValues = malloc(length * sizeof(char*));
    
    // Create and fill each buffer with ASCII values
    for (int i = 0; i < length; i++) {
        asciiValues[i] = malloc(5 * sizeof(char)); // max 3 digits for ASCII + space + null
        charToASCII(input[i], asciiValues[i]);
    }
    
    // Print the ASCII values
    printf("ASCII values for the input string \"%s\":\n", input);
    for (int i = 0; i < length; i++) {
        printf("%s", asciiValues[i]);
        free(asciiValues[i]); // Free individual buffers after use
    }
    printf("\n");
    
    free(asciiValues); // Free the array of buffers
}

// Function to generate a decorative ASCII art border
void printBorder(int length) {
    for (int i = 0; i < length + 2; i++) {
        printf("*"); // Print border on top and bottom
    }
    printf("\n");
}

// Main function
int main() {
    char input[256];
    
    printf("Welcome to the Text to ASCII Art Generator!\n");
    printf("Please enter a string (max 255 characters): ");
    
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove newline character if present
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        printBorder(strlen(input)); // Print top border
        stringToASCIIArt(input); // String to ASCII conversion
        printBorder(strlen(input)); // Print bottom border
    } else {
        fprintf(stderr, "Error reading input.\n");
    }
    
    return 0;
}