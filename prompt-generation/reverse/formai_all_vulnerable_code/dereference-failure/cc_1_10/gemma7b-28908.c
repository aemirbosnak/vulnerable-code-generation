//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100

typedef struct Token {
    char *lexeme;
    int type;
    struct Token *next;
} Token;

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
    exit(1);
}

int main() {
    char *source = "int x = 10; float y = 3.14;";
    Token *tokens = NULL;

    // Tokenization
    char *p = source;
    while (*p) {
        char *lexeme = malloc(MAX_TOKENS);
        int type = 0;

        // Identifier
        if (isalnum(*p) && *p != '_') {
            type = 1;
            while (isalnum(*p)) {
                *lexeme++ = *p;
                p++;
            }
            *lexeme = NULL;
        }

        // Number
        else if (isdigit(*p)) {
            type = 2;
            while (isdigit(*p)) {
                *lexeme++ = *p;
                p++;
            }
            *lexeme = NULL;
        }

        // Operator
        else if (strchr("+-*/%=~", *p) != NULL) {
            type = 3;
            *lexeme = *p;
            p++;
        }

        // Punctuation
        else if (strchr("()[]{}|", *p) != NULL) {
            type = 4;
            *lexeme = *p;
            p++;
        }

        Token *new_token = malloc(sizeof(Token));
        new_token->lexeme = lexeme;
        new_token->type = type;
        new_token->next = tokens;
        tokens = new_token;
    }

    // Print tokens
    for (Token *token = tokens; token; token = token->next) {
        printf("%s (%d)\n", token->lexeme, token->type);
    }

    return 0;
}