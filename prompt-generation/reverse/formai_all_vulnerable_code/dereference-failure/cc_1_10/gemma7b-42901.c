//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: single-threaded
#include <stdio.h>
#include <string.h>

#define MAX_TOKENS 100

typedef struct Token {
    char *lexeme;
    int type;
    struct Token *next;
} Token;

Token *parse_c_syntax(char *source) {
    Token *head = NULL;
    Token *tail = NULL;
    char *p = source;
    char *start = NULL;
    int token_type = 0;

    while (p) {
        start = p;
        // Identifier
        if (*p >= 'a' && *p <= 'z') {
            token_type = 1;
        }
        // Number
        else if (*p >= '0' && *p <= '9') {
            token_type = 2;
        }
        // Operator
        else if (*p == '+' || *p == '-' || *p == '*' || *p == '/') {
            token_type = 3;
        }
        // Parentheses
        else if (*p == '(' || *p == ')') {
            token_type = 4;
        }
        // Comments
        else if (*p == '/' && *(p + 1) == '/') {
            token_type = 5;
        }

        if (token_type) {
            Token *new_token = malloc(sizeof(Token));
            new_token->lexeme = strdup(start);
            new_token->type = token_type;
            new_token->next = NULL;

            if (head) {
                tail->next = new_token;
                tail = new_token;
            } else {
                head = new_token;
                tail = new_token;
            }
        }

        p++;
    }

    return head;
}

int main() {
    char *source = "int main() { return 0; }";
    Token *tokens = parse_c_syntax(source);

    for (Token *token = tokens; token; token = token->next) {
        printf("Lexeme: %s, Type: %d\n", token->lexeme, token->type);
    }

    return 0;
}