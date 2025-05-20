//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100
#define MAX_ATTEMPTS 3

// Function to sanitize string input
void sanitizeString(char *input, char *output) {
    int i, j = 0;
    // Remove leading and trailing whitespaces
    while (isspace((unsigned char)input[j])) j++;
    for (i = j; input[i] != '\0'; i++) {
        // Check for alphanumeric characters and spaces
        if (isalnum((unsigned char)input[i]) || isspace((unsigned char)input[i])) {
            output[strlen(output)] = input[i];
        }
    }
    output[strlen(output)] = '\0'; // Null-terminate the sanitized string
}

// Function to sanitize integer input
int sanitizeIntInput() {
    char buffer[MAX_STRING_LENGTH];
    int isValid = 0, attempts = 0;
    int value = 0;

    while (!isValid && attempts < MAX_ATTEMPTS) {
        printf("Enter an integer: ");
        fgets(buffer, sizeof(buffer), stdin);
        value = atoi(buffer);
        if (value != 0 || (buffer[0] == '0' && buffer[1] == '\n')) {
            // Valid integer input
            isValid = 1;
        } else {
            attempts++;
            printf("Invalid integer. Please try again. (%d attempts left)\n", MAX_ATTEMPTS - attempts);
        }
    }
    if (!isValid) {
        printf("Maximum attempts reached. Setting value to 0.\n");
        return 0; // Default value
    }
    return value;
}

// Function to sanitize float input
float sanitizeFloatInput() {
    char buffer[MAX_STRING_LENGTH];
    int isValid = 0, attempts = 0;
    float value = 0.0;

    while (!isValid && attempts < MAX_ATTEMPTS) {
        printf("Enter a floating point number: ");
        fgets(buffer, sizeof(buffer), stdin);
        char *endptr;
        value = strtof(buffer, &endptr);
        if (endptr != buffer && *endptr == '\n') {
            // Valid float input
            isValid = 1;
        } else {
            attempts++;
            printf("Invalid float. Please try again. (%d attempts left)\n", MAX_ATTEMPTS - attempts);
        }
    }
    if (!isValid) {
        printf("Maximum attempts reached. Setting value to 0.0.\n");
        return 0.0f; // Default value
    }
    return value;
}

int main() {
    char inputString[MAX_STRING_LENGTH];
    char sanitizedString[MAX_STRING_LENGTH] = "";

    printf("Input Sanitizer Program\n");
    
    // String input
    printf("Enter a string (alphanumeric and spaces only): ");
    fgets(inputString, sizeof(inputString), stdin);
    sanitizeString(inputString, sanitizedString);
    printf("Sanitized String: '%s'\n", sanitizedString);

    // Integer input
    int sanitizedInt = sanitizeIntInput();
    printf("Sanitized Integer: %d\n", sanitizedInt);

    // Float input
    float sanitizedFloat = sanitizeFloatInput();
    printf("Sanitized Float: %.2f\n", sanitizedFloat);
    
    return 0;
}