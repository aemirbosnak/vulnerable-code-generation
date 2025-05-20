//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100
#define MAX_OPER 5

// Structure to store a mathematical expression
typedef struct {
    char op[2];  // Operator (e.g. +, -, x, /)
    int num1, num2; // Numerical values
} exp;

// Function to evaluate a mathematical expression
int evaluate(exp *expr) {
    int res = 0;
    switch (expr->op[0]) {
        case '+':
            res = expr->num1 + expr->num2;
            break;
        case '-':
            res = expr->num1 - expr->num2;
            break;
        case '*':
            res = expr->num1 * expr->num2;
            break;
        case '/':
            if (expr->num2 == 0) {
                printf("Error: Division by zero!\n");
                return 0;
            }
            res = expr->num1 / expr->num2;
            break;
        default:
            printf("Invalid operator\n");
            return 0;
    }
    return res;
}

// Function to parse a mathematical expression
exp *parse_expression(char *str) {
    exp *expr = (exp *) malloc(sizeof(exp));
    char *token;
    int i = 0;

    // Tokenize the input string
    while (i < strlen(str)) {
        token = str + i;
        if (token[0] == ' ' || token[0] == '\t') {
            i++;
            continue;
        }
        break;
    }

    // Extract the operator and numerical values
    expr->op[0] = token[0];
    expr->num1 = atoi(token + 1);
    i++;
    while (i < strlen(str)) {
        token = str + i;
        if (token[0] == ' ' || token[0] == '\t') {
            i++;
            continue;
        }
        break;
    }
    expr->num2 = atoi(token + 1);

    return expr;
}

int main() {
    srand(time(NULL));  // Seed the random number generator

    // Generate a random mathematical expression
    char *str = (char *) malloc(sizeof(char) * 100);
    for (int i = 0; i < 100; i++) {
        str[i] = 'a' + (rand() % 26);  // Generate a random character
    }
    str[99] = '\0';  // Null-terminate the string

    // Parse the expression and evaluate it
    exp *expr = parse_expression(str);
    int result = evaluate(expr);

    // Print the result
    printf("Result: %d\n", result);

    // Free memory
    free(str);
    free(expr);

    return 0;
}