//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    TOKEN_INT,
    TOKEN_FLOAT,
    TOKEN_IDENTIFIER,
    TOKEN_ASSIGN,
    TOKEN_SEMICOLON,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_EOF,
    TOKEN_INVALID
} TokenType;

typedef struct {
    TokenType type;
    char value[64];
} Token;

typedef struct {
    Token *tokens;
    int position;
    int size;
} TokenStream;

TokenStream* create_token_stream() {
    TokenStream *stream = (TokenStream*)malloc(sizeof(TokenStream));
    stream->tokens = (Token*)malloc(sizeof(Token) * 256);
    stream->position = 0;
    stream->size = 0;
    return stream;
}

void free_token_stream(TokenStream *stream) {
    free(stream->tokens);
    free(stream);
}

void add_token(TokenStream *stream, TokenType type, const char *value) {
    if (stream->size < 256) {
        stream->tokens[stream->size].type = type;
        strncpy(stream->tokens[stream->size].value, value, 63);
        stream->tokens[stream->size].value[63] = '\0'; // Ensure null-termination
        stream->size++;
    }
}

Token* get_next_token(TokenStream *stream) {
    if (stream->position < stream->size) {
        return &stream->tokens[stream->position++];
    }
    return NULL;
}

void parse_expression(TokenStream *stream);
void parse_term(TokenStream *stream);
void parse_factor(TokenStream *stream);

void parse_expression(TokenStream *stream) {
    parse_term(stream);
    
    Token *token;
    while ((token = get_next_token(stream)) != NULL) {
        if (token->type == TOKEN_PLUS || token->type == TOKEN_MINUS) {
            printf("Parsed operator: %s\n", token->value);
            parse_term(stream);
        } else {
            stream->position--; // Unconsume the token
            break;
        }
    }
}

void parse_term(TokenStream *stream) {
    parse_factor(stream);
    
    Token *token;
    while ((token = get_next_token(stream)) != NULL) {
        if (token->type == TOKEN_MULTIPLY || token->type == TOKEN_DIVIDE) {
            printf("Parsed operator: %s\n", token->value);
            parse_factor(stream);
        } else {
            stream->position--; // Unconsume the token
            break;
        }
    }
}

void parse_factor(TokenStream *stream) {
    Token *token = get_next_token(stream);
    if (token == NULL) {
        printf("Unexpected end of input\n");
        return;
    }

    if (token->type == TOKEN_INT || token->type == TOKEN_FLOAT) {
        printf("Parsed number: %s\n", token->value);
    } else if (token->type == TOKEN_IDENTIFIER) {
        printf("Parsed identifier: %s\n", token->value);
    } else if (token->type == TOKEN_LPAREN) {
        parse_expression(stream);
        token = get_next_token(stream);
        if (token == NULL || token->type != TOKEN_RPAREN) {
            printf("Error: Missing closing parenthesis\n");
        }
    } else {
        printf("Unexpected token: %s\n", token->value);
    }
}

void tokenize(const char *input, TokenStream *stream) {
    char *current = (char*)input;
    while (*current) {
        if (isspace(*current)) {
            current++;
            continue;
        }
        if (isdigit(*current)) {
            char buffer[64];
            int len = 0;
            while (isdigit(*current) || *current == '.') {
                if (len < 63) buffer[len++] = *current;
                current++;
            }
            buffer[len] = '\0';
            if (strchr(buffer, '.')) {
                add_token(stream, TOKEN_FLOAT, buffer);
            } else {
                add_token(stream, TOKEN_INT, buffer);
            }
            continue;
        }
        if (isalpha(*current)) {
            char buffer[64];
            int len = 0;
            while (isalnum(*current)) {
                if (len < 63) buffer[len++] = *current;
                current++;
            }
            buffer[len] = '\0';
            add_token(stream, TOKEN_IDENTIFIER, buffer);
            continue;
        }
        switch (*current) {
            case '+': add_token(stream, TOKEN_PLUS, "+"); break;
            case '-': add_token(stream, TOKEN_MINUS, "-"); break;
            case '*': add_token(stream, TOKEN_MULTIPLY, "*"); break;
            case '/': add_token(stream, TOKEN_DIVIDE, "/"); break;
            case '=': add_token(stream, TOKEN_ASSIGN, "="); break;
            case ';': add_token(stream, TOKEN_SEMICOLON, ";"); break;
            case '(': add_token(stream, TOKEN_LPAREN, "("); break;
            case ')': add_token(stream, TOKEN_RPAREN, ")"); break;
            default: 
                printf("Invalid character: %c\n", *current);
                current++;
                continue;
        }
        current++;
    }
    add_token(stream, TOKEN_EOF, "EOF");
}

int main() {
    const char *input = "x = 10 + 20 * (30 - 15); y = x / 2.5;";
    
    TokenStream *stream = create_token_stream();
    tokenize(input, stream);
    
    printf("Tokens generated:\n");
    for (int i = 0; i < stream->size; i++) {
        printf("Token type: %d, value: %s\n", stream->tokens[i].type, stream->tokens[i].value);
    }

    printf("\nParsing Expression:\n");
    stream->position = 0; // Reset position for parsing
    parse_expression(stream);

    free_token_stream(stream);
    return 0;
}