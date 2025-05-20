//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of user input
#define MAX_INPUT_LENGTH 1024

// Define the list of allowed characters
char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .,?!";

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

    // Copy the first character of the input to the sanitized input
    sanitized_input[0] = input[0];

    // Loop through the remaining characters in the input
    for (int i = 1; i < strlen(input); i++) {
        // Check if the character is allowed
        if (is_allowed_char(input[i])) {
            // If the character is allowed, copy it to the sanitized input
            sanitized_input[i] = input[i];
        } else {
            // If the character is not allowed, replace it with a space
            sanitized_input[i] = ' ';
        }
    }

    // Null-terminate the sanitized input
    sanitized_input[strlen(input)] = '\0';

    // Return the sanitized input
    return sanitized_input;
}

// Main function
int main() {
    // Prompt the user for input
    printf("Enter your input: ");

    // Get the user input
    char input[MAX_INPUT_LENGTH];
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Sanitize the user input
    char* sanitized_input = sanitize_input(input);

    // Print the sanitized input
    printf("Sanitized input: %s\n", sanitized_input);

    // Free the memory allocated for the sanitized input
    free(sanitized_input);

    return 0;
}