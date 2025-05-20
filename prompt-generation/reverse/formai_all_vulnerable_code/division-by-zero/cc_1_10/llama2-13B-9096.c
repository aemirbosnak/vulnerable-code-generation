//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUM 100
#define MAX_OPERATIONS 10

// Structure to store a math expression
typedef struct {
    char op[3];  // Operation (e.g. +, -, *, /)
    int num1, num2; // Numerators
} math_expr;

// Function to parse a math expression
math_expr parse_expr(char *str) {
    math_expr expr;
    char *token;
    int i = 0;

    // Tokenize the input string
    while ((token = strtok(str, " +-*/")) != NULL) {
        if (i == 0) {
            expr.op[0] = *token;
        } else if (i == 1) {
            expr.num1 = atoi(token);
        } else {
            expr.num2 = atoi(token);
        }
        i++;
    }

    return expr;
}

// Function to evaluate a math expression
double evaluate(math_expr expr) {
    double result = 0;

    switch (expr.op[0]) {
        case '+':
            result = expr.num1 + expr.num2;
            break;
        case '-':
            result = expr.num1 - expr.num2;
            break;
        case '*':
            result = expr.num1 * expr.num2;
            break;
        case '/':
            result = expr.num1 / expr.num2;
            break;
        default:
            printf("Invalid operation\n");
            return 0;
    }

    return result;
}

int main() {
    // Create a menu for the user to choose an operation
    char menu[] = "Select an operation (1-4): ";
    char choice;

    do {
        printf("%s", menu);
        scanf("%c", &choice);

        // Perform the chosen operation
        math_expr expr;
        expr = parse_expr(choice);
        double result = evaluate(expr);

        // Print the result
        printf("Result: %f\n", result);
    } while (choice != '4');

    return 0;
}