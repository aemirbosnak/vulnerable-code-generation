//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a function to calculate the factorial of a given integer
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

// Define a function to calculate the value of a given expression
int evaluate(char *expression) {
    int num1, num2, result;
    char op;

    // Tokenize the expression into individual components
    char *token = strtok(expression, "+-*/");
    num1 = atoi(token);
    token = strtok(NULL, "+-*/");
    num2 = atoi(token);
    token = strtok(NULL, "+-*/");
    op = *token;

    // Evaluate the expression based on the operator
    if (op == '+') {
        result = num1 + num2;
    } else if (op == '-') {
        result = num1 - num2;
    } else if (op == '*') {
        result = num1 * num2;
    } else if (op == '/') {
        result = num1 / num2;
    } else {
        // Handle invalid expressions
        result = -1;
    }

    return result;
}

int main() {
    int n, result;

    // Example 1: Evaluate the expression 4 + 5
    n = 4;
    result = evaluate("4 + 5");
    printf("4 + 5 = %d\n", result);

    // Example 2: Evaluate the expression 2 * 3 + 1
    n = 2;
    result = evaluate("2 * 3 + 1");
    printf("2 * 3 + 1 = %d\n", result);

    // Example 3: Evaluate the expression 10 / 2
    n = 10;
    result = evaluate("10 / 2");
    printf("10 / 2 = %d\n", result);

    // Example 4: Evaluate the expression 6 - 2
    n = 6;
    result = evaluate("6 - 2");
    printf("6 - 2 = %d\n", result);

    return 0;
}