//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

struct expression {
    char *input;
    int length;
    int index;
};

struct expression_parser {
    struct expression expression;
    char *tokens[100];
    int num_tokens;
};

struct expression_parser *create_parser(char *input) {
    struct expression_parser *parser = malloc(sizeof(struct expression_parser));
    parser->expression.input = strdup(input);
    parser->expression.length = strlen(input);
    parser->expression.index = 0;
    parser->num_tokens = 0;
    return parser;
}

void destroy_parser(struct expression_parser *parser) {
    free(parser->expression.input);
    for (int i = 0; i < parser->num_tokens; i++) {
        free(parser->tokens[i]);
    }
    free(parser);
}

char *get_next_token(struct expression_parser *parser) {
    if (parser->expression.index >= parser->expression.length) {
        return NULL;
    }

    char *token = malloc(MAX_INPUT_SIZE);
    int token_length = 0;

    while (parser->expression.index < parser->expression.length && isspace(parser->expression.input[parser->expression.index])) {
        parser->expression.index++;
    }

    while (parser->expression.index < parser->expression.length && !isspace(parser->expression.input[parser->expression.index])) {
        token[token_length++] = parser->expression.input[parser->expression.index++];
    }

    token[token_length] = '\0';
    parser->tokens[parser->num_tokens++] = token;
    return token;
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter an expression: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    struct expression_parser *parser = create_parser(input);
    char *token;
    while ((token = get_next_token(parser)) != NULL) {
        printf("Token: %s\n", token);
    }

    destroy_parser(parser);
    return 0;
}