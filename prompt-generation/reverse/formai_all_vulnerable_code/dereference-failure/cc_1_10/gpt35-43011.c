//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_EXPRESSION_SIZE 50

// Function prototypes
void clear_input_buffer();
bool is_valid_input(char input[]);
void calculate_result(char expression[], double* result);

// Main function
int main() {
    char expression[MAX_EXPRESSION_SIZE];
    double result;

    while (true) {
        printf("Enter an expression: ");
        fgets(expression, MAX_EXPRESSION_SIZE, stdin);
        clear_input_buffer();

        if (!is_valid_input(expression)) {
            printf("Invalid input!\n");
            continue;
        }

        calculate_result(expression, &result);
        printf("Result: %lf\n", result);
        printf("Clearing input buffer...\n");
        clear_input_buffer();
    }

    return 0;
}

// Function to clear input buffer
void clear_input_buffer() {
    while (getchar() != '\n');
}

// Function to check if input is valid
bool is_valid_input(char input[]) {
    // Ensure input string is not empty
    if (strlen(input) == 1) {
        return false;
    }

    // Ensure input string ends with a newline character
    if (input[strlen(input) - 1] != '\n') {
        return false;
    }

    // Ensure input string does not exceed maximum size
    if (strlen(input) > MAX_EXPRESSION_SIZE) {
        return false;
    }

    // Ensure input string contains only valid characters
    for (int i = 0; i < strlen(input) - 1; i++) {
        if (!(isdigit(input[i]) || isspace(input[i]) || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '^')) {
            return false;
        }
    }

    return true;
}

// Function to calculate result of expression
void calculate_result(char expression[], double* result) {
    // Parse first number
    char* token;
    double num1 = strtod(strtok(expression, " "), NULL);

    // Parse operator
    token = strtok(NULL, " ");
    char op = token[0];

    // Parse second number
    double num2 = strtod(strtok(NULL, " "), NULL);

    // Check for possible security issues
    if ((num1 >= 100000000 || num2 >= 100000000) && op == '/') {
        printf("Error: Possible security issue detected!\n");
        *result = 0;
        return;
    }
    
    if (num1 >= 100000000 && num2 >= 100000000) {
        printf("Error: Possible security issue detected!\n");
        *result = 0;
        return;
    }

    if ((num1* num2 >= 100000) && op == '^') {
        printf("Error: Possible security issue detected!\n");
        *result = 0;
        return;
    }

    // Calculate result based on operator
    switch (op) {
        case '+':
            *result = num1 + num2;
            break;

        case '-':
            *result = num1 - num2;
            break;

        case '*':
            *result = num1 * num2;
            break;

        case '/':
            *result = num1 / num2;
            break;

        case '^':
            *result = pow(num1, num2);
            break;

        default:
            printf("Invalid operator!\n");
            *result = 0;
            break;
    }
}