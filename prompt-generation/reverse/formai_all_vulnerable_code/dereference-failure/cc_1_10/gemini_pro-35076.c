//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

typedef enum {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_KEYWORD,
    TOKEN_OPERATOR,
    TOKEN_PUNCTUATOR,
} TokenType;

typedef struct {
    TokenType type;
    char *value;
} Token;

typedef struct {
    Token *tokens;
    int num_tokens;
} TokenList;

TokenList *tokenize(char *input) {
    TokenList *tokens = malloc(sizeof(TokenList));
    tokens->tokens = malloc(MAX_TOKENS * sizeof(Token));
    tokens->num_tokens = 0;

    char *token_start = input;
    int token_length = 0;

    while (*input != '\0') {
        if (isspace(*input)) {
            if (token_length > 0) {
                tokens->tokens[tokens->num_tokens].type = TOKEN_IDENTIFIER;
                tokens->tokens[tokens->num_tokens].value = strndup(token_start, token_length);
                tokens->num_tokens++;
            }
            token_start = input + 1;
            token_length = 0;
        } else if (isdigit(*input)) {
            if (token_length == 0) {
                token_start = input;
            }
            token_length++;
        } else if (isalpha(*input)) {
            if (token_length == 0) {
                token_start = input;
            }
            token_length++;
        } else {
            if (token_length > 0) {
                tokens->tokens[tokens->num_tokens].type = TOKEN_IDENTIFIER;
                tokens->tokens[tokens->num_tokens].value = strndup(token_start, token_length);
                tokens->num_tokens++;
            }
            tokens->tokens[tokens->num_tokens].type = TOKEN_PUNCTUATOR;
            tokens->tokens[tokens->num_tokens].value = strndup(input, 1);
            tokens->num_tokens++;
            token_start = input + 1;
            token_length = 0;
        }
        input++;
    }

    if (token_length > 0) {
        tokens->tokens[tokens->num_tokens].type = TOKEN_IDENTIFIER;
        tokens->tokens[tokens->num_tokens].value = strndup(token_start, token_length);
        tokens->num_tokens++;
    }

    return tokens;
}

void free_tokens(TokenList *tokens) {
    for (int i = 0; i < tokens->num_tokens; i++) {
        free(tokens->tokens[i].value);
    }
    free(tokens->tokens);
    free(tokens);
}

int main() {
    char *input = "int main() { return 0; }";

    TokenList *tokens = tokenize(input);

    for (int i = 0; i < tokens->num_tokens; i++) {
        printf("%s\n", tokens->tokens[i].value);
    }

    free_tokens(tokens);

    return 0;
}