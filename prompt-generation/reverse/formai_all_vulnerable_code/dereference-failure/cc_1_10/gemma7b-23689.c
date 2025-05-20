//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1024

typedef struct Token {
    char* lexeme;
    int line_number;
    struct Token* next;
} Token;

Token* parse_c_syntax(char* source_code) {
    Token* tokens = NULL;
    char* current_lexeme = NULL;
    int line_number = 1;

    // Tokenization
    for (int i = 0; source_code[i] != '\0'; i++) {
        switch (source_code[i]) {
            case ';':
            case ':':
            case '(':
            case ')':
            case '{':
            case '}':
            case ',':
            case '.':
            case '*':
            case '"':
            case '#':
                if (current_lexeme) {
                    Token* new_token = malloc(sizeof(Token));
                    new_token->lexeme = strdup(current_lexeme);
                    new_token->line_number = line_number;
                    new_token->next = tokens;
                    tokens = new_token;
                }
                current_lexeme = NULL;
                break;
            default:
                current_lexeme = current_lexeme ? strcat(current_lexeme, source_code[i]) : strdup(source_code[i]);
                break;
        }
    }

    // Final token
    if (current_lexeme) {
        Token* new_token = malloc(sizeof(Token));
        new_token->lexeme = strdup(current_lexeme);
        new_token->line_number = line_number;
        new_token->next = tokens;
        tokens = new_token;
    }

    return tokens;
}

int main() {
    char* source_code = "int main() { return 0; }";
    Token* tokens = parse_c_syntax(source_code);

    for (Token* token = tokens; token; token = token->next) {
        printf("Lexeme: %s, Line Number: %d\n", token->lexeme, token->line_number);
    }

    return 0;
}