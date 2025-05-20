//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonParser {
    char **buffer;
    int size;
    int position;
    int state;
} JsonParser;

JsonParser *parser_init(int size) {
    JsonParser *parser = malloc(sizeof(JsonParser));
    parser->buffer = malloc(size * sizeof(char));
    parser->size = size;
    parser->position = 0;
    parser->state = 0;
    return parser;
}

void parser_free(JsonParser *parser) {
    free(parser->buffer);
    free(parser);
}

void parser_parse(JsonParser *parser, char *json_string) {
    parser->buffer[parser->position++] = *json_string;
    switch (parser->state) {
    case 0:
        if (*json_string == '{') {
            parser->state = 1;
        } else if (*json_string == '"') {
            parser->state = 2;
        } else if (*json_string == ',') {
            parser->state = 3;
        } else if (*json_string == '}') {
            parser->state = 4;
        } else {
            parser->state = 0;
        }
        break;
    case 1:
        if (*json_string == '"') {
            parser->state = 2;
        } else if (*json_string == ',') {
            parser->state = 3;
        } else if (*json_string == '}') {
            parser->state = 4;
        } else {
            parser->state = 1;
        }
        break;
    case 2:
        if (*json_string == '"') {
            parser->state = 3;
        } else if (*json_string == ',') {
            parser->state = 3;
        } else if (*json_string == '}') {
            parser->state = 4;
        } else {
            parser->state = 2;
        }
        break;
    case 3:
        if (*json_string == ',') {
            parser->state = 3;
        } else if (*json_string == '}') {
            parser->state = 4;
        } else {
            parser->state = 3;
        }
        break;
    case 4:
        parser->state = 0;
        break;
    }
}

int main() {
    char json_string[] = "{ 'name': 'John Doe', 'age': 30 }";
    JsonParser *parser = parser_init(MAX_BUFFER_SIZE);
    parser_parse(parser, json_string);
    parser_free(parser);
    return 0;
}