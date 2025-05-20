//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100

typedef struct Token {
    char *lexeme;
    struct Token *next;
} Token;

Token *tokenize(char *source) {
    Token *head = NULL;
    char *p = source;
    char *start = NULL;

    while (p) {
        if (*p == ' ' || *p == '\n' || *p == '\t') {
            if (start) {
                Token *new_token = malloc(sizeof(Token));
                new_token->lexeme = strdup(start);
                new_token->next = head;
                head = new_token;
            }
            start = NULL;
        } else if (start == NULL) {
            start = p;
        }
        p++;
    }

    if (start) {
        Token *new_token = malloc(sizeof(Token));
        new_token->lexeme = strdup(start);
        new_token->next = head;
        head = new_token;
    }

    return head;
}

int main() {
    char *source = "Hello, world!";
    Token *tokens = tokenize(source);

    while (tokens) {
        printf("%s ", tokens->lexeme);
        tokens = tokens->next;
    }

    printf("\n");

    return 0;
}