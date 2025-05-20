//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_LENGTH 1024

typedef struct {
    char* value;
    int length;
} Token;

typedef struct {
    Token* tokens;
    int numTokens;
} TokenList;

Token* createToken(char* value, int length) {
    Token* token = (Token*)malloc(sizeof(Token));
    token->value = (char*)malloc(length * sizeof(char));
    token->length = length;
    strncpy(token->value, value, length);
    token->value[length - 1] = '\0';
    return token;
}

void addToken(TokenList* list, Token* token) {
    list->tokens = (Token*)realloc(list->tokens, (list->numTokens + 1) * sizeof(Token));
    list->tokens[list->numTokens] = *token;
    list->numTokens++;
}

void freeTokenList(TokenList* list) {
    for (int i = 0; i < list->numTokens; i++) {
        free(list->tokens[i].value);
    }
    free(list->tokens);
}

char* readLine(FILE* file) {
    char* line = NULL;
    size_t length = 0;
    ssize_t read;

    while ((read = getline(&line, &length, file))!= -1) {
        if (read > 0 && line[read - 1] == '\n') {
            line[--read] = '\0';
        }
    }

    return line;
}

TokenList* parse(FILE* file) {
    TokenList* tokens = (TokenList*)malloc(sizeof(TokenList));
    tokens->numTokens = 0;

    char* line = readLine(file);
    while (line!= NULL) {
        Token* token = createToken(line, strlen(line));
        addToken(tokens, token);
        line = readLine(file);
    }

    return tokens;
}

void printTokens(TokenList* tokens) {
    for (int i = 0; i < tokens->numTokens; i++) {
        printf("%s\n", tokens->tokens[i].value);
    }
}

int main() {
    FILE* file = fopen("example.xml", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    TokenList* tokens = parse(file);
    printTokens(tokens);

    freeTokenList(tokens);
    fclose(file);

    return 0;
}