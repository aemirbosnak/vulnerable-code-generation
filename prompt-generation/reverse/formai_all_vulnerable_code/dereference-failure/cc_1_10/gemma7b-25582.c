//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: scalable
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
    int size;
} JsonParser;

JsonParser *jsonParser_create(int size) {
    JsonParser *parser = (JsonParser *)malloc(sizeof(JsonParser));
    parser->head = NULL;
    parser->size = size;
    return parser;
}

void jsonParser_add(JsonParser *parser, char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = strdup(data);
    newNode->next = NULL;

    if (parser->head == NULL) {
        parser->head = newNode;
    } else {
        parser->head->next = newNode;
    }

    parser->size++;
}

char *jsonParser_get(JsonParser *parser, int index) {
    Node *current = parser->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

void jsonParser_free(JsonParser *parser) {
    Node *current = parser->head;
    while (current) {
        Node *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(parser);
}

int main() {
    JsonParser *parser = jsonParser_create(10);
    jsonParser_add(parser, "John Doe");
    jsonParser_add(parser, "Jane Doe");
    jsonParser_add(parser, "Peter Pan");

    char *name = jsonParser_get(parser, 1);
    printf("Name: %s\n", name);

    jsonParser_free(parser);

    return 0;
}