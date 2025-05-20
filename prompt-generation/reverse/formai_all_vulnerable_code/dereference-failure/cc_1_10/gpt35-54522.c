//FormAI DATASET v1.0 Category: Syntax parsing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {IDENTIFIER, NUMBER, OPERATOR, DELIMITER, ERROR} TokenType;

typedef struct Token {
    TokenType type;
    char* lexeme;
} Token;

TokenType checkTokenType(char* lexeme) {
    if(isdigit(lexeme[0])) {
        return NUMBER;
    }
    if(isalpha(lexeme[0])) {
        return IDENTIFIER;
    }
    if(lexeme[0] == '+' || lexeme[0] == '-' || lexeme[0] == '*' || lexeme[0] == '/') {
        return OPERATOR;
    }
    if(lexeme[0] == ';' || lexeme[0] == ',') {
        return DELIMITER;
    }
    return ERROR;
}

Token* tokenize(char* input) {
    Token* tokens = malloc(100 * sizeof(Token));
    char* token = strtok(input, " ");
    int i = 0;
    while(token != NULL) {
        TokenType type = checkTokenType(token);
        tokens[i].type = type;
        tokens[i].lexeme = token;
        i++;
        token = strtok(NULL, " ");
    }
    return tokens;
}

int main() {
    char input[100];
    printf("Enter input: ");
    fgets(input, 100, stdin);
    char* newline = strchr(input, '\n');
    if(newline != NULL) {
        *newline = '\0';
    }
    Token* tokens = tokenize(input);
    for(int i = 0; i < strlen(input); i++) {
        printf("Token %d: Type: ", (i+1));
        switch(tokens[i].type) {
            case IDENTIFIER:
                printf("IDENTIFIER");
                break;
            case NUMBER:
                printf("NUMBER");
                break;
            case OPERATOR:
                printf("OPERATOR");
                break;
            case DELIMITER:
                printf("DELIMITER");
                break;
            case ERROR:
                printf("ERROR");
                break;
        }
        printf(" Lexeme: %s\n", tokens[i].lexeme);
    }
    free(tokens);
    return 0;
}