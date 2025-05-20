//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is valid in a given context
int is_valid_char(char c, int context) {
    switch (context) {
        case 0:  // Alphanumeric only
            return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
        case 1:  // Alphabetic only
            return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
        case 2:  // Numeric only
            return (c >= '0' && c <= '9');
        case 3:  // Alphanumeric or space
            return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c == ' ');
        case 4:  // Alphabetic or space
            return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == ' ');
        case 5:  // Any character
            return 1;
        default:
            return 0;  // Invalid context
    }
}

// Function to sanitize a string according to a given context
char *sanitize_string(char *input, int context) {
    char *sanitized = malloc(strlen(input) + 1);
    int i, j;
    for (i = 0, j = 0; input[i] != '\0'; i++) {
        if (is_valid_char(input[i], context)) {
            sanitized[j++] = input[i];
        }
    }
    sanitized[j] = '\0';
    return sanitized;
}

int main() {
    // Get the input string from the user
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Sanitize the string according to the given context
    char *sanitized = sanitize_string(input, 0);  // Alphanumeric only

    // Print the sanitized string
    printf("Sanitized string: %s", sanitized);

    // Free the allocated memory
    free(sanitized);

    return 0;
}