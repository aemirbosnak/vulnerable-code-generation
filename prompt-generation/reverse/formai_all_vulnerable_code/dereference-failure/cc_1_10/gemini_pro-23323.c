//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum input length
#define MAX_INPUT_LENGTH 1024

// Define the allowed characters for input
#define ALLOWED_CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ,.-'?!()"

// Function to validate a string based on a set of allowed characters
int validate_string(char *input, char *allowed_characters) {
    // Check if input is NULL or empty
    if (input == NULL || strlen(input) == 0) {
        return 0;
    }

    // Check if each character in the input is allowed
    for (int i = 0; i < strlen(input); i++) {
        if (strchr(allowed_characters, input[i]) == NULL) {
            return 0;
        }
    }

    // If all characters are allowed, return 1
    return 1;
}

// Function to sanitize a string by replacing invalid characters with a placeholder character
char *sanitize_string(char *input, char *allowed_characters, char placeholder) {
    // Allocate memory for the sanitized string
    char *sanitized_string = (char *)malloc(strlen(input) + 1);

    // Copy the input string to the sanitized string
    strcpy(sanitized_string, input);

    // Replace invalid characters with the placeholder character
    for (int i = 0; i < strlen(sanitized_string); i++) {
        if (strchr(allowed_characters, sanitized_string[i]) == NULL) {
            sanitized_string[i] = placeholder;
        }
    }

    // Return the sanitized string
    return sanitized_string;
}

int main() {
    // Get input from the user
    char input[MAX_INPUT_LENGTH];
    printf("Enter a string: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Validate the input
    if (validate_string(input, ALLOWED_CHARACTERS)) {
        printf("The input is valid.\n");
    } else {
        printf("The input is invalid.\n");
    }

    // Sanitize the input
    char *sanitized_input = sanitize_string(input, ALLOWED_CHARACTERS, '*');

    // Print the sanitized input
    printf("The sanitized input is: %s\n", sanitized_input);

    // Free the memory allocated for the sanitized string
    free(sanitized_input);

    return 0;
}