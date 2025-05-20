//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonParser {
    char **buffer;
    int bufferSize;
    int pos;
    int depth;
    struct JsonParser **children;
} JsonParser;

JsonParser *JsonParser_Create() {
    JsonParser *parser = malloc(sizeof(JsonParser));
    parser->buffer = NULL;
    parser->bufferSize = MAX_BUFFER_SIZE;
    parser->pos = 0;
    parser->depth = 0;
    parser->children = NULL;

    return parser;
}

void JsonParser_Parse(JsonParser *parser, char *jsonStr) {
    parser->buffer = realloc(parser->buffer, (parser->bufferSize) * (parser->pos + 1));
    parser->buffer[parser->pos++] = *jsonStr;

    switch (*jsonStr) {
        case '{' :
            parser->children = realloc(parser->children, (parser->depth + 1) * sizeof(JsonParser *));
            parser->children[parser->depth] = JsonParser_Create();
            parser->children[parser->depth]->depth = parser->depth + 1;
            JsonParser_Parse(parser->children[parser->depth], jsonStr + 1);
            break;
        case '}' :
            parser->depth--;
            break;
        case '"':
            parser->children = realloc(parser->children, (parser->depth + 1) * sizeof(JsonParser *));
            parser->children[parser->depth] = JsonParser_Create();
            parser->children[parser->depth]->depth = parser->depth + 1;
            JsonParser_Parse(parser->children[parser->depth], jsonStr + 1);
            break;
        default :
            break;
    }
}

int main() {
    char jsonStr[] = "{ 'name': 'Claude Shannon', 'age': 100 }";
    JsonParser *parser = JsonParser_Create();
    JsonParser_Parse(parser, jsonStr);

    return 0;
}