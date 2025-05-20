//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: curious
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
            Token *new_token = malloc(sizeof(Token));
            new_token->name = strdup(p);
            new_token->value = strdup(token + 1);
            new_token->next = NULL;

            if (head) {
                tail->next = new_token;
                tail = new_token;
            } else {
                head = new_token;
                tail = new_token;
            }
        } else {
            p = strchr(p, ';');
            if (p) {
                *p = '\0';
                Token *new_token = malloc(sizeof(Token));
                new_token->name = strdup(p);
                new_token->value = strdup("");
                new_token->next = NULL;

                if (head) {
                    tail->next = new_token;
                    tail = new_token;
                } else {
                    head = new_token;
                    tail = new_token;
                }
            } else {
                break;
            }
        }
    }

    return head;
}

int main() {
    char str[] = "foo=bar; baz=quux";
    Token *tokens = tokenize(str);

    for (Token *token = tokens; token; token = token->next) {
        printf("%s = %s\n", token->name, token->value);
    }

    return 0;
}