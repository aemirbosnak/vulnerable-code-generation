//FormAI DATASET v1.0 Category: Syntax parsing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATEMENT_LENGTH 100
#define MAX_TOKEN_LENGTH 30

typedef struct TokenStruct {
    char* value;
    char* type;
} Token;

char* statement;
int pos = 0;
int length = 0;

Token* readNextToken() {
    Token* token = (Token*)malloc(sizeof(Token));
    char* value = (char*)malloc(sizeof(char) * MAX_TOKEN_LENGTH);
    char* type = (char*)malloc(sizeof(char) * MAX_TOKEN_LENGTH);
    int valuePos = 0;
    int typePos = 0;
    int startIndex = pos;

    while (pos < length && statement[pos] != ' ' && statement[pos] != '\n') {
        if (statement[pos] == ';' || statement[pos] == '{' || statement[pos] == '}') {
            if (valuePos > 0) {
                break;
            }
            value[valuePos++] = statement[pos++];
            break;
        }
        if (statement[pos] == '(' || statement[pos] == ')' || statement[pos] == ',' || statement[pos] == '=') {
            if (valuePos > 0) {
                break;
            }
            value[valuePos++] = statement[pos++];
            strcpy(type, "Operator");
            break;
        }
        value[valuePos++] = statement[pos++];
    }

    if (strlen(type) == 0) {
        strcpy(type, "Identifier");
    }

    token->type = type;

    for (int i = startIndex; i < pos; i++) {
        value[i - startIndex] = statement[i];
    }

    token->value = value;
    return token; 
}

void skipWhiteSpaces() {
    while (pos < length && (statement[pos] == ' ' || statement[pos] == '\t')) {
        pos++;
    }
}

void parseStatement() {
    while (pos < length) {
        Token* token = readNextToken();
        printf("Token Value: %s | Token Type: %s\n", token->value, token->type);
        free(token->type);
        free(token->value);
        free(token);
        skipWhiteSpaces();
    }
}

int main() {
    statement = (char*)malloc(sizeof(char) * MAX_STATEMENT_LENGTH);
    printf("Enter the statement to be parsed: ");
    fgets(statement, MAX_STATEMENT_LENGTH, stdin);
    length = strlen(statement) - 1;
    parseStatement();
    free(statement);
    return 0;
}