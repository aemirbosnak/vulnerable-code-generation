//FormAI DATASET v1.0 Category: Syntax parsing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024

typedef enum {
    TOKEN_NONE,
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN
} TokenType;

typedef struct {
    TokenType type;
    int value;
    char op;
} Token;

Token tokenize(char *input);
int parse_expression(char **input_ptr);

int main(void) {
    char input[MAX_INPUT_SIZE];
    printf("Enter an expression: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    Token token = tokenize(input);
    int result = parse_expression(&input);
    printf("%d\n", result);
    return 0;
}

Token tokenize(char *input) {
    Token token = {TOKEN_NONE, 0, '\0'};

    if (*input == '\0') {
        return token;
    }

    while (isspace(*input)) {
        input++;
    }

    if (isdigit(*input)) {
        token.type = TOKEN_NUMBER;
        token.value = strtol(input, &input, 10);
    } else if (*input == '+' || *input == '-' || *input == '*' || *input == '/') {
        token.type = TOKEN_OPERATOR;
        token.op = *input;
        input++;
    } else if (*input == '(') {
        token.type = TOKEN_LEFT_PAREN;
        input++;
    } else if (*input == ')') {
        token.type = TOKEN_RIGHT_PAREN;
        input++;
    }

    return token;
}

int parse_expression(char **input_ptr) {
    int value = 0;
    Token token = tokenize(*input_ptr);

    if (token.type == TOKEN_NONE) {
        return value;
    }

    if (token.type == TOKEN_NUMBER) {
        value = token.value;
        token = tokenize(*input_ptr);
    }

    while (token.type == TOKEN_OPERATOR) {
        char op = token.op;
        token = tokenize(*input_ptr);

        int right = 0;
        if (token.type == TOKEN_NUMBER) {
            right = token.value;
            token = tokenize(*input_ptr);
        } else if (token.type == TOKEN_LEFT_PAREN) {
            right = parse_expression(input_ptr);
            token = tokenize(*input_ptr);
        }

        switch (op) {
            case '+': value += right; break;
            case '-': value -= right; break;
            case '*': value *= right; break;
            case '/': value /= right; break;
        }
    }

    return value;
}