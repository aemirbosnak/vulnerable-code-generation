//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1000

// Function to sanitize user input
void sanitize_input(char* input) {
    int i = 0;
    int j = 0;

    // Remove leading/trailing whitespaces
    while (isspace(input[i])) {
        i++;
    }
    while (isspace(input[j + strlen(input) - 1])) {
        input[j + strlen(input) - 1] = '\0';
        j--;
    }

    // Remove any non-alphanumeric characters
    while (i < j) {
        if (!isalnum(input[i])) {
            memmove(&input[i], &input[i + 1], j - i);
            j--;
        } else {
            i++;
        }
    }

    // Add null terminator
    input[j] = '\0';
}

int main() {
    char input[MAX_INPUT_LENGTH];

    // Prompt user for input
    printf("Enter some text: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Sanitize input
    sanitize_input(input);

    // Print sanitized input
    printf("Sanitized input: %s\n", input);

    return 0;
}