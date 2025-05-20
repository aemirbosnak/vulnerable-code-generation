//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of the input string
#define MAX_INPUT_LENGTH 100

// Define the allowed characters in the input string
const char ALLOWED_CHARACTERS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,!? ";

// Function to check if the input string contains only allowed characters
bool is_valid_input(const char *input) {
    for (int i = 0; i < strlen(input); i++) {
        if (!strchr(ALLOWED_CHARACTERS, input[i])) {
            return false;
        }
    }
    return true;
}

// Function to sanitize the input string by removing all non-allowed characters
char *sanitize_input(char *input) {
    char *sanitized_input = malloc(strlen(input) + 1);
    int j = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (strchr(ALLOWED_CHARACTERS, input[i])) {
            sanitized_input[j++] = input[i];
        }
    }
    sanitized_input[j] = '\0';
    return sanitized_input;
}

int main() {
    // Get the user input
    char input[MAX_INPUT_LENGTH];
    printf("Enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Check if the input is valid
    if (!is_valid_input(input)) {
        printf("Invalid input. Please enter only allowed characters.\n");
        return EXIT_FAILURE;
    }

    // Sanitize the input
    char *sanitized_input = sanitize_input(input);

    // Print the sanitized input
    printf("Sanitized input: %s\n", sanitized_input);

    // Free the allocated memory
    free(sanitized_input);

    return EXIT_SUCCESS;
}