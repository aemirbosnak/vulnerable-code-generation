//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: mathematical
#include <stdio.h>
#include <string.h>

// Define a struct to represent a mathematical expression
typedef struct {
    char op; // operator (e.g. +, -, *, /)
    int num1, num2; // two numbers in the expression
} math_expr;

// Function to evaluate a mathematical expression
int evaluate(math_expr *expr) {
    int result = 0;
    switch (expr->op) {
        case '+':
            result = expr->num1 + expr->num2;
            break;
        case '-':
            result = expr->num1 - expr->num2;
            break;
        case '*':
            result = expr->num1 * expr->num2;
            break;
        case '/':
            result = expr->num1 / expr->num2;
            break;
        default:
            printf("Invalid operator\n");
            return 0;
    }
    return result;
}

// Function to parse a string representing a mathematical expression
math_expr *parse_expr(char *str) {
    math_expr *expr = malloc(sizeof(math_expr));
    char *token;
    int i = 0;

    // Tokenize the string into individual characters
    while ((token = strtok(str, "+" - '0'))) {
        if (isdigit(token[0])) { // Check if the token is a number
            expr->num1 *= 10; // Convert the number to an integer
            expr->num1 += (token[0] - '0');
        } else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
            expr->op = token[0];
        } else {
            printf("Invalid character in expression\n");
            return NULL;
        }
    }
    return expr;
}

int main() {
    char str[] = "+3*2+5/2";
    math_expr *expr = parse_expr(str);
    if (expr == NULL) {
        return 1;
    }
    int result = evaluate(expr);
    printf("Result: %d\n", result);
    free(expr);
    return 0;
}