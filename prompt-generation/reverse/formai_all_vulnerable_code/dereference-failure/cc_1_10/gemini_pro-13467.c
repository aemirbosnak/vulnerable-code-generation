//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double value;
    char *str;
} Token;

typedef struct {
    Token *tokens;
    int count;
    int capacity;
} TokenList;

TokenList *tokenize(char *expr) {
    TokenList *list = malloc(sizeof(TokenList));
    list->tokens = malloc(sizeof(Token) * 10);
    list->count = 0;
    list->capacity = 10;

    char *token = strtok(expr, " ");
    while (token != NULL) {
        if (*token == '(' || *token == ')' || *token == '+' || *token == '-' || *token == '*' || *token == '/') {
            Token t = { .str = token };
            list->tokens[list->count++] = t;
        } else {
            double value = strtod(token, NULL);
            Token t = { .value = value };
            list->tokens[list->count++] = t;
        }

        token = strtok(NULL, " ");
    }

    return list;
}

double eval(TokenList *list) {
    double stack[100];
    int top = 0;

    for (int i = 0; i < list->count; i++) {
        Token token = list->tokens[i];

        if (*token.str == '(') {
            stack[top++] = 0;
        } else if (*token.str == ')') {
            double a = stack[--top];
            double b = stack[--top];
            double c = stack[--top];

            switch (*token.str) {
                case '+':
                    stack[top++] = a + b;
                    break;
                case '-':
                    stack[top++] = a - b;
                    break;
                case '*':
                    stack[top++] = a * b;
                    break;
                case '/':
                    stack[top++] = a / b;
                    break;
            }
        } else {
            stack[top++] = token.value;
        }
    }

    return stack[0];
}

int main() {
    char *expr = "(2 + 3) * 4";
    TokenList *list = tokenize(expr);
    double result = eval(list);

    printf("%s = %f\n", expr, result);

    return 0;
}