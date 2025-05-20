//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_TOKENS 10

typedef struct Token {
    char* lexeme;
    int type;
    struct Token* next;
} Token;

void parse_syntax(char* str) {
    Token* head = NULL;
    Token* token = NULL;

    // Tokenize the string
    char* token_stream = strtok(str, " ");
    int token_index = 0;

    // Create tokens
    while (token_stream) {
        token = malloc(sizeof(Token));
        token->lexeme = strdup(token_stream);
        token->type = token_index;
        token->next = NULL;

        if (head == NULL) {
            head = token;
        } else {
            token->next = head;
            head = token;
        }

        token_stream = strtok(NULL, " ");
        token_index++;
    }

    // Print tokens
    token = head;
    while (token) {
        printf("%s (%d)\n", token->lexeme, token->type);
        token = token->next;
    }

    // Free tokens
    token = head;
    while (token) {
        free(token->lexeme);
        free(token);
        token = token->next;
    }
}

int main() {
    parse_syntax("Hello, world!");
    return 0;
}