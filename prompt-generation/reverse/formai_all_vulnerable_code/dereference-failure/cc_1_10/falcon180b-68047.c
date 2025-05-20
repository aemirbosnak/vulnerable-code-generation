//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LEN 100

typedef struct {
    char *token;
    int len;
} Token;

Token *tokenize(char *str) {
    int i = 0;
    Token *tokens = calloc(MAX_TOKENS, sizeof(Token));

    char *token = strtok(str, " ");
    while (token!= NULL) {
        tokens[i].token = token;
        tokens[i].len = strlen(token);
        i++;

        if (i == MAX_TOKENS) {
            printf("Error: Too many tokens\n");
            exit(1);
        }

        token = strtok(NULL, " ");
    }

    tokens[i].token = NULL;
    tokens[i].len = 0;

    return tokens;
}

void printTokens(Token *tokens) {
    for (int i = 0; tokens[i].token!= NULL; i++) {
        printf("Token: %s\n", tokens[i].token);
    }
}

int main() {
    char input[MAX_TOKEN_LEN];

    while (1) {
        printf("Enter a sentence: ");
        fgets(input, MAX_TOKEN_LEN, stdin);

        Token *tokens = tokenize(input);
        printTokens(tokens);

        free(tokens);
    }

    return 0;
}