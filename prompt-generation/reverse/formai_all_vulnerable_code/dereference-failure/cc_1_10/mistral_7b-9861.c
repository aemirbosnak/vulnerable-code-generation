//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 100

// Custom user input sanitizer function
void sanitize_input(char *input, int *length) {
    int i = 0, j = 0;
    bool is_valid = true;

    // Loop through input string
    while (input[i] != '\0') {
        // Check for valid characters
        if ((input[i] >= 'A' && input[i] <= 'Z') ||
            (input[i] >= 'a' && input[i] <= 'z') ||
            (input[i] >= '0' && input[i] <= '9') ||
            input[i] == ' ' || input[i] == '\'' || input[i] == '&' || input[i] == '#' || input[i] == '@') {
            input[j++] = input[i];
        } else {
            is_valid = false;
            break;
        }

        i++;
    }

    // Set input length to valid characters only
    *length = j;

    // Sanitize the input by allocating new memory and copying valid characters only
    char *sanitized_input = (char *) malloc((*length) + 1);
    strncpy(sanitized_input, input, *length + 1);

    // Free old input memory
    free(input);

    // Set sanitized input as new input
    input = sanitized_input;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    int length = 0;

    printf("Enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Sanitize user input
    sanitize_input(input, &length);

    printf("Sanitized Input: %s\n", input);

    return 0;
}