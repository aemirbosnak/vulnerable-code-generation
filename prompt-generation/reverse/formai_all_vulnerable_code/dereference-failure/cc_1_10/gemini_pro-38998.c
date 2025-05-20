//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the input is a valid integer
int is_integer(char *input) {
    int i = 0;
    while (input[i] != '\0') {
        if (input[i] < '0' || input[i] > '9') {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to check if the input is a valid floating-point number
int is_floating_point_number(char *input) {
    int i = 0, decimal_count = 0;
    while (input[i] != '\0') {
        if (input[i] == '.') {
            decimal_count++;
        } else if (input[i] < '0' || input[i] > '9') {
            return 0;
        }
        i++;
    }
    return decimal_count == 1;
}

// Function to sanitize the input
char *sanitize_input(char *input) {
    // Remove all non-alphanumeric characters
    int i = 0, j = 0;
    while (input[i] != '\0') {
        if (input[i] >= 'a' && input[i] <= 'z') {
            input[j++] = input[i];
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            input[j++] = input[i];
        } else if (input[i] >= '0' && input[i] <= '9') {
            input[j++] = input[i];
        } else if (input[i] == ' ') {
            input[j++] = input[i];
        }
        i++;
    }
    input[j] = '\0';

    // Trim leading and trailing spaces
    i = 0;
    while (input[i] == ' ') {
        i++;
    }
    j = strlen(input) - 1;
    while (input[j] == ' ') {
        j--;
    }
    input[j + 1] = '\0';

    return input;
}

int main() {
    char input[100];
    printf("Enter input: ");
    gets(input);

    // Sanitize the input
    char *sanitized_input = sanitize_input(input);

    // Check if the input is a valid integer
    if (is_integer(sanitized_input)) {
        printf("Input is a valid integer: %s\n", sanitized_input);
    }
    // Check if the input is a valid floating-point number
    else if (is_floating_point_number(sanitized_input)) {
        printf("Input is a valid floating-point number: %s\n", sanitized_input);
    }
    // Otherwise, the input is invalid
    else {
        printf("Input is invalid: %s\n", sanitized_input);
    }

    return 0;
}