//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TOKENS 1024

typedef struct Token {
    char *name;
    char *value;
    struct Token *next;
} Token;

Token *tokenize(char *str) {
    char *p = str;
    Token *head = NULL;
    Token *tail = NULL;

    while (p) {
        char *token = strchr(p, '=');
        if (token) {
            *token = '\0';
            Token *newToken = malloc(sizeof(Token));
            newToken->name = strdup(p);
            newToken->value = strdup(token + 1);
            newToken->next = NULL;

            if (head) {
                tail->next = newToken;
                tail = newToken;
            } else {
                head = newToken;
                tail = newToken;
            }
        } else {
            break;
        }

        p = token + 1;
    }

    return head;
}

int main() {
    char *str = "foo=bar,baz=quux";
    Token *tokens = tokenize(str);

    while (tokens) {
        printf("Name: %s, Value: %s\n", tokens->name, tokens->value);
        tokens = tokens->next;
    }

    return 0;
}