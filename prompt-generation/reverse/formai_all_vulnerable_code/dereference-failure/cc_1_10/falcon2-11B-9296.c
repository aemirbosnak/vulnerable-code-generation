//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_OPERANDS 10
#define MAX_OPERATIONS 10
#define MAX_DIGITS 100

struct Operation {
    int operands[MAX_OPERANDS];
    char operator;
};

struct Expression {
    char digits[MAX_DIGITS];
    struct Operation operations[MAX_OPERATIONS];
    int operand_count;
};

struct Expression parse_expression(const char *expression) {
    struct Expression expr;
    expr.operand_count = 0;
    char *token = strtok(expression, " ");
    while (token!= NULL) {
        if (isdigit(*token)) {
            int num = strtol(token, NULL, 10);
            if (num < 0 || num >= MAX_DIGITS) {
                printf("Error: Number too large\n");
                return expr;
            }
            strcpy(expr.digits + expr.operand_count * MAX_DIGITS, token);
            expr.operand_count++;
        } else {
            struct Operation op;
            op.operator = *token;
            token = strtok(NULL, " ");
            for (int i = 0; i < expr.operand_count; i++) {
                if (isdigit(*token)) {
                    int num = strtol(token, NULL, 10);
                    if (num < 0 || num >= MAX_DIGITS) {
                        printf("Error: Number too large\n");
                        return expr;
                    }
                    op.operands[i] = num;
                    token = strtok(NULL, " ");
                } else {
                    printf("Error: Invalid operator\n");
                    return expr;
                }
            }
            if (expr.operand_count < MAX_OPERANDS) {
                expr.operations[expr.operand_count++] = op;
            }
        }
    }
    if (expr.operand_count == 0) {
        printf("Error: Empty expression\n");
        return expr;
    }
    return expr;
}

void print_expression(struct Expression expr) {
    for (int i = 0; i < expr.operand_count; i++) {
        printf("%c", expr.digits[i * MAX_DIGITS]);
    }
    for (int i = 0; i < expr.operand_count; i++) {
        printf(" %c", expr.operations[i].operator);
    }
    printf("\n");
}

struct Expression evaluate_expression(struct Expression expr) {
    struct Expression result = expr;
    int index = 0;
    while (index < expr.operand_count) {
        if (expr.operations[index].operator == '+') {
            result.operations[index].operands[0] += result.operations[index].operands[1];
            result.operations[index].operands[1] = 0;
            index++;
        } else if (expr.operations[index].operator == '-') {
            result.operations[index].operands[0] -= result.operations[index].operands[1];
            result.operations[index].operands[1] = 0;
            index++;
        } else if (expr.operations[index].operator == '*') {
            result.operations[index].operands[0] *= result.operations[index].operands[1];
            result.operations[index].operands[1] = 0;
            index++;
        } else if (expr.operations[index].operator == '/') {
            result.operations[index].operands[0] /= result.operations[index].operands[1];
            result.operations[index].operands[1] = 0;
            index++;
        } else {
            printf("Error: Invalid operator\n");
            return expr;
        }
    }
    return result;
}

int main() {
    struct Expression expr = parse_expression("3 + 4 * 2 / 8");
    print_expression(expr);
    expr = evaluate_expression(expr);
    print_expression(expr);
    return 0;
}