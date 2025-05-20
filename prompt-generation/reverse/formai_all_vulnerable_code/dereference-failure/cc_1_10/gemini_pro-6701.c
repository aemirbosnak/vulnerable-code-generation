//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

// Function to sanitize user input
char* sanitize(char* input) {
    // Allocate memory for the sanitized input
    char* sanitized_input = malloc(MAX_INPUT_SIZE);

    // Copy the input to the sanitized input
    strcpy(sanitized_input, input);

    // Loop through the sanitized input
    for (int i = 0; i < strlen(sanitized_input); i++) {
        // Check if the current character is a special character
        if (strchr("<>&;", sanitized_input[i])) {
            // Replace the special character with an HTML entity
            switch (sanitized_input[i]) {
                case '<':
                    strcat(sanitized_input, "&lt;");
                    break;
                case '>':
                    strcat(sanitized_input, "&gt;");
                    break;
                case '&':
                    strcat(sanitized_input, "&amp;");
                    break;
                case ';':
                    strcat(sanitized_input, "&semi;");
                    break;
            }

            // Remove the special character from the sanitized input
            sanitized_input[i] = '\0';
        }
    }

    // Return the sanitized input
    return sanitized_input;
}

// Function to validate user input
int validate(char* input) {
    // Check if the input is empty
    if (strlen(input) == 0) {
        return 0;
    }

    // Check if the input contains any special characters
    for (int i = 0; i < strlen(input); i++) {
        if (strchr("<>&;", input[i])) {
            return 0;
        }
    }

    // The input is valid
    return 1;
}

// Function to get user input
char* get_input() {
    // Allocate memory for the user input
    char* input = malloc(MAX_INPUT_SIZE);

    // Get the user input
    printf("Enter your input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Remove the newline character from the input
    input[strlen(input) - 1] = '\0';

    // Return the user input
    return input;
}

// Main function
int main() {
    // Get the user input
    char* input = get_input();

    // Validate the user input
    if (!validate(input)) {
        // The input is invalid
        printf("Invalid input.\n");
        return 1;
    }

    // Sanitize the user input
    char* sanitized_input = sanitize(input);

    // Print the sanitized input
    printf("Sanitized input: %s\n", sanitized_input);

    // Free the memory allocated for the user input and the sanitized input
    free(input);
    free(sanitized_input);

    return 0;
}