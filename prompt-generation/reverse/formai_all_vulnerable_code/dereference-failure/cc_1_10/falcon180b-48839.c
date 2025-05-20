//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_LINE_LENGTH 1024

typedef enum {
    T_NUMBER,
    T_IDENTIFIER,
    T_KEYWORD,
    T_OPERATOR,
    T_STRING,
    T_EOF
} TokenType;

typedef struct {
    TokenType type;
    char *value;
} Token;

Token tokens[MAX_TOKENS];
int token_count = 0;

char *get_token_value(Token token) {
    switch (token.type) {
        case T_NUMBER:
            return "number";
        case T_IDENTIFIER:
            return "identifier";
        case T_KEYWORD:
            return "keyword";
        case T_OPERATOR:
            return "operator";
        case T_STRING:
            return "string";
        case T_EOF:
            return "end of file";
        default:
            return "unknown";
    }
}

void add_token(TokenType type, char *value) {
    if (token_count >= MAX_TOKENS) {
        printf("Error: maximum number of tokens exceeded\n");
        exit(1);
    }
    tokens[token_count++] = (Token) {type, value};
}

void print_tokens() {
    for (int i = 0; i < token_count; i++) {
        printf("Token %d: %s\n", i, get_token_value(tokens[i]));
    }
}

char *get_next_token(char *line) {
    char *token_start = line;
    while (*line!= '\0' && isspace(*line)) {
        line++;
    }
    if (*line == '\0') {
        add_token(T_EOF, "");
        return NULL;
    }
    char *token_end = line;
    while (*line!= '\0' &&!isspace(*line)) {
        line++;
    }
    int token_length = line - token_start;
    char *token_value = malloc(token_length + 1);
    strncpy(token_value, token_start, token_length);
    token_value[token_length] = '\0';
    add_token(T_IDENTIFIER, token_value);
    return line;
}

int main() {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        char *token = get_next_token(line);
        if (token == NULL) {
            break;
        }
    }
    print_tokens();
    return 0;
}