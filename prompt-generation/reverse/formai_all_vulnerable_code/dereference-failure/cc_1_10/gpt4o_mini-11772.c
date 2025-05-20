//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_EXPR_LEN 256

typedef enum {
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN,
    TOKEN_END
} TokenType;

typedef struct {
    TokenType type;
    double value;
    char operator;
} Token;

typedef struct {
    const char *input;
    size_t pos;
} Lexer;

typedef struct {
    Lexer *lexer;
    Token current_token;
} Parser;

// Function prototypes
void lexer_init(Lexer *lexer, const char *input);
Token lexer_get_next_token(Lexer *lexer);
Parser *parser_init(Lexer *lexer);
double parser_parse_expression(Parser *parser);
double parser_parse_term(Parser *parser);
double parser_parse_factor(Parser *parser);

void lexer_init(Lexer *lexer, const char *input) {
    lexer->input = input;
    lexer->pos = 0;
}

Token lexer_get_next_token(Lexer *lexer) {
    Token token;

    while (lexer->pos < strlen(lexer->input)) {
        char current_char = lexer->input[lexer->pos];

        if (isspace(current_char)) {
            lexer->pos++;
            continue;
        }

        if (isdigit(current_char)) {
            char *endptr;
            double value = strtod(&lexer->input[lexer->pos], &endptr);
            lexer->pos = endptr - lexer->input;
            token.type = TOKEN_NUMBER;
            token.value = value;
            return token;
        }

        if (current_char == '+' || current_char == '-' ||
            current_char == '*' || current_char == '/') {
            token.type = TOKEN_OPERATOR;
            token.operator = current_char;
            lexer->pos++;
            return token;
        }

        if (current_char == '(') {
            token.type = TOKEN_LEFT_PAREN;
            lexer->pos++;
            return token;
        }

        if (current_char == ')') {
            token.type = TOKEN_RIGHT_PAREN;
            lexer->pos++;
            return token;
        }

        fprintf(stderr, "Error: Unrecognized character: %c\n", current_char);
        exit(EXIT_FAILURE);
    }

    token.type = TOKEN_END;
    return token;
}

Parser *parser_init(Lexer *lexer) {
    Parser *parser = (Parser *)malloc(sizeof(Parser));
    parser->lexer = lexer;
    parser->current_token = lexer_get_next_token(lexer);
    return parser;
}

void parser_advance(Parser *parser) {
    parser->current_token = lexer_get_next_token(parser->lexer);
}

double parser_parse_factor(Parser *parser) {
    if (parser->current_token.type == TOKEN_NUMBER) {
        double value = parser->current_token.value;
        parser_advance(parser);
        return value;
    } else if (parser->current_token.type == TOKEN_LEFT_PAREN) {
        parser_advance(parser);
        double value = parser_parse_expression(parser);
        if (parser->current_token.type != TOKEN_RIGHT_PAREN) {
            fprintf(stderr, "Error: Mismatched parentheses\n");
            exit(EXIT_FAILURE);
        }
        parser_advance(parser);
        return value;
    }

    fprintf(stderr, "Error: Expected a number or left parenthesis\n");
    exit(EXIT_FAILURE);
}

double parser_parse_term(Parser *parser) {
    double result = parser_parse_factor(parser);
    while (parser->current_token.type == TOKEN_OPERATOR &&
           (parser->current_token.operator == '*' || parser->current_token.operator == '/')) {
        char op = parser->current_token.operator;
        parser_advance(parser);
        double next_factor = parser_parse_factor(parser);
        if (op == '*') {
            result *= next_factor;
        } else {
            result /= next_factor;
        }
    }
    return result;
}

double parser_parse_expression(Parser *parser) {
    double result = parser_parse_term(parser);
    while (parser->current_token.type == TOKEN_OPERATOR && 
           (parser->current_token.operator == '+' || parser->current_token.operator == '-')) {
        char op = parser->current_token.operator;
        parser_advance(parser);
        double next_term = parser_parse_term(parser);
        if (op == '+') {
            result += next_term;
        } else {
            result -= next_term;
        }
    }
    return result;
}

int main() {
    char expression[MAX_EXPR_LEN];

    printf("Enter a mathematical expression: ");
    if (fgets(expression, MAX_EXPR_LEN, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }

    Lexer lexer;
    lexer_init(&lexer, expression);
    Parser *parser = parser_init(&lexer);
    
    double result = parser_parse_expression(parser);
    printf("Result: %f\n", result);

    free(parser);
    return EXIT_SUCCESS;
}