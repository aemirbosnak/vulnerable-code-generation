//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_LENGTH 1024
#define TOKEN_COUNT 10

typedef enum {
    TOKEN_IDENTIFIER,
    TOKEN_KEYWORD,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_OPERATOR
} TokenType;

typedef struct {
    TokenType type;
    int line;
    int col;
    char *text;
} Token;

static void lexer(char *src, Token *tokens, int *token_count) {
    int i = 0;
    int line = 1;
    int col = 1;
    char c;

    while (i < strlen(src)) {
        c = src[i];

        if (isalpha(c) || c == '_') {
            // Identifier or keyword
            tokens[*token_count].type = TOKEN_IDENTIFIER;
            tokens[*token_count].line = line;
            tokens[*token_count].col = col;
            tokens[*token_count].text = src + i;
            (*token_count)++;
        } else if (isdigit(c) || c == '.') {
            // Number
            tokens[*token_count].type = TOKEN_NUMBER;
            tokens[*token_count].line = line;
            tokens[*token_count].col = col;
            tokens[*token_count].text = src + i;
            (*token_count)++;
        } else if (c == '"') {
            // String
            int j = i + 1;
            int k = strlen(src) - j;
            tokens[*token_count].type = TOKEN_STRING;
            tokens[*token_count].line = line;
            tokens[*token_count].col = col;
            tokens[*token_count].text = src + j;
            (*token_count)++;
            i = k;
        } else if (c == '(' || c == '[' || c == ']' || c == '}') {
            // Operator
            tokens[*token_count].type = TOKEN_OPERATOR;
            tokens[*token_count].line = line;
            tokens[*token_count].col = col;
            tokens[*token_count].text = src + i;
            (*token_count)++;
        }

        i++;
        line++;
        col = 1;
    }
}

int main() {
    char src[] = "int main() { return 42; }";
    Token tokens[TOKEN_COUNT];
    int token_count = 0;

    lexer(src, tokens, &token_count);

    for (int i = 0; i < token_count; i++) {
        printf("%d:%d: %s\n", tokens[i].line, tokens[i].col, tokens[i].text);
    }

    return 0;
}