//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a valid integer
int is_integer(char *str) {
    int i;
    if (str[0] == '-') {
        i = 1;
    } else {
        i = 0;
    }
    for (; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

// Function to check if a string is a valid floating-point number
int is_float(char *str) {
    int i, dot_count;
    if (str[0] == '-') {
        i = 1;
    } else {
        i = 0;
    }
    dot_count = 0;
    for (; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            if (str[i] == '.' && dot_count == 0) {
                dot_count++;
            } else {
                return 0;
            }
        }
    }
    return 1;
}

// Function to sanitize user input
char *sanitize_input(char *input) {
    char *sanitized_input;
    int input_length;

    // Remove leading and trailing whitespace
    while (*input == ' ') {
        input++;
    }
    input_length = strlen(input);
    while (input_length > 0 && input[input_length - 1] == ' ') {
        input_length--;
    }

    // Allocate memory for the sanitized input
    sanitized_input = malloc(input_length + 1);
    if (sanitized_input == NULL) {
        return NULL;
    }

    // Copy the sanitized input into the new buffer
    strncpy(sanitized_input, input, input_length);
    sanitized_input[input_length] = '\0';

    return sanitized_input;
}

int main() {
    char *input;
    char *sanitized_input;

    // Get user input
    printf("Enter a string: ");
    input = malloc(100);
    if (input == NULL) {
        return 1;
    }
    fgets(input, 100, stdin);

    // Sanitize the user input
    sanitized_input = sanitize_input(input);
    if (sanitized_input == NULL) {
        return 1;
    }

    // Check if the sanitized input is a valid integer
    if (is_integer(sanitized_input)) {
        printf("The sanitized input is a valid integer: %s\n", sanitized_input);
    } else {
        printf("The sanitized input is not a valid integer: %s\n", sanitized_input);
    }

    // Check if the sanitized input is a valid floating-point number
    if (is_float(sanitized_input)) {
        printf("The sanitized input is a valid floating-point number: %s\n", sanitized_input);
    } else {
        printf("The sanitized input is not a valid floating-point number: %s\n", sanitized_input);
    }

    // Free the allocated memory
    free(input);
    free(sanitized_input);

    return 0;
}