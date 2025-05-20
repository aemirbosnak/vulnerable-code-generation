//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_TOKENS 10

typedef struct Token {
    char *lexeme;
    int lineNumber;
    struct Token *next;
} Token;

Token *createToken(char *lexeme, int lineNumber) {
    Token *token = malloc(sizeof(Token));
    token->lexeme = strdup(lexeme);
    token->lineNumber = lineNumber;
    token->next = NULL;
    return token;
}

void parseSyntax(char *source) {
    // 1. Tokenize the source code
    char *p = source;
    Token *tokens = NULL;
    int i = 0;
    while (p) {
        char *lexeme = malloc(MAX_TOKENS);
        *lexeme = '\0';
        int lineNumber = i;
        while (*p && !isspace(*p) && *p != ';') {
            *lexeme = *p;
            p++;
        }
        tokens = createToken(lexeme, lineNumber);
        if (tokens) {
            tokens->next = tokens;
        }
        i++;
    }

    // 2. Analyze the tokens
    for (tokens = tokens; tokens; tokens = tokens->next) {
        printf("%s (line %d)\n", tokens->lexeme, tokens->lineNumber);
    }
}

int main() {
    parseSyntax("int x = 10;");
    parseSyntax("func() {}");
    return 0;
}