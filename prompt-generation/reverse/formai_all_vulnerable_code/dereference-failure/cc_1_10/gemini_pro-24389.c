//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

typedef enum {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_KEYWORD,
    TOKEN_OPERATOR,
    TOKEN_PUNCTUATOR
} token_type;

typedef struct {
    token_type type;
    char value[MAX_TOKEN_LENGTH];
} token;

typedef struct {
    token tokens[MAX_TOKENS];
    int num_tokens;
} token_stream;

token_stream* create_token_stream(char* input) {
    token_stream* stream = malloc(sizeof(token_stream));
    stream->num_tokens = 0;

    char* token_start = input;
    while (*input != '\0') {
        if (*input == ' ' || *input == '\n' || *input == '\t') {
            if (token_start != input) {
                token* token = &stream->tokens[stream->num_tokens++];
                token->type = TOKEN_IDENTIFIER;
                strncpy(token->value, token_start, input - token_start);
                token->value[input - token_start] = '\0';
            }
            token_start = input + 1;
        } else if (*input == '"' || *input == '\'') {
            char* end_quote = strchr(input + 1, *input);
            if (end_quote != NULL) {
                token* token = &stream->tokens[stream->num_tokens++];
                token->type = TOKEN_STRING;
                strncpy(token->value, input + 1, end_quote - input - 1);
                token->value[end_quote - input - 1] = '\0';
                input = end_quote + 1;
                token_start = input;
            } else {
                fprintf(stderr, "Unterminated string literal: %s\n", input);
                exit(1);
            }
        } else if (*input == '+' || *input == '-' || *input == '*' || *input == '/' || *input == '%') {
            token* token = &stream->tokens[stream->num_tokens++];
            token->type = TOKEN_OPERATOR;
            token->value[0] = *input;
            token->value[1] = '\0';
            input++;
            token_start = input;
        } else if (*input == ';' || *input == ',' || *input == '(' || *input == ')' || *input == '{' || *input == '}') {
            token* token = &stream->tokens[stream->num_tokens++];
            token->type = TOKEN_PUNCTUATOR;
            token->value[0] = *input;
            token->value[1] = '\0';
            input++;
            token_start = input;
        } else if (*input >= '0' && *input <= '9') {
            char* end_number = strchr(input + 1, ' ');
            if (end_number == NULL) {
                end_number = input + strlen(input);
            }
            token* token = &stream->tokens[stream->num_tokens++];
            token->type = TOKEN_NUMBER;
            strncpy(token->value, input, end_number - input);
            token->value[end_number - input] = '\0';
            input = end_number + 1;
            token_start = input;
        } else {
            input++;
        }
    }

    if (token_start != input) {
        token* token = &stream->tokens[stream->num_tokens++];
        token->type = TOKEN_IDENTIFIER;
        strncpy(token->value, token_start, input - token_start);
        token->value[input - token_start] = '\0';
    }

    token* token = &stream->tokens[stream->num_tokens];
    token->type = TOKEN_EOF;
    strcpy(token->value, "");

    return stream;
}

void free_token_stream(token_stream* stream) {
    free(stream);
}

void print_token_stream(token_stream* stream) {
    for (int i = 0; i < stream->num_tokens; i++) {
        token* token = &stream->tokens[i];
        printf("Token %d: type = %d, value = %s\n", i, token->type, token->value);
    }
}

int main() {
    char* input = "int main() { return 0; }";
    token_stream* stream = create_token_stream(input);
    print_token_stream(stream);
    free_token_stream(stream);
    return 0;
}