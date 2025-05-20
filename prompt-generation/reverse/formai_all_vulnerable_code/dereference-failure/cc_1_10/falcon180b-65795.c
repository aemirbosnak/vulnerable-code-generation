//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1000

// Function to sanitize user input
void sanitize_input(char* input) {
    // Remove leading and trailing whitespace
    char* input_trimmed = input;
    while (isspace(*input_trimmed)) {
        input_trimmed++;
    }
    int input_length = strlen(input_trimmed);
    while (isspace(input_trimmed[input_length - 1])) {
        input_trimmed[input_length - 1] = '\0';
        input_length--;
    }

    // Replace non-alphanumeric characters with underscores
    char* input_sanitized = malloc(input_length + 1);
    int sanitized_length = 0;
    for (int i = 0; i < input_length; i++) {
        if (isalnum(input_trimmed[i])) {
            input_sanitized[sanitized_length++] = input_trimmed[i];
        } else {
            input_sanitized[sanitized_length++] = '_';
        }
    }
    input_sanitized[sanitized_length] = '\0';

    // Copy sanitized input to original input
    strcpy(input, input_sanitized);
    free(input_sanitized);
}

// Function to get user input
char* get_input(char* prompt) {
    char* input = malloc(MAX_INPUT_LENGTH);
    printf("%s", prompt);
    fgets(input, MAX_INPUT_LENGTH, stdin);
    return input;
}

int main() {
    char* name = get_input("Enter your name: ");
    sanitize_input(name);
    printf("Hello, %s!\n", name);

    char* message = get_input("Enter a message: ");
    sanitize_input(message);
    printf("You said: %s\n", message);

    free(name);
    free(message);
    return 0;
}