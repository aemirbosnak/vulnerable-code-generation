//FormAI DATASET v1.0 Category: Syntax parsing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum Token_Type {
    TOKEN_INVALID,
    TOKEN_INT,
    TOKEN_FLOAT,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_STAR,
    TOKEN_SLASH,
    TOKEN_LPAREN,
    TOKEN_RPAREN
} Token_Type;

typedef struct Token {
    Token_Type type;
    const char* start;
    int length;
    int line;
} Token;

typedef struct Parser {
    Token* tokens;
    int current;
} Parser;

void eat(Parser* parser) {
    parser->current++;
}

bool match(Parser* parser, Token_Type type) {
    if (parser->tokens[parser->current].type == type) {
        eat(parser);
        return true;
    }
    return false;
}

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

bool is_alpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

Token get_token(const char* source, int line) {
    Token token = {TOKEN_INVALID, source, 0, line};
    switch (*source) {
        case '+': token.type = TOKEN_PLUS; break;
        case '-': token.type = TOKEN_MINUS; break;
        case '*': token.type = TOKEN_STAR; break;
        case '/': token.type = TOKEN_SLASH; break;
        case '(': token.type = TOKEN_LPAREN; break;
        case ')': token.type = TOKEN_RPAREN; break;
        default:
            if (is_digit(*source)) {
                token.type = TOKEN_INT;
                while (is_digit(*(++source)))
                    ;
            } else if (is_alpha(*source)) {
                while (is_alpha(*(++source)) || is_digit(*source))
                    ;
            }
            token.length = source - token.start;
    }

    return token;
}

void lex(const char* source, int lines, Token* tokens, int* num_tokens) {
    int start_line = 1;
    const char* c = source;

    while (*c) {
        if (*c == '\n') {
            start_line++;
        }

        if (*c == ' ' || *c == '\n' || *c == '\r' || *c == '\t') {
            c++;
        } else {
            tokens[*num_tokens] = get_token(c, start_line);
            (*num_tokens)++;
            c += tokens[*num_tokens - 1].length;
        }
    }
}

int parse_expression(Parser* parser);

int parse_primitive(Parser* parser) {
    if (match(parser, TOKEN_INT)) {
        return atoi(parser->tokens[parser->current - 1].start);
    } else if (match(parser, TOKEN_LPAREN)) {
        int value = parse_expression(parser);
        if (match(parser, TOKEN_RPAREN)) {
            return value;
        }
    }
    perror("Invalid syntax");
    exit(1);
}

int parse_term(Parser* parser) {
    int value = parse_primitive(parser);
    while (true) {
        if (match(parser, TOKEN_STAR)) {
            value *= parse_primitive(parser);
        } else if (match(parser, TOKEN_SLASH)) {
            value /= parse_primitive(parser);
        } else {
            break;
        }
    }
    return value;
}

int parse_expression(Parser* parser) {
    int value = parse_term(parser);
    while (true) {
        if (match(parser, TOKEN_PLUS)) {
            value += parse_term(parser);
        } else if (match(parser, TOKEN_MINUS)) {
            value -= parse_term(parser);
        } else {
            break;
        }
    }
    return value;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: ./parser <expression>\n");
        return 0;
    }

    Token* tokens = malloc(sizeof(Token) * 100);
    int num_tokens = 0;
    lex(argv[1], 1, tokens, &num_tokens);

    Parser parser = {tokens, 0};
    int value = parse_expression(&parser);

    printf("%d\n", value);

    free(tokens);

    return 0;
}