//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSONParser {
    char **buffer;
    int size;
    int pos;
    int allocatedSize;
} JSONParser;

JSONParser *jsonParser_init(int size) {
    JSONParser *parser = malloc(sizeof(JSONParser));
    parser->buffer = NULL;
    parser->size = 0;
    parser->pos = 0;
    parser->allocatedSize = size;

    parser->buffer = malloc(size * sizeof(char));

    return parser;
}

void jsonParser_free(JSONParser *parser) {
    free(parser->buffer);
    free(parser);
}

void jsonParser_append(JSONParser *parser, char data) {
    if (parser->size == parser->allocatedSize) {
        parser->allocatedSize *= 2;
        parser->buffer = realloc(parser->buffer, parser->allocatedSize * sizeof(char));
    }

    parser->buffer[parser->size++] = data;
}

char *jsonParser_get(JSONParser *parser) {
    return parser->buffer;
}

int main() {
    JSONParser *parser = jsonParser_init(MAX_BUFFER_SIZE);

    jsonParser_append(parser, '{');
    jsonParser_append(parser, '"');
    jsonParser_append(parser, "name");
    jsonParser_append(parser, '"');
    jsonParser_append(parser, ':');
    jsonParser_append(parser, '"');
    jsonParser_append(parser, "John Doe");
    jsonParser_append(parser, '}');

    char *jsonString = jsonParser_get(parser);

    printf("%s", jsonString);

    jsonParser_free(parser);

    return 0;
}