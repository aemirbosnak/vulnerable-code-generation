//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_OPERANDS 5
#define MAX_OPERATORS 5

// Structure to hold the operands and operators
typedef struct {
    int num; // number operand
    char op; // operator (e.g. +, -, *, /)
} operand_t;

// Function to parse the input expression and evaluate it
int evaluate(char *expression) {
    // Tokenize the expression into operands and operators
    operand_t operands[MAX_OPERANDS];
    char operators[MAX_OPERATORS];
    int i = 0;
    while (expression[i] != '\0') {
        if (isdigit(expression[i])) {
            operands[i].num = atoi(expression + i);
            i++;
        } else if (expression[i] == '+') {
            operands[i].op = '+';
        } else if (expression[i] == '-') {
            operands[i].op = '-';
        } else if (expression[i] == '*') {
            operands[i].op = '*';
        } else if (expression[i] == '/') {
            operands[i].op = '/';
        } else {
            break;
        }
        i++;
    }

    // Evaluate the expression
    int result = 0;
    for (int j = 0; j < i; j++) {
        if (operands[j].op == '+') {
            result += operands[j].num;
        } else if (operands[j].op == '-') {
            result -= operands[j].num;
        } else if (operands[j].op == '*') {
            result *= operands[j].num;
        } else if (operands[j].op == '/') {
            result /= operands[j].num;
        }
    }

    return result;
}

int main() {
    char expression[100];
    printf("Enter an expression: ");
    fgets(expression, 100, stdin);

    // Evaluate the expression
    int result = evaluate(expression);

    // Print the result
    printf("Result: %d\n", result);

    return 0;
}