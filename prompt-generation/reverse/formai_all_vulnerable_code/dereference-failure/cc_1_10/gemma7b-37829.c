//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSONParser {
    char **buffer;
    int size;
    int pos;
    int alloc_size;
} JSONParser;

JSONParser *json_parser_init(int size) {
    JSONParser *parser = (JSONParser *)malloc(sizeof(JSONParser));
    parser->buffer = (char **)malloc(sizeof(char *) * size);
    parser->size = size;
    parser->pos = 0;
    parser->alloc_size = size;
    return parser;
}

void json_parser_free(JSONParser *parser) {
    free(parser->buffer);
    free(parser);
}

void json_parser_add_char(JSONParser *parser, char ch) {
    if (parser->pos >= parser->alloc_size) {
        parser->buffer = (char **)realloc(parser->buffer, (parser->alloc_size * 2) * sizeof(char *));
        parser->alloc_size *= 2;
    }
    parser->buffer[parser->pos++] = ch;
}

char *json_parser_get_string(JSONParser *parser) {
    char *str = NULL;
    int i = parser->pos - 1;
    for (; i >= 0 && parser->buffer[i] != '"'; i--) {}
    str = (char *)malloc(i + 2);
    memcpy(str, parser->buffer, i);
    str[i + 1] = '\0';
    return str;
}

int main() {
    JSONParser *parser = json_parser_init(MAX_BUFFER_SIZE);
    json_parser_add_char(parser, '"');
    json_parser_add_char(parser, '{"');
    json_parser_add_char(parser, "name");
    json_parser_add_char(parser, ":");
    json_parser_add_char(parser, "\"John Doe\"");
    json_parser_add_char(parser, '}');
    json_parser_add_char(parser, '"');

    char *str = json_parser_get_string(parser);
    printf("%s\n", str);

    json_parser_free(parser);
    free(str);

    return 0;
}