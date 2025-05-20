//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

/**
 * Sanitizes user input by removing any non-alphanumeric characters and converting all characters to lowercase.
 *
 * @param input The input string to sanitize.
 * @param length The length of the input string.
 * @return The sanitized input string.
 */
char* sanitize_input(char* input, int length) {
    char* sanitized_input = (char*)malloc(length + 1);
    int i, j;

    for (i = 0, j = 0; i < length; i++) {
        if (isalnum(input[i])) {
            sanitized_input[j++] = tolower(input[i]);
        }
    }

    sanitized_input[j] = '\0';

    return sanitized_input;
}

/**
 * Prompts the user for input and sanitizes the input before returning it.
 *
 * @param prompt The prompt to display to the user.
 * @return The sanitized user input.
 */
char* get_sanitized_input(char* prompt) {
    char input[MAX_INPUT_LENGTH];
    printf("%s", prompt);
    fgets(input, MAX_INPUT_LENGTH, stdin);

    return sanitize_input(input, strlen(input));
}

int main() {
    char* name = get_sanitized_input("What is your name? ");
    char* message = get_sanitized_input("What is your message to the future? ");

    printf("Hello, %s! Your message to the future is: %s\n", name, message);

    free(name);
    free(message);

    return 0;
}