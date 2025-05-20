//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000

/* Function to sanitize user input */
char* sanitize_input(char* input) {
    char* sanitized_input = malloc(MAX_INPUT_LENGTH * sizeof(char));
    int length = 0;

    /* Remove leading and trailing whitespace */
    while (isspace(*input)) {
        input++;
    }
    while (isspace(*(input + strlen(input) - 1))) {
        *(input + strlen(input) - 1) = '\0';
    }

    /* Convert all characters to lowercase */
    for (int i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            sanitized_input[length++] = tolower(input[i]);
        }
    }
    sanitized_input[length] = '\0';

    /* Remove any non-alphanumeric characters */
    char* temp = sanitized_input;
    while (*temp) {
        if (!isalnum(*temp)) {
            *temp = '\0';
        }
        temp++;
    }

    return sanitized_input;
}

int main() {
    char input[MAX_INPUT_LENGTH];

    /* Prompt user for input */
    printf("Enter some text: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    /* Sanitize user input */
    char* sanitized_input = sanitize_input(input);

    /* Print sanitized input */
    printf("Sanitized input: %s\n", sanitized_input);

    /* Free memory */
    free(sanitized_input);

    return 0;
}