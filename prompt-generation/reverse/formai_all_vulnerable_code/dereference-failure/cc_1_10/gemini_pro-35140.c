//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Token types
enum TokenType {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_INTEGER,
    TOKEN_STRING,
    TOKEN_SYMBOL,
    TOKEN_KEYWORD
};

// Token structure
struct Token {
    enum TokenType type;
    char *value;
};

// Lexer structure
struct Lexer {
    char *source;
    int pos;
    int len;
};

// Function to create a new lexer
struct Lexer *new_lexer(char *source) {
    struct Lexer *lexer = malloc(sizeof(struct Lexer));
    lexer->source = source;
    lexer->pos = 0;
    lexer->len = strlen(source);
    return lexer;
}

// Function to get the next token
struct Token *get_next_token(struct Lexer *lexer) {
    struct Token *token = malloc(sizeof(struct Token));

    // Skip whitespace
    while (lexer->pos < lexer->len && isspace(lexer->source[lexer->pos])) {
        lexer->pos++;
    }

    // Check for end of file
    if (lexer->pos >= lexer->len) {
        token->type = TOKEN_EOF;
        token->value = NULL;
        return token;
    }

    // Check for identifiers
    if (isalpha(lexer->source[lexer->pos])) {
        int start = lexer->pos;
        while (lexer->pos < lexer->len && isalnum(lexer->source[lexer->pos])) {
            lexer->pos++;
        }
        token->type = TOKEN_IDENTIFIER;
        token->value = strndup(lexer->source + start, lexer->pos - start);
        return token;
    }

    // Check for integers
    if (isdigit(lexer->source[lexer->pos])) {
        int start = lexer->pos;
        while (lexer->pos < lexer->len && isdigit(lexer->source[lexer->pos])) {
            lexer->pos++;
        }
        token->type = TOKEN_INTEGER;
        token->value = strndup(lexer->source + start, lexer->pos - start);
        return token;
    }

    // Check for strings
    if (lexer->source[lexer->pos] == '"') {
        int start = lexer->pos + 1;
        while (lexer->pos < lexer->len && lexer->source[lexer->pos] != '"') {
            lexer->pos++;
        }
        token->type = TOKEN_STRING;
        token->value = strndup(lexer->source + start, lexer->pos - start);
        lexer->pos++;
        return token;
    }

    // Check for symbols
    if (ispunct(lexer->source[lexer->pos])) {
        token->type = TOKEN_SYMBOL;
        token->value = strndup(lexer->source + lexer->pos, 1);
        lexer->pos++;
        return token;
    }

    // Check for keywords
    if (lexer->source[lexer->pos] == 'f' && lexer->source[lexer->pos + 1] == 'u' && lexer->source[lexer->pos + 2] == 'n') {
        token->type = TOKEN_KEYWORD;
        token->value = strndup("fun", 3);
        lexer->pos += 3;
        return token;
    }

    // Unknown token
    token->type = TOKEN_EOF;
    token->value = NULL;
    return token;
}

// Function to free a token
void free_token(struct Token *token) {
    free(token->value);
    free(token);
}

// Function to free a lexer
void free_lexer(struct Lexer *lexer) {
    free(lexer);
}

// Main function
int main() {
    // Create a lexer
    struct Lexer *lexer = new_lexer("fun main() {}");

    // Get the next token
    struct Token *token = get_next_token(lexer);

    // Print the token type and value
    while (token->type != TOKEN_EOF) {
        printf("Token type: %d, Token value: %s\n", token->type, token->value);

        // Get the next token
        token = get_next_token(lexer);
    }

    // Free the lexer
    free_lexer(lexer);

    return 0;
}