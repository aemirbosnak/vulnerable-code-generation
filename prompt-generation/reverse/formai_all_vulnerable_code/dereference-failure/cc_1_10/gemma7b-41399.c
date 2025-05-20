//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Parser {
    Node* head;
    char* buffer;
    int pos;
    int line;
} Parser;

Parser* parser_init() {
    Parser* parser = malloc(sizeof(Parser));
    parser->head = NULL;
    parser->buffer = NULL;
    parser->pos = 0;
    parser->line = 1;
    return parser;
}

void parser_add_node(Parser* parser, char data) {
    Node* node = malloc(sizeof(Node));
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
    char ch;
    while ((ch = parser->buffer[parser->pos]) != '\0') {
        switch (ch) {
            case '(':
                parser_add_node(parser, '(');
                break;
            case ')':
                parser_add_node(parser, ')');
                break;
            case ',':
                parser_add_node(parser, ',');
                break;
            default:
                parser_add_node(parser, ch);
                break;
        }
        parser->pos++;
    }
}

int main() {
    Parser* parser = parser_init();
    parser->buffer = "((a),b)";
    parser_parse(parser);

    Node* node = parser->head;
    while (node) {
        printf("%c ", node->data);
        node = node->next;
    }

    return 0;
}