//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the maximum input length
#define MAX_INPUT_LENGTH 1024

// Define the list of allowed characters
char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

// Function to check if a character is allowed
int is_allowed_char(char c) {
    for (int i = 0; i < strlen(allowed_chars); i++) {
        if (c == allowed_chars[i]) {
            return 1;
        }
    }
    return 0;
}

// Function to sanitize user input
char* sanitize_input(char* input) {
    // Allocate memory for the sanitized input
    char* sanitized_input = malloc(MAX_INPUT_LENGTH);

    // Initialize the sanitized input to empty
    sanitized_input[0] = '\0';

    // Iterate over the input string
    for (int i = 0; i < strlen(input); i++) {
        // Check if the character is allowed
        if (is_allowed_char(input[i])) {
            // Append the character to the sanitized input
            strcat(sanitized_input, &input[i]);
        }
    }

    // Return the sanitized input
    return sanitized_input;
}

// Main function
int main() {
    // Get user input
    char input[MAX_INPUT_LENGTH];
    printf("Enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Sanitize the user input
    char* sanitized_input = sanitize_input(input);

    // Print the sanitized input
    printf("Sanitized input: %s\n", sanitized_input);

    // Free the allocated memory
    free(sanitized_input);

    return 0;
}