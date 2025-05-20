//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_INPUT_SIZE 1000

typedef struct {
    char *input;
    size_t length;
} Input;

Input create_input(void) {
    Input input = {
       .input = malloc(MAX_INPUT_SIZE * sizeof(char)),
       .length = 0
    };

    if (input.input == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    return input;
}

void destroy_input(Input *input) {
    free(input->input);
}

void sanitize_input(Input *input) {
    char *sanitized_input = malloc(MAX_INPUT_SIZE * sizeof(char));
    size_t sanitized_length = 0;

    for (size_t i = 0; i < input->length; i++) {
        char c = input->input[i];

        if (isalnum(c)) {
            sanitized_input[sanitized_length++] = c;
        }
    }

    sanitized_input[sanitized_length] = '\0';

    strncpy(input->input, sanitized_input, MAX_INPUT_SIZE);
    input->length = strlen(input->input);

    free(sanitized_input);
}

int main(void) {
    Input input = create_input();

    printf("Enter some text: ");
    fgets(input.input, MAX_INPUT_SIZE, stdin);

    sanitize_input(&input);

    printf("Sanitized input: %s\n", input.input);

    destroy_input(&input);

    return 0;
}