//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Parser {
    char* buffer;
    int length;
    int pos;
    Node* head;
} Parser;

Parser* parser_init(int size) {
    Parser* parser = (Parser*)malloc(sizeof(Parser));
    parser->buffer = (char*)malloc(size);
    parser->length = size;
    parser->pos = 0;
    parser->head = NULL;
    return parser;
}

void parser_add(Parser* parser, char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (parser->head == NULL) {
        parser->head = node;
    } else {
        parser->head->next = node;
        parser->head = node;
    }
}

void parser_parse(Parser* parser) {
    while (parser->pos < parser->length && parser->buffer[parser->pos] != '\0') {
        parser_add(parser, parser->buffer[parser->pos]);
        parser->pos++;
    }
}

int main() {
    Parser* parser = parser_init(100);
    parser_add(parser, 'a');
    parser_add(parser, 'b');
    parser_add(parser, 'c');
    parser_add(parser, 'd');
    parser_parse(parser);
    Node* current = parser->head;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
    return 0;
}