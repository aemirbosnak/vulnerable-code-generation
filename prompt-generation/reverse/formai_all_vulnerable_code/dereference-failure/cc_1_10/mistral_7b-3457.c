//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 100

char *sanitize_input(char *input) {
    char *sanitized = malloc(MAX_INPUT_SIZE * sizeof(char));
    int i = 0, j = 0;

    if (input == NULL) {
        fprintf(stderr, "Error: Input is NULL\n");
        exit(1);
    }

    // Check for malicious input
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            sanitized[j++] = input[i];
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            sanitized[j++] = input[i];
        } else if (input[i] >= '0' && input[i] <= '9') {
            sanitized[j++] = input[i];
        } else if (input[i] == '_' || input[i] == '.' || input[i] == '-') {
            sanitized[j++] = input[i];
        } else {
            fprintf(stderr, "Error: Malicious character '%c' detected in input\n", input[i]);
            free(sanitized);
            exit(1);
        }
    }

    sanitized[j] = '\0';
    return sanitized;
}

int main(int argc, char *argv[]) {
    char *input, *sanitized;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input string>\n", argv[0]);
        exit(1);
    }

    input = argv[1];
    sanitized = sanitize_input(input);

    printf("Sanitized input: %s\n", sanitized);
    free(sanitized);

    return 0;
}