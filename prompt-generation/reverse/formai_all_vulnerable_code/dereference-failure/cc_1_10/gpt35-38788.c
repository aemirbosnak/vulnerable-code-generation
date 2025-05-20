//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize user input
char *sanitize_input(char *input)
{
    int len = strlen(input);

    // Remove trailing newline character
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
        len--;
    }

    // Remove leading and trailing whitespaces
    int i = 0;
    while (isspace(input[i])) {
        i++;
    }
    int j = len - 1;
    while (isspace(input[j])) {
        j--;
    }
    int k = 0;
    while (i <= j) {
        input[k] = input[i];
        i++;
        k++;
    }
    input[k] = '\0';
    len = k;

    // Check for any invalid characters
    for (i = 0; i < len; i++) {
        if (!isalnum(input[i]) && input[i] != ' ') {
            printf("Error: Invalid character '%c' found in input.\n", input[i]);
            exit(1);
        }
    }

    // Convert all characters to uppercase
    for (i = 0; i < len; i++) {
        input[i] = toupper(input[i]);
    }

    return input;
}

// Main program
int main()
{
    char input[100];
    printf("Enter your name: ");
    fgets(input, sizeof(input), stdin);
    char *sanitized_input = sanitize_input(input);
    printf("Hello, %s!\n", sanitized_input);
    return 0;
}