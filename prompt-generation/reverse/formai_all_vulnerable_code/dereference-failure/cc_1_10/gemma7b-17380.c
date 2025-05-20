//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Parser {
    Node* head;
    char* buffer;
    int index;
    int size;
} Parser;

Parser* parser_init(int size) {
    Parser* parser = malloc(sizeof(Parser));
    parser->head = NULL;
    parser->buffer = malloc(size * MAX_BUFFER_SIZE);
    parser->index = 0;
    parser->size = size;
    return parser;
}

void parser_parse(Parser* parser, char data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = parser->head;
    parser->head = node;
}

void parser_free(Parser* parser) {
    free(parser->buffer);
    free(parser->head);
    free(parser);
}

int main() {
    Parser* parser = parser_init(10);
    parser_parse(parser, 'a');
    parser_parse(parser, 'b');
    parser_parse(parser, 'c');
    parser_parse(parser, 'd');
    parser_free(parser);

    return 0;
}