//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to sanitize user input
char *sanitize_input(char *input, size_t max_len) {
    // Replace special characters with HTML entities
    char *sanitized = malloc(max_len);
    if (sanitized == NULL) {
        return NULL;
    }

    size_t i = 0;
    while (input[i] != '\0') {
        switch (input[i]) {
            case '<':
                strcat(sanitized, "&lt;");
                break;
            case '>':
                strcat(sanitized, "&gt;");
                break;
            case '&':
                strcat(sanitized, "&amp;");
                break;
            case '"':
                strcat(sanitized, "&quot;");
                break;
            case '\'':
                strcat(sanitized, "&#39;");
                break;
            default:
                sanitized[i] = input[i];
        }
        i++;
    }

    sanitized[i] = '\0';
    return sanitized;
}

// Function to get user input
char *get_user_input(size_t max_len) {
    char *input = malloc(max_len);
    if (input == NULL) {
        return NULL;
    }

    printf("Enter input: ");
    fgets(input, max_len, stdin);

    // Remove the newline character from the input
    strtok(input, "\n");

    return input;
}

int main() {
    // Set the maximum length of user input
    size_t max_len = 100;

    // Get user input
    char *input = get_user_input(max_len);
    if (input == NULL) {
        printf("Error allocating memory for user input.\n");
        return 1;
    }

    // Sanitize the user input
    char *sanitized_input = sanitize_input(input, max_len);
    if (sanitized_input == NULL) {
        printf("Error allocating memory for sanitized input.\n");
        return 1;
    }

    // Print the sanitized input
    printf("Sanitized input: %s\n", sanitized_input);

    // Free the allocated memory
    free(input);
    free(sanitized_input);

    return 0;
}