//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_INPUT_LENGTH 1024

// Define the list of allowed characters
char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";

// Get the user input
char *get_user_input(void) {
    // Allocate memory for the input string
    char *input_string = (char *)malloc(MAX_INPUT_LENGTH);
    if (input_string == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for the input string.\n");
        exit(1);
    }

    // Get the input string from the user
    printf("Enter your input: ");
    fgets(input_string, MAX_INPUT_LENGTH, stdin);

    // Remove the newline character from the input string
    input_string[strlen(input_string) - 1] = '\0';

    // Return the input string
    return input_string;
}

// Sanitize the user input
char *sanitize_user_input(char *input_string) {
    // Allocate memory for the sanitized input string
    char *sanitized_input_string = (char *)malloc(MAX_INPUT_LENGTH);
    if (sanitized_input_string == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for the sanitized input string.\n");
        exit(1);
    }

    // Initialize the sanitized input string
    sanitized_input_string[0] = '\0';

    // Iterate over the input string
    for (int i = 0; i < strlen(input_string); i++) {
        // Check if the current character is allowed
        if (strchr(allowed_chars, input_string[i]) != NULL) {
            // Add the current character to the sanitized input string
            strncat(sanitized_input_string, &input_string[i], 1);
        }
    }

    // Return the sanitized input string
    return sanitized_input_string;
}

// Print the sanitized user input
void print_sanitized_user_input(char *sanitized_input_string) {
    // Print the sanitized input string
    printf("Sanitized input: %s\n", sanitized_input_string);
}

// Main function
int main(void) {
    // Get the user input
    char *input_string = get_user_input();

    // Sanitize the user input
    char *sanitized_input_string = sanitize_user_input(input_string);

    // Print the sanitized user input
    print_sanitized_user_input(sanitized_input_string);

    // Free the memory allocated for the input string
    free(input_string);

    // Free the memory allocated for the sanitized input string
    free(sanitized_input_string);

    return 0;
}