//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: curious
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1024

typedef struct Token {
    char *lexeme;
    int lineNumber;
    struct Token *next;
} Token;

Token *tokenize(char *source) {
    Token *head = NULL;
    char *p = source;
    char *start = NULL;

    while (*p) {
        if (isspace(*p)) {
            if (start) {
                Token *newToken = malloc(sizeof(Token));
                newToken->lexeme = strdup(start);
                newToken->lineNumber = 1;
                newToken->next = head;
                head = newToken;
            }
            start = NULL;
        } else if (start == NULL) {
            start = p;
        }
        p++;
    }

    if (start) {
        Token *newToken = malloc(sizeof(Token));
        newToken->lexeme = strdup(start);
        newToken->lineNumber = 1;
        newToken->next = head;
        head = newToken;
    }

    return head;
}

int main() {
    char source[] = "This is a sample text. It has some tokens. And a few more.";
    Token *tokens = tokenize(source);

    printf("Tokens:\n");
    for (Token *token = tokens; token; token = token->next) {
        printf("  %s (line %d)\n", token->lexeme, token->lineNumber);
    }

    return 0;
}