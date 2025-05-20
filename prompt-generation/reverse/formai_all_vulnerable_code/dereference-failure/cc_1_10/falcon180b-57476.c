//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1024

typedef struct {
    char *input;
    int length;
} Input;

Input *create_input() {
    Input *input = malloc(sizeof(Input));
    input->input = malloc(MAX_INPUT_LENGTH);
    input->length = 0;
    return input;
}

void add_char(Input *input, char c) {
    if (input->length >= MAX_INPUT_LENGTH - 1) {
        printf("Error: Input too long.\n");
        exit(1);
    }
    input->input[input->length] = c;
    input->length++;
}

void add_string(Input *input, char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        add_char(input, str[i]);
    }
}

char *sanitize_input(Input *input) {
    int i;
    char *sanitized_input = malloc(input->length + 1);
    for (i = 0; i < input->length; i++) {
        if (isalnum(input->input[i])) {
            sanitized_input[i] = input->input[i];
        } else {
            sanitized_input[i] = '_';
        }
    }
    sanitized_input[input->length] = '\0';
    return sanitized_input;
}

int main() {
    Input *input = create_input();
    char *sanitized_input;
    char buffer[MAX_INPUT_LENGTH];
    int i;

    printf("Enter some input to sanitize:\n");
    fgets(buffer, MAX_INPUT_LENGTH, stdin);
    for (i = 0; i < strlen(buffer); i++) {
        add_char(input, buffer[i]);
    }

    sanitized_input = sanitize_input(input);
    printf("Sanitized input: %s\n", sanitized_input);

    free(input->input);
    free(input);
    free(sanitized_input);

    return 0;
}