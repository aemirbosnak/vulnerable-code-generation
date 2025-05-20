//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef enum {
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_POW,
    OP_SQRT,
    OP_SIN,
    OP_COS,
    OP_TAN,
    OP_LN,
    OP_LOG,
    OP_EXP
} Operator;

typedef struct {
    double value;
    Operator op;
} StackItem;

StackItem stack[MAX_STACK_SIZE];
int stack_top = -1;

void push(double value, Operator op) {
    if (stack_top == MAX_STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++stack_top].value = value;
    stack[stack_top].op = op;
}

double pop() {
    if (stack_top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[stack_top--].value;
}

double calculate(const char *expr) {
    char *token;
    char *rest = strdup(expr);

    while ((token = strtok_r(rest, " ", &rest))) {
        if (isdigit(*token)) {
            push(atof(token), OP_ADD);
        } else {
            double a = pop();
            double b = pop();
            switch (*token) {
                case '+':
                    push(b + a, OP_ADD);
                    break;
                case '-':
                    push(b - a, OP_SUB);
                    break;
                case '*':
                    push(b * a, OP_MUL);
                    break;
                case '/':
                    push(b / a, OP_DIV);
                    break;
                case '^':
                    push(pow(b, a), OP_POW);
                    break;
                case 's':
                    if (strcmp(token, "sin") == 0) {
                        push(sin(a), OP_SIN);
                    } else if (strcmp(token, "sqrt") == 0) {
                        push(sqrt(a), OP_SQRT);
                    } else {
                        printf("Invalid operator: %s\n", token);
                        exit(1);
                    }
                    break;
                case 'c':
                    if (strcmp(token, "cos") == 0) {
                        push(cos(a), OP_COS);
                    } else {
                        printf("Invalid operator: %s\n", token);
                        exit(1);
                    }
                    break;
                case 't':
                    if (strcmp(token, "tan") == 0) {
                        push(tan(a), OP_TAN);
                    } else {
                        printf("Invalid operator: %s\n", token);
                        exit(1);
                    }
                    break;
                case 'l':
                    if (strcmp(token, "ln") == 0) {
                        push(log(a), OP_LN);
                    } else if (strcmp(token, "log") == 0) {
                        push(log10(a), OP_LOG);
                    } else {
                        printf("Invalid operator: %s\n", token);
                        exit(1);
                    }
                    break;
                case 'e':
                    if (strcmp(token, "exp") == 0) {
                        push(exp(a), OP_EXP);
                    } else {
                        printf("Invalid operator: %s\n", token);
                        exit(1);
                    }
                    break;
                default:
                    printf("Invalid operator: %s\n", token);
                    exit(1);
            }
        }
    }

    return pop();
}

int main() {
    char expr[100];
    while (1) {
        printf("Enter an expression (or 'q' to quit): ");
        gets(expr);
        if (strcmp(expr, "q") == 0) {
            break;
        }
        printf("Result: %f\n", calculate(expr));
    }
    return 0;
}