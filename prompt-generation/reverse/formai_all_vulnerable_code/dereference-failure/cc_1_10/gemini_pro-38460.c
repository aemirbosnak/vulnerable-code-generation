//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: retro
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    TOKEN_INT,
    TOKEN_FLOAT,
    TOKEN_STRING,
    TOKEN_IDENTIFIER,
    TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    char *value;
} Token;

Token *currentToken;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

Token *getToken() {
    if (currentToken == NULL) {
        currentToken = (Token *) malloc(sizeof(Token));
    }

    int c = getchar();
    while (c == ' ' || c == '\n' || c == '\t') {
        c = getchar();
    }

    if (c == EOF) {
        currentToken->type = TOKEN_EOF;
        currentToken->value = NULL;
        return currentToken;
    }

    if (isdigit(c)) {
        currentToken->type = TOKEN_INT;
        currentToken->value = malloc(sizeof(char) * 100);
        int i = 0;
        while (isdigit(c)) {
            currentToken->value[i++] = c;
            c = getchar();
        }
        currentToken->value[i] = '\0';
        ungetc(c, stdin);
        return currentToken;
    }

    if (isalpha(c)) {
        currentToken->type = TOKEN_IDENTIFIER;
        currentToken->value = malloc(sizeof(char) * 100);
        int i = 0;
        while (isalpha(c)) {
            currentToken->value[i++] = c;
            c = getchar();
        }
        currentToken->value[i] = '\0';
        ungetc(c, stdin);
        return currentToken;
    }

    if (c == '"') {
        currentToken->type = TOKEN_STRING;
        currentToken->value = malloc(sizeof(char) * 100);
        int i = 0;
        c = getchar();
        while (c != '"') {
            currentToken->value[i++] = c;
            c = getchar();
        }
        currentToken->value[i] = '\0';
        return currentToken;
    }

    error("Invalid token");
    return NULL;
}

void parseExpression() {
    Token *token = getToken();

    if (token->type == TOKEN_INT) {
        printf("Integer: %s\n", token->value);
    } else if (token->type == TOKEN_FLOAT) {
        printf("Float: %s\n", token->value);
    } else if (token->type == TOKEN_STRING) {
        printf("String: %s\n", token->value);
    } else if (token->type == TOKEN_IDENTIFIER) {
        printf("Identifier: %s\n", token->value);
    } else if (token->type == TOKEN_EOF) {
        printf("End of file\n");
    } else {
        error("Invalid token");
    }

    free(token->value);
    free(token);
}

int main() {
    parseExpression();
    return 0;
}