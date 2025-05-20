//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: thoughtful
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
    int buffer_size;
    int current_position;
    int line_number;
} Parser;

Parser* parser_init(int buffer_size) {
    Parser* parser = malloc(sizeof(Parser));
    parser->head = NULL;
    parser->buffer = malloc(buffer_size);
    parser->buffer_size = buffer_size;
    parser->current_position = 0;
    parser->line_number = 1;
    return parser;
}

void parser_add_node(Parser* parser, char data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (parser->head == NULL) {
        parser->head = new_node;
    } else {
        parser->head->next = new_node;
        parser->head = new_node;
    }
}

void parser_parse(Parser* parser, char* str) {
    parser_add_node(parser, str[0]);

    for (int i = 1; str[i] != '\0'; i++) {
        parser_add_node(parser, str[i]);
    }
}

int main() {
    Parser* parser = parser_init(MAX_BUFFER_SIZE);
    parser_parse(parser, "abc");

    Node* current_node = parser->head;
    while (current_node) {
        printf("%c ", current_node->data);
        current_node = current_node->next;
    }

    free(parser->buffer);
    free(parser);

    return 0;
}