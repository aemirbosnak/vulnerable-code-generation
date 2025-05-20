//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100
#define MAX_OPER 5

typedef struct {
    char num[10];
    char op[2];
} expression;

expression *parse(char *str) {
    expression *exp = (expression *)malloc(sizeof(expression));
    int i = 0;
    char *token = strtok(str, " \t");

    while (token != NULL && i < MAX_NUM) {
        if (isdigit(token[0])) {
            exp->num[i] = token[0] - '0';
        } else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
            exp->op[0] = token[0];
            i++;
            if (i >= MAX_OPER) {
                break;
            }
        }
        token = strtok(NULL, " \t");
    }

    return exp;
}

int evaluate(expression *exp) {
    int res = 0;

    if (exp->op[0] == '+') {
        res = exp->num[0] + evaluate(exp->num + 1);
    } else if (exp->op[0] == '-') {
        res = exp->num[0] - evaluate(exp->num + 1);
    } else if (exp->op[0] == '*') {
        res = exp->num[0] * evaluate(exp->num + 1);
    } else if (exp->op[0] == '/') {
        res = exp->num[0] / evaluate(exp->num + 1);
    }

    return res;
}

int main() {
    srand(time(NULL));
    char str[100];
    printf("Enter an expression: ");
    fgets(str, 100, stdin);

    expression *exp = parse(str);
    printf("Result: %d\n", evaluate(exp));

    return 0;
}