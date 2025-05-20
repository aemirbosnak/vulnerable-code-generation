//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 256

char* sanitize_input(char* input);

int main() {
    char buffer[BUFFER_SIZE];
    char* sanitized_input;

    printf("Enter a string to be sanitized: ");
    fgets(buffer, BUFFER_SIZE, stdin);  // Get user input

    sanitized_input = sanitize_input(buffer);  // Sanitize the input

    printf("Sanitized input: %s\n", sanitized_input);

    free(sanitized_input);  // Free allocated memory
    return 0;
}

char* sanitize_input(char* input) {
    int length = strlen(input);
    char* sanitized = (char*) malloc(length * sizeof(char));  // Allocate memory for the sanitized string
    int index = 0;

    // Loop through each character in the input string
    for (int i = 0; i < length; i++) {
        // If a character is a letter, add it to the sanitized string in lowercase form
        if (isalpha(input[i])) {
            sanitized[index] = tolower(input[i]);
            index++;
        }
        // If a character is a digit, add it to the sanitized string
        else if (isdigit(input[i])) {
            sanitized[index] = input[i];
            index++;
        }
        // If a character is a space, replace it with an underscore in the sanitized string
        else if (isspace(input[i])) {
            sanitized[index] = '_';
            index++;
        }
        // Ignore all other characters
    }
    sanitized[index] = '\0';  // Add null terminator to end of string
    return sanitized;
}