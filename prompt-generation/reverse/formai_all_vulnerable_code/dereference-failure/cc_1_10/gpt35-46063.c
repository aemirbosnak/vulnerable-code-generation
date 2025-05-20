//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define maximum input length
#define MAX_INPUT_LENGTH 100

// Define function to sanitize user input
char* sanitize_input(char* input) {
    // Allocate memory for new sanitized string
    char* sanitized_input = (char*) malloc(MAX_INPUT_LENGTH * sizeof(char));

    // Initialize new string index and input string index
    int new_index = 0, input_index = 0;

    // Iterate through input string
    while (input[input_index] != '\0') {
        // Check if character is alphanumeric or space
        if ((input[input_index] >= 'a' && input[input_index] <= 'z') ||
                (input[input_index] >= 'A' && input[input_index] <= 'Z') ||
                (input[input_index] >= '0' && input[input_index] <= '9') ||
                input[input_index] == ' ') {
            // Character is valid, add to new string
            sanitized_input[new_index] = input[input_index];
            new_index++;
        }

        // Increment input index
        input_index++;
    }

    // Null-terminate sanitized string
    sanitized_input[new_index] = '\0';

    // Return sanitized string
    return sanitized_input;
}

int main() {
    // Define input buffer
    char input_buffer[MAX_INPUT_LENGTH];

    // Request user input
    printf("Enter a string: ");
    fgets(input_buffer, MAX_INPUT_LENGTH, stdin);

    // Sanitize user input
    char* sanitized_input = sanitize_input(input_buffer);

    // Print sanitized input
    printf("Sanitized input: %s\n", sanitized_input);

    // Free sanitized input memory
    free(sanitized_input);

    // Exit program
    return 0;
}