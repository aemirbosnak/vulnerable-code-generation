//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1024

// Define a custom error code for invalid input.
#define ERR_INVALID_INPUT -1

// Define a function to check if a character is alphanumeric.
int is_alphanumeric(char c) {
    return isalpha(c) || isdigit(c);
}

// Define a function to check if a string is alphanumeric.
int is_alphanumeric_string(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_alphanumeric(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Define a function to sanitize a string by removing all non-alphanumeric characters.
char *sanitize_string(char *str) {
    char *sanitized_str = malloc(strlen(str) + 1);
    int sanitized_str_index = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alphanumeric(str[i])) {
            sanitized_str[sanitized_str_index++] = str[i];
        }
    }
    sanitized_str[sanitized_str_index] = '\0';
    return sanitized_str;
}

// Define a function to get a sanitized string from the user.
int get_sanitized_string(char *str, int max_length) {
    // Get the input string from the user.
    if (fgets(str, max_length, stdin) == NULL) {
        return ERR_INVALID_INPUT;
    }

    // Remove the newline character from the end of the string.
    str[strcspn(str, "\n")] = '\0';

    // Sanitize the string.
    char *sanitized_str = sanitize_string(str);

    // Check if the sanitized string is empty.
    if (strlen(sanitized_str) == 0) {
        free(sanitized_str);
        return ERR_INVALID_INPUT;
    }

    // Copy the sanitized string back to the original string.
    strcpy(str, sanitized_str);

    // Free the memory allocated for the sanitized string.
    free(sanitized_str);

    return 0;
}

int main() {
    // Declare a variable to store the user input.
    char input[MAX_INPUT_LENGTH];

    // Get a sanitized string from the user.
    int result = get_sanitized_string(input, MAX_INPUT_LENGTH);

    // Check if the user input is valid.
    if (result == ERR_INVALID_INPUT) {
        printf("Invalid input. Please enter an alphanumeric string.\n");
        return EXIT_FAILURE;
    }

    // Print the sanitized string.
    printf("Sanitized string: %s\n", input);

    return EXIT_SUCCESS;
}