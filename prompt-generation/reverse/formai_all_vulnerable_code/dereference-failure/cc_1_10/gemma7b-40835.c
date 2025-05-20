//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

typedef struct JsonParser {
    Node *head;
    int depth;
    char currentKey[MAX_BUFFER_SIZE];
    char currentValue[MAX_BUFFER_SIZE];
    char isArray[MAX_BUFFER_SIZE];
} JsonParser;

JsonParser *parser_init() {
    JsonParser *parser = malloc(sizeof(JsonParser));
    parser->head = NULL;
    parser->depth = 0;
    parser->currentKey[0] = '\0';
    parser->currentValue[0] = '\0';
    parser->isArray[0] = '\0';
    return parser;
}

void parser_parse(JsonParser *parser, char *json) {
    char *buffer = malloc(MAX_BUFFER_SIZE);
    int index = 0;
    int state = 0;

    while (json[index] != '\0') {
        switch (state) {
            case 0:
                if (json[index] == '{') {
                    state = 1;
                } else if (json[index] == '[') {
                    state = 2;
                } else if (json[index] == '"') {
                    state = 3;
                }
                break;
            case 1:
                if (json[index] == '"') {
                    parser->currentKey[0] = '\0';
                    index++;
                    while (json[index] != '"') {
                        strcat(parser->currentKey, json + index);
                        index++;
                    }
                    index++;
                    state = 4;
                }
                break;
            case 2:
                if (json[index] == ']') {
                    state = 0;
                }
                break;
            case 3:
                parser->currentValue[0] = '\0';
                index++;
                while (json[index] != '"') {
                    strcat(parser->currentValue, json + index);
                    index++;
                }
                index++;
                parser->isArray[0] = '\0';
                if (json[index] == ']') {
                    parser->isArray[0] = '1';
                }
                state = 0;
                break;
            default:
                break;
        }
        index++;
    }

    free(buffer);
}

int main() {
    char json[] = "{ 'name': 'John Doe', 'age': 30, 'interests': [ 'music', 'reading', 'coding' ] }";
    JsonParser *parser = parser_init();
    parser_parse(parser, json);

    printf("Current Key: %s\n", parser->currentKey);
    printf("Current Value: %s\n", parser->currentValue);
    printf("Is Array: %s\n", parser->isArray);

    return 0;
}