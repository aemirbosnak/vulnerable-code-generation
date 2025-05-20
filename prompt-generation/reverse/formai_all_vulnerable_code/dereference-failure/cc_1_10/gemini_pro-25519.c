//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Welcome message
void print_welcome() {
    printf("Welcome to the Wasteland Sanitizer, wanderer.\n");
    printf("Here, you can cleanse your tainted text of impurities and filth.\n");
    printf("Enter your corrupted input, and I shall purify it.\n\n");
}

// Get user input
char *get_user_input() {
    char *input = NULL;
    size_t len = 0;
    printf("Enter your text: ");
    getline(&input, &len, stdin);
    return input;
}

// Sanitize user input
char *sanitize_input(char *input) {
    int i, len = strlen(input);
    char *sanitized = malloc(len + 1);
    for (i = 0; i < len; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            sanitized[i] = input[i];
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            sanitized[i] = input[i];
        } else if (input[i] >= '0' && input[i] <= '9') {
            sanitized[i] = input[i];
        } else if (input[i] == ' ' || input[i] == '.' || input[i] == ',') {
            sanitized[i] = input[i];
        } else {
            sanitized[i] = '_';
        }
    }
    sanitized[len] = '\0';
    return sanitized;
}

// Print sanitized output
void print_sanitized_output(char *sanitized) {
    printf("\nSanitized output: %s\n", sanitized);
}

// Main function
int main() {
    char *input, *sanitized;
    print_welcome();
    input = get_user_input();
    sanitized = sanitize_input(input);
    print_sanitized_output(sanitized);
    free(input);
    free(sanitized);
    return 0;
}