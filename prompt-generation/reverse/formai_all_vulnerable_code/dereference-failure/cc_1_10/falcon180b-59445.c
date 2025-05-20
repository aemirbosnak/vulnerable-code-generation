//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100
#define MAX_CLEAN_LENGTH (MAX_INPUT_LENGTH * 2)

// Function to sanitize user input
char* sanitize_input(char* input) {
    char clean_input[MAX_CLEAN_LENGTH];
    int clean_input_length = 0;

    // Remove leading/trailing whitespace
    while (isspace(*input)) {
        input++;
    }
    while (isspace(input[strlen(input) - 1])) {
        input[strlen(input) - 1] = '\0';
    }

    // Remove non-alphanumeric characters
    for (int i = 0; i < strlen(input); i++) {
        if (isalnum(input[i])) {
            clean_input[clean_input_length++] = input[i];
        }
    }

    // Add null terminator to clean input
    clean_input[clean_input_length] = '\0';

    // Copy clean input to input buffer
    strcpy(input, clean_input);

    return input;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter some text to sanitize: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Sanitize user input
    char* sanitized_input = sanitize_input(input);

    // Print sanitized input
    printf("Sanitized input: %s\n", sanitized_input);

    return 0;
}