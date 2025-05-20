//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 1000
#define MAX_OUTPUT_SIZE 10000

// Function to check if a character is a letter
bool is_letter(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// Function to check if a character is a number
bool is_number(char c) {
    return (c >= '0' && c <= '9');
}

// Function to sanitize user input
void sanitize_input(char* input) {
    // Remove leading and trailing whitespace
    while (isspace(*input)) {
        input++;
    }
    while (isspace(*(input + strlen(input) - 1))) {
        *(input + strlen(input) - 1) = '\0';
    }

    // Convert all characters to lowercase
    for (int i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    // Remove non-letter and non-number characters
    char* output = (char*)malloc(MAX_OUTPUT_SIZE * sizeof(char));
    int output_index = 0;
    bool in_word = false;
    for (int i = 0; i < strlen(input); i++) {
        if (is_letter(input[i]) || is_number(input[i])) {
            if (!in_word) {
                in_word = true;
            }
            strncat(output, &input[i], 1);
        } else if (in_word) {
            in_word = false;
        }
    }
    if (in_word) {
        strncat(output, &input[strlen(input) - 1], 1);
    }
    strcpy(input, output);
    free(output);
}

int main() {
    char input[MAX_INPUT_SIZE];

    // Get user input
    printf("Enter some text:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Sanitize user input
    sanitize_input(input);

    // Print sanitized input
    printf("Sanitized input:\n%s\n", input);

    return 0;
}