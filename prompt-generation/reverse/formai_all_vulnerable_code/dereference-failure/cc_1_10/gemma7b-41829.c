//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSONParser {
    char* data;
    int size;
    int pos;
    struct JSONParser* next;
} JSONParser;

JSONParser* parser_init(int size) {
    JSONParser* parser = malloc(sizeof(JSONParser));
    parser->data = malloc(size * MAX_BUFFER_SIZE);
    parser->size = size;
    parser->pos = 0;
    parser->next = NULL;
    return parser;
}

void parser_add(JSONParser* parser, char ch) {
    if (parser->pos >= parser->size) {
        parser->data = realloc(parser->data, (parser->size) * MAX_BUFFER_SIZE * 2);
        parser->size *= 2;
    }
    parser->data[parser->pos++] = ch;
}

int parser_get(JSONParser* parser) {
    return parser->data[parser->pos - 1];
}

void parser_next(JSONParser* parser) {
    parser->pos++;
}

void parser_free(JSONParser* parser) {
    free(parser->data);
    free(parser);
}

int main() {
    JSONParser* parser = parser_init(10);
    parser_add(parser, '{');
    parser_add(parser, '"');
    parser_add(parser, "name");
    parser_add(parser, ':');
    parser_add(parser, "\"John Doe\"");
    parser_add(parser, '}');

    parser_next(parser);
    parser_next(parser);
    int name = parser_get(parser);
    printf("%c\n", name);

    parser_free(parser);

    return 0;
}