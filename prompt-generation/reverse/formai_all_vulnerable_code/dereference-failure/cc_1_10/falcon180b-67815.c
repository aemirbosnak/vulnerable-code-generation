//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

// Function to sanitize user input by removing invalid characters
void sanitize_input(char* input) {
    int i, j;
    char valid_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    char* sanitized_input = malloc(MAX_INPUT_LENGTH * sizeof(char));
    j = 0;

    // Loop through each character in the input string
    for (i = 0; i < strlen(input); i++) {

        // Check if the character is a valid alphanumeric character
        if (strchr(valid_chars, tolower(input[i]))) {
            // Add the character to the sanitized input string
            sanitized_input[j] = tolower(input[i]);
            j++;
        }
    }

    // Add a null terminator to the sanitized input string
    sanitized_input[j] = '\0';

    // Print the sanitized input string
    printf("Sanitized input: %s\n", sanitized_input);

    // Free the memory allocated for the sanitized input string
    free(sanitized_input);
}

int main() {
    char input[MAX_INPUT_LENGTH];

    // Prompt the user for input
    printf("Enter some input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove the newline character from the input string
    input[strcspn(input, "\n")] = '\0';

    // Sanitize the input
    sanitize_input(input);

    return 0;
}