//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TOKENS 100

typedef struct Token {
    char *name;
    int value;
    struct Token *next;
} Token;

Token *createToken(char *name, int value) {
    Token *newToken = malloc(sizeof(Token));
    newToken->name = strdup(name);
    newToken->value = value;
    newToken->next = NULL;
    return newToken;
}

void extractMetadata(char *text) {
    char *tokens[MAX_TOKENS];
    int nTokens = 0;
    Token *tokenList = NULL;

    // Tokenize the text
    tokens[nTokens++] = strtok(text, ":");
    while (tokens[nTokens - 1] != NULL) {
        tokens[nTokens++] = strtok(NULL, ":");
    }

    // Create a token list
    for (int i = 0; i < nTokens; i++) {
        tokenList = createToken(tokens[i], i);
        if (tokenList != NULL) {
            tokenList->next = tokenList;
        }
    }

    // Print the token list
    tokenList = tokenList->next;
    while (tokenList) {
        printf("%s: %d\n", tokenList->name, tokenList->value);
        tokenList = tokenList->next;
    }
}

int main() {
    char *text = "Name: Donald Knuth\nEmail: don@knuth.com\nPhone: 123-456-7890";
    extractMetadata(text);

    return 0;
}