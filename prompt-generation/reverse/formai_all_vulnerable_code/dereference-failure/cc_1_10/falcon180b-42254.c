//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

typedef struct {
    char *input;
    size_t length;
} Input;

Input read_input() {
    Input input = {0};
    char buffer[MAX_INPUT_SIZE];

    printf("Enter your input: ");
    fgets(buffer, MAX_INPUT_SIZE, stdin);

    input.input = strdup(buffer);
    input.length = strlen(input.input);

    return input;
}

void sanitize_input(Input *input) {
    char *sanitized_input = malloc(input->length + 1);
    memset(sanitized_input, 0, input->length + 1);

    for (size_t i = 0; i < input->length; i++) {
        if (isalnum(input->input[i])) {
            sanitized_input[i] = input->input[i];
        }
    }

    free(input->input);
    input->input = sanitized_input;
}

void print_sanitized_input(Input input) {
    printf("Sanitized input: %s\n", input.input);
}

int main() {
    Input input = read_input();
    sanitize_input(&input);
    print_sanitized_input(input);

    free(input.input);
    return 0;
}