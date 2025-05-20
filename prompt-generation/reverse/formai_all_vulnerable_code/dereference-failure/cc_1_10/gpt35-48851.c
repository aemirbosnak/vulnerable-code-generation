//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

void sanitize_input(char *input) {
    int i, j;
    char sanitized_input[MAX_INPUT_LENGTH];

    // Remove trailing whitespaces
    i = 0;
    while (input[i] != '\0') {
        i++;
    }
    while (isspace(input[i - 1])) {
        i--;
    }
    input[i] = '\0';

    // Remove leading whitespaces
    i = 0;
    while (isspace(input[i])) {
        i++;
    }
    for (j = 0; input[i] != '\0'; i++) {
        if (!isspace(input[i])) {
            sanitized_input[j] = input[i];
            j++;
        } else if (!isspace(input[i - 1])) {
            sanitized_input[j] = ' ';
            j++;
        }
    }
    sanitized_input[j] = '\0';

    // Copy sanitized input to original input
    for (i = 0; i < j; i++) {
        input[i] = sanitized_input[i];
    }
    input[i] = '\0';
}

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Sanitize input
    sanitize_input(input);

    printf("Your sanitized input is: %s\n", input);

    return 0;
}