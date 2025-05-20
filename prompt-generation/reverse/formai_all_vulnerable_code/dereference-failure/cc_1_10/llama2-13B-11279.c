//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_TOKEN_LEN 256
#define MAX_STMT_LEN 1024

typedef enum {
    TOKEN_TYPE_IDENTIFIER,
    TOKEN_TYPE_KEYWORD,
    TOKEN_TYPE_NUMBER,
    TOKEN_TYPE_STRING,
    TOKEN_TYPE_OPERATOR,
    TOKEN_TYPE_LEFT_PAREN,
    TOKEN_TYPE_RIGHT_PAREN,
    TOKEN_TYPE_LEFT_BRACE,
    TOKEN_TYPE_RIGHT_BRACE,
    TOKEN_TYPE_SEMICOLON,
    TOKEN_TYPE_COMMA,
    TOKEN_TYPE_ERROR
} TokenType;

typedef struct {
    TokenType type;
    char lit[MAX_TOKEN_LEN];
    int line;
    int col;
} Token;

typedef struct {
    Token *tokens;
    int count;
    int capacity;
} TokenStream;

static void tokenize(const char *src, TokenStream *stream) {
    int i = 0;
    int j = 0;
    char c;

    stream->tokens = calloc(1, sizeof(Token));
    stream->count = 0;
    stream->capacity = 16;

    while (i < strlen(src)) {
        c = src[i];

        if (isspace(c)) {
            continue;
        }

        if (j >= stream->capacity) {
            stream->capacity *= 2;
            stream->tokens = realloc(stream->tokens, stream->capacity * sizeof(Token));
        }

        stream->tokens[j].type = TOKEN_TYPE_ERROR;
        stream->tokens[j].lit[0] = 0;
        stream->tokens[j].line = i / 10;
        stream->tokens[j].col = i % 10;

        switch (c) {
            case ' ':
                stream->tokens[j].type = TOKEN_TYPE_IDENTIFIER;
                break;
            case '(':
                stream->tokens[j].type = TOKEN_TYPE_LEFT_PAREN;
                break;
            case ')':
                stream->tokens[j].type = TOKEN_TYPE_RIGHT_PAREN;
                break;
            case '{':
                stream->tokens[j].type = TOKEN_TYPE_LEFT_BRACE;
                break;
            case '}':
                stream->tokens[j].type = TOKEN_TYPE_RIGHT_BRACE;
                break;
            case ';':
                stream->tokens[j].type = TOKEN_TYPE_SEMICOLON;
                break;
            case ',':
                stream->tokens[j].type = TOKEN_TYPE_COMMA;
                break;
            default:
                if (isalpha(c) || c == '_') {
                    stream->tokens[j].type = TOKEN_TYPE_IDENTIFIER;
                } else {
                    stream->tokens[j].type = TOKEN_TYPE_NUMBER;
                    stream->tokens[j].lit[0] = c;
                }
                break;
        }

        j++;
        i++;
    }

    stream->count = j;
}

static void parse(TokenStream *stream) {
    int i = 0;

    while (i < stream->count) {
        Token curr = stream->tokens[i];

        switch (curr.type) {
            case TOKEN_TYPE_IDENTIFIER:
                printf("Identifier: %s\n", curr.lit);
                break;
            case TOKEN_TYPE_KEYWORD:
                printf("Keyword: %s\n", curr.lit);
                break;
            case TOKEN_TYPE_NUMBER:
                printf("Number: %d\n", atoi(curr.lit));
                break;
            case TOKEN_TYPE_STRING:
                printf("String: %s\n", curr.lit);
                break;
            case TOKEN_TYPE_OPERATOR:
                printf("Operator: %c\n", curr.lit[0]);
                break;
            case TOKEN_TYPE_LEFT_PAREN:
                printf("Left Paren: %c\n", curr.lit[0]);
                break;
            case TOKEN_TYPE_RIGHT_PAREN:
                printf("Right Paren: %c\n", curr.lit[0]);
                break;
            case TOKEN_TYPE_LEFT_BRACE:
                printf("Left Brace: %c\n", curr.lit[0]);
                break;
            case TOKEN_TYPE_RIGHT_BRACE:
                printf("Right Brace: %c\n", curr.lit[0]);
                break;
            case TOKEN_TYPE_SEMICOLON:
                printf("Semicolon: %c\n", curr.lit[0]);
                break;
            case TOKEN_TYPE_COMMA:
                printf("Comma: %c\n", curr.lit[0]);
                break;
            default:
                printf("Error: Unknown token type %d\n", curr.type);
                break;
        }

        i++;
    }
}

int main() {
    char src[] = "int main() { return 0; }";
    TokenStream stream;

    tokenize(src, &stream);
    parse(&stream);

    return 0;
}