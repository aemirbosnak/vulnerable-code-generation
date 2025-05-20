//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom error codes
#define ERR_INVALID_INPUT 1
#define ERR_OUT_OF_BOUNDS 2
#define ERR_UNEXPECTED_EOF 3

// Function to check if a string is a valid integer
int is_valid_int(char *str) {
    int len = strlen(str);

    // Check if the string is empty
    if (len == 0) {
        return 0;
    }

    // Check if the first character is a '-' sign
    if (str[0] == '-') {
        // Check if the string has more than one '-' sign
        for (int i = 1; i < len; i++) {
            if (str[i] == '-') {
                return 0;
            }
        }

        // Check if the string is all '-' signs
        if (len == 1) {
            return 0;
        }

        // Check if the rest of the string is a valid integer
        char *rest = str + 1;
        return is_valid_int(rest);
    }

    // Check if the string contains any non-digit characters
    for (int i = 0; i < len; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }

    // If all checks pass, the string is a valid integer
    return 1;
}

// Function to check if a string is within a specified range
int is_in_range(char *str, int min, int max) {
    // Check if the string is a valid integer
    if (!is_valid_int(str)) {
        return 0;
    }

    // Convert the string to an integer
    int num = atoi(str);

    // Check if the integer is within the specified range
    if (num < min || num > max) {
        return 0;
    }

    // If all checks pass, the string is within the specified range
    return 1;
}

// Function to get a valid integer from the user
int get_valid_int(int min, int max) {
    char *input = NULL;
    size_t len = 0;
    int valid = 0;

    // Prompt the user for input
    printf("Enter an integer between %d and %d: ", min, max);

    // Get the user's input
    getline(&input, &len, stdin);

    // Remove the newline character from the input
    input[strcspn(input, "\n")] = '\0';

    // Validate the input
    while (!valid) {
        // Check if the input is empty
        if (strlen(input) == 0) {
            printf("Invalid input. Please enter an integer between %d and %d: ", min, max);
            getline(&input, &len, stdin);
            input[strcspn(input, "\n")] = '\0';
        }
        // Check if the input is a valid integer
        else if (!is_valid_int(input)) {
            printf("Invalid input. Please enter an integer between %d and %d: ", min, max);
            getline(&input, &len, stdin);
            input[strcspn(input, "\n")] = '\0';
        }
        // Check if the input is within the specified range
        else if (!is_in_range(input, min, max)) {
            printf("Invalid input. Please enter an integer between %d and %d: ", min, max);
            getline(&input, &len, stdin);
            input[strcspn(input, "\n")] = '\0';
        }
        // If all checks pass, the input is valid
        else {
            valid = 1;
        }
    }

    // Convert the input to an integer and return it
    return atoi(input);
}

// Main function
int main() {
    // Get a valid integer from the user
    int num = get_valid_int(0, 100);

    // Print the user's input
    printf("You entered the integer: %d\n", num);

    return 0;
}