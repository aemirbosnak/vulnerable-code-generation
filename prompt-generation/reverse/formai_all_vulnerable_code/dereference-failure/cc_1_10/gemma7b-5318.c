//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1024

typedef struct Token {
    char *lexeme;
    struct Token *next;
} Token;

Token *tokenize(char *source) {
    Token *head = NULL;
    char *p = source;
    char *start = NULL;
    int i = 0;

    while (*p) {
        switch (*p) {
            case ' ':
            case '\n':
            case '\t':
                if (start) {
                    Token *new_token = malloc(sizeof(Token));
                    new_token->lexeme = strdup(start);
                    new_token->next = head;
                    head = new_token;
                }
                start = NULL;
                break;
            default:
                start = p;
                i++;
                break;
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
    char *source = "This is a sample text with a few tokens.";
    Token *tokens = tokenize(source);

    printf("Tokens:");
    for (Token *token = tokens; token; token = token->next) {
        printf(" %s", token->lexeme);
    }

    return 0;
}