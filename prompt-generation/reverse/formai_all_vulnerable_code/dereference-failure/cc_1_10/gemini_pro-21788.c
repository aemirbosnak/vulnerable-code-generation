//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Token types
typedef enum {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_KEYWORD,
    TOKEN_OPERATOR,
    TOKEN_PUNCTUATOR
} TokenType;

// Token structure
typedef struct {
    TokenType type;
    char *value;
} Token;

// Lexer state
typedef struct {
    char *source;
    char *current;
    int line;
    int column;
} LexerState;

// Create a new lexer state
LexerState *new_lexer_state(char *source) {
    LexerState *state = malloc(sizeof(LexerState));
    state->source = source;
    state->current = source;
    state->line = 1;
    state->column = 1;
    return state;
}

// Get the next token
Token *get_next_token(LexerState *state) {
    // Skip whitespace
    while (*state->current == ' ' || *state->current == '\t' || *state->current == '\n') {
        if (*state->current == '\n') {
            state->line++;
            state->column = 1;
        } else {
            state->column++;
        }
        state->current++;
    }

    // Check for end of file
    if (*state->current == '\0') {
        return malloc(sizeof(Token)); // Return EOF token
    }

    // Check for identifiers and keywords
    if (isalpha(*state->current) || *state->current == '_') {
        char *start = state->current;
        while (isalnum(*state->current) || *state->current == '_') {
            state->current++;
        }
        int length = state->current - start;
        char *value = malloc(length + 1);
        strncpy(value, start, length);
        value[length] = '\0';
        Token *token = malloc(sizeof(Token));
        token->type = TOKEN_IDENTIFIER;
        token->value = value;
        return token;
    }

    // Check for numbers
    if (isdigit(*state->current)) {
        char *start = state->current;
        while (isdigit(*state->current)) {
            state->current++;
        }
        int length = state->current - start;
        char *value = malloc(length + 1);
        strncpy(value, start, length);
        value[length] = '\0';
        Token *token = malloc(sizeof(Token));
        token->type = TOKEN_NUMBER;
        token->value = value;
        return token;
    }

    // Check for strings
    if (*state->current == '"') {
        state->current++;
        char *start = state->current;
        while (*state->current != '"') {
            state->current++;
        }
        int length = state->current - start;
        char *value = malloc(length + 1);
        strncpy(value, start, length);
        value[length] = '\0';
        Token *token = malloc(sizeof(Token));
        token->type = TOKEN_STRING;
        token->value = value;
        state->current++;
        return token;
    }

    // Check for operators
    if (strchr("+-*/%^&|><=", *state->current)) {
        char *value = malloc(2);
        value[0] = *state->current;
        value[1] = '\0';
        Token *token = malloc(sizeof(Token));
        token->type = TOKEN_OPERATOR;
        token->value = value;
        state->current++;
        return token;
    }

    // Check for punctuators
    if (strchr("(){}[];,", *state->current)) {
        char *value = malloc(2);
        value[0] = *state->current;
        value[1] = '\0';
        Token *token = malloc(sizeof(Token));
        token->type = TOKEN_PUNCTUATOR;
        token->value = value;
        state->current++;
        return token;
    }

    // Unknown token
    printf("Unknown token: %c\n", *state->current);
    exit(1);
}

// Free a token
void free_token(Token *token) {
    free(token->value);
    free(token);
}

// Parse a source string
void parse_source(char *source) {
    LexerState *state = new_lexer_state(source);
    Token *token;
    while ((token = get_next_token(state))->type != TOKEN_EOF) {
        printf("Token: %s (%d)\n", token->value, token->type);
        free_token(token);
    }
    free_token(token);
    free(state);
}

int main() {
    char *source = "int main() { return 0; }";
    parse_source(source);
    return 0;
}