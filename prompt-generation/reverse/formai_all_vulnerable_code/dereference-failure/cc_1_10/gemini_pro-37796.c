//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a macro to check if a character is alphanumeric
#define IS_ALNUM(c) ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))

// Define a macro to check if a character is a whitespace character
#define IS_WHITESPACE(c) (c == ' ' || c == '\t' || c == '\n' || c == '\r')

// Define a function to sanitize a string
char *sanitize_string(char *str) {
    // Allocate a new string to store the sanitized string
    char *sanitized_str = (char *)malloc(strlen(str) + 1);

    // Initialize the index of the sanitized string
    int i = 0;

    // Iterate over the characters in the original string
    for (int j = 0; j < strlen(str); j++) {
        // If the character is alphanumeric, add it to the sanitized string
        if (IS_ALNUM(str[j])) {
            sanitized_str[i++] = str[j];
        }
        // If the character is a whitespace character, add a single space to the sanitized string
        else if (IS_WHITESPACE(str[j])) {
            sanitized_str[i++] = ' ';
        }
    }

    // Add a null terminator to the sanitized string
    sanitized_str[i] = '\0';

    // Return the sanitized string
    return sanitized_str;
}

// Define a main function
int main() {
    // Get the input string from the user
    char str[100];
    printf("Enter a string: ");
    gets(str);

    // Sanitize the input string
    char *sanitized_str = sanitize_string(str);

    // Print the sanitized string
    printf("Sanitized string: %s\n", sanitized_str);

    // Free the memory allocated for the sanitized string
    free(sanitized_str);

    return 0;
}