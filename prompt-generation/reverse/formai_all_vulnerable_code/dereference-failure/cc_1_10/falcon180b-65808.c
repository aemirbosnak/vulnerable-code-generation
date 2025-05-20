//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_LINE_LENGTH 1000

enum TokenType {
    NUMBER,
    IDENTIFIER,
    STRING,
    OPERATOR,
    KEYWORD,
    WHITESPACE,
    COMMENT,
    ERROR
};

struct Token {
    enum TokenType type;
    char *value;
};

struct Token getToken(char *line, int *index) {
    struct Token token;
    char *start = line + *index;
    char c = line[*index];
    if (isspace(c)) {
        token.type = WHITESPACE;
        token.value = " ";
        *index += 1;
    } else if (isdigit(c)) {
        token.type = NUMBER;
        int i = 0;
        while (isdigit(c) || c == '.') {
            token.value[i++] = c;
            c = line[*index + i];
        }
        token.value[i] = '\0';
        *index += i;
    } else if (isalpha(c)) {
        token.type = IDENTIFIER;
        int i = 0;
        while (isalnum(c) || c == '_') {
            token.value[i++] = c;
            c = line[*index + i];
        }
        token.value[i] = '\0';
        *index += i;
    } else if (c == '"') {
        token.type = STRING;
        int i = 0;
        c = line[*index + i];
        while (c!= '"' || line[*index + i + 1] == '"') {
            token.value[i++] = c;
            c = line[*index + i];
        }
        *index += i + 1;
    } else {
        token.type = ERROR;
        *index += 1;
    }
    return token;
}

void printToken(struct Token token) {
    printf("Type: %d\n", token.type);
    printf("Value: %s\n\n", token.value);
}

int main() {
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, stdin);
    int index = 0;
    struct Token token;
    while (index < strlen(line)) {
        token = getToken(line, &index);
        printToken(token);
    }
    return 0;
}