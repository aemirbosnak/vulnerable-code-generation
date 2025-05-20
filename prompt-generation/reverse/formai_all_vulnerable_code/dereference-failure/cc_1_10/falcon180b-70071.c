//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

// Function to sanitize user input
char* sanitize_input(char* input) {
    char* sanitized_input = malloc(MAX_INPUT_LENGTH * sizeof(char));
    int i = 0;

    // Remove any leading or trailing whitespace
    while (isspace(*input)) {
        input++;
    }
    while (isspace(*(input + strlen(input) - 1))) {
        *(input + strlen(input) - 1) = '\0';
        input--;
    }

    // Sanitize any non-alphanumeric characters
    for (i = 0; i < strlen(input); i++) {
        if (!isalnum(*(input + i))) {
            *(sanitized_input + i) = '_';
        } else {
            *(sanitized_input + i) = *(input + i);
        }
    }

    // Add null terminator
    *(sanitized_input + strlen(input)) = '\0';

    return sanitized_input;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char* sanitized_input;

    // Prompt user for input
    printf("Enter some text: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Sanitize input
    sanitized_input = sanitize_input(input);

    // Print sanitized input
    printf("Sanitized input: %s\n", sanitized_input);

    // Free memory
    free(sanitized_input);

    return 0;
}