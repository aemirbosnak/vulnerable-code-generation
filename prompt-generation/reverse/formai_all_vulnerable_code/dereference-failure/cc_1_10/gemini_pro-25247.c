//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100

typedef enum {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_KEYWORD,
    TOKEN_OPERATOR,
    TOKEN_PUNCTUATOR
} token_type;

typedef struct {
    token_type type;
    char *value;
} token;

typedef struct {
    int count;
    token tokens[MAX_TOKENS];
} token_list;

token_list *tokenize(char *input) {
    token_list *tokens = malloc(sizeof(token_list));
    tokens->count = 0;

    char *start = input;
    while (*input != '\0') {
        if (*input == ' ' || *input == '\t' || *input == '\n') {
            // Skip whitespace
            input++;
            start = input;
        } else if (isalpha(*input)) {
            // Identifier or keyword
            input++;
            while (isalnum(*input) || *input == '_') {
                input++;
            }
            int length = input - start;
            char *value = malloc(length + 1);
            strncpy(value, start, length);
            value[length] = '\0';
            token token = {TOKEN_IDENTIFIER, value};
            tokens->tokens[tokens->count++] = token;
        } else if (isdigit(*input)) {
            // Number
            input++;
            while (isdigit(*input)) {
                input++;
            }
            int length = input - start;
            char *value = malloc(length + 1);
            strncpy(value, start, length);
            value[length] = '\0';
            token token = {TOKEN_NUMBER, value};
            tokens->tokens[tokens->count++] = token;
        } else if (*input == '"') {
            // String
            input++;
            start = input;
            while (*input != '"' && *input != '\0') {
                input++;
            }
            int length = input - start;
            char *value = malloc(length + 1);
            strncpy(value, start, length);
            value[length] = '\0';
            token token = {TOKEN_STRING, value};
            tokens->tokens[tokens->count++] = token;
        } else {
            // Operator or punctuator
            char *operators = "+-*/%()[]{};,";
            char operator = *input;
            if (strchr(operators, operator) != NULL) {
                token token = {TOKEN_OPERATOR, &operator};
                tokens->tokens[tokens->count++] = token;
            } else {
                token token = {TOKEN_PUNCTUATOR, &operator};
                tokens->tokens[tokens->count++] = token;
            }
            input++;
        }
    }

    token token = {TOKEN_EOF, NULL};
    tokens->tokens[tokens->count++] = token;

    return tokens;
}

void print_tokens(token_list *tokens) {
    for (int i = 0; i < tokens->count; i++) {
        token token = tokens->tokens[i];
        switch (token.type) {
            case TOKEN_EOF:
                printf("EOF\n");
                break;
            case TOKEN_IDENTIFIER:
                printf("IDENTIFIER: %s\n", token.value);
                break;
            case TOKEN_NUMBER:
                printf("NUMBER: %s\n", token.value);
                break;
            case TOKEN_STRING:
                printf("STRING: %s\n", token.value);
                break;
            case TOKEN_KEYWORD:
                printf("KEYWORD: %s\n", token.value);
                break;
            case TOKEN_OPERATOR:
                printf("OPERATOR: %c\n", *token.value);
                break;
            case TOKEN_PUNCTUATOR:
                printf("PUNCTUATOR: %c\n", *token.value);
                break;
        }
    }
}

int main() {
    char *input = "int main() { printf(\"Hello, world!\n\"); }";

    token_list *tokens = tokenize(input);
    print_tokens(tokens);

    return 0;
}