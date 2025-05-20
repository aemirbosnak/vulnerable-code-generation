//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum input size
#define MAX_INPUT_SIZE 1024

// Define the list of allowed characters
char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_.";

// Function to sanitize the input
char* sanitize(char* input) {
    // Allocate memory for the sanitized input
    char* sanitized_input = malloc(strlen(input) + 1);

    // Initialize the index of the sanitized input
    int sanitized_input_index = 0;

    // Iterate over the input
    for (int i = 0; i < strlen(input); i++) {
        // Check if the current character is allowed
        int is_allowed = 0;
        for (int j = 0; j < strlen(allowed_chars); j++) {
            if (input[i] == allowed_chars[j]) {
                is_allowed = 1;
                break;
            }
        }

        // If the current character is allowed, add it to the sanitized input
        if (is_allowed) {
            sanitized_input[sanitized_input_index] = input[i];
            sanitized_input_index++;
        }
    }

    // Null-terminate the sanitized input
    sanitized_input[sanitized_input_index] = '\0';

    // Return the sanitized input
    return sanitized_input;
}

// Main function
int main() {
    // Get the input from the user
    char input[MAX_INPUT_SIZE];
    printf("Enter your input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Sanitize the input
    char* sanitized_input = sanitize(input);

    // Print the sanitized input
    printf("Sanitized input: %s", sanitized_input);

    // Free the memory allocated for the sanitized input
    free(sanitized_input);

    return 0;
}