//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

/**
 * Function to sanitize user input
 * 
 * @param input The input string to sanitize
 * @return The sanitized string
 */
char *sanitize_input(char *input) {
    char *output = malloc(MAX_LINE_LENGTH);
    int output_length = 0;

    if (input == NULL) {
        strcpy(output, "");
        return output;
    }

    // Remove leading/trailing whitespace
    while (isspace(*input)) {
        input++;
    }
    while (isspace(*(input + strlen(input) - 1))) {
        input[strlen(input) - 1] = '\0';
    }

    // Remove any non-ASCII characters
    for (int i = 0; i < strlen(input); i++) {
        if (!isascii(input[i])) {
            input[i] = '\0';
        }
    }

    // Remove any control characters
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] < 32) {
            input[i] = '\0';
        }
    }

    // Copy sanitized input to output
    for (int i = 0; i < strlen(input); i++) {
        if (input[i]!= '\0') {
            output[output_length++] = input[i];
        }
    }
    output[output_length] = '\0';

    return output;
}

int main() {
    char input[MAX_LINE_LENGTH];

    printf("Enter some text to sanitize: ");
    fgets(input, MAX_LINE_LENGTH, stdin);

    char *sanitized_input = sanitize_input(input);

    printf("Sanitized input: %s\n", sanitized_input);

    free(sanitized_input);

    return 0;
}