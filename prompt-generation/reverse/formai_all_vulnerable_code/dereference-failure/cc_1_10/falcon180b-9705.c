//Falcon-180B DATASET v1.0 Category: Error handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length of a string
#define MAX_LENGTH 100

// Function to check if a string is a valid integer
int is_integer(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to handle errors
void error_handler(char *error_message) {
    printf("Error: %s", error_message);
    exit(1);
}

// Function to read a string input from user
char *read_string(char *prompt) {
    char input[MAX_LENGTH];
    printf("%s", prompt);
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';
    return strdup(input);
}

// Function to read an integer input from user
int read_integer(char *prompt) {
    char input[MAX_LENGTH];
    printf("%s", prompt);
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';
    return atoi(input);
}

int main() {
    // Declare variables
    char *name;
    int age;

    // Read name input from user
    name = read_string("Enter your name: ");

    // Check if name input is valid
    if (strlen(name) == 0) {
        error_handler("Name cannot be empty.");
    }

    // Read age input from user
    age = read_integer("Enter your age: ");

    // Check if age input is valid
    if (!is_integer(name)) {
        error_handler("Age must be an integer.");
    }

    // Print user information
    printf("Hello, %s. You are %d years old.\n", name, age);

    return 0;
}