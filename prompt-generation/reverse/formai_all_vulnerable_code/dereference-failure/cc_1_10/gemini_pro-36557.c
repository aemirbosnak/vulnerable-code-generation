//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: cheerful
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cheerful input sanitizer helper functions
static bool is_safe_char(char c) {
    return isalnum(c) || c == '_' || c == '-' || c == ' ';
}

static bool is_safe_input(char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (!is_safe_char(input[i])) {
            return false;
        }
    }
    return true;
}

// Main input sanitizer function
char *sanitize_input(char *input) {
    int sanitized_len = 0;
    // Count the number of safe characters in the input
    for (int i = 0; input[i] != '\0'; i++) {
        if (is_safe_char(input[i])) {
            sanitized_len++;
        }
    }
    // Allocate memory for the sanitized input
    char *sanitized_input = malloc(sanitized_len + 1);
    // Copy only the safe characters to the sanitized input
    int idx = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (is_safe_char(input[i])) {
            sanitized_input[idx++] = input[i];
        }
    }
    sanitized_input[idx] = '\0';
    return sanitized_input;
}

int main() {
    // Let's cheer up the user with a friendly greeting!
    printf("Hello there, cautious coder! Let's keep your inputs safe and secure!\n");
    // Prompt the user to enter some input
    printf("Please enter some input (alphabets, numbers, underscores, hyphens, and spaces only): ");
    char *input = NULL;
    size_t len = 0;
    getline(&input, &len, stdin);
    // Now, let's use our input sanitizer to make sure the input is safe
    char *sanitized_input = sanitize_input(input);
    // Check if the input was safe or not
    if (strcmp(input, sanitized_input) == 0) {
        printf("Yay! Your input is squeaky clean!\n");
    } else {
        printf("Oops! We've done some scrubbing and made your input safer:\n");
        printf("Original input: %s\n", input);
        printf("Sanitized input: %s\n", sanitized_input);
    }
    // Tidy up by freeing the allocated memory
    free(sanitized_input);
    return 0;
}