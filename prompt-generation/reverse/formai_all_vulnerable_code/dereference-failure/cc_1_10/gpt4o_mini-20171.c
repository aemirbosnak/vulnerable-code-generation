//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 256

void strTrim(char *str) {
    char *end;

    // Trim leading whitespace
    while (isspace((unsigned char) *str)) str++;

    // Trim trailing whitespace
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char) *end)) end--;

    // Null terminate after the last non-whitespace character
    *(end + 1) = '\0';
}

int isInputValid(const char *input) {
    // Reject input containing special characters
    for (const char *ptr = input; *ptr; ptr++) {
        if (!isalnum((unsigned char) *ptr) && !isspace((unsigned char) *ptr)) {
            return 0; // invalid input
        }
    }
    return 1; // valid input
}

char *sanitizeInput(const char *input) {
    // Allocate memory for sanitized input
    char *sanitized = (char *)malloc(MAX_INPUT_SIZE);
    if (!sanitized) {
        fprintf(stderr, "Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }

    // Copy to sanitized string while removing extra spaces
    const char *srcPtr = input;
    char *destPtr = sanitized;

    while (*srcPtr) {
        // Skip leading spaces
        while (*srcPtr && isspace((unsigned char) *srcPtr)) srcPtr++;

        // Copy until the next space or end
        while (*srcPtr && !isspace((unsigned char) *srcPtr)) {
            *destPtr++ = *srcPtr++;
        }

        // Add a single space if there's more text
        if (*srcPtr) {
            *destPtr++ = ' ';
        }
    }
    *destPtr = '\0'; // Null terminate the sanitized string

    return sanitized;
}

void captureAndSanitizeInput() {
    char input[MAX_INPUT_SIZE];

    printf("Please enter your input (max %d characters): ", MAX_INPUT_SIZE - 1);
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        exit(EXIT_FAILURE);
    }

    strTrim(input); // Trim the input
    printf("Raw input: \"%s\"\n", input);

    if (!isInputValid(input)) {
        fprintf(stderr, "Input contains invalid characters!\n");
        return;
    }

    char *sanitized = sanitizeInput(input);
    printf("Sanitized input: \"%s\"\n", sanitized);

    // Free allocated memory for sanitized input
    free(sanitized);
}

int main() {
    printf("=== Input Sanitizer ===\n");
    int repeat = 1;

    while (repeat) {
        captureAndSanitizeInput();

        char choice;
        printf("Do you want to enter another input? (y/n): ");
        choice = getchar();
        while (getchar() != '\n'); // Clear the buffer

        if (choice != 'y' && choice != 'Y') {
            repeat = 0;
        }
    }

    printf("Thank you for using the Input Sanitizer!\n");
    return EXIT_SUCCESS;
}