//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1000

void sanitize_input(char* input) {
    int i = 0;
    int j = 0;

    // Remove leading/trailing whitespace
    while (isspace(input[i])) {
        i++;
    }
    while (isspace(input[j])) {
        j--;
    }
    j++;

    // Copy sanitized input to new string
    char sanitized_input[MAX_INPUT_LENGTH];
    strncpy(sanitized_input, &input[i], j - i);
    sanitized_input[j - i] = '\0';

    // Replace invalid characters with underscores
    for (i = 0; i < strlen(sanitized_input); i++) {
        if (!isalnum(sanitized_input[i])) {
            sanitized_input[i] = '_';
        }
    }

    // Copy sanitized input back to original string
    strcpy(input, sanitized_input);
}

int main() {
    char input[MAX_INPUT_LENGTH];

    // Prompt user for input
    printf("Enter some text: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Sanitize input
    sanitize_input(input);

    // Print sanitized input
    printf("Sanitized input: %s\n", input);

    return 0;
}