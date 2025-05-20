//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_INPUT_SIZE 1024

// Function to check if a character is alphanumeric
int is_alphanumeric(char c) {
    return (isalnum(c) || (c == '_'));
}

// Function to sanitize input
char *sanitize_input(char *input) {
    char *sanitized_input = malloc(MAX_INPUT_SIZE);
    int sanitized_length = 0;

    // Loop through each character in the input
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];

        // Check if the character is alphanumeric
        if (is_alphanumeric(c)) {
            // Convert the character to lowercase and add it to the sanitized input
            sanitized_input[sanitized_length++] = tolower(c);
        }
    }

    // Add a null terminator to the end of the sanitized input
    sanitized_input[sanitized_length] = '\0';

    return sanitized_input;
}

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Enter some input:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Sanitize the input
    char *sanitized_input = sanitize_input(input);

    // Print the sanitized input
    printf("Sanitized input: %s\n", sanitized_input);

    free(sanitized_input);

    return 0;
}