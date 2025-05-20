//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is an integer
int is_integer(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

// Function to check if a string is a float
int is_float(char *str) {
    int i, dot_count = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.' && ++dot_count > 1) {
            return 0;
        }
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

// Function to sanitize user input
char *sanitize_input(char *input) {
    char *sanitized_input = malloc(strlen(input) + 1);
    int i, j = 0;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == '<' || input[i] == '>' || input[i] == '&' || input[i] == '"') {
            continue;
        }
        sanitized_input[j++] = input[i];
    }
    sanitized_input[j] = '\0';
    return sanitized_input;
}

// Main function
int main() {
    char *input = malloc(100);
    printf("Enter your input: ");
    scanf("%s", input);

    // Sanitize the input
    char *sanitized_input = sanitize_input(input);

    // Check if the input is an integer
    if (is_integer(sanitized_input)) {
        printf("The input is an integer: %s\n", sanitized_input);
    }
    // Check if the input is a float
    else if (is_float(sanitized_input)) {
        printf("The input is a float: %s\n", sanitized_input);
    }
    // Otherwise, the input is a string
    else {
        printf("The input is a string: %s\n", sanitized_input);
    }

    // Free the allocated memory
    free(input);
    free(sanitized_input);
    return 0;
}