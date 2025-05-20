//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum allowed input length
#define MAX_INPUT_LENGTH 1024

// Define the list of allowed characters
char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .,?!;:()[]{}<>+-*/";

// Define the sanitizer function
char* sanitize_input(char* input) {
    // Allocate memory for the sanitized input
    char* sanitized_input = malloc(strlen(input) + 1);

    // Initialize the index of the sanitized input
    int sanitized_index = 0;

    // Iterate over the characters in the input
    for (int i = 0; i < strlen(input); i++) {
        // Check if the character is allowed
        if (strchr(allowed_chars, input[i]) != NULL) {
            // Add the character to the sanitized input
            sanitized_input[sanitized_index++] = input[i];
        }
    }

    // Terminate the sanitized input with a null character
    sanitized_input[sanitized_index] = '\0';

    // Return the sanitized input
    return sanitized_input;
}

// Define the main function
int main() {
    // Get the input from the user
    char input[MAX_INPUT_LENGTH];
    printf("Enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Sanitize the input
    char* sanitized_input = sanitize_input(input);

    // Print the sanitized input
    printf("Sanitized input: %s", sanitized_input);

    // Free the memory allocated for the sanitized input
    free(sanitized_input);

    // Return 0 to indicate successful execution
    return 0;
}