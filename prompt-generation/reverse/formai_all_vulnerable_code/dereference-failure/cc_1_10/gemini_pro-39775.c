//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STACK_SIZE 100

typedef struct {
    double value;
    char operator;
} Token;

typedef struct {
    Token *tokens;
    int top;
} Stack;

void push(Stack *stack, Token token) {
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Error: Stack overflow\n");
        exit(1);
    }

    stack->tokens[++stack->top] = token;
}

Token pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Error: Stack underflow\n");
        exit(1);
    }

    return stack->tokens[stack->top--];
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char operator) {
    switch (operator) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

double evaluate(char *expression) {
    Stack stack;
    stack.top = -1;
    stack.tokens = malloc(sizeof(Token) * MAX_STACK_SIZE);

    char *p = expression;
    while (*p != '\0') {
        if (isdigit(*p)) {
            double value = 0;
            while (isdigit(*p)) {
                value = value * 10 + (*p - '0');
                p++;
            }

            Token token;
            token.value = value;
            token.operator = '\0';
            push(&stack, token);
        } else if (isOperator(*p)) {
            while (stack.top != -1 && precedence(stack.tokens[stack.top].operator) >= precedence(*p)) {
                Token token = pop(&stack);
                double result;
                switch (token.operator) {
                    case '+':
                        result = stack.tokens[stack.top].value + token.value;
                        break;
                    case '-':
                        result = stack.tokens[stack.top].value - token.value;
                        break;
                    case '*':
                        result = stack.tokens[stack.top].value * token.value;
                        break;
                    case '/':
                        result = stack.tokens[stack.top].value / token.value;
                        break;
                    case '^':
                        result = pow(stack.tokens[stack.top].value, token.value);
                        break;
                }

                stack.tokens[stack.top].value = result;
            }

            Token token;
            token.value = 0;
            token.operator = *p;
            push(&stack, token);

            p++;
        } else {
            p++;
        }
    }

    while (stack.top != -1) {
        Token token = pop(&stack);
        double result;
        switch (token.operator) {
            case '+':
                result = stack.tokens[stack.top].value + token.value;
                break;
            case '-':
                result = stack.tokens[stack.top].value - token.value;
                break;
            case '*':
                result = stack.tokens[stack.top].value * token.value;
                break;
            case '/':
                result = stack.tokens[stack.top].value / token.value;
                break;
            case '^':
                result = pow(stack.tokens[stack.top].value, token.value);
                break;
        }

        stack.tokens[stack.top].value = result;
    }

    return stack.tokens[0].value;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <expression>\n", argv[0]);
        return 1;
    }

    char *expression = argv[1];
    double result = evaluate(expression);

    printf("%.2lf\n", result);

    return 0;
}