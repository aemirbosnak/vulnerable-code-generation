//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100

typedef struct {
    char *str;
    int len;
    int line;
    int col;
} Token;

typedef struct {
    Token tokens[MAX_TOKENS];
    int num_tokens;
    int current_token;
} TokenStream;

TokenStream *new_token_stream() {
    TokenStream *ts = malloc(sizeof(TokenStream));
    ts->num_tokens = 0;
    ts->current_token = 0;
    return ts;
}

void free_token_stream(TokenStream *ts) {
    for (int i = 0; i < ts->num_tokens; i++) {
        free(ts->tokens[i].str);
    }
    free(ts);
}

int add_token(TokenStream *ts, char *str, int len, int line, int col) {
    if (ts->num_tokens >= MAX_TOKENS) {
        return -1;
    }
    ts->tokens[ts->num_tokens].str = strndup(str, len);
    ts->tokens[ts->num_tokens].len = len;
    ts->tokens[ts->num_tokens].line = line;
    ts->tokens[ts->num_tokens].col = col;
    ts->num_tokens++;
    return 0;
}

Token *peek_token(TokenStream *ts) {
    if (ts->current_token >= ts->num_tokens) {
        return NULL;
    }
    return &ts->tokens[ts->current_token];
}

Token *get_token(TokenStream *ts) {
    if (ts->current_token >= ts->num_tokens) {
        return NULL;
    }
    return &ts->tokens[ts->current_token++];
}

int is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

int is_alpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int is_alphanumeric(char c) {
    return is_digit(c) || is_alpha(c);
}

int is_punctuation(char c) {
    return !is_whitespace(c) && !is_digit(c) && !is_alpha(c);
}

Token *tokenize(char *input) {
    TokenStream *ts = new_token_stream();
    int line = 1;
    int col = 1;
    int start = 0;
    int end = 0;
    char c;

    while ((c = input[end])) {
        if (is_whitespace(c)) {
            if (start != end) {
                add_token(ts, &input[start], end - start, line, col);
                start = end + 1;
            }
            if (c == '\n') {
                line++;
                col = 1;
            } else {
                col++;
            }
        } else if (is_digit(c)) {
            if (start == end) {
                start = end;
            }
            end++;
            col++;
        } else if (is_alpha(c)) {
            if (start == end) {
                start = end;
            }
            end++;
            col++;
        } else if (is_punctuation(c)) {
            if (start != end) {
                add_token(ts, &input[start], end - start, line, col);
                start = end + 1;
            }
            add_token(ts, &input[end], 1, line, col);
            start = end + 1;
            col++;
        } else {
            printf("Unknown character '%c'\n", c);
            exit(1);
        }
        end++;
    }

    if (start != end) {
        add_token(ts, &input[start], end - start, line, col);
    }

    return ts;
}

int main() {
    char *input = "int main() {\n    printf(\"Hello, world!\n\");\n}";
    TokenStream *ts = tokenize(input);

    Token *token;
    while ((token = get_token(ts)) != NULL) {
        printf("Token: '%s', Length: %d, Line: %d, Column: %d\n",
                token->str, token->len, token->line, token->col);
    }

    free_token_stream(ts);

    return 0;
}