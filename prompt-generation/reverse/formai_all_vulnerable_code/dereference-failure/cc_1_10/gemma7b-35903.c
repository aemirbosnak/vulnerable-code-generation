//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonParser {
    char *buffer;
    int position;
    int size;
    struct JsonParser *next;
} JsonParser;

JsonParser *parseJson(char *jsonString) {
    JsonParser *parser = (JsonParser *)malloc(sizeof(JsonParser));

    parser->buffer = (char *)malloc(MAX_BUFFER_SIZE);
    parser->position = 0;
    parser->size = MAX_BUFFER_SIZE;
    parser->next = NULL;

    parser->buffer = jsonString;
    parser->position = 0;

    return parser;
}

void parseJsonData(JsonParser *parser) {
    char currentChar;
    int isQuote = 0;
    int isNumber = 0;
    char numberBuffer[1024];

    while (parser->position < parser->size) {
        currentChar = parser->buffer[parser->position];

        if (isQuote && currentChar != '"') {
            numberBuffer[parser->position - 1] = currentChar;
            parser->position++;
        } else if (isNumber && currentChar == '"') {
            numberBuffer[parser->position - 1] = '\0';
            printf("%s\n", numberBuffer);
            parser->position++;
            isNumber = 0;
        } else if (currentChar == '"') {
            isQuote = 1;
            parser->position++;
        } else if (currentChar == '{' || currentChar == '[') {
            parser->position++;
        } else if (currentChar == '}') {
            parser->position++;
        } else if (currentChar == '}') {
            parser->position++;
        } else {
            parser->position++;
        }
    }
}

int main() {
    char jsonString[] = "{ 'name': 'John Doe', 'age': 30 }";
    JsonParser *parser = parseJson(jsonString);
    parseJsonData(parser);
    free(parser->buffer);
    free(parser);

    return 0;
}