//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string contains only digits
int is_digits(char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a string contains only alpha characters
int is_alpha(char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a string contains only alpha-numeric characters
int is_alphanumeric(char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (!isalnum(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to get a valid integer from the user
int get_integer(char* prompt) {
    char input[100];
    int value;

    while (1) {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);

        // Remove trailing newline character
        input[strcspn(input, "\n")] = '\0';

        // Check if the input is valid
        if (!is_digits(input)) {
            printf("Invalid input. Please enter a valid integer.\n");
        } else {
            value = atoi(input);
            break;
        }
    }

    return value;
}

// Function to get a valid string from the user
char* get_string(char* prompt) {
    char input[100];
    char* value;

    while (1) {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);

        // Remove trailing newline character
        input[strcspn(input, "\n")] = '\0';

        // Check if the input is valid
        if (strlen(input) == 0) {
            printf("Invalid input. Please enter a valid string.\n");
        } else {
            value = strdup(input);
            break;
        }
    }

    return value;
}

// Function to test the input sanitizer
int main() {
    int age;
    char* name;

    // Get a valid integer from the user
    age = get_integer("Enter your age: ");

    // Get a valid string from the user
    name = get_string("Enter your name: ");

    // Print the sanitized input
    printf("Your age is: %d\n", age);
    printf("Your name is: %s\n", name);

    return 0;
}