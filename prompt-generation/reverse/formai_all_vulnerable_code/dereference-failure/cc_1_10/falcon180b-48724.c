//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_ALLOWED_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}\\|;:'\",.<>/?`~"

int is_allowed_char(char c) {
    char *allowed_chars = MAX_ALLOWED_CHARS;
    while (*allowed_chars!= '\0') {
        if (c == *allowed_chars) {
            return 1;
        }
        allowed_chars++;
    }
    return 0;
}

char* sanitize_input(char* input) {
    char* sanitized_input = malloc(MAX_INPUT_LENGTH * sizeof(char));
    int sanitized_input_length = 0;

    if (input == NULL || strlen(input) == 0) {
        strcpy(sanitized_input, "");
        return sanitized_input;
    }

    while (sanitized_input_length < MAX_INPUT_LENGTH && input[sanitized_input_length]!= '\0') {
        if (is_allowed_char(input[sanitized_input_length])) {
            sanitized_input[sanitized_input_length] = input[sanitized_input_length];
            sanitized_input_length++;
        }
    }

    sanitized_input[sanitized_input_length] = '\0';

    return sanitized_input;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char* sanitized_input;

    printf("Enter some text: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    sanitized_input = sanitize_input(input);

    printf("Sanitized input: %s\n", sanitized_input);

    free(sanitized_input);

    return 0;
}