//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// A custom function to sanitize user input
char* sanitize_input(char* input) {
    // Allocate memory for the sanitized input
    char* sanitized_input = malloc(strlen(input) + 1);
    if (sanitized_input == NULL) {
        // Handle memory allocation error
        return NULL;
    }

    // Initialize a counter to keep track of the position in the sanitized input
    int sanitized_index = 0;

    // Iterate over the characters in the input
    for (int i = 0; input[i] != '\0'; i++) {
        // Check if the character is alphanumeric or a space
        if (isalnum(input[i]) || input[i] == ' ') {
            // Copy the character to the sanitized input
            sanitized_input[sanitized_index++] = input[i];
        }
    }

    // Add a null terminator to the sanitized input
    sanitized_input[sanitized_index] = '\0';

    // Return the sanitized input
    return sanitized_input;
}

int main() {
    // Get user input
    char* input = malloc(1024);
    if (input == NULL) {
        // Handle memory allocation error
        return 1;
    }
    printf("Enter your input: ");
    fgets(input, 1024, stdin);

    // Sanitize the user input
    char* sanitized_input = sanitize_input(input);
    if (sanitized_input == NULL) {
        // Handle memory allocation error
        return 1;
    }

    // Print the sanitized input
    printf("Sanitized input: %s", sanitized_input);

    // Free the allocated memory
    free(input);
    free(sanitized_input);

    return 0;
}