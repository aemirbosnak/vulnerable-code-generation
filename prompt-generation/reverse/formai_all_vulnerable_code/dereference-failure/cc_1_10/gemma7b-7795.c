//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonParser {
    char *buffer;
    int pos;
    int size;
} JsonParser;

JsonParser *parser_init() {
    JsonParser *parser = malloc(sizeof(JsonParser));
    parser->buffer = NULL;
    parser->pos = 0;
    parser->size = 0;
    return parser;
}

void parser_free(JsonParser *parser) {
    free(parser->buffer);
    free(parser);
}

void parser_append(JsonParser *parser, char data) {
    if (parser->size == parser->buffer) {
        parser->buffer = realloc(parser->buffer, parser->size * 2);
        parser->size *= 2;
    }
    parser->buffer[parser->pos++] = data;
}

int parser_parse_string(JsonParser *parser) {
    int i = parser->pos;
    char *string_start = parser->buffer + i;
    while (parser->buffer[parser->pos] != '"') {
        parser_append(parser, parser->buffer[parser->pos]);
        parser->pos++;
    }
    parser_append(parser, '\0');
    return parser->pos - i + 1;
}

int parser_parse_number(JsonParser *parser) {
    int i = parser->pos;
    char *number_start = parser->buffer + i;
    while (parser->buffer[parser->pos] >= '0' && parser->buffer[parser->pos] <= '9') {
        parser_append(parser, parser->buffer[parser->pos]);
        parser->pos++;
    }
    parser_append(parser, '\0');
    return parser->pos - i + 1;
}

int parser_parse_object(JsonParser *parser) {
    int i = parser->pos;
    parser_append(parser, '{');
    parser->pos++;
    while (parser->buffer[parser->pos] != '}') {
        parser_parse_string(parser);
        parser_append(parser, ':');
        parser->pos++;
        parser_parse_value(parser);
        parser_append(parser, ',');
        parser->pos++;
    }
    parser_append(parser, '}');
    parser->pos++;
    return parser->pos - i + 1;
}

int parser_parse_array(JsonParser *parser) {
    int i = parser->pos;
    parser_append(parser, '[');
    parser->pos++;
    while (parser->buffer[parser->pos] != ']') {
        parser_parse_value(parser);
        parser_append(parser, ',');
        parser->pos++;
    }
    parser_append(parser, ']');
    parser->pos++;
    return parser->pos - i + 1;
}

int parser_parse_value(JsonParser *parser) {
    if (parser->buffer[parser->pos] == '"') {
        return parser_parse_string(parser);
    } else if (parser->buffer[parser->pos] >= '0' && parser->buffer[parser->pos] <= '9') {
        return parser_parse_number(parser);
    } else if (parser->buffer[parser->pos] == '{') {
        return parser_parse_object(parser);
    } else if (parser->buffer[parser->pos] == '[') {
        return parser_parse_array(parser);
    }
    return 0;
}

int main() {
    JsonParser *parser = parser_init();
    parser_append(parser, '{"name": "John Doe", "age": 30}');
    parser_parse_value(parser);
    printf("%s\n", parser->buffer);
    parser_free(parser);
    return 0;
}