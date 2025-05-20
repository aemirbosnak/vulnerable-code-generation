//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100

typedef struct Token {
    char *lexeme;
    int lineNumber;
    struct Token *next;
} Token;

Token *tokenize(char *source, int lineNumber) {
    Token *head = NULL;
    char *p = source;
    char *start = NULL;
    int i = 0;

    while (*p) {
        switch (*p) {
            case ' ':
            case '\t':
            case '\n':
                if (start) {
                    Token *newToken = malloc(sizeof(Token));
                    newToken->lexeme = strdup(start);
                    newToken->lineNumber = lineNumber;
                    newToken->next = head;
                    head = newToken;
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
        Token *newToken = malloc(sizeof(Token));
        newToken->lexeme = strdup(start);
        newToken->lineNumber = lineNumber;
        newToken->next = head;
        head = newToken;
    }

    return head;
}

int main() {
    char source[] = "This is a sample text with some keywords and comments.";
    int lineNumber = 1;

    Token *tokens = tokenize(source, lineNumber);

    while (tokens) {
        printf("L%d: %s\n", tokens->lineNumber, tokens->lexeme);
        tokens = tokens->next;
    }

    return 0;
}