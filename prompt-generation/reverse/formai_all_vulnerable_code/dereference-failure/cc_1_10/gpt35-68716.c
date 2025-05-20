//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_BUFFER 50

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int is_valid_input(char *input, int max_length) {
    /*
      Checks if a user input is valid:

      1. The input must not be empty
      2. The input must not exceed the maximum length
      3. The input must only contain printable ASCII characters
    */

    if (strlen(input) == 0) { // The input is empty
        return 0;
    }

    if (strlen(input) > max_length) { // The input is too long
        return 0;
    }

    for (int i = 0; i < strlen(input); i++) { // The input contains invalid characters
        if (!isprint(input[i])) {
            return 0;
        }
    }

    return 1; // The input is valid
}

void sanitize_input(char *input) {
    /*
      Sanitizes a user input by removing leading/trailing whitespace characters
      and converting all characters to lowercase.
    */

    int i, j;

    // Remove leading whitespace characters
    i = 0;
    while (isspace(input[i])) {
        i++;
    }

    // Remove trailing whitespace characters
    j = strlen(input) - 1;
    while (isspace(input[j])) {
        j--;
    }
    input[j + 1] = '\0';

    // Convert characters to lowercase
    for (int k = 0; k < strlen(input); k++) {
        input[k] = tolower(input[k]);
    }
}

int get_input(char *input, int max_length, char *prompt) {
    /*
      Gets user input and sanitizes it.

      Returns:

      - 1 if the input is valid
      - 0 if the input is invalid
    */

    int is_valid = 0;

    do {
        printf(prompt);
        fgets(input, max_length, stdin);
        sanitize_input(input);
        is_valid = is_valid_input(input, max_length);
        if (!is_valid) {
            printf("Invalid input. Please try again.\n");
        }
        clear_input_buffer(); // Clear input buffer
    } while (!is_valid);

    return 1;
}

int main() {
    char input[MAX_INPUT_BUFFER];

    // Example usage
    char prompt[] = "Enter a word: ";
    get_input(input, MAX_INPUT_BUFFER, prompt);
    printf("You entered: %s\n", input);

    return 0;
}