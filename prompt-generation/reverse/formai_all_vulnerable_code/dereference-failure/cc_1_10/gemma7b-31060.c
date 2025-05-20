//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data[MAX_BUFFER_SIZE];
    struct Node* next;
} Node;

typedef struct JSONParser {
    Node* head;
    int currentPosition;
    char buffer[MAX_BUFFER_SIZE];
    int bufferPosition;
} JSONParser;

JSONParser* parser_init(void) {
    JSONParser* parser = malloc(sizeof(JSONParser));
    parser->head = NULL;
    parser->currentPosition = 0;
    parser->bufferPosition = 0;
    return parser;
}

void parser_parse(JSONParser* parser, char* json) {
    parser->bufferPosition = 0;
    strcpy(parser->buffer, json);

    char* currentToken = strtok(parser->buffer, ",:");
    while (currentToken) {
        Node* newNode = malloc(sizeof(Node));
        newNode->next = parser->head;
        parser->head = newNode;

        char* key = strtok(currentToken, ":");
        strcpy(newNode->data, key);

        currentToken = strtok(NULL, ",:");
    }
}

void parser_print(JSONParser* parser) {
    Node* currentNode = parser->head;
    while (currentNode) {
        printf("%s:", currentNode->data);
        printf("\n");
        currentNode = currentNode->next;
    }
}

int main() {
    JSONParser* parser = parser_init();
    parser_parse(parser, "{ \"name\": \"John Doe\", \"age\": 30 }");
    parser_print(parser);

    return 0;
}