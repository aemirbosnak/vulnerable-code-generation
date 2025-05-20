//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct JsonParser {
    Node* head;
    char* buffer;
    int bufferSize;
} JsonParser;

JsonParser* parser_init(int size) {
    JsonParser* parser = malloc(sizeof(JsonParser));
    parser->head = NULL;
    parser->buffer = NULL;
    parser->bufferSize = size;

    return parser;
}

void parser_free(JsonParser* parser) {
    free(parser->buffer);
    free(parser);
}

void parser_append(JsonParser* parser, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (parser->head == NULL) {
        parser->head = newNode;
    } else {
        parser->head->next = newNode;
        parser->head = newNode;
    }

    parser->buffer = realloc(parser->buffer, parser->bufferSize * 2);
    parser->bufferSize *= 2;
}

char parser_get(JsonParser* parser) {
    if (parser->head == NULL) {
        return '\0';
    }

    return parser->head->data;
}

int main() {
    JsonParser* parser = parser_init(MAX_BUFFER_SIZE);
    parser_append(parser, 'a');
    parser_append(parser, 'b');
    parser_append(parser, 'c');
    parser_append(parser, 'd');

    char data = parser_get(parser);
    printf("%c\n", data);

    parser_free(parser);

    return 0;
}