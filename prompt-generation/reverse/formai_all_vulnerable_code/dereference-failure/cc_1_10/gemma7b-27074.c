//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1024

typedef struct Token {
    char *lexeme;
    int lineNumber;
    struct Token *next;
} Token;

Token *parseCSyntax(char *sourceCode) {
    // Tokenization
    char **tokens = malloc(MAX_TOKENS * sizeof(char *));
    int tokenCount = 0;
    char *p = sourceCode;
    while (p) {
        // Identifier
        if (*p >= 'a' && *p <= 'z') {
            tokens[tokenCount++] = strdup(p);
        }
        // Keyword
        else if (*p >= 'A' && *p <= 'Z') {
            tokens[tokenCount++] = strdup(p);
        }
        // Operator
        else if (*p >= '+') {
            tokens[tokenCount++] = strdup(p);
        }
        // Punctuation
        else if (*p >= ':' && *p <= '/') {
            tokens[tokenCount++] = strdup(p);
        }
        p++;
    }

    // Lexical Analysis
    Token *head = NULL;
    for (int i = 0; i < tokenCount; i++) {
        Token *token = malloc(sizeof(Token));
        token->lexeme = strdup(tokens[i]);
        token->lineNumber = i + 1;
        token->next = head;
        head = token;
    }

    free(tokens);

    return head;
}

int main() {
    char *sourceCode = "int main() { return 0; }";
    Token *tokens = parseCSyntax(sourceCode);

    // Print tokens
    for (Token *token = tokens; token; token = token->next) {
        printf("%s (line %d)\n", token->lexeme, token->lineNumber);
    }

    return 0;
}