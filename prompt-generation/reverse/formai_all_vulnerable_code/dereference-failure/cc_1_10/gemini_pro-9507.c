//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_INPUT_LENGTH 1024

// Define the list of allowed characters
char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

// Function to sanitize the input string
char *sanitize_input(char *input) {
    // Allocate memory for the sanitized string
    char *sanitized_input = malloc(MAX_INPUT_LENGTH);

    // Loop through the input string
    int i = 0;
    while (input[i] != '\0') {
        // Check if the current character is allowed
        int is_allowed = 0;
        for (int j = 0; j < strlen(allowed_chars); j++) {
            if (input[i] == allowed_chars[j]) {
                is_allowed = 1;
                break;
            }
        }

        // If the current character is allowed, add it to the sanitized string
        if (is_allowed) {
            sanitized_input[i] = input[i];
        }

        // Increment the index of the input string
        i++;
    }

    // Null-terminate the sanitized string
    sanitized_input[i] = '\0';

    // Return the sanitized string
    return sanitized_input;
}

// Function to take input from the user
char *get_input() {
    // Allocate memory for the input string
    char *input = malloc(MAX_INPUT_LENGTH);

    // Read the input string from the user
    printf("Enter your input: ");
    scanf(" %[^\n]s", input);

    // Return the input string
    return input;
}

// Function to print the sanitized input
void print_sanitized_input(char *sanitized_input) {
    // Print the sanitized input
    printf("The sanitized input is: %s\n", sanitized_input);

    // Free the memory allocated for the sanitized input
    free(sanitized_input);
}

// Main function
int main() {
    // Get the input from the user
    char *input = get_input();

    // Sanitize the input
    char *sanitized_input = sanitize_input(input);

    // Print the sanitized input
    print_sanitized_input(sanitized_input);

    // Free the memory allocated for the input
    free(input);

    return 0;
}