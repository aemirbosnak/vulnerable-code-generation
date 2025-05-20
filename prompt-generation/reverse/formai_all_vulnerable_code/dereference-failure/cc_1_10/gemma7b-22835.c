//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: scalable
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
} Parser;

Parser* parser_init(int buffer_size) {
    Parser* parser = malloc(sizeof(Parser));
    parser->head = NULL;
    parser->buffer = malloc(buffer_size);
    parser->buffer_size = buffer_size;
    parser->current_position = 0;

    return parser;
}

void parser_parse(Parser* parser, char input) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = input;
    new_node->next = NULL;

    if (parser->head == NULL) {
        parser->head = new_node;
    } else {
        parser->head->next = new_node;
        parser->head = new_node;
    }
}

void parser_print(Parser* parser) {
    Node* current_node = parser->head;

    while (current_node) {
        printf("%c ", current_node->data);
        current_node = current_node->next;
    }

    printf("\n");
}

int main() {
    Parser* parser = parser_init(MAX_BUFFER_SIZE);

    parser_parse(parser, 'a');
    parser_parse(parser, 'b');
    parser_parse(parser, 'c');
    parser_parse(parser, 'd');

    parser_print(parser);

    free(parser->buffer);
    free(parser);

    return 0;
}