//FormAI DATASET v1.0 Category: Syntax parsing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_EXPR_LENGTH 100

char *parse_expr(char *expr, int *index);
float evaluate_expr(char *expr);

int main() {
    FILE *fp;
    char expr[MAX_EXPR_LENGTH];
    char *pexpr;
    float result;
    int i = 0;

    fp = fopen("equations.txt", "r");

    while (fgets(expr, MAX_EXPR_LENGTH, fp)) {
        printf("Equation %d: %s", ++i, expr);

        pexpr = expr;
        result = evaluate_expr(pexpr);

        printf("Result: %.2f\n", result);
    }

    fclose(fp);
    return 0;
}

float evaluate_expr(char *expr) {
    int index = 0;

    //Parse and evaluate each operand
    char *op1 = parse_expr(expr, &index);
    char *op2 = parse_expr(expr, &index);
    char *operator = parse_expr(expr, &index);

    //Convert operands to float datatype for mathematical operations
    float f_op1 = strtof(op1, NULL);
    float f_op2 = strtof(op2, NULL);
    float result = 0;

    //Evaluate the mathematical operation based on the operator
    if (strcmp(operator, "+") == 0) {
        result = f_op1 + f_op2;
    } else if (strcmp(operator, "-") == 0) {
        result = f_op1 - f_op2;
    } else if (strcmp(operator, "*") == 0) {
        result = f_op1 * f_op2;
    } else if (strcmp(operator, "/") == 0) {
        result = f_op1 / f_op2;
    } else if (strcmp(operator, "^") == 0) {
        result = pow(f_op1, f_op2);
    }

    //Free the memory allocated to the operands and operator
    free(op1);
    free(op2);
    free(operator);

    return result;
}

char *parse_expr(char *expr, int *index) {
    char *operand = malloc(sizeof(char) * MAX_EXPR_LENGTH);
    int i = 0;
    memset(operand, 0, MAX_EXPR_LENGTH);

    //Ignore any leading whitespace
    while (isspace(expr[*index])) {
        (*index)++;
    }

    //Loop through each character until we hit whitespace or the end of the string
    while (!isspace(expr[*index]) && expr[*index] != '\0') {
        operand[i++] = expr[(*index)++];
    }

    operand[i] = '\0';

    return operand;
}