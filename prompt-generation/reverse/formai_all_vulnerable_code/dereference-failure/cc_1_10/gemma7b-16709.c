//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_TOKENS 1024

typedef struct Token {
    char type;
    char value[MAX_TOKENS];
} Token;

Token *lex(char *source) {
    Token *tokens = NULL;
    char *p = source;
    int i = 0;

    while (*p) {
        switch (*p) {
            case '(':
            case ')':
            case '{':
            case '}':
            case ',':
            case ';':
            case '.':
            case ' ':
                tokens = realloc(tokens, (i + 1) * sizeof(Token));
                tokens[i].type = *p;
                tokens[i].value[0] = '\0';
                i++;
                break;
            default:
                tokens = realloc(tokens, (i + 1) * sizeof(Token));
                tokens[i].type = 'V';
                strcpy(tokens[i].value, p);
                i++;
        }
        p++;
    }

    return tokens;
}

int main() {
    char source[] = "int main() { return 0; }";
    Token *tokens = lex(source);

    for (int i = 0; tokens[i].type != '\0'; i++) {
        printf("%c: %s\n", tokens[i].type, tokens[i].value);
    }

    free(tokens);

    return 0;
}