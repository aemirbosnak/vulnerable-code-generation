//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum size of the input buffer
#define MAX_INPUT_SIZE 1024

// Define the characters that are allowed in the input
#define ALLOWED_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_ "

// This function checks if the input string contains only allowed characters
int is_valid_input(char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (!strchr(ALLOWED_CHARS, input[i])) {
            return 0;
        }
    }

    return 1;
}

// This function prompts the user for input and validates it
char *get_validated_input(char *prompt) {
    // Allocate memory for the input buffer
    char *input = malloc(MAX_INPUT_SIZE);

    // Prompt the user for input
    printf("%s", prompt);

    // Get the input from the user
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Remove the newline character from the input
    input[strcspn(input, "\n")] = '\0';

    // Validate the input
    while (!is_valid_input(input)) {
        printf("Invalid input. Please try again: ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        input[strcspn(input, "\n")] = '\0';
    }

    // Return the validated input
    return input;
}

int main() {
    // Get the user's name
    char *name = get_validated_input("What is your name? ");

    // Get the user's age
    char *age = get_validated_input("How old are you? ");

    // Get the user's favorite color
    char *color = get_validated_input("What is your favorite color? ");

    // Print the user's information
    printf("Your name is %s, you are %s years old, and your favorite color is %s.\n", name, age, color);

    // Free the memory allocated for the input buffers
    free(name);
    free(age);
    free(color);

    return 0;
}