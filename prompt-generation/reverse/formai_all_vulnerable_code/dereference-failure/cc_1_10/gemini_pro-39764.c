//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: ephemeral
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t len;
} Input;

bool is_valid_input(const Input *input) {
    if (input->len == 0) {
        return false;
    }
    for (size_t i = 0; i < input->len; i++) {
        if (!isalnum(input->data[i])) {
            return false;
        }
    }
    return true;
}

char *sanitize_input(const Input *input) {
    char *sanitized_input = malloc(input->len + 1);
    if (sanitized_input == NULL) {
        return NULL;
    }
    for (size_t i = 0; i < input->len; i++) {
        if (isalnum(input->data[i])) {
            sanitized_input[i] = input->data[i];
        } else {
            sanitized_input[i] = '_';
        }
    }
    sanitized_input[input->len] = '\0';
    return sanitized_input;
}

int main(void) {
    Input input;
    char *sanitized_input;

    printf("Enter some input: ");
    if (scanf(" %s ", input.data) != 1) {
        fprintf(stderr, "Error: Invalid input.\n");
        return EXIT_FAILURE;
    }
    input.len = strlen(input.data);

    if (!is_valid_input(&input)) {
        fprintf(stderr, "Error: Invalid input. Only alphanumeric characters are allowed.\n");
        return EXIT_FAILURE;
    }

    sanitized_input = sanitize_input(&input);
    if (sanitized_input == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for sanitized input.\n");
        return EXIT_FAILURE;
    }

    printf("Sanitized input: %s\n", sanitized_input);
    free(sanitized_input);

    return EXIT_SUCCESS;
}