//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonParser
{
    char **buffer;
    int size;
    int position;
    struct JsonParser *next;
} JsonParser;

JsonParser *parser_init(int size)
{
    JsonParser *parser = malloc(sizeof(JsonParser));
    parser->buffer = malloc(size * MAX_BUFFER_SIZE);
    parser->size = size;
    parser->position = 0;
    parser->next = NULL;

    return parser;
}

void parser_parse(JsonParser *parser, char *json_string)
{
    parser->buffer[parser->position++] = *json_string++;

    if (*json_string == '\0')
    {
        parser->buffer[parser->position] = '\0';
        parser->position = 0;
    }
}

void parser_free(JsonParser *parser)
{
    free(parser->buffer);
    free(parser);
}

int main()
{
    JsonParser *parser = parser_init(10);
    parser_parse(parser, "{ \"name\": \"John Doe\", \"age\": 30 }");
    parser_parse(parser, ", \"occupation\": \"Software Engineer\"");
    parser_parse(parser, "}");

    printf("%s\n", parser->buffer);

    parser_free(parser);

    return 0;
}