//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *key;
    struct Node *next;
    void *data;
} Node;

typedef struct JSONParser {
    Node **root;
    int depth;
    char **buffer;
    int bufferSize;
    int pos;
    int state;
    int quoteState;
} JSONParser;

JSONParser *parser_init(int size)
{
    JSONParser *parser = (JSONParser *)malloc(sizeof(JSONParser));
    parser->root = NULL;
    parser->depth = 0;
    parser->buffer = (char *)malloc(size * MAX_BUFFER_SIZE);
    parser->bufferSize = size * MAX_BUFFER_SIZE;
    parser->pos = 0;
    parser->state = 0;
    parser->quoteState = 0;

    return parser;
}

void parser_parse(JSONParser *parser, char c)
{
    switch (parser->state) {
        case 0:
            switch (c) {
                case '{':
                    parser->state = 1;
                    break;
                case ' ':
                    break;
                default:
                    parser->state = -1;
                    break;
            }
            break;
        case 1:
            switch (c) {
                case '"':
                    parser->quoteState = 1;
                    break;
                case ':':
                    parser->state = 2;
                    break;
                default:
                    parser->state = -1;
                    break;
            }
            break;
        case 2:
            switch (c) {
                case '"':
                    parser->quoteState = 0;
                    break;
                case ',':
                    parser->state = 3;
                    break;
                default:
                    parser->state = -1;
                    break;
            }
            break;
        case 3:
            switch (c) {
                case '}':
                    parser->state = 0;
                    break;
                default:
                    parser->state = -1;
                    break;
            }
            break;
        default:
            parser->state = -1;
            break;
    }

    if (parser->quoteState) {
        parser->buffer[parser->pos++] = c;
    } else if (c != '\n' && c != '\r') {
        parser->buffer[parser->pos++] = c;
    }
}

void parser_finalize(JSONParser *parser)
{
    free(parser->buffer);
    free(parser);
}

int main()
{
    JSONParser *parser = parser_init(1024);
    parser_parse(parser, '{');
    parser_parse(parser, "foo");
    parser_parse(parser, ":");
    parser_parse(parser, 12);
    parser_parse(parser, '}');

    parser_finalize(parser);

    return 0;
}