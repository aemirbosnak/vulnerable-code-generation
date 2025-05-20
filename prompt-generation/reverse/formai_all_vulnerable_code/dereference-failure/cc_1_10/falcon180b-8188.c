//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1024

/**
 * Sanitizes user input by removing any non-alphanumeric characters and trimming leading/trailing whitespace.
 *
 * @param input The input string to sanitize.
 * @param output The sanitized output string.
 * @param output_size The maximum size of the output string.
 * @return The length of the sanitized output string.
 */
int sanitize_input(const char* input, char* output, int output_size) {
    int input_length = strlen(input);
    int output_length = 0;

    // Remove leading/trailing whitespace
    while (isspace(input[0])) {
        input++;
        input_length--;
    }
    while (isspace(input[input_length - 1])) {
        input_length--;
    }

    // Sanitize input
    for (int i = 0; i < input_length; i++) {
        if (isalnum(input[i])) {
            output[output_length++] = tolower(input[i]);
        }
    }
    output[output_length] = '\0';

    return output_length;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char sanitized_input[MAX_INPUT_LENGTH];

    printf("Enter some text to sanitize:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    int sanitized_input_length = sanitize_input(input, sanitized_input, MAX_INPUT_LENGTH);

    printf("Sanitized input: %s\n", sanitized_input);

    return 0;
}