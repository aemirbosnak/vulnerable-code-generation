//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100

typedef struct {
    char *str;
    int len;
} Token;

typedef struct {
    Token *tokens;
    int num_tokens;
} TokenList;

TokenList *tokenize(char *str) {
    TokenList *tokens = malloc(sizeof(TokenList));
    tokens->tokens = malloc(sizeof(Token) * MAX_TOKENS);
    tokens->num_tokens = 0;

    char *start = str;
    while (*str != '\0') {
        if (*str == ' ' || *str == '\t' || *str == '\n') {
            if (str != start) {
                tokens->tokens[tokens->num_tokens].str = start;
                tokens->tokens[tokens->num_tokens].len = str - start;
                tokens->num_tokens++;
            }
            start = str + 1;
        }
        str++;
    }

    if (str != start) {
        tokens->tokens[tokens->num_tokens].str = start;
        tokens->tokens[tokens->num_tokens].len = str - start;
        tokens->num_tokens++;
    }

    return tokens;
}

void free_tokens(TokenList *tokens) {
    for (int i = 0; i < tokens->num_tokens; i++) {
        free(tokens->tokens[i].str);
    }
    free(tokens->tokens);
    free(tokens);
}

int main() {
    char *str = "This is a test string";
    TokenList *tokens = tokenize(str);

    for (int i = 0; i < tokens->num_tokens; i++) {
        printf("Token %d: %.*s\n", i, tokens->tokens[i].len, tokens->tokens[i].str);
    }

    free_tokens(tokens);

    return 0;
}