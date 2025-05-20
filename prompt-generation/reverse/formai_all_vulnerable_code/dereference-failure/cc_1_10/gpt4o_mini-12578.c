//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256

// Function prototypes
int isValidNumeric(const char *input);
int isValidString(const char *input);
void sanitizeInput(const char *input, char *sanitized);

// Main function
int main() {
    char userInput[MAX_INPUT_LENGTH];
    char sanitizedInput[MAX_INPUT_LENGTH];

    printf("Enter a numeric value (e.g. 3.142, 2E5): ");
    fgets(userInput, MAX_INPUT_LENGTH, stdin);
    userInput[strcspn(userInput, "\n")] = 0; // Remove newline character

    // Validate numeric input
    if (isValidNumeric(userInput)) {
        sanitizeInput(userInput, sanitizedInput);
        printf("Sanitized Numeric Input: %s\n", sanitizedInput);
    } else {
        printf("Error: Invalid numeric input.\n");
    }

    printf("\nEnter a string (only letters and spaces allowed): ");
    fgets(userInput, MAX_INPUT_LENGTH, stdin);
    userInput[strcspn(userInput, "\n")] = 0; // Remove newline character

    // Validate string input
    if (isValidString(userInput)) {
        sanitizeInput(userInput, sanitizedInput);
        printf("Sanitized String Input: %s\n", sanitizedInput);
    } else {
        printf("Error: Invalid string input.\n");
    }

    return 0;
}

// Function to check if the input is a valid numeric value
int isValidNumeric(const char *input) {
    char *endptr;
    strtod(input, &endptr); // Convert string to double
    return *endptr == '\0'; // Check if the entire string was processed
}

// Function to check if the input string contains only valid characters
int isValidString(const char *input) {
    while (*input) {
        if (!isalpha(*input) && !isspace(*input)) {
            return 0; // Invalid character found
        }
        input++;
    }
    return 1; // All characters are valid
}

// Function to sanitize input by stripping out any leading or trailing spaces
void sanitizeInput(const char *input, char *sanitized) {
    const char *start = input;
    const char *end = input + strlen(input) - 1;

    // Trim leading spaces
    while (isspace((unsigned char)*start)) {
        start++;
    }

    // Trim trailing spaces
    while (end > start && isspace((unsigned char)*end)) {
        end--;
    }

    // Copy sanitized string
    size_t length = end - start + 1;
    strncpy(sanitized, start, length);
    sanitized[length] = '\0'; // Null-terminate the sanitized string
}