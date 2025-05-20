//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_LEN 100
#define TOKEN_TYPES (1 << 0)  // INT
#define TOKEN_TYPES (1 << 1)  // VAR
#define TOKEN_TYPES (1 << 2)  // FUNC

typedef struct token_t {
    char *name;
    int type;
} token_t;

void parse_token(char *src, token_t *tok) {
    int i, len;

    len = strcspn(src, " \t\n");
    tok->name = malloc(len + 1);
    strncpy(tok->name, src, len);
    tok->name[len] = '\0';

    for (i = 0; i < len; i++) {
        if (src[i] == ' ') {
            tok->type |= TOKEN_TYPES;
        }
    }
}

void parse_program(char *src) {
    char *token;
    token_t tok;

    parse_token(src, &tok);

    while (1) {
        switch (tok.type) {
            case TOKEN_TYPES:
                printf("INT: %s\n", tok.name);
                break;
            case TOKEN_TYPES << 1:
                printf("VAR: %s\n", tok.name);
                break;
            case TOKEN_TYPES << 2:
                printf("FUNC: %s\n", tok.name);
                break;
            default:
                printf("UNKNOWN: %s\n", tok.name);
                break;
        }

        parse_token(src, &tok);
    }
}

int main() {
    char src[] = "INT x = 5; VAR y = 10; FUNC z(INT a, VAR b) { return a + b; }";
    parse_program(src);
    return 0;
}