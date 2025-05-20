//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to check if a string contains only digits
int is_digit_string(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a string contains only letters
int is_letter_string(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a string contains only alphanumeric characters
int is_alphanumeric_string(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalnum(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to get a sanitized numeric input from the user
int get_numeric_input(char *prompt) {
    char input[100];
    int number;

    // Prompt the user for input
    printf("%s", prompt);

    // Get the input from the user
    fgets(input, sizeof(input), stdin);

    // Remove the newline character from the input
    input[strcspn(input, "\n")] = '\0';

    // Check if the input is a digit string
    if (!is_digit_string(input)) {
        printf("Error: Invalid input. Please enter a numeric value.\n");
        return -1;
    }

    // Convert the input to an integer
    number = atoi(input);

    // Return the integer
    return number;
}

// Function to get a sanitized string input from the user
char *get_string_input(char *prompt) {
    char *input;
    size_t len;

    // Prompt the user for input
    printf("%s", prompt);

    // Get the input from the user
    input = NULL;
    getline(&input, &len, stdin);

    // Remove the newline character from the input
    input[strcspn(input, "\n")] = '\0';

    // Return the input
    return input;
}

// Function to get a sanitized alphanumeric string input from the user
char *get_alphanumeric_string_input(char *prompt) {
    char *input;
    size_t len;

    // Prompt the user for input
    printf("%s", prompt);

    // Get the input from the user
    input = NULL;
    getline(&input, &len, stdin);

    // Remove the newline character from the input
    input[strcspn(input, "\n")] = '\0';

    // Check if the input is an alphanumeric string
    if (!is_alphanumeric_string(input)) {
        printf("Error: Invalid input. Please enter an alphanumeric value.\n");
        return NULL;
    }

    // Return the input
    return input;
}

int main() {
    // Define the input variables
    int age;
    char *name;
    char *username;

    // Get the age from the user
    age = get_numeric_input("Enter your age: ");

    // Get the name from the user
    name = get_string_input("Enter your name: ");

    // Get the username from the user
    username = get_alphanumeric_string_input("Enter your username: ");

    // Print the input values
    printf("Age: %d\n", age);
    printf("Name: %s\n", name);
    printf("Username: %s\n", username);

    // Free the allocated memory
    free(name);
    free(username);

    return 0;
}