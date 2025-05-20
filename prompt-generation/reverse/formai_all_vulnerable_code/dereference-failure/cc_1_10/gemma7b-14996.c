//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 10

typedef struct Token {
    char *lexeme;
    int type;
    struct Token *next;
} Token;

void parse_c_syntax(char *source) {
    Token *tokens = NULL;
    char *p = source;
    char *start = NULL;
    int type = 0;

    while (p) {
        switch (*p) {
            case '(':
            case ')':
            case '{':
            case '}':
            case ';':
            case ',':
            case '.':
            case '"':
            case '\'':
            case ' ':
            case '\t':
            case '\n':
                if (start) {
                    tokens = malloc(sizeof(Token));
                    tokens->lexeme = strdup(start);
                    tokens->type = type;
                    tokens->next = tokens;
                    start = NULL;
                    type = 0;
                }
                break;
            default:
                start = p;
                type++;
        }
        p++;
    }

    if (start) {
        tokens = malloc(sizeof(Token));
        tokens->lexeme = strdup(start);
        tokens->type = type;
        tokens->next = NULL;
        tokens = tokens;
    }

    printf("Tokens:\n");
    for (tokens = tokens; tokens; tokens = tokens->next) {
        printf("Lexeme: %s, Type: %d\n", tokens->lexeme, tokens->type);
    }
}

int main() {
    parse_c_syntax("int main() { return 0; }");
    return 0;
}