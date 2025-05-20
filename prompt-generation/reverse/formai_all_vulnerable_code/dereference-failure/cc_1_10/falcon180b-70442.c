//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 1024
#define MAX_SANITIZED_SIZE (MAX_INPUT_SIZE * 2)

char *sanitize_input(const char *input) {
    char *sanitized_input = malloc(MAX_SANITIZED_SIZE);
    if (sanitized_input == NULL) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    size_t input_length = strlen(input);
    size_t sanitized_length = 0;

    for (size_t i = 0; i < input_length; i++) {
        char c = toupper(input[i]);

        if (isalpha(c) || isdigit(c) || c == '.' || c == '-') {
            sanitized_input[sanitized_length++] = c;
        } else {
            sanitized_input[sanitized_length++] = '_';
        }
    }

    sanitized_input[sanitized_length] = '\0';

    return sanitized_input;
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter some input: ");
    if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    char *sanitized_input = sanitize_input(input);
    printf("Sanitized input: %s\n", sanitized_input);

    free(sanitized_input);
    return 0;
}