//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a struct to represent a mathematical expression
struct expression {
    char op; // operator (e.g. +, -, *, /)
    struct expression *left, *right; // left and right operands
};

// Define a function to parse a mathematical expression
struct expression *parse_expression(char *str) {
    // Step 1: Check for invalid input
    if (str == NULL || *str == '\0') {
        return NULL;
    }

    // Step 2: Parse the expression one character at a time
    struct expression *expr = NULL;
    char curr_char = *str++; // Get the first character of the expression
    while (*str != '\0') {
        // Check for operator
        if (curr_char == '+' || curr_char == '-' || curr_char == '*' || curr_char == '/') {
            // If we find an operator, create a new expression node
            expr = (struct expression *)malloc(sizeof(struct expression));
            expr->op = curr_char;
            expr->left = parse_expression(str);
            expr->right = parse_expression(str);
            break; // Break out of the loop
        } else {
            // If we don't find an operator, just consume the character
            curr_char = *str++;
        }
    }

    // Step 3: Return the parsed expression
    return expr;
}

// Define a function to evaluate a mathematical expression
double evaluate(struct expression *expr) {
    double result = 0;

    // Evaluate the expression recursively
    if (expr->op == '+' || expr->op == '-') {
        result = evaluate(expr->left) + evaluate(expr->right);
    } else if (expr->op == '*' || expr->op == '/') {
        result = evaluate(expr->left) * evaluate(expr->right);
    } else {
        // If we encounter an unknown operator, return an error
        return -1;
    }

    return result;
}

int main() {
    char str[100];
    struct expression *expr = NULL;

    // Parse the expression from the user
    printf("Enter a mathematical expression (e.g. 2+2): ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove the newline character
    expr = parse_expression(str);

    // Evaluate the expression
    double result = evaluate(expr);

    // Print the result
    printf("Result: %f\n", result);

    return 0;
}