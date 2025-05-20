//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

// Function to sanitize user input
void sanitize_input(char* input) {
    // Remove leading and trailing white spaces
    int len = strlen(input);
    while (isspace(input[0])) {
        input++;
        len--;
    }
    while (len > 0 && isspace(input[len - 1])) {
        input[--len] = 0;
    }

    // Remove any non-alphanumeric characters
    char* sanitized = malloc(MAX_INPUT_LENGTH * sizeof(char));
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalnum(input[i])) {
            sanitized[j++] = input[i];
        }
    }
    sanitized[j] = 0;

    // Copy sanitized input back to original input
    strcpy(input, sanitized);

    // Free temporary memory
    free(sanitized);
}

int main() {
    char input[MAX_INPUT_LENGTH];

    // Get user input
    printf("Enter a string: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Sanitize user input
    sanitize_input(input);

    // Print sanitized input
    printf("\nSanitized input: %s\n", input);

    return 0;
}