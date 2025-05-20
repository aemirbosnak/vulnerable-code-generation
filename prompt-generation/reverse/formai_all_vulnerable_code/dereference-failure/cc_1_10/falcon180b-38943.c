//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_SANITIZED_LENGTH (MAX_INPUT_LENGTH * 2)

// Function to sanitize user input
void sanitize_input(char* input) {
    char sanitized_input[MAX_SANITIZED_LENGTH];
    size_t sanitized_input_length = 0;

    // Remove any leading/trailing whitespace
    while (isspace(*input)) {
        input++;
    }
    while (isspace(*(input + strlen(input) - 1))) {
        input[strlen(input) - 1] = '\0';
    }

    // Convert input to lowercase
    for (int i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            sanitized_input[sanitized_input_length++] = tolower(input[i]);
        }
    }
    sanitized_input[sanitized_input_length] = '\0';

    // Remove any non-alphanumeric characters
    for (int i = 0; i < strlen(sanitized_input); i++) {
        if (!isalnum(sanitized_input[i])) {
            sanitized_input[i] = '_';
        }
    }

    // Copy sanitized input back to original input buffer
    strcpy(input, sanitized_input);
}

int main() {
    char input[MAX_INPUT_LENGTH];

    // Get user input
    printf("Enter some text:\n");
    if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL) {
        printf("Error: Input was too long.\n");
        return 1;
    }

    // Sanitize input
    sanitize_input(input);

    // Print sanitized input
    printf("Sanitized input: %s\n", input);

    return 0;
}