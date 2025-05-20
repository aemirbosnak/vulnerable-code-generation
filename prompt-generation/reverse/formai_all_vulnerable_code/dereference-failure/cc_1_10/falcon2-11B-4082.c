//Falcon2-11B DATASET v1.0 Category: Syntax parsing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_SIZE 100

typedef struct {
    char* token;
    int type;
} Token;

typedef struct {
    char* keyword;
    int type;
} Keyword;

Token tokens[MAX_STR_SIZE];
Keyword keywords[MAX_STR_SIZE];

int token_count = 0;
int keyword_count = 0;

void initializeTokens() {
    tokens[token_count].token = (char*)malloc(sizeof(char) * MAX_STR_SIZE);
    tokens[token_count].type = 0;
    token_count++;
}

void initializeKeywords() {
    keywords[keyword_count].keyword = (char*)malloc(sizeof(char) * MAX_STR_SIZE);
    keywords[keyword_count].type = 0;
    keyword_count++;
}

void pushToken(char* token) {
    if (token_count == MAX_STR_SIZE) {
        printf("Too many tokens! Exceeded maximum size.\n");
        return;
    }

    tokens[token_count].token = token;
    tokens[token_count].type = 1;
    token_count++;
}

void pushKeyword(char* keyword) {
    if (keyword_count == MAX_STR_SIZE) {
        printf("Too many keywords! Exceeded maximum size.\n");
        return;
    }

    keywords[keyword_count].keyword = keyword;
    keywords[keyword_count].type = 2;
    keyword_count++;
}

int isIdentifier(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i]) && str[i]!= '_' && str[i]!= '$') {
            return 0;
        }
    }

    return 1;
}

int isNumber(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }

    return 1;
}

int isOperator(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isalnum(str[i])) {
            return 1;
        }
    }

    return 0;
}

int isKeyword(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i])) {
            return 0;
        }
    }

    return 1;
}

int main() {
    initializeTokens();
    initializeKeywords();

    pushToken("int");
    pushKeyword("main");

    pushToken("(");
    pushToken("(");
    pushToken(")");
    pushToken(")");

    pushToken("{");
    pushKeyword("while");
    pushToken("(");
    pushToken("true");
    pushToken(";");
    pushToken(")");
    pushToken("}");

    printf("Token count: %d\n", token_count);
    printf("Keyword count: %d\n", keyword_count);

    return 0;
}