//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum input size.
#define MAX_INPUT_SIZE 1024

// Function to sanitize user input.
char* sanitize_input(char* input) {

    // Allocate memory for the sanitized input.
    char* sanitized_input = (char*)malloc(MAX_INPUT_SIZE);
    if (sanitized_input == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for sanitized input.\n");
        exit(EXIT_FAILURE);
    }

    // Copy the input into the sanitized input.
    strcpy(sanitized_input, input);

    // Replace all non-alphanumeric characters with spaces.
    for (int i = 0; i < strlen(sanitized_input); i++) {
        if (!isalnum(sanitized_input[i])) {
            sanitized_input[i] = ' ';
        }
    }

    // Trim any leading or trailing spaces.
    while (isspace(sanitized_input[0])) {
        memmove(sanitized_input, sanitized_input + 1, strlen(sanitized_input));
    }
    while (isspace(sanitized_input[strlen(sanitized_input) - 1])) {
        sanitized_input[strlen(sanitized_input) - 1] = '\0';
    }

    // Return the sanitized input.
    return sanitized_input;
}

// Main function.
int main(void) {

    // Get the user input.
    char input[MAX_INPUT_SIZE];
    printf("Enter your input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Sanitize the user input.
    char* sanitized_input = sanitize_input(input);

    // Print the sanitized input.
    printf("Sanitized input: %s\n", sanitized_input);

    // Free the memory allocated for the sanitized input.
    free(sanitized_input);

    return EXIT_SUCCESS;
}