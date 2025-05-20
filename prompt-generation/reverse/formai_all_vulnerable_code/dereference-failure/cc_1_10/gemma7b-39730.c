//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonParser {
    char **buffer;
    int size;
    int pos;
} JsonParser;

JsonParser *jsonParser_init(int size) {
    JsonParser *parser = (JsonParser *)malloc(sizeof(JsonParser));
    parser->buffer = (char **)malloc(size * sizeof(char *));
    parser->size = size;
    parser->pos = 0;

    return parser;
}

void jsonParser_append(JsonParser *parser, char data) {
    if (parser->pos >= parser->size) {
        parser->buffer = (char **)realloc(parser->buffer, (parser->size * 2) * sizeof(char *));
        parser->size *= 2;
    }

    parser->buffer[parser->pos++] = data;
}

char **jsonParser_get_data(JsonParser *parser) {
    return parser->buffer;
}

int main() {
    JsonParser *parser = jsonParser_init(MAX_BUFFER_SIZE);

    // Parse JSON data
    jsonParser_append(parser, '{');
    jsonParser_append(parser, '"');
    jsonParser_append(parser, "name");
    jsonParser_append(parser, ':');
    jsonParser_append(parser, '"');
    jsonParser_append(parser, "John Doe");
    jsonParser_append(parser, '}');

    // Get parsed data
    char **data = jsonParser_get_data(parser);

    // Print data
    printf("%s\n", data[0]);
    printf("%s\n", data[1]);
    printf("%s\n", data[2]);

    // Free parser
    free(parser->buffer);
    free(parser);

    return 0;
}