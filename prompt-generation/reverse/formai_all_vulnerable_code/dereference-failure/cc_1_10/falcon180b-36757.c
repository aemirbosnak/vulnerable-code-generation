//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1000

// Function to sanitize user input
void sanitize_input(char *input) {
    int i, j;

    // Remove leading and trailing white spaces
    while (isspace(input[0])) {
        for (i = 0; i < strlen(input); i++) {
            input[i] = input[i+1];
        }
        input[strlen(input)-1] = '\0';
    }
    while (isspace(input[strlen(input)-1])) {
        input[strlen(input)-1] = '\0';
    }

    // Remove all non-alphanumeric characters
    for (i = 0; i < strlen(input); i++) {
        if (!isalnum(input[i])) {
            for (j = i; j < strlen(input)-1; j++) {
                input[j] = input[j+1];
            }
            input[strlen(input)-1] = '\0';
            i--;
        }
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    int input_length;

    printf("Enter a string: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input_length = strlen(input);

    // Sanitize user input
    sanitize_input(input);

    // Display sanitized input
    printf("Sanitized input: %s\n", input);

    return 0;
}