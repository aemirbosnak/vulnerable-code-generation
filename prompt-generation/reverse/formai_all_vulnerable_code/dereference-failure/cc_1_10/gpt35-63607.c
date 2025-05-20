//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

char* sanitize_input(char input[]) {
    int length = strlen(input);

    // Allocate memory for sanitized input
    char* sanitized_input = malloc(MAX_INPUT_LENGTH);

    int j = 0;
    for(int i = 0; i < length; i++) {
        // Only allow alphanumeric characters and spaces
        if(isalnum(input[i]) || isspace(input[i])) {
            // Convert uppercase letters to lowercase
            if(isupper(input[i])) {
                sanitized_input[j] = tolower(input[i]);
            } else {
                sanitized_input[j] = input[i];
            }
            j++;
        }
    }

    // Terminate the sanitized input string
    sanitized_input[j] = '\0';

    return sanitized_input;
}

int main() {
    char input[MAX_INPUT_LENGTH];

    // Prompt user for input
    printf("Enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove the newline character inserted by fgets
    input[strcspn(input, "\n")] = 0;

    // Sanitize user input
    char* sanitized_input = sanitize_input(input);

    printf("Sanitized input: %s\n", sanitized_input);

    // Free dynamically allocated memory
    free(sanitized_input);

    return 0;
}