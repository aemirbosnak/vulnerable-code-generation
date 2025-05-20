//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

struct JsonParser {
    Node *head;
    char *buffer;
    int position;
    int bufferSize;
    int jsonEnded;
};

void parseJson(struct JsonParser *parser) {
    parser->head = NULL;
    parser->buffer = NULL;
    parser->position = 0;
    parser->bufferSize = MAX_BUFFER_SIZE;
    parser->jsonEnded = 0;
}

void addNode(struct JsonParser *parser, char data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = malloc(sizeof(char) * parser->bufferSize);
    newNode->next = NULL;

    if (parser->head == NULL) {
        parser->head = newNode;
    } else {
        parser->head->next = newNode;
        parser->head = newNode;
    }

    parser->buffer[parser->position] = data;
    parser->position++;

    if (parser->position >= parser->bufferSize - 1) {
        parser->bufferSize *= 2;
        parser->buffer = realloc(parser->buffer, parser->bufferSize);
    }
}

void parseJsonString(struct JsonParser *parser, char *jsonString) {
    parser->buffer = malloc(sizeof(char) * parser->bufferSize);
    parser->position = 0;
    parser->jsonEnded = 0;

    while (*jsonString) {
        char data = *jsonString++;
        addNode(parser, data);
    }

    parser->jsonEnded = 1;
}

int main() {
    struct JsonParser parser;
    parseJson(&parser);
    parseJsonString(&parser, "{ \"name\": \"John Doe\", \"age\": 30 }");

    if (parser.jsonEnded) {
        printf("JSON parsed successfully!\n");
    } else {
        printf("Error parsing JSON.\n");
    }

    return 0;
}