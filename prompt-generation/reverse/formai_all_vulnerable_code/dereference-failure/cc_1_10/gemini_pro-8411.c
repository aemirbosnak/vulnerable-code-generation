//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Token types
enum TokenType {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_KEYWORD,
    TOKEN_OPERATOR,
    TOKEN_PUNCTUATOR,
    TOKEN_LITERAL
};

// Token structure
struct Token {
    enum TokenType type;
    char *value;
};

// Lexer
struct Lexer {
    char *input;
    int position;
    int length;
};

// Initialize lexer
struct Lexer *lexer_init(char *input) {
    struct Lexer *lexer = malloc(sizeof(struct Lexer));
    lexer->input = input;
    lexer->position = 0;
    lexer->length = strlen(input);
    return lexer;
}

// Get next token
struct Token *lexer_next_token(struct Lexer *lexer) {
    struct Token *token = malloc(sizeof(struct Token));

    // Skip whitespace
    while (lexer->position < lexer->length && isspace(lexer->input[lexer->position])) {
        lexer->position++;
    }

    // Check for end of input
    if (lexer->position >= lexer->length) {
        token->type = TOKEN_EOF;
        token->value = NULL;
        return token;
    }

    // Check for identifiers
    if (isalpha(lexer->input[lexer->position])) {
        int start = lexer->position;
        while (lexer->position < lexer->length && isalnum(lexer->input[lexer->position])) {
            lexer->position++;
        }
        token->type = TOKEN_IDENTIFIER;
        token->value = strndup(lexer->input + start, lexer->position - start);
        return token;
    }

    // Check for keywords
    if (lexer->input[lexer->position] == '_') {
        int start = lexer->position;
        while (lexer->position < lexer->length && isalnum(lexer->input[lexer->position])) {
            lexer->position++;
        }
        token->type = TOKEN_KEYWORD;
        token->value = strndup(lexer->input + start, lexer->position - start);
        return token;
    }

    // Check for operators
    if (strchr("+-*/%^&|!", lexer->input[lexer->position])) {
        token->type = TOKEN_OPERATOR;
        token->value = strndup(lexer->input + lexer->position, 1);
        lexer->position++;
        return token;
    }

    // Check for punctuators
    if (strchr("(){}[],;:", lexer->input[lexer->position])) {
        token->type = TOKEN_PUNCTUATOR;
        token->value = strndup(lexer->input + lexer->position, 1);
        lexer->position++;
        return token;
    }

    // Check for literals
    if (lexer->input[lexer->position] == '"') {
        int start = lexer->position;
        while (lexer->position < lexer->length && lexer->input[lexer->position] != '"') {
            lexer->position++;
        }
        token->type = TOKEN_LITERAL;
        token->value = strndup(lexer->input + start + 1, lexer->position - start - 1);
        lexer->position++;
        return token;
    }

    // Unknown token
    token->type = TOKEN_EOF;
    token->value = NULL;
    return token;
}

// Free token
void token_free(struct Token *token) {
    free(token->value);
    free(token);
}

// Free lexer
void lexer_free(struct Lexer *lexer) {
    free(lexer);
}

// Main
int main() {
    // Initialize lexer
    struct Lexer *lexer = lexer_init("int main() { return 0; }");

    // Get next token
    struct Token *token;
    while ((token = lexer_next_token(lexer))->type != TOKEN_EOF) {
        // Print token
        switch (token->type) {
            case TOKEN_IDENTIFIER:
                printf("Identifier: %s\n", token->value);
                break;
            case TOKEN_KEYWORD:
                printf("Keyword: %s\n", token->value);
                break;
            case TOKEN_OPERATOR:
                printf("Operator: %s\n", token->value);
                break;
            case TOKEN_PUNCTUATOR:
                printf("Punctuator: %s\n", token->value);
                break;
            case TOKEN_LITERAL:
                printf("Literal: %s\n", token->value);
                break;
            case TOKEN_EOF:
                printf("End of input\n");
                break;
        }

        // Free token
        token_free(token);
    }

    // Free lexer
    lexer_free(lexer);

    return 0;
}