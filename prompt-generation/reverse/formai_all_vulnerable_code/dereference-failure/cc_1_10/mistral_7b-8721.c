//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

// Function to validate input is a number
int is_valid_number(const char *str) {
    int i, valid = 1;
    for (i = 0; str[i]; i++) {
        if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-') {
            valid = 0;
            break;
        }
    }
    return valid;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to check input string and convert Fahrenheit to Celsius
void parse_and_convert(char *input) {
    float fahrenheit;
    char *endptr;

    if (strlen(input) > MAX_INPUT_SIZE) {
        printf("Error: Input size exceeds maximum limit.\n");
        exit(EXIT_FAILURE);
    }

    input[strlen(input) - 1] = '\0'; // Remove trailing space if present

    if (strlen(input) < 2 || (strlen(input) > 3 && input[1] != 'F')) {
        printf("Error: Invalid input format. Use Fahrenheit value followed by 'F'.\n");
        exit(EXIT_FAILURE);
    }

    fahrenheit = strtof(input, &endptr);

    if (input == endptr) {
        printf("Error: Invalid input.\n");
        exit(EXIT_FAILURE);
    }

    if (!is_valid_number(input)) {
        printf("Error: Input must be a valid number.\n");
        exit(EXIT_FAILURE);
    }

    fahrenheit = fahrenheit_to_celsius(fahrenheit);

    printf("Input: %s\n", input);
    printf("Output: %.2f°C\n", fahrenheit);
}

int main() {
    char input[MAX_INPUT_SIZE + 1];

    while (1) {
        printf("Enter temperature in Fahrenheit (or type 'exit' to quit): ");
        fgets(input, sizeof(input), stdin);

        if (strstr(input, "exit")) {
            break;
        }

        input[strlen(input) - 1] = '\0'; // Remove trailing newline character

        parse_and_convert(input);
    }

    return EXIT_SUCCESS;
}