//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to sanitize user input
char *sanitize_input(char *input) {
    // Allocate memory for the sanitized input
    char *sanitized_input = malloc(strlen(input) + 1);
    if (sanitized_input == NULL) {
        return NULL;
    }

    // Copy the input to the sanitized input
    strcpy(sanitized_input, input);

    // Replace all special characters with spaces
    for (int i = 0; i < strlen(sanitized_input); i++) {
        if (!isalnum(sanitized_input[i])) {
            sanitized_input[i] = ' ';
        }
    }

    // Remove all leading and trailing spaces
    while (isspace(sanitized_input[0])) {
        memmove(sanitized_input, sanitized_input + 1, strlen(sanitized_input));
    }
    while (isspace(sanitized_input[strlen(sanitized_input) - 1])) {
        sanitized_input[strlen(sanitized_input) - 1] = '\0';
    }

    // Return the sanitized input
    return sanitized_input;
}

// Main function
int main() {
    // Get user input
    char input[100];
    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin);

    // Sanitize the user input
    char *sanitized_input = sanitize_input(input);
    if (sanitized_input == NULL) {
        printf("Error: Could not allocate memory for sanitized input.\n");
        return EXIT_FAILURE;
    }

    // Print the sanitized input
    printf("Sanitized input: %s\n", sanitized_input);

    // Free the memory allocated for the sanitized input
    free(sanitized_input);

    return EXIT_SUCCESS;
}