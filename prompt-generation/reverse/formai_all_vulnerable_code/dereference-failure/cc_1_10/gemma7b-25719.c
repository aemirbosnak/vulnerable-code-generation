//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct JsonParser {
    Node* head;
    int depth;
    char currentKey[256];
    char currentValue[256];
} JsonParser;

JsonParser* parser_init() {
    JsonParser* parser = malloc(sizeof(JsonParser));
    parser->head = NULL;
    parser->depth = 0;
    parser->currentKey[0] = '\0';
    parser->currentValue[0] = '\0';
    return parser;
}

void parser_parse(JsonParser* parser, char* jsonStr) {
    parser->depth++;
    parser->currentKey[0] = '\0';
    parser->currentValue[0] = '\0';

    Node* newNode = malloc(sizeof(Node));
    newNode->data = jsonStr[0];
    newNode->next = parser->head;
    parser->head = newNode;

    switch (jsonStr[0]) {
        case '"':
            parser->currentKey[0] = jsonStr[1];
            for (int i = 2; jsonStr[i] != '"'; i++) {
                parser->currentKey[i - 2] = jsonStr[i];
            }
            parser->currentKey[parser->currentKey - parser->currentValue] = '\0';
            break;
        case '{' :
            parser->currentValue[0] = jsonStr[1];
            for (int i = 2; jsonStr[i] != '}'; i++) {
                parser->currentValue[i - 2] = jsonStr[i];
            }
            parser->currentValue[parser->currentValue - parser->currentKey] = '\0';
            break;
        case '[' :
            parser->currentValue[0] = jsonStr[1];
            for (int i = 2; jsonStr[i] != ']'; i++) {
                parser->currentValue[i - 2] = jsonStr[i];
            }
            parser->currentValue[parser->currentValue - parser->currentKey] = '\0';
            break;
    }
    parser->depth--;
}

int main() {
    char* jsonStr = "{ 'name': 'John Doe', 'age': 30, 'interests': ['music', 'reading', 'coding'] }";
    JsonParser* parser = parser_init();
    parser_parse(parser, jsonStr);

    printf("Key: %s, Value: %s\n", parser->currentKey, parser->currentValue);
    printf("Depth: %d\n", parser->depth);

    return 0;
}