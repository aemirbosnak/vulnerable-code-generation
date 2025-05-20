//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: decentralized
#include <stdio.h>
#include <string.h>

#define MAX_TOKENS 100

typedef struct Token {
    char *lexeme;
    int lineNumber;
    struct Token *next;
} Token;

Token **parseCSyntax(char *sourceCode) {
    char *p = sourceCode;
    Token **tokens = NULL;
    int tokenCount = 0;

    // Tokenization
    while (p) {
        // Identifier
        if (*p >= 'a' && *p <= 'z') {
            Token *newToken = malloc(sizeof(Token));
            newToken->lexeme = strdup(p);
            newToken->lineNumber = tokenCount;
            newToken->next = tokens;
            tokens = &newToken;
            tokenCount++;
        }
        // Keyword
        else if (*p >= 'A' && *p <= 'Z') {
            Token *newToken = malloc(sizeof(Token));
            newToken->lexeme = strdup(p);
            newToken->lineNumber = tokenCount;
            newToken->next = tokens;
            tokens = &newToken;
            tokenCount++;
        }
        // Operator
        else if (*p >= '+' && *p <= '/') {
            Token *newToken = malloc(sizeof(Token));
            newToken->lexeme = strdup(p);
            newToken->lineNumber = tokenCount;
            newToken->next = tokens;
            tokens = &newToken;
            tokenCount++;
        }
        // Parentheses
        else if (*p == '(' || *p == ')') {
            Token *newToken = malloc(sizeof(Token));
            newToken->lexeme = strdup(p);
            newToken->lineNumber = tokenCount;
            newToken->next = tokens;
            tokens = &newToken;
            tokenCount++;
        }
        // Comments
        else if (*p == '/' && *(p+1) == '/') {
            p++;
        }
        p++;
    }

    return tokens;
}

int main() {
    char *sourceCode = "int main() { return 0; }";
    Token **tokens = parseCSyntax(sourceCode);

    for (Token *token = tokens; token; token = token->next) {
        printf("L%d: %s\n", token->lineNumber, token->lexeme);
    }

    return 0;
}