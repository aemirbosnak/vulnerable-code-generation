//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024

int main() {
    // Declare and initialize variables
    char input[MAX_INPUT_LENGTH];
    int number;
    float decimal;
    char *ptr;

    // Get user input
    printf("Enter a string: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Sanitize the string
    // Remove leading and trailing whitespace
    ptr = input;
    while (*ptr != '\0') {
        if (*ptr == ' ' || *ptr == '\t') {
            ptr++;
        } else {
            break;
        }
    }
    strcpy(input, ptr);

    // Remove trailing newline
    ptr = input + strlen(input) - 1;
    while (*ptr == '\n' || *ptr == '\r') {
        *ptr = '\0';
        ptr--;
    }

    // Convert the string to a number
    number = strtol(input, &ptr, 10);

    // If the string is not a valid number, print an error message
    if (*ptr != '\0') {
        printf("Invalid number: %s\n", input);
        return EXIT_FAILURE;
    }

    // Convert the string to a decimal
    decimal = strtof(input, &ptr);

    // If the string is not a valid decimal, print an error message
    if (*ptr != '\0') {
        printf("Invalid decimal: %s\n", input);
        return EXIT_FAILURE;
    }

    // Print the sanitized input
    printf("Sanitized string: %s\n", input);
    printf("Number: %d\n", number);
    printf("Decimal: %f\n", decimal);

    return EXIT_SUCCESS;
}