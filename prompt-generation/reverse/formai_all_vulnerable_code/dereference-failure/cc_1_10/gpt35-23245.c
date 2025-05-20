//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

char* sanitize_input(char* input) {
    // Allocate memory for the sanitized string
    char* sanitized = (char*) malloc(sizeof(char) * MAX_LENGTH);
    int index = 0;
    int length = strlen(input);

    // Iterate over each character in the input
    for (int i = 0; i < length; i++) {
        char c = input[i];

        // If the character is a letter, convert it to lowercase and add it to the sanitized string
        if (isalpha(c)) {
            sanitized[index] = tolower(c);
            index++;
        }
        // If the character is a digit, add it to the sanitized string
        else if (isdigit(c)) {
            sanitized[index] = c;
            index++;
        }
        // If the character is a space, add it to the sanitized string
        else if (isspace(c)) {
            sanitized[index] = ' ';
            index++;
        }
    }

    // Terminate the sanitized string with a null character
    sanitized[index] = '\0';

    return sanitized;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter some text: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove the newline character from the end of the input
    input[strcspn(input, "\n")] = 0;

    char* sanitized = sanitize_input(input);
    printf("Sanitized input: %s\n", sanitized);

    free(sanitized);
    return 0;
}