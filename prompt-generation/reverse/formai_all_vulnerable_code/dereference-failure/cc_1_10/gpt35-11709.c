//FormAI DATASET v1.0 Category: Syntax parsing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void expression();
void term();
void factor();

char token;
char *input;

void error() {
    printf("Invalid Syntax\n");
    exit(1);
}

void next_token() {
    token = *input++;
}

void match(char expected_token) {
    if (token == expected_token) {
        next_token();
    } else {
        error();
    }
}

void factor() {
    if (token >= '0' && token <= '9') {
        next_token();
    } else if (token == '(') {
        next_token();
        expression();
        match(')');
    } else {
        error();
    }
}

void term() {
    factor();
    while (token == '*' || token == '/') {
        next_token();
        factor();
    }
}

void expression() {
    term();
    while (token == '+' || token == '-') {
        next_token();
        term();
    }
}

int main() {
    input = malloc(sizeof(char) * 256);
    printf("Enter an expression: ");
    fgets(input, 256, stdin);
    next_token();
    expression();
    if (token == '\0') {
        printf("Valid Syntax\n");
    } else {
        error();
    }
    free(input);
    return 0;
}