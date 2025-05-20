//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonParser {
    char** buffer;
    int size;
    int capacity;
    int pos;
    int depth;
} JsonParser;

JsonParser* parser_init(int capacity) {
    JsonParser* parser = malloc(sizeof(JsonParser));
    parser->buffer = NULL;
    parser->size = 0;
    parser->capacity = capacity;
    parser->pos = 0;
    parser->depth = 0;
    return parser;
}

void parser_push(JsonParser* parser, char* data) {
    if (parser->size >= parser->capacity) {
        parser->buffer = realloc(parser->buffer, parser->capacity * 2);
        parser->capacity *= 2;
    }
    parser->buffer[parser->size++] = data;
}

void parser_pop(JsonParser* parser) {
    parser->size--;
}

void parser_set_depth(JsonParser* parser, int depth) {
    parser->depth = depth;
}

char* parser_get_data(JsonParser* parser) {
    return parser->buffer[parser->pos];
}

void parser_free(JsonParser* parser) {
    free(parser->buffer);
    free(parser);
}

int main() {
    JsonParser* parser = parser_init(MAX_BUFFER_SIZE);
    parser_push(parser, "key: value");
    parser_push(parser, ",");
    parser_push(parser, "another key: another value");
    parser_push(parser, "}");

    parser_set_depth(parser, 2);

    printf("Current data: %s\n", parser_get_data(parser));

    parser_pop(parser);
    parser_pop(parser);

    printf("Updated data: %s\n", parser_get_data(parser));

    parser_free(parser);

    return 0;
}