//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPERANDS 5
#define MAX_OPERATIONS 5
#define MAX_NUM_DIGITS 10

typedef struct {
    char *name;
    int value;
} operand_t;

typedef struct {
    char *name;
    operand_t operands[MAX_OPERANDS];
    char operation;
} expression_t;

void parse_expression(expression_t *expr);
void evaluate_expression(expression_t *expr);

int main() {
    srand(time(NULL));

    expression_t expression;
    char input[100];

    printf("Welcome to the Arithmetic Playground!\n");

    while (1) {
        printf("Enter an expression: ");
        fgets(input, 100, stdin);

        expression.name = input;
        parse_expression(&expression);

        evaluate_expression(&expression);

        printf("\n");
    }

    return 0;
}

void parse_expression(expression_t *expr) {
    char *token;
    int i = 0;

    token = strtok(expr->name, " \t");
    while (token != NULL && i < MAX_OPERANDS) {
        expr->operands[i].name = token;
        token = strtok(NULL, " \t");
        i++;
    }

    expr->operation = token[0];
}

void evaluate_expression(expression_t *expr) {
    int result = 0;
    int i = 0;

    if (expr->operation == '+') {
        while (i < MAX_OPERANDS) {
            result += expr->operands[i].value;
            i++;
        }
    } else if (expr->operation == '-') {
        while (i < MAX_OPERANDS) {
            result -= expr->operands[i].value;
            i++;
        }
    } else if (expr->operation == '*') {
        while (i < MAX_OPERANDS) {
            result *= expr->operands[i].value;
            i++;
        }
    } else if (expr->operation == '/') {
        while (i < MAX_OPERANDS) {
            result /= expr->operands[i].value;
            i++;
        }
    } else if (expr->operation == '%') {
        while (i < MAX_OPERANDS) {
            result %= expr->operands[i].value;
            i++;
        }
    }

    printf("Result: %d\n", result);
}