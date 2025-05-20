//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: artistic
// A magical journey through the land of arithmetic

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 1000
#define MAGIC_NUMBER 42

// Define a structure to hold our arithmetic expressions
typedef struct {
    char op; // operator (e.g. +, -, x, /)
    int num1, num2; // numbers being operated on
} expression;

// Function to evaluate an expression
int evaluate(expression exp) {
    int result;

    // Handle special cases
    if (exp.op == '+') {
        result = exp.num1 + exp.num2;
    } else if (exp.op == '-') {
        result = exp.num1 - exp.num2;
    } else if (exp.op == '*') {
        result = exp.num1 * exp.num2;
    } else if (exp.op == '/') {
        result = exp.num1 / exp.num2;
    } else {
        // Unknown operator, return error
        return -1;
    }

    // Perform the operation
    return result;
}

// Function to parse an arithmetic expression
expression parse(char *str) {
    expression exp;

    // Split the string into tokens
    char *tokens[5];
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\t') {
            continue;
        }
        tokens[i] = str + i;
        i++;
    }

    // Check for invalid input
    if (tokens[0][0] == '\0' || tokens[1][0] == '\0' ||
            tokens[2][0] == '\0' || tokens[3][0] == '\0' ||
            tokens[4][0] == '\0') {
        return exp; // Return an empty structure to indicate error
    }

    // Assign the operator and numbers
    exp.op = tokens[0][0];
    exp.num1 = atoi(tokens[1]);
    exp.num2 = atoi(tokens[2]);

    return exp;
}

int main() {
    srand(time(0)); // Seed the random number generator

    // Define an array of expressions to evaluate
    expression exp[5];

    // Generate a random expression
    int i = 0;
    while (i < 5) {
        char str[100];
        snprintf(str, 100, "%d %c %d", rand() % 100,
                  (rand() % 2) ? '+' : '-', rand() % 100);
        exp[i] = parse(str);
        i++;
    }

    // Evaluate each expression and print the result
    for (int i = 0; i < 5; i++) {
        int result = evaluate(exp[i]);
        printf("%d\n", result);
    }

    return 0;
}