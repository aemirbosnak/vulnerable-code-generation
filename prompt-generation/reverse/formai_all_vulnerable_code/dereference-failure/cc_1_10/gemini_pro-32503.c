//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Token types
typedef enum {
    TOKEN_EOF,
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_STAR,
    TOKEN_SLASH,
    TOKEN_LPAREN,
    TOKEN_RPAREN
} TokenKind;

// Token structure
typedef struct {
    TokenKind kind;
    int value;
} Token;

// Lexer state
typedef struct {
    const char *text;
    const char *current;
} LexerState;

// Lexer functions
Token next_token(LexerState *state) {
    Token token;

    // Skip whitespace
    while (*state->current == ' ') {
        state->current++;
    }

    // Check for end of string
    if (*state->current == '\0') {
        token.kind = TOKEN_EOF;
        return token;
    }

    // Check for numbers
    if (isdigit(*state->current)) {
        token.kind = TOKEN_NUMBER;
        token.value = atoi(state->current);
        while (isdigit(*state->current)) {
            state->current++;
        }
        return token;
    }

    // Check for operators
    switch (*state->current) {
        case '+':
            token.kind = TOKEN_PLUS;
            break;
        case '-':
            token.kind = TOKEN_MINUS;
            break;
        case '*':
            token.kind = TOKEN_STAR;
            break;
        case '/':
            token.kind = TOKEN_SLASH;
            break;
        case '(':
            token.kind = TOKEN_LPAREN;
            break;
        case ')':
            token.kind = TOKEN_RPAREN;
            break;
        default:
            fprintf(stderr, "Error: Invalid token '%c'\n", *state->current);
            exit(1);
    }

    state->current++;
    return token;
}

// Parser state
typedef struct {
    LexerState lexer_state;
    Token current_token;
} ParserState;

// Parser functions
int parse_expression(ParserState *state);

int parse_term(ParserState *state) {
    int value = parse_factor(state);

    while (state->current_token.kind == TOKEN_PLUS || state->current_token.kind == TOKEN_MINUS) {
        if (state->current_token.kind == TOKEN_PLUS) {
            value += parse_factor(state);
        } else {
            value -= parse_factor(state);
        }
    }

    return value;
}

int parse_factor(ParserState *state) {
    int value;

    if (state->current_token.kind == TOKEN_NUMBER) {
        value = state->current_token.value;
        state->current_token = next_token(state);
    } else if (state->current_token.kind == TOKEN_LPAREN) {
        state->current_token = next_token(state);
        value = parse_expression(state);
        if (state->current_token.kind != TOKEN_RPAREN) {
            fprintf(stderr, "Error: Missing right parenthesis\n");
            exit(1);
        }
        state->current_token = next_token(state);
    } else {
        fprintf(stderr, "Error: Invalid factor\n");
        exit(1);
    }

    return value;
}

int parse_expression(ParserState *state) {
    int value = parse_term(state);

    while (state->current_token.kind == TOKEN_STAR || state->current_token.kind == TOKEN_SLASH) {
        if (state->current_token.kind == TOKEN_STAR) {
            value *= parse_term(state);
        } else {
            value /= parse_term(state);
        }
    }

    return value;
}

// Main function
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <expression>\n", argv[0]);
        exit(1);
    }

    LexerState lexer_state;
    lexer_state.text = argv[1];
    lexer_state.current = lexer_state.text;

    ParserState parser_state;
    parser_state.lexer_state = lexer_state;
    parser_state.current_token = next_token(&parser_state.lexer_state);

    int result = parse_expression(&parser_state);

    printf("Result: %d\n", result);

    return 0;
}