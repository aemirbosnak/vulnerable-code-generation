//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKEN_LENGTH 100
#define MAX_LINE_LENGTH 1000

enum TokenType {
    TOKEN_INVALID = 0,
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_OPERATOR
};

struct Token {
    enum TokenType type;
    char* value;
};

struct Token* createToken(enum TokenType type, char* value) {
    struct Token* token = (struct Token*)malloc(sizeof(struct Token));
    token->type = type;
    token->value = value;
    return token;
}

void destroyToken(struct Token* token) {
    free(token->value);
    free(token);
}

char* getNextToken(char* line) {
    char* tokenStart = line;
    while (*line!= '\0' && isspace(*line)) {
        line++;
    }
    if (*line == '\0') {
        return NULL;
    }
    char* tokenEnd = line;
    while (*line!= '\0' &&!isspace(*line)) {
        line++;
    }
    char* tokenValue = (char*)malloc(line - tokenEnd + 1);
    strncpy(tokenValue, tokenEnd, line - tokenEnd);
    tokenValue[line - tokenEnd] = '\0';
    return tokenValue;
}

void printToken(struct Token* token) {
    switch (token->type) {
        case TOKEN_KEYWORD:
            printf("Keyword: %s\n", token->value);
            break;
        case TOKEN_IDENTIFIER:
            printf("Identifier: %s\n", token->value);
            break;
        case TOKEN_NUMBER:
            printf("Number: %s\n", token->value);
            break;
        case TOKEN_STRING:
            printf("String: %s\n", token->value);
            break;
        case TOKEN_OPERATOR:
            printf("Operator: %s\n", token->value);
            break;
        default:
            printf("Invalid token\n");
            break;
    }
}

int main() {
    char input[MAX_LINE_LENGTH];
    while (fgets(input, MAX_LINE_LENGTH, stdin)!= NULL) {
        char* line = strdup(input);
        struct Token* token = getNextToken(line);
        while (token!= NULL) {
            printToken(token);
            destroyToken(token);
            token = getNextToken(line);
        }
        free(line);
    }
    return 0;
}