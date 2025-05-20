//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a struct to represent a mathematical expression
typedef struct {
    char op[2];  // Operator (e.g. +, -, *, /)
    double num1, num2;  // Numerators
} Expression;

// Function to evaluate an expression
double evaluate(Expression exp) {
    double result;

    // Evaluate the expression based on the operator and numerators
    switch (exp.op[0]) {
        case '+':
            result = exp.num1 + exp.num2;
            break;
        case '-':
            result = exp.num1 - exp.num2;
            break;
        case '*':
            result = exp.num1 * exp.num2;
            break;
        case '/':
            result = exp.num1 / exp.num2;
            break;
        default:
            result = 0;  // Handle invalid expressions
    }

    return result;
}

// Function to read an expression from a file
Expression read_expression(FILE *file) {
    Expression exp;
    char line[100];

    // Read the expression from the file
    while (fgets(line, 100, file) != NULL) {
        // Ignore comments and empty lines
        if (line[0] == '#' || strlen(line) == 0) {
            continue;
        }

        // Extract the operator and numerators
        sscanf(line, "%c%lf%lf", &exp.op[0], &exp.num1, &exp.num2);

        // Return the expression
        return exp;
    }

    // Handle end of file
    return exp;
}

int main() {
    // Open the file
    FILE *file = fopen("expressions.txt", "r");

    // Read the expressions from the file
    Expression exp1 = read_expression(file);
    Expression exp2 = read_expression(file);

    // Evaluate the expressions
    double result1 = evaluate(exp1);
    double result2 = evaluate(exp2);

    // Print the results
    printf("Result of expression 1: %f\n", result1);
    printf("Result of expression 2: %f\n", result2);

    // Close the file
    fclose(file);

    return 0;
}