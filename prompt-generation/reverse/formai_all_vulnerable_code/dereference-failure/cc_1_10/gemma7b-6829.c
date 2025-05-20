//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct JsonParser {
    char **buffer;
    int size;
    int position;
    int state;
} JsonParser;

void JsonParser_init(JsonParser *parser) {
    parser->buffer = NULL;
    parser->size = 0;
    parser->position = 0;
    parser->state = 0;
}

void JsonParser_parse(JsonParser *parser, char *json_string) {
    parser->buffer = realloc(parser->buffer, (parser->size + 1) * MAX_BUFFER_SIZE);
    parser->buffer[parser->size++] = json_string[parser->position];
    parser->position++;

    switch (parser->state) {
        case 0:
            if (json_string[parser->position] == '"') {
                parser->state = 1;
            } else if (json_string[parser->position] == '}') {
                parser->state = 4;
            }
            break;
        case 1:
            if (json_string[parser->position] == '"') {
                parser->state = 2;
            } else if (json_string[parser->position] == ':') {
                parser->state = 3;
            }
            break;
        case 2:
            if (json_string[parser->position] == '"') {
                parser->state = 1;
            }
            break;
        case 3:
            if (json_string[parser->position] == '}') {
                parser->state = 0;
            }
            break;
        case 4:
            if (json_string[parser->position] == ',') {
                parser->state = 0;
            } else if (json_string[parser->position] == '}') {
                parser->state = 0;
            }
            break;
    }
}

int main() {
    JsonParser parser;
    JsonParser_init(&parser);

    char json_string[] = "{ 'name': 'John Doe', 'age': 30 }";
    JsonParser_parse(&parser, json_string);

    printf("Name: %s\n", parser.buffer[0]);
    printf("Age: %d\n", parser.buffer[1]);

    return 0;
}