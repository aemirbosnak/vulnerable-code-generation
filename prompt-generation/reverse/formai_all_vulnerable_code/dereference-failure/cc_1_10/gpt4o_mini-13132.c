//GPT-4o-mini DATASET v1.0 Category: User Input Sanitizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

// Function declarations
void sanitize_input(char *input);
int is_valid_number(const char *input);
int is_valid_expression(const char *expression);
void trim_whitespace(char *str);
void remove_special_characters(char *str);

int main() {
    char input[MAX_INPUT_SIZE];
    
    printf("=============================================\n");
    printf("       Mathematical Input Sanitizer         \n");
    printf("=============================================\n");
    printf("Please enter a mathematical expression (e.g., 2 + 3 * (4 - 5)): \n");

    // Read the input
    if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }

    // Sanitize the input
    sanitize_input(input);
    
    // Check if the sanitized input is a valid expression
    if (is_valid_expression(input)) {
        printf("Sanitized valid expression: %s\n", input);
    } else {
        printf("Invalid mathematical expression.\n");
    }

    return EXIT_SUCCESS;
}

// Function to sanitize the input
void sanitize_input(char *input) {
    // Trim whitespace
    trim_whitespace(input);
    
    // Remove special characters (keep numbers, operators and parentheses)
    remove_special_characters(input);
}

// Function to trim leading and trailing whitespace
void trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate after the last non-space character
    *(end + 1) = '\0';
}

// Function to remove special characters
void remove_special_characters(char *str) {
    char valid_chars[MAX_INPUT_SIZE] = "0123456789+-*/() ";
    char sanitized[MAX_INPUT_SIZE] = {0};
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (strchr(valid_chars, str[i]) != NULL) {
            sanitized[index++] = str[i];
        }
    }
    sanitized[index] = '\0';
    strcpy(str, sanitized); // Copy back sanitized string
}

// Function to validate if the input is a number
int is_valid_number(const char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i]) && input[i] != '.' && input[i] != '-') {
            return 0;
        }
    }
    return 1;
}

// Function to validate mathematical expression
int is_valid_expression(const char *expression) {
    // Check for balanced parentheses and valid operators
    int balance = 0;
    int last_char_was_operator = 1; // To ensure that operators are well placed

    for (int i = 0; expression[i] != '\0'; i++) {
        char current = expression[i];

        // Check for parentheses balance
        if (current == '(') {
            balance++;
            last_char_was_operator = 0;
        } else if (current == ')') {
            balance--;
            if (balance < 0) return 0; // More closing than opening
            last_char_was_operator = 1;
        } else if (strchr("+-*/", current)) {
            if (last_char_was_operator) return 0; // No two operators in a row
            last_char_was_operator = 1;
        } else if (isdigit(current)) {
            last_char_was_operator = 0; // Valid number read
        } else if (isspace(current)) {
            continue; // Ignore whitespace
        } else {
            return 0; // Invalid character
        }
    }

    // Ensure all parentheses are closed and last character isn't an operator
    return balance == 0 && !last_char_was_operator;
}