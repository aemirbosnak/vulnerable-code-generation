//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSONParser {
    char **buffer;
    int size;
    int capacity;
} JSONParser;

JSONParser *parser_init(int capacity) {
    JSONParser *parser = malloc(sizeof(JSONParser));
    parser->buffer = malloc(sizeof(char *) * capacity);
    parser->size = 0;
    parser->capacity = capacity;
    return parser;
}

void parser_push(JSONParser *parser, char data) {
    if (parser->size == parser->capacity) {
        parser->buffer = realloc(parser->buffer, (parser->capacity * 2) * sizeof(char *));
        parser->capacity *= 2;
    }
    parser->buffer[parser->size++] = data;
}

char *parser_pop(JSONParser *parser) {
    if (parser->size == 0) {
        return NULL;
    }
    return parser->buffer[--parser->size];
}

int main() {
    JSONParser *parser = parser_init(MAX_BUFFER_SIZE);
    parser_push(parser, '{');
    parser_push(parser, '"');
    parser_push(parser, "name");
    parser_push(parser, ':');
    parser_push(parser, '"');
    parser_push(parser, "John Doe");
    parser_push(parser, '}');

    char *json_string = parser_pop(parser);
    printf("%s\n", json_string);

    free(parser->buffer);
    free(parser);

    return 0;
}