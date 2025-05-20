//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1000

char *sanitize_input(char *input) {
    int i, j;
    char *sanitized_input = malloc(MAX_INPUT_SIZE * sizeof(char));
    i = j = 0;

    // Remove leading and trailing white spaces
    while (isspace(input[i])) {
        i++;
    }
    while (isspace(input[j])) {
        j--;
    }
    j++;

    // Copy the input string to the sanitized input string
    while (i <= j) {
        if (isalnum(input[i])) {
            sanitized_input[i - j] = tolower(input[i]);
            i++;
        } else {
            i++;
        }
    }
    sanitized_input[i - j] = '\0';

    return sanitized_input;
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter a string: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Sanitize the input
    char *sanitized_input = sanitize_input(input);

    // Print the sanitized input
    printf("Sanitized input: %s\n", sanitized_input);

    // Free the memory allocated for the sanitized input
    free(sanitized_input);

    return 0;
}