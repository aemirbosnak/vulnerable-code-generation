//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Define a macro to check if a character is alphanumeric
#define IS_ALNUM(ch) ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))

// Function to sanitize user input
char* sanitize_input(char* input) {
    // Allocate memory for the sanitized input
    char* sanitized_input = malloc(sizeof(char) * (strlen(input) + 1));
    if (sanitized_input == NULL) {
        return NULL;
    }

    // Initialize the index of the sanitized input
    int index = 0;

    // Iterate over the characters in the input
    for (int i = 0; input[i] != '\0'; i++) {
        // Check if the character is alphanumeric
        if (IS_ALNUM(input[i])) {
            // Append the character to the sanitized input
            sanitized_input[index++] = input[i];
        }
    }

    // Null-terminate the sanitized input
    sanitized_input[index] = '\0';

    // Return the sanitized input
    return sanitized_input;
}

int main() {
    // Get the user input
    char* input = malloc(sizeof(char) * 100);
    if (input == NULL) {
        return EXIT_FAILURE;
    }
    printf("Enter your input: ");
    fgets(input, 100, stdin);

    // Sanitize the user input
    char* sanitized_input = sanitize_input(input);
    if (sanitized_input == NULL) {
        return EXIT_FAILURE;
    }

    // Print the sanitized input
    printf("Sanitized input: %s", sanitized_input);

    // Free the allocated memory
    free(input);
    free(sanitized_input);

    return EXIT_SUCCESS;
}