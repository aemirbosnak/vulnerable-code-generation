//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to remove leading whitespaces from a string
char *ltrim(char *str) {
    while (isspace(*str))
        str++;

    return str;
}

// Function to remove trailing whitespaces from a string
char *rtrim(char *str) {
    char *end = str + strlen(str) - 1;

    while (end > str && isspace(*end))
        end--;

    *(end + 1) = '\0';
    return str;
}

// Function to remove leading and trailing whitespaces from a string
char *trim(char *str) {
    return rtrim(ltrim(str));
}

// Function to sanitize a string by removing any non-ascii and non-alphanumeric characters
char *sanitize_input(char *input) {
    int i, j = 0;

    char *sanitized_input = (char *)malloc(strlen(input) + 1);

    for (i = 0; input[i] != '\0'; i++) {
        if (isascii(input[i]) && isalnum(input[i])) {
            sanitized_input[j++] = input[i];
        }
    }

    sanitized_input[j] = '\0';
    return sanitized_input;
}

int main() {
    char input[100];

    printf("Enter some input: ");
    fgets(input, 100, stdin);

    char *trimmed_input = trim(input);
    char *sanitized_input = sanitize_input(trimmed_input);

    printf("Sanitized input: %s\n", sanitized_input);

    free(sanitized_input);
    return 0;
}