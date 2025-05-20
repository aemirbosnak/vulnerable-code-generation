//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1000

// Function to check if a string contains only alphanumeric characters
int isValidString(char *str) {
    int i = 0;
    while (str[i]!= '\0') {
        if (!isalnum(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to sanitize user input
char *sanitizeInput(char *input) {
    char *sanitizedInput = malloc(MAX_BUFFER_SIZE);
    int i = 0, j = 0;
    while (input[i]!= '\0') {
        if (isalnum(input[i])) {
            sanitizedInput[j] = input[i];
            j++;
        }
        i++;
    }
    sanitizedInput[j] = '\0';
    return sanitizedInput;
}

int main() {
    char input[MAX_BUFFER_SIZE];
    char *sanitizedInput;

    printf("Enter a string:\n");
    fgets(input, MAX_BUFFER_SIZE, stdin);

    // Sanitize user input
    sanitizedInput = sanitizeInput(input);

    // Check if sanitized input is empty
    if (strlen(sanitizedInput) == 0) {
        printf("Input is empty.\n");
    } else {
        printf("Sanitized input: %s\n", sanitizedInput);
    }

    free(sanitizedInput);
    return 0;
}