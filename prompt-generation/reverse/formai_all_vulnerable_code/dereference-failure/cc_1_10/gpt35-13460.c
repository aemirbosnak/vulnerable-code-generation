//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

typedef enum { FALSE = 0, TRUE } BOOL;

typedef struct {
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

typedef enum {
    TOKEN_STRING,
    TOKEN_NUMBER,
    TOKEN_INVALID,
    TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    char* value;
} Token;

typedef struct {
    InputBuffer* input;
    Token current_token;
} JSONParser;

void input_buffer_init(InputBuffer* input) {
    input->buffer = NULL;
    input->buffer_length = 0;
    input->input_length = 0;
}

void input_buffer_free(InputBuffer* input) {
    free(input->buffer);
    input->buffer = NULL;
    input->buffer_length = 0;
    input->input_length = 0;
}

void input_buffer_read(InputBuffer* input) {
    ssize_t bytes_read = getline(&(input->buffer), &(input->buffer_length), stdin);

    if (bytes_read <= 0) {
        printf("Error reading input\n");
        exit(EXIT_FAILURE);
    }

    input->input_length = bytes_read - 1;
    input->buffer[bytes_read - 1] = '\0';
}

JSONParser* json_parser_init() {
    JSONParser* parser = malloc(sizeof(JSONParser));

    if (parser == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    parser->input = malloc(sizeof(InputBuffer));

    if (parser->input == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    input_buffer_init(parser->input);

    return parser;
}

void json_parser_free(JSONParser* parser) {
    input_buffer_free(parser->input);
    free(parser->input);
    free(parser);
}

void json_parser_consume_whitespace(JSONParser* parser) {
    while (isspace(*(parser->input->buffer))) {
        ++(parser->input->buffer);
    }
}

Token json_parser_get_string_token(JSONParser* parser) {
    Token token;
    token.type = TOKEN_STRING;

    int buffer_length = 0;
    char* buffer = malloc(sizeof(char) * BUFFER_SIZE);

    if (buffer == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    ++(parser->input->buffer);
    --(parser->input->input_length);

    while (*(parser->input->buffer) != '\0') {
        if (*(parser->input->buffer) == '\"') {
            ++(parser->input->buffer);
            --(parser->input->input_length);
            buffer[buffer_length] = '\0';
            token.value = buffer;
            return token;
        }
        buffer[buffer_length] = *(parser->input->buffer);
        ++buffer_length;
        ++(parser->input->buffer);
        --(parser->input->input_length);
    }

    token.type = TOKEN_INVALID;
    token.value = "Invalid string token";

    return token;
}

Token json_parser_get_number_token(JSONParser* parser) {
    Token token;
    token.type = TOKEN_NUMBER;

    int buffer_length = 0;
    char* buffer = malloc(sizeof(char) * BUFFER_SIZE);

    if (buffer == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (isdigit(*(parser->input->buffer)) || *(parser->input->buffer) == '.') {
        buffer[buffer_length] = *(parser->input->buffer);
        ++buffer_length;
        ++(parser->input->buffer);
        --(parser->input->input_length);
    }

    buffer[buffer_length] = '\0';
    token.value = buffer;

    return token;
}

Token json_parser_get_next_token(JSONParser* parser) {
    json_parser_consume_whitespace(parser);

    if (*(parser->input->buffer) == '\0') {
        Token token;
        token.type = TOKEN_EOF;
        token.value = "";
        return token;
    }

    if (*(parser->input->buffer) == '\"') {
        return json_parser_get_string_token(parser);
    }

    if (isdigit(*(parser->input->buffer))) {
        return json_parser_get_number_token(parser);
    }

    Token token;
    token.type = TOKEN_INVALID;
    token.value = "Invalid token";
    ++(parser->input->buffer);
    --(parser->input->input_length);
    return token;
}

int main() {
    JSONParser* parser = json_parser_init();

    printf("Enter JSON input: ");
    input_buffer_read(parser->input);

    Token token;

    do {
        token = json_parser_get_next_token(parser);

        if (token.type == TOKEN_STRING) {
            printf("String token: %s\n", token.value);
        } else if (token.type == TOKEN_NUMBER) {
            printf("Number token: %s\n", token.value);
        }
    } while (token.type != TOKEN_EOF);

    json_parser_free(parser);

    return 0;
}