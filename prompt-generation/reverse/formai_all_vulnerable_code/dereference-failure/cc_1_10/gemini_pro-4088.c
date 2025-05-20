//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string contains only digits
int is_digits(const char *str) {
    while (*str) {
        if (*str < '0' || *str > '9') {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to get a valid integer from the user
int get_int(const char *prompt) {
    char input[100];
    int value;

    while (1) {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);

        // Remove trailing newline character
        input[strcspn(input, "\n")] = '\0';

        // Check if the input is valid
        if (is_digits(input)) {
            value = atoi(input);
            return value;
        } else {
            printf("Invalid input. Please enter a valid integer.\n");
        }
    }
}

// Function to get a valid float from the user
float get_float(const char *prompt) {
    char input[100];
    float value;

    while (1) {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);

        // Remove trailing newline character
        input[strcspn(input, "\n")] = '\0';

        // Check if the input is valid
        if (strchr(input, '.') != NULL) {
            value = atof(input);
            return value;
        } else {
            printf("Invalid input. Please enter a valid float.\n");
        }
    }
}

// Function to get a valid string from the user
char *get_string(const char *prompt) {
    char *input = NULL;
    size_t len = 0;

    printf("%s", prompt);
    getline(&input, &len, stdin);

    // Remove trailing newline character
    input[strcspn(input, "\n")] = '\0';

    return input;
}

int main() {
    int age;
    float height;
    char *name;

    // Get the user's age
    age = get_int("Enter your age: ");

    // Get the user's height
    height = get_float("Enter your height: ");

    // Get the user's name
    name = get_string("Enter your name: ");

    // Print the user's information
    printf("Your age is %d.\n", age);
    printf("Your height is %.2f.\n", height);
    printf("Your name is %s.\n", name);

    // Free the memory allocated for the name string
    free(name);

    return 0;
}