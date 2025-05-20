//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 256

char* sanitize_input(char* raw_input);

int main() {
    char raw_input[MAX_INPUT_SIZE];
    printf("Enter your input: ");
    fgets(raw_input, MAX_INPUT_SIZE, stdin);

    char* sanitized_input = sanitize_input(raw_input);
    printf("Sanitized input: %s", sanitized_input);

    free(sanitized_input);
    return 0;
}

char* sanitize_input(char* raw_input) {
    // remove any whitespaces at the beginning
    while (isspace(*raw_input)) {
        raw_input++;
    }

    // remove any whitespaces at the end
    char* end = raw_input + strlen(raw_input) - 1;
    while (end > raw_input && isspace(*end)) {
        end--;
    }
    *(end + 1) = '\0';  // terminate the sanitized string

    // initialize a buffer for sanitizing the input
    char* sanitized_input = (char*) malloc(MAX_INPUT_SIZE * sizeof(char));
    if (sanitized_input == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    // sanitize the input by copying only alphanumeric characters and removing any special characters
    char* raw_ptr = raw_input;
    char* sanitized_ptr = sanitized_input;
    while (*raw_ptr != '\0') {
        if (isalnum(*raw_ptr)) {
            *sanitized_ptr = *raw_ptr;
            sanitized_ptr++;
        }
        raw_ptr++;
    }
    *sanitized_ptr = '\0';  // terminate the sanitized string
    return sanitized_input;
}