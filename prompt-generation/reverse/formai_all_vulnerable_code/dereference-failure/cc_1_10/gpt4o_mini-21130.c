//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_EXPRESSION_LENGTH 256

// Token types
typedef enum {
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MULTIPLY,
    TOKEN_EOF,
    TOKEN_INVALID
} TokenType;

// Token structure
typedef struct {
    TokenType type;
    int value; // Holds the value if the token is a number
} Token;

// Lexer structure
typedef struct {
    const char *input;
    size_t position;
    char current_char;
} Lexer;

// Parser structure
typedef struct {
    Lexer *lexer;
    Token current_token;
} Parser;

// Function prototypes
Lexer *create_lexer(const char *input);
Token get_next_token(Lexer *lexer);
Parser *create_parser(Lexer *lexer);
void eat(Parser *parser, TokenType token_type);
int factor(Parser *parser);
int term(Parser *parser);
int expression(Parser *parser);
void free_parser(Parser *parser);

int main() {
    char input[MAX_EXPRESSION_LENGTH];
    printf("Enter an arithmetic expression: ");
    fgets(input, MAX_EXPRESSION_LENGTH, stdin);

    // Remove newline character if present
    input[strcspn(input, "\n")] = 0;

    Lexer *lexer = create_lexer(input);
    Parser *parser = create_parser(lexer);

    int result = expression(parser);
    printf("Result: %d\n", result);

    free_parser(parser);
    free(lexer);
    return 0;
}

Lexer *create_lexer(const char *input) {
    Lexer *lexer = (Lexer *)malloc(sizeof(Lexer));
    lexer->input = input;
    lexer->position = 0;
    lexer->current_char = input[lexer->position];
    return lexer;
}

void advance(Lexer *lexer) {
    lexer->position++;
    if (lexer->position > strlen(lexer->input) - 1) {
        lexer->current_char = '\0'; // End of input
    } else {
        lexer->current_char = lexer->input[lexer->position];
    }
}

Token get_next_token(Lexer *lexer) {
    while (lexer->current_char != '\0') {
        if (isspace(lexer->current_char)) {
            advance(lexer);
            continue;
        }
        if (isdigit(lexer->current_char)) {
            int value = 0;
            while (lexer->current_char != '\0' && isdigit(lexer->current_char)) {
                value = value * 10 + (lexer->current_char - '0');
                advance(lexer);
            }
            return (Token){.type = TOKEN_NUMBER, .value = value};
        }
        if (lexer->current_char == '+') {
            advance(lexer);
            return (Token){.type = TOKEN_PLUS};
        }
        if (lexer->current_char == '*') {
            advance(lexer);
            return (Token){.type = TOKEN_MULTIPLY};
        }
        return (Token){.type = TOKEN_INVALID};
    }
    return (Token){.type = TOKEN_EOF};
}

Parser *create_parser(Lexer *lexer) {
    Parser *parser = (Parser *)malloc(sizeof(Parser));
    parser->lexer = lexer;
    parser->current_token = get_next_token(lexer);
    return parser;
}

void eat(Parser *parser, TokenType token_type) {
    if (parser->current_token.type == token_type) {
        parser->current_token = get_next_token(parser->lexer);
    } else {
        fprintf(stderr, "Invalid syntax!\n");
        exit(EXIT_FAILURE);
    }
}

int factor(Parser *parser) {
    Token token = parser->current_token;
    if (token.type == TOKEN_NUMBER) {
        eat(parser, TOKEN_NUMBER);
        return token.value;
    }
    return 0;
}

int term(Parser *parser) {
    int result = factor(parser);
    while (parser->current_token.type == TOKEN_MULTIPLY) {
        eat(parser, TOKEN_MULTIPLY);
        result *= factor(parser);
    }
    return result;
}

int expression(Parser *parser) {
    int result = term(parser);
    while (parser->current_token.type == TOKEN_PLUS) {
        eat(parser, TOKEN_PLUS);
        result += term(parser);
    }
    return result;
}

void free_parser(Parser *parser) {
    free(parser);
}