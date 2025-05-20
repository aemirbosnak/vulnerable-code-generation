//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize a user input string
char *sanitize_input(char *str) {
    // Allocate a new string to store the sanitized input
    char *sanitized = (char *)malloc(strlen(str) + 1);
    if (sanitized == NULL) {
        return NULL;
    }

    // Copy the input string to the sanitized string
    strcpy(sanitized, str);

    // Iterate over the characters in the sanitized string
    for (int i = 0; i < strlen(sanitized); i++) {
        // Check if the character is a letter or a number
        if (!isalpha(sanitized[i]) && !isdigit(sanitized[i])) {
            // If the character is not a letter or a number, replace it with an underscore
            sanitized[i] = '_';
        }
    }

    // Return the sanitized string
    return sanitized;
}

// Main function
int main() {
    // Get the user input
    char *input = (char *)malloc(1024);
    if (input == NULL) {
        return EXIT_FAILURE;
    }
    printf("Enter a string: ");
    fgets(input, 1024, stdin);

    // Sanitize the user input
    char *sanitized = sanitize_input(input);
    if (sanitized == NULL) {
        return EXIT_FAILURE;
    }

    // Print the sanitized string
    printf("Sanitized string: %s\n", sanitized);

    // Free the allocated memory
    free(input);
    free(sanitized);

    return EXIT_SUCCESS;
}