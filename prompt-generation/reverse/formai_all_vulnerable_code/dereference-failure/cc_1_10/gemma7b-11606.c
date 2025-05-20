//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: Alan Turing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1024

typedef struct Token {
    char *lexeme;
    int line_number;
    struct Token *next;
} Token;

Token *tokenize(char *text);

int main() {
    char text[] = "This is a string with some metadata. The metadata includes the following information: name, age, and address. The name is John Doe, the age is 25, and the address is 123 Main St.";
    Token *tokens = tokenize(text);

    for (Token *token = tokens; token; token = token->next) {
        printf("Lexeme: %s, Line Number: %d\n", token->lexeme, token->line_number);
    }

    return 0;
}

Token *tokenize(char *text) {
    char *p = text;
    Token *tokens = NULL;
    Token *current_token = NULL;

    while (p) {
        // Skip whitespace
        while (*p && isspace(*p)) {
            p++;
        }

        // Lexeme starts
        char lexeme[MAX_TOKENS] = "";
        int i = 0;

        // Read the lexeme
        while (*p && !isspace(*p) && i < MAX_TOKENS) {
            lexeme[i] = *p;
            i++;
            p++;
        }

        // End of lexeme
        lexeme[i] = '\0';

        // Create a new token
        Token *new_token = malloc(sizeof(Token));
        new_token->lexeme = strdup(lexeme);
        new_token->line_number = 1; // TODO: Implement line number extraction
        new_token->next = NULL;

        // Add the new token to the list
        if (tokens) {
            current_token->next = new_token;
        } else {
            tokens = new_token;
        }

        current_token = new_token;
    }

    return tokens;
}