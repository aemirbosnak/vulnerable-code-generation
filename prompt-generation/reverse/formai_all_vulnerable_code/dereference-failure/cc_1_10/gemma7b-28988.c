//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonParser {
    char **buffer;
    int size;
    int position;
    int is_string;
    struct JsonParser *next;
} JsonParser;

JsonParser *createParser(int size) {
    JsonParser *parser = malloc(sizeof(JsonParser));
    parser->buffer = malloc(size * MAX_BUFFER_SIZE);
    parser->size = size;
    parser->position = 0;
    parser->is_string = 0;
    parser->next = NULL;
    return parser;
}

void parseJson(JsonParser *parser) {
    char c;
    parser->position++;

    switch (c = parser->buffer[parser->position - 1]) {
        case '"':
            parser->is_string = 1;
            break;
        case ':':
            parser->is_string = 0;
            break;
        case ',':
            parser->is_string = 0;
            break;
        case ' ':
            parser->is_string = 0;
            break;
        default:
            break;
    }

    if (parser->is_string) {
        printf("String: %s\n", parser->buffer);
    } else {
        printf("Value: %c\n", c);
    }
}

int main() {
    JsonParser *parser = createParser(10);
    parser->buffer[0] = '{';
    parser->buffer[1] = '"';
    parser->buffer[2] = "name";
    parser->buffer[3] = ':';
    parser->buffer[4] = '"';
    parser->buffer[5] = "John Doe";
    parser->buffer[6] = '}';

    parseJson(parser);

    return 0;
}