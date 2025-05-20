//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSONParser {
    char **buffer;
    int size;
    int pos;
    int allocSize;
} JSONParser;

JSONParser *parser_init(int allocSize) {
    JSONParser *parser = malloc(sizeof(JSONParser));

    parser->buffer = NULL;
    parser->size = 0;
    parser->pos = 0;
    parser->allocSize = allocSize;

    return parser;
}

void parser_free(JSONParser *parser) {
    free(parser->buffer);
    free(parser);
}

void parser_append(JSONParser *parser, char data) {
    if (parser->size == parser->allocSize) {
        parser->allocSize *= 2;
        parser->buffer = realloc(parser->buffer, parser->allocSize);
    }

    parser->buffer[parser->size++] = data;
}

int parser_get_string(JSONParser *parser, char **string) {
    int i = parser->pos;
    char quote = 0;
    *string = malloc(MAX_BUFFER_SIZE);

    while (parser->buffer[i] && parser->buffer[i] != '"') {
        if (parser->buffer[i] == '\\') {
            i++;
        }

        *string[i - parser->pos] = parser->buffer[i];
        i++;
    }

    *string[i - parser->pos] = '\0';

    parser->pos = i + 1;

    return 0;
}

int main() {
    char json_string[] = "{ 'name': 'John Doe', 'age': 30 }";
    JSONParser *parser = parser_init(MAX_BUFFER_SIZE);

    for (int i = 0; json_string[i] != '\0'; i++) {
        parser_append(parser, json_string[i]);
    }

    char *name = NULL;
    parser_get_string(parser, &name);

    printf("Name: %s\n", name);

    parser_free(parser);

    return 0;
}