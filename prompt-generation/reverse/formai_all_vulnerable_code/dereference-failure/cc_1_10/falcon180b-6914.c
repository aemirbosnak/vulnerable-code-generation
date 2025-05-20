//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 100

void sanitize_input(char *input) {
    int i = 0, j = 0;
    char sanitized_input[MAX_INPUT_LENGTH];
    bool is_alpha_numeric = true;

    // Remove leading/trailing whitespace
    while (isspace(input[i])) {
        i++;
    }
    while (isspace(input[j])) {
        j--;
    }
    input[j+1] = '\0';

    // Copy sanitized input to new string
    for (int k = 0; k < strlen(input); k++) {
        if (isalpha(input[k]) || isdigit(input[k])) {
            sanitized_input[k] = input[k];
        } else {
            sanitized_input[k] = '_';
            is_alpha_numeric = false;
        }
    }

    // Add null terminator to sanitized input
    sanitized_input[strlen(sanitized_input)] = '\0';

    // Print sanitized input
    printf("Sanitized input: %s\n", sanitized_input);

    // Check if input is alphanumeric
    if (is_alpha_numeric) {
        printf("Input is alphanumeric.\n");
    } else {
        printf("Input is not alphanumeric.\n");
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];

    // Get user input
    printf("Enter input to sanitize: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Sanitize input
    sanitize_input(input);

    return 0;
}