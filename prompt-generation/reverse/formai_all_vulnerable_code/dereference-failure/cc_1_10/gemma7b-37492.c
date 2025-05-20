//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Token {
    char type;
    char value[MAX_BUFFER_SIZE];
    struct Token* next;
} Token;

Token* parse_c_syntax(char* source) {
    Token* head = NULL;
    Token* current = NULL;
    char* buffer = malloc(MAX_BUFFER_SIZE);
    int buffer_size = 0;

    // Lexical analysis
    char* p = source;
    while (*p) {
        // Identifier
        if (*p >= 'a' && *p <= 'z') {
            buffer[buffer_size++] = *p;
            while (*p >= 'a' && *p <= 'z') {
                p++;
                buffer[buffer_size++] = *p;
            }
            Token* new_token = malloc(sizeof(Token));
            new_token->type = 'I';
            strncpy(new_token->value, buffer, buffer_size);
            new_token->next = NULL;
            if (current) {
                current->next = new_token;
            } else {
                head = new_token;
            }
            current = new_token;
            buffer_size = 0;
        }

        // Operator
        else if (*p == '+' || *p == '-' || *p == '*' || *p == '/') {
            buffer[buffer_size++] = *p;
            Token* new_token = malloc(sizeof(Token));
            new_token->type = 'O';
            strncpy(new_token->value, buffer, buffer_size);
            new_token->next = NULL;
            if (current) {
                current->next = new_token;
            } else {
                head = new_token;
            }
            current = new_token;
            buffer_size = 0;
        }

        // Parentheses
        else if (*p == '(' || *p == ')') {
            buffer[buffer_size++] = *p;
            Token* new_token = malloc(sizeof(Token));
            new_token->type = 'P';
            strncpy(new_token->value, buffer, buffer_size);
            new_token->next = NULL;
            if (current) {
                current->next = new_token;
            } else {
                head = new_token;
            }
            current = new_token;
            buffer_size = 0;
        }

        p++;
    }

    // Free memory
    free(buffer);

    return head;
}

int main() {
    char* source = "int main() { return 0; }";
    Token* tokens = parse_c_syntax(source);

    printf("Tokens:");
    for (Token* token = tokens; token; token = token->next) {
        printf(" %c: %s", token->type, token->value);
    }

    return 0;
}