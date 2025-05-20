//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

typedef struct JSONParser {
    Node *head;
    int currentDepth;
} JSONParser;

JSONParser *parser_init(void) {
    JSONParser *parser = malloc(sizeof(JSONParser));
    parser->head = NULL;
    parser->currentDepth = 0;
    return parser;
}

void parser_add_node(JSONParser *parser, char *data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = strdup(data);
    newNode->next = NULL;

    if (parser->head == NULL) {
        parser->head = newNode;
    } else {
        Node *currentNode = parser->head;
        while (currentNode->next) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

void parser_increment_depth(JSONParser *parser) {
    parser->currentDepth++;
}

void parser_decrement_depth(JSONParser *parser) {
    parser->currentDepth--;
}

void parser_parse_json(JSONParser *parser, char *jsonStr) {
    parser_add_node(parser, jsonStr);
    parser_increment_depth(parser);

    // Parse JSON data recursively
    parser_parse_json(parser, strchr(jsonStr, '{') + 1);

    parser_decrement_depth(parser);
}

int main() {
    JSONParser *parser = parser_init();
    parser_parse_json(parser, "{ 'name': 'John Doe', 'age': 30 }");

    Node *currentNode = parser->head;
    while (currentNode) {
        printf("%s\n", currentNode->data);
        currentNode = currentNode->next;
    }

    return 0;
}