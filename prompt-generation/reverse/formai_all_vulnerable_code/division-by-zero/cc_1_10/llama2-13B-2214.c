//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a struct to represent a mathematical expression
typedef struct {
    char op[2];  // operator (e.g. +, -, *, /)
    int num1, num2;  // two numbers in the expression
} Exp;

// Function to parse a mathematical expression
Exp parse_expr(char *str) {
    // Step 1: Find the first operator
    char *op_ptr = str;
    while (*op_ptr != '+' && *op_ptr != '-' && *op_ptr != '*' && *op_ptr != '/') {
        op_ptr++;
    }

    // Step 2: Find the second operator
    char *num_ptr = op_ptr + 1;
    while (*num_ptr != '0' && *num_ptr != '1' && *num_ptr != '2' && *num_ptr != '3' && *num_ptr != '4' && *num_ptr != '5' && *num_ptr != '6' && *num_ptr != '7' && *num_ptr != '8' && *num_ptr != '9') {
        num_ptr++;
    }

    // Step 3: Create the Exp struct
    Exp exp = {
        .op = op_ptr[0],
        .num1 = atoi(op_ptr + 1),
        .num2 = atoi(num_ptr)
    };

    return exp;
}

// Function to evaluate a mathematical expression
double evaluate(Exp exp) {
    switch (exp.op[0]) {
        case '+':
            return exp.num1 + exp.num2;
        case '-':
            return exp.num1 - exp.num2;
        case '*':
            return exp.num1 * exp.num2;
        case '/':
            return exp.num1 / exp.num2;
        default:
            printf("Invalid operator\n");
            return 0;
    }
}

int main() {
    char str[100];
    printf("Enter a mathematical expression: ");
    fgets(str, 100, stdin);

    // Parse the expression
    Exp exp = parse_expr(str);

    // Evaluate the expression
    double result = evaluate(exp);

    // Print the result
    printf("Result: %f\n", result);

    return 0;
}