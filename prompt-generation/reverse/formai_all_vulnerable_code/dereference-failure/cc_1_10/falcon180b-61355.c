//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is alphanumeric
int isAlphanumeric(char c) {
    return (isalnum(c));
}

// Function to sanitize user input
int sanitize(char *input) {
    int i, j;
    char sanitized[100];
    int len = strlen(input);

    // Remove any leading or trailing spaces
    while (isspace(input[0])) {
        strcpy(input, input + 1);
    }
    while (isspace(input[len - 1])) {
        input[len - 1] = '\0';
    }

    // Remove any non-alphanumeric characters
    for (i = 0, j = 0; i < len; i++) {
        if (isAlphanumeric(input[i])) {
            sanitized[j++] = tolower(input[i]);
        }
    }
    sanitized[j] = '\0';

    // Copy sanitized string back to input
    strcpy(input, sanitized);

    return 0;
}

int main() {
    char input[100];

    // Get user input
    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);

    // Sanitize user input
    sanitize(input);

    // Print sanitized input
    printf("Sanitized input: %s\n", input);

    return 0;
}