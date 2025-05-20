//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSONParser {
    char** buffer;
    int size;
    int index;
} JSONParser;

JSONParser* parser_init(int size) {
    JSONParser* parser = malloc(sizeof(JSONParser));
    parser->buffer = malloc(sizeof(char*) * size);
    parser->size = size;
    parser->index = 0;
    return parser;
}

void parser_free(JSONParser* parser) {
    free(parser->buffer);
    free(parser);
}

int parser_push(JSONParser* parser, char* data) {
    if (parser->index >= parser->size) {
        return -1;
    }

    parser->buffer[parser->index++] = data;
    return 0;
}

int parser_pop(JSONParser* parser) {
    if (parser->index <= 0) {
        return -1;
    }

    parser->index--;
    return 0;
}

int parser_get(JSONParser* parser) {
    if (parser->index <= 0) {
        return -1;
    }

    return parser->buffer[parser->index - 1];
}

int main() {
    JSONParser* parser = parser_init(MAX_BUFFER_SIZE);

    char* json_data = "{ 'name': 'John Doe', 'age': 30 }";

    parser_push(parser, json_data);

    char* name = parser_get(parser);
    int age = atoi(parser_get(parser));

    printf("Name: %s, Age: %d\n", name, age);

    parser_free(parser);

    return 0;
}