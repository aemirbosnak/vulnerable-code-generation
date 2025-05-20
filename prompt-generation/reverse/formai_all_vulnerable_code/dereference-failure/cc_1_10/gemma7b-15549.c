//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int lineNumber = 1;

    while (p) {
        switch (*p) {
            case ';':
            case '(':
            case ')':
            case ',':
            case '.':
            case '"':
            case '#':
            case ' ':
                if (start) {
                    Token *token = malloc(sizeof(Token));
                    token->lexeme = strdup(start);
                    token->lineNumber = lineNumber;
                    token->next = head;
                    head = token;
                }
                start = NULL;
                break;
            default:
                start = p;
        }

        p++;
        if (*p == '\n') lineNumber++;
    }

    if (start) {
        Token *token = malloc(sizeof(Token));
        token->lexeme = strdup(start);
        token->lineNumber = lineNumber;
        token->next = head;
        head = token;
    }

    return head;
}

int main() {
    char *source = "int main() {\n"
                     "  return 0;\n"
                     "}";

    Token *tokens = tokenize(source);

    for (Token *token = tokens; token; token = token->next) {
        printf("L%d: %s\n", token->lineNumber, token->lexeme);
    }

    return 0;
}