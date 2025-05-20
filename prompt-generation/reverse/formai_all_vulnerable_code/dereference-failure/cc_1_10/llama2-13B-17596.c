//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EXPR_LENGTH 100
#define TOKEN_COUNT 6

// Token types
enum token_type {
    TOKEN_NUMBER,
    TOKEN_ADD,
    TOKEN_SUB,
    TOKEN_MUL,
    TOKEN_DIV,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
};

// Token struct
struct token {
    char *str;
    enum token_type type;
};

// Expression struct
struct expression {
    struct token *tokens;
    int len;
};

// Parse expression
struct expression *parse_expression(char *str) {
    struct expression *expr = malloc(sizeof(struct expression));
    expr->tokens = malloc(TOKEN_COUNT * sizeof(struct token));
    int i = 0;

    // Parse tokens
    for (; i < TOKEN_COUNT; i++) {
        char c = str[i];
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            expr->tokens[i].type = TOKEN_ADD;
        } else if (c == '(' || c == ')') {
            expr->tokens[i].type = TOKEN_LPAREN;
        } else if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5') {
            expr->tokens[i].type = TOKEN_NUMBER;
        } else {
            expr->tokens[i].type = TOKEN_SUB;
        }
    }

    // Check for errors
    if (str[TOKEN_COUNT] != ')') {
        printf("Error: missing ')' token\n");
        return NULL;
    }

    // Evaluate expression
    int result = evaluate(expr);

    // Free memory
    free(expr->tokens);
    free(expr);

    return result;
}

// Evaluate expression
int evaluate(struct expression *expr) {
    int result = 0;

    // Evaluate tokens
    for (int i = 0; i < TOKEN_COUNT; i++) {
        struct token *token = expr->tokens + i;
        if (token->type == TOKEN_ADD) {
            result += evaluate(expr->tokens + i + 1) + evaluate(expr->tokens + i + 2);
        } else if (token->type == TOKEN_SUB) {
            result -= evaluate(expr->tokens + i + 1) - evaluate(expr->tokens + i + 2);
        } else if (token->type == TOKEN_MUL) {
            result *= evaluate(expr->tokens + i + 1);
        } else if (token->type == TOKEN_DIV) {
            result /= evaluate(expr->tokens + i + 1);
        }
    }

    return result;
}

int main() {
    char str[] = "+ 3 * 4 - 2 + 5";
    struct expression *expr = parse_expression(str);
    if (expr == NULL) {
        return 1;
    }

    printf("Result: %d\n", evaluate(expr));

    return 0;
}