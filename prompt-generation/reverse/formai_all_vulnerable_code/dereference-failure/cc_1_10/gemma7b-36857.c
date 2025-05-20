//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1024

typedef struct Token {
    char *name;
    struct Token *next;
} Token;

Token *tokenize(char *str) {
    Token *head = NULL;
    char *p = str;
    char *q;

    while (*p) {
        q = p;
        while (*q && !isalnum(*q)) {
            q++;
        }
        if (head == NULL) {
            head = malloc(sizeof(Token));
            head->name = malloc(q - p + 1);
            memcpy(head->name, p, q - p);
            head->name[q - p] = '\0';
            head->next = NULL;
        } else {
            Token *new_token = malloc(sizeof(Token));
            new_token->name = malloc(q - p + 1);
            memcpy(new_token->name, p, q - p);
            new_token->name[q - p] = '\0';
            new_token->next = NULL;
            head->next = new_token;
            head = new_token;
        }
        p = q;
    }

    return head;
}

int main() {
    char *str = "This is a sample string with some tokens. They are: foo, bar, and baz.";
    Token *tokens = tokenize(str);

    printf("Tokens:");
    for (Token *token = tokens; token; token = token->next) {
        printf(" %s", token->name);
    }

    return 0;
}