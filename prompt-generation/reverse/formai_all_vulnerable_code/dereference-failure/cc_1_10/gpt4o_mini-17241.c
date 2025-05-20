//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

// Function to trim whitespace from both ends of a string
char* trim_whitespace(char *str) {
    char *end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return str; // All spaces
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0'; // Null terminate after the last non-space character
    return str;
}

// Function to sanitize user input
void sanitize_input(char *input) {
    char *sanitized = (char *)malloc(MAX_INPUT_LENGTH);
    int index = 0;

    for (int i = 0; input[i] != '\0' && index < MAX_INPUT_LENGTH - 1; i++) {
        // Only allow alphanumeric characters and spaces
        if (isalnum((unsigned char)input[i]) || isspace((unsigned char)input[i])) {
            sanitized[index++] = input[i];
        }
    }
    sanitized[index] = '\0';
    strncpy(input, sanitized, MAX_INPUT_LENGTH); // Copy sanitized input back
    free(sanitized);
}

int main() {
    char user_input[MAX_INPUT_LENGTH];

    printf("🎉 Welcome to the User Input Sanitizer! 🎉\n");
    printf("Please enter a string (max %d characters): ", MAX_INPUT_LENGTH - 1);

    if (fgets(user_input, MAX_INPUT_LENGTH, stdin) != NULL) {
        // Remove the newline character from fgets
        user_input[strcspn(user_input, "\n")] = '\0';

        // Trim and sanitize the input
        char *trimmed_input = trim_whitespace(user_input);
        sanitize_input(trimmed_input);

        printf("🌟 Sanitized Input: \"%s\"\n", trimmed_input);
    } else {
        printf("Oops! Something went wrong. Please try again.\n");
    }

    return 0;
}