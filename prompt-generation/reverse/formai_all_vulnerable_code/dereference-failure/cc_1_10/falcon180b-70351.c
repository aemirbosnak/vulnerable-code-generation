//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STR_LEN 1024
#define MAX_INPUT_LEN 256

// Function to sanitize user input
void sanitize_input(char* input) {
    int i, j;
    char sanitized_input[MAX_STR_LEN];

    // Remove leading and trailing spaces
    while (isspace(*input)) {
        input++;
    }
    j = strlen(input) - 1;
    while (isspace(input[j])) {
        input[j] = '\0';
        j--;
    }

    // Remove all non-alphanumeric characters
    i = 0;
    while (isspace(input[i]) == 0) {
        if (!isalnum(input[i])) {
            input[i] = '\0';
        }
        i++;
    }

    // Remove any remaining spaces
    j = 0;
    while (isspace(input[j]) == 0) {
        sanitized_input[j] = input[j];
        j++;
    }
    sanitized_input[j] = '\0';

    // Copy sanitized input back to original buffer
    strcpy(input, sanitized_input);
}

int main() {
    char input[MAX_INPUT_LEN];
    printf("Enter your input: ");
    fgets(input, MAX_INPUT_LEN, stdin);

    // Sanitize user input
    sanitize_input(input);

    // Print sanitized input
    printf("Sanitized input: %s\n", input);

    return 0;
}