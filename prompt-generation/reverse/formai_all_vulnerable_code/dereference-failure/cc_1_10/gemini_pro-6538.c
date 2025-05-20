//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef enum {
    TOKEN_INT,
    TOKEN_FLOAT,
    TOKEN_STRING,
    TOKEN_ID,
    TOKEN_EOF
} token_type;

typedef struct {
    token_type type;
    char *value;
} token;

typedef struct {
    char *source;
    int line_number;
    int column_number;
    token current_token;
} parser;

parser *parser_new(char *source) {
    parser *p = malloc(sizeof(parser));
    p->source = source;
    p->line_number = 1;
    p->column_number = 1;
    p->current_token = (token) { .type = TOKEN_EOF };
    return p;
}

void parser_free(parser *p) {
    free(p->source);
    free(p);
}

token parser_next_token(parser *p) {
    char *start = p->source + p->column_number;
    while (*p->source && isspace(*p->source)) {
        if (*p->source == '\n') {
            p->line_number++;
            p->column_number = 1;
        } else {
            p->column_number++;
        }
        p->source++;
    }
    if (!*p->source) {
        p->current_token = (token) { .type = TOKEN_EOF };
        return p->current_token;
    }
    if (isdigit(*p->source)) {
        while (isdigit(*p->source)) {
            p->column_number++;
            p->source++;
        }
        if (*p->source == '.') {
            p->column_number++;
            p->source++;
            while (isdigit(*p->source)) {
                p->column_number++;
                p->source++;
            }
            p->current_token = (token) { .type = TOKEN_FLOAT, .value = strndup(start, p->source - start) };
        } else {
            p->current_token = (token) { .type = TOKEN_INT, .value = strndup(start, p->source - start) };
        }
    } else if (*p->source == '"') {
        p->column_number++;
        p->source++;
        start = p->source;
        while (*p->source && *p->source != '"') {
            p->column_number++;
            p->source++;
        }
        p->current_token = (token) { .type = TOKEN_STRING, .value = strndup(start, p->source - start) };
        p->column_number++;
        p->source++;
    } else if (isalpha(*p->source) || *p->source == '_') {
        while (isalnum(*p->source) || *p->source == '_') {
            p->column_number++;
            p->source++;
        }
        p->current_token = (token) { .type = TOKEN_ID, .value = strndup(start, p->source - start) };
    } else {
        p->current_token = (token) { .type = TOKEN_EOF };
    }
    return p->current_token;
}

int main() {
    char *source = "int main() {\n    float x = 3.14;\n    char *s = \"Hello world!\";\n}";
    parser *p = parser_new(source);
    token token = parser_next_token(p);
    while (token.type != TOKEN_EOF) {
        printf("%d %d %s\n", token.type, p->line_number, token.value);
        token = parser_next_token(p);
    }
    parser_free(p);
    return 0;
}