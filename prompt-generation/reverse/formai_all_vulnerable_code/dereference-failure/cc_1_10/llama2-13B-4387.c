//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

// Define a struct to represent a mathematical expression
typedef struct {
    char op[2];  // operator (e.g. +, -, x, /)
    int num1, num2; // numbers in the expression
} math_expr_t;

// Function to evaluate a mathematical expression
int evaluate(math_expr_t *expr) {
    int result = 0;

    // Evaluate the expression from left to right
    if (strcmp(expr->op, "+") == 0) {
        result = expr->num1 + expr->num2;
    } else if (strcmp(expr->op, "-") == 0) {
        result = expr->num1 - expr->num2;
    } else if (strcmp(expr->op, "*") == 0) {
        result = expr->num1 * expr->num2;
    } else if (strcmp(expr->op, "/") == 0) {
        result = expr->num1 / expr->num2;
    } else {
        // Unknown operator, print an error message
        printf("Unknown operator %s\n", expr->op);
        return 0;
    }

    // Return the result of the evaluation
    return result;
}

// Function to parse a mathematical expression from a string
math_expr_t *parse_expr(char *str) {
    math_expr_t *expr = malloc(sizeof(math_expr_t));

    // Parse the expression from the string
    char *token = strtok(str, " ");
    expr->num1 = atoi(token);
    token = strtok(NULL, " ");
    expr->op[0] = *token++;
    expr->op[1] = *token;
    token = strtok(NULL, " ");
    expr->num2 = atoi(token);

    // Return the parsed expression
    return expr;
}

int main() {
    // Define a list of mathematical expressions to evaluate
    char *expressions[] = {
        "+3 x 4",
        "-2 / 5",
        "2 + 2",
        "4 x 3",
        "3 - 1",
        "2 * 2",
        "1 / 2",
        "3 + 1",
        "4 - 3",
        "2 * 3",
        "1 / 4"
    };

    // Evaluate each expression and print the result
    for (int i = 0; i < sizeof(expressions) / sizeof(expressions[0]); i++) {
        math_expr_t *expr = parse_expr(expressions[i]);
        int result = evaluate(expr);
        printf("%s = %d\n", expressions[i], result);
    }

    // Print a message when the program completes
    printf("All expressions evaluated successfully\n");

    return 0;
}