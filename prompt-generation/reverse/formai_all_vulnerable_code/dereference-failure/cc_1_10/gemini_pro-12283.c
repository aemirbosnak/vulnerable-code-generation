//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef enum {
    TOKEN_TYPE_IDENTIFIER,
    TOKEN_TYPE_NUMBER,
    TOKEN_TYPE_STRING,
    TOKEN_TYPE_OPERATOR,
    TOKEN_TYPE_KEYWORD,
    TOKEN_TYPE_PUNCTUATOR,
    TOKEN_TYPE_WHITESPACE,
    TOKEN_TYPE_COMMENT,
    TOKEN_TYPE_EOF
} token_type_t;

typedef struct {
    token_type_t type;
    char *value;
} token_t;

typedef struct {
    char *source;
    int length;
    int pos;
    int line;
    int column;
} source_t;

typedef struct {
    token_t *tokens;
    int num_tokens;
} token_list_t;

token_list_t *tokenize(source_t *source) {
    token_list_t *tokens = malloc(sizeof(token_list_t));
    tokens->tokens = malloc(sizeof(token_t) * MAX_LINE_LENGTH);
    tokens->num_tokens = 0;

    while (source->pos < source->length) {
        char c = source->source[source->pos];

        if (isspace(c)) {
            source->pos++;
            source->column++;
            continue;
        } else if (isalpha(c) || c == '_') {
            int start = source->pos;
            while (isalnum(source->source[source->pos]) || source->source[source->pos] == '_') {
                source->pos++;
                source->column++;
            }
            int end = source->pos;
            token_t token = { TOKEN_TYPE_IDENTIFIER, strndup(source->source + start, end - start) };
            tokens->tokens[tokens->num_tokens++] = token;
            continue;
        } else if (isdigit(c)) {
            int start = source->pos;
            while (isdigit(source->source[source->pos])) {
                source->pos++;
                source->column++;
            }
            int end = source->pos;
            token_t token = { TOKEN_TYPE_NUMBER, strndup(source->source + start, end - start) };
            tokens->tokens[tokens->num_tokens++] = token;
            continue;
        } else if (c == '"') {
            int start = source->pos + 1;
            while (source->source[source->pos] != '"') {
                source->pos++;
                source->column++;
            }
            int end = source->pos;
            token_t token = { TOKEN_TYPE_STRING, strndup(source->source + start, end - start) };
            tokens->tokens[tokens->num_tokens++] = token;
            source->pos++;
            source->column++;
            continue;
        } else if (strchr("+-*/%^&|<>=!", c)) {
            token_t token = { TOKEN_TYPE_OPERATOR, strndup(&c, 1) };
            tokens->tokens[tokens->num_tokens++] = token;
            source->pos++;
            source->column++;
            continue;
        } else if (strchr(";", c)) {
            token_t token = { TOKEN_TYPE_PUNCTUATOR, strndup(&c, 1) };
            tokens->tokens[tokens->num_tokens++] = token;
            source->pos++;
            source->column++;
            continue;
        } else if (c == '\n') {
            source->line++;
            source->column = 0;
            source->pos++;
            continue;
        } else if (c == '/') {
            if (source->source[source->pos + 1] == '/') {
                while (source->source[source->pos] != '\n') {
                    source->pos++;
                    source->column++;
                }
                continue;
            } else if (source->source[source->pos + 1] == '*') {
                source->pos += 2;
                source->column += 2;
                while (source->source[source->pos] != '*' || source->source[source->pos + 1] != '/') {
                    source->pos++;
                    source->column++;
                }
                source->pos += 2;
                source->column += 2;
                continue;
            } else {
                token_t token = { TOKEN_TYPE_OPERATOR, strndup("/", 1) };
                tokens->tokens[tokens->num_tokens++] = token;
                source->pos++;
                source->column++;
                continue;
            }
        } else {
            printf("Error: unexpected character '%c' at line %d, column %d\n", c, source->line, source->column);
            exit(1);
        }
    }

    token_t token = { TOKEN_TYPE_EOF, NULL };
    tokens->tokens[tokens->num_tokens++] = token;

    return tokens;
}

void print_tokens(token_list_t *tokens) {
    for (int i = 0; i < tokens->num_tokens; i++) {
        token_t token = tokens->tokens[i];
        printf("%d: %s (%d)\n", i, token.value, token.type);
    }
}

int main() {
    char *source_code = "int main() {\n    printf(\"Hello, world!\");\n    return 0;\n}";
    source_t source = { source_code, strlen(source_code), 0, 1, 0 };
    token_list_t *tokens = tokenize(&source);
    print_tokens(tokens);
    return 0;
}