//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256
#define WHITESPACE " \t\n"

void sanitizeInput(char *input, char *output) {
    // Remove leading and trailing whitespace
    while (isspace((unsigned char)*input)) input++;
    char *end = input + strlen(input) - 1;
    while (end > input && isspace((unsigned char)*end)) end--;
    end[1] = '\0';  // Null terminate string

    // Sanitize: remove any characters that are not alphanumeric or whitespace
    char *cleaned = output;
    while (*input) {
        if (isalnum((unsigned char)*input) || strchr(WHITESPACE, *input)) {
            *cleaned++ = *input;
        }
        input++;
    }
    *cleaned = '\0';  // Null terminate the sanitized output
}

bool isValidInput(const char *input) {
    // Check if the input is at least 3 characters long
    return strlen(input) >= 3;
}

void getUserInput() {
    char input[MAX_INPUT_LENGTH];
    char sanitized[MAX_INPUT_LENGTH];

    printf("Please enter your input (min 3 characters): ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Input error. Exiting...\n");
        return;
    }

    sanitizeInput(input, sanitized);

    // Validate the sanitized input
    if (!isValidInput(sanitized)) {
        printf("Invalid input: must be at least 3 valid characters.\n");
    } else {
        printf("Sanitized input: '%s'\n", sanitized);
    }
}

void repeatInputPrompt() {
    char choice;
    do {
        getUserInput();
        printf("Would you like to enter another input? (y/n): ");
        choice = getchar();
        while (getchar() != '\n'); // Clear input buffer
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the input sanitizer program. Goodbye!\n");
}

int main() {
    repeatInputPrompt();
    return 0;
}