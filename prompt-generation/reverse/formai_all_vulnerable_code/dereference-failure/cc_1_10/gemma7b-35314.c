//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1024

struct Token {
    char *lexeme;
    int lineNumber;
    int columnNumber;
    struct Token *next;
};

void extractMetadata(char *sourceCode) {
    struct Token *tokens = NULL;
    char *sourceCodePtr = sourceCode;
    char *token = NULL;
    int lineNumber = 1;
    int columnNumber = 1;

    while (sourceCodePtr) {
        token = strsep(sourceCodePtr, ":");
        if (token) {
            struct Token *newToken = malloc(sizeof(struct Token));
            newToken->lexeme = strdup(token);
            newToken->lineNumber = lineNumber;
            newToken->columnNumber = columnNumber;
            newToken->next = tokens;
            tokens = newToken;
        }

        sourceCodePtr += strcspn(sourceCodePtr, "\n");
        lineNumber++;
        columnNumber = 1;
    }

    // Print the extracted tokens
    for (struct Token *token = tokens; token; token = token->next) {
        printf("L%d, C%d: %s\n", token->lineNumber, token->columnNumber, token->lexeme);
    }

    free(tokens);
}

int main() {
    char *sourceCode = "foo: bar\n\nhello: world\n";
    extractMetadata(sourceCode);

    return 0;
}