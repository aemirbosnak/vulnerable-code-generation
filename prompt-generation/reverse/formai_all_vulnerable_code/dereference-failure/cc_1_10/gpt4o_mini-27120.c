//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256
#define MAX_TOKENS 100

typedef enum {
    TOKEN_TYPE_IDENTIFIER,
    TOKEN_TYPE_INTEGER,
    TOKEN_TYPE_OPERATOR,
    TOKEN_TYPE_KEYWORD,
    TOKEN_TYPE_SEMICOLON,
    TOKEN_TYPE_UNKNOWN
} TokenType;

typedef struct {
    char *value;
    TokenType type;
} Token;

Token *tokenize(char *line, int *token_count) {
    Token *tokens = malloc(MAX_TOKENS * sizeof(Token));
    char *token_value = strtok(line, " \t\n");
    *token_count = 0;

    while (token_value != NULL) {
        Token token;
        token.value = strdup(token_value);

        // Determine the type of the token
        if (strcmp(token_value, "int") == 0 || strcmp(token_value, "return") == 0 || strcmp(token_value, "void") == 0) {
            token.type = TOKEN_TYPE_KEYWORD;
        } else if (isdigit(token_value[0])) {
            token.type = TOKEN_TYPE_INTEGER;
        } else if (strchr("+-*/=;", token_value[0]) != NULL) {
            token.type = TOKEN_TYPE_OPERATOR;
            if (token_value[0] == ';') {
                token.type = TOKEN_TYPE_SEMICOLON;
            }
        } else if (isalpha(token_value[0]) || token_value[0] == '_') {
            token.type = TOKEN_TYPE_IDENTIFIER;
        } else {
            token.type = TOKEN_TYPE_UNKNOWN;
            printf("Unknown token: %s\n", token_value);
        }

        tokens[*token_count] = token;
        (*token_count)++;
        token_value = strtok(NULL, " \t\n");
    }

    return tokens;
}

void print_tokens(Token *tokens, int token_count) {
    printf("Token count: %d\n", token_count);
    for (int i = 0; i < token_count; i++) {
        printf("Token: %s, Type: %d\n", tokens[i].value, tokens[i].type);
        free(tokens[i].value);
    }
}

void free_tokens(Token *tokens) {
    free(tokens);
}

int main() {
    char line[MAX_LENGTH];

    printf("Enter a line of C code: ");
    if (fgets(line, MAX_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    int token_count = 0;
    Token *tokens = tokenize(line, &token_count);
    
    print_tokens(tokens, token_count);
    free_tokens(tokens);

    return 0;
}