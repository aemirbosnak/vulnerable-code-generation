//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 256

int main(void) {
    char *input = malloc(MAX_INPUT_LEN);
    if (input == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for input buffer.\n");
        return EXIT_FAILURE;
    }

    printf("Enter a string of up to %d characters:\n", MAX_INPUT_LEN - 1);
    if (fgets(input, MAX_INPUT_LEN, stdin) == NULL) {
        fprintf(stderr, "Error: Unable to read input from standard input.\n");
        return EXIT_FAILURE;
    }

    // Remove the newline character from the end of the input string, if present.
    char *newline_char = strchr(input, '\n');
    if (newline_char != NULL) {
        *newline_char = '\0';
    }

    // Check if the input string contains any invalid characters.
    for (char *p = input; *p != '\0'; p++) {
        if (!isalnum(*p) && *p != ' ') {
            fprintf(stderr, "Error: Input string contains invalid characters.\n");
            return EXIT_FAILURE;
        }
    }

    // Sanitize the input string by removing all leading and trailing whitespace.
    while (*input == ' ') {
        input++;
    }
    char *end = input + strlen(input);
    while (end > input && *end == ' ') {
        end--;
    }
    *end = '\0';

    // Print the sanitized input string.
    printf("Sanitized input string: \"%s\"\n", input);

    free(input);

    return EXIT_SUCCESS;
}