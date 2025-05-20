//Falcon-180B DATASET v1.0 Category: Building a JSON Parser ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_LEN 1024
#define MAX_DEPTH 1000

typedef struct {
    char *key;
    char *value;
    int is_object;
    int is_array;
} json_token;

typedef struct {
    json_token **tokens;
    int num_tokens;
    int depth;
} json_parser;

json_parser *json_parser_create() {
    json_parser *parser = (json_parser *)malloc(sizeof(json_parser));
    parser->tokens = (json_token **)malloc(MAX_DEPTH * sizeof(json_token *));
    parser->num_tokens = 0;
    parser->depth = 0;
    return parser;
}

void json_parser_destroy(json_parser *parser) {
    for (int i = 0; i < parser->num_tokens; i++) {
        free(parser->tokens[i]->key);
        free(parser->tokens[i]->value);
        free(parser->tokens[i]);
    }
    free(parser->tokens);
    free(parser);
}

void json_parser_reset(json_parser *parser) {
    parser->num_tokens = 0;
    parser->depth = 0;
}

int json_parser_feed(json_parser *parser, const char *data) {
    char *token = strtok(data, "{}[],:");
    while (token!= NULL) {
        if (parser->num_tokens >= MAX_DEPTH) {
            printf("Error: Maximum parsing depth exceeded.\n");
            return -1;
        }
        json_token *new_token = (json_token *)malloc(sizeof(json_token));
        new_token->key = strdup(token);
        new_token->value = NULL;
        new_token->is_object = 0;
        new_token->is_array = 0;
        parser->tokens[parser->num_tokens++] = new_token;
        token = strtok(NULL, "{}[],:");
    }
    return 0;
}

json_token *json_parser_get_token(json_parser *parser, int index) {
    if (index < 0 || index >= parser->num_tokens) {
        return NULL;
    }
    return parser->tokens[index];
}

int json_parser_is_object(json_parser *parser) {
    if (parser->depth == 0) {
        return 0;
    }
    return parser->tokens[parser->depth - 1]->is_object;
}

int json_parser_is_array(json_parser *parser) {
    if (parser->depth == 0) {
        return 0;
    }
    return parser->tokens[parser->depth - 1]->is_array;
}

int main() {
    char input[MAX_TOKEN_LEN];
    json_parser *parser = json_parser_create();

    while (fgets(input, MAX_TOKEN_LEN, stdin)!= NULL) {
        json_parser_feed(parser, input);
    }

    json_parser_destroy(parser);
    return 0;
}