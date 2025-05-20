//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 1000

void sanitize_input(char *input) {
    int i = 0;
    char sanitized_input[MAX_INPUT_SIZE] = {0};
    bool is_alpha_numeric = true;

    // Remove leading/trailing spaces
    while (isspace(input[i])) {
        i++;
    }
    while (isspace(input[strlen(input) - 1])) {
        input[strlen(input) - 1] = '\0';
    }

    // Check if input is alphanumeric
    for (i = 0; input[i]!= '\0'; i++) {
        if (!isalnum(input[i])) {
            is_alpha_numeric = false;
            break;
        }
    }

    // Sanitize input
    if (is_alpha_numeric) {
        strcpy(sanitized_input, input);
    } else {
        strcpy(sanitized_input, "");
    }

    // Copy sanitized input back to original input
    strcpy(input, sanitized_input);
}

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Enter input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    sanitize_input(input);

    printf("Sanitized input: %s\n", input);

    return 0;
}