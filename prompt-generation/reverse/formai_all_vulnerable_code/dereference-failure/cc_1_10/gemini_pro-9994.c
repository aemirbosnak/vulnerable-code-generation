//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *str;
    int len;
} Token;

typedef struct {
    Token tokens[MAX_TOKENS];
    int num_tokens;
} TokenList;

TokenList *tokenize(char *str) {
    TokenList *tokens = malloc(sizeof(TokenList));
    tokens->num_tokens = 0;

    char *ptr = str;
    while (*ptr != '\0') {
        if (*ptr == ' ' || *ptr == '\t' || *ptr == '\n') {
            ptr++;
            continue;
        }

        char *start = ptr;
        while (*ptr != ' ' && *ptr != '\t' && *ptr != '\n' && *ptr != '\0') {
            ptr++;
        }

        Token token = {
            .str = malloc(ptr - start + 1),
            .len = ptr - start
        };
        memcpy(token.str, start, token.len);
        token.str[token.len] = '\0';

        tokens->tokens[tokens->num_tokens++] = token;
    }

    return tokens;
}

void free_tokens(TokenList *tokens) {
    for (int i = 0; i < tokens->num_tokens; i++) {
        free(tokens->tokens[i].str);
    }
    free(tokens);
}

int main() {
    char *str = "int main() { printf(\"Hello, world!\n\"); }";
    TokenList *tokens = tokenize(str);

    for (int i = 0; i < tokens->num_tokens; i++) {
        printf("%s\n", tokens->tokens[i].str);
    }

    free_tokens(tokens);

    return 0;
}