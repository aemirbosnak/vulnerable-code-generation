//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Parser {
    char* buffer;
    int position;
    Node* head;
    int syntaxError;
} Parser;

Parser* parser_init(int capacity) {
    Parser* parser = malloc(sizeof(Parser));
    parser->buffer = malloc(capacity * MAX_BUFFER_SIZE);
    parser->position = 0;
    parser->head = NULL;
    parser->syntaxError = 0;

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
    char token;

    while ((token = parser->buffer[parser->position]) != '\0') {
        switch (token) {
            case '(':
                parser_add_node(parser, token);
                break;
            case ')':
                parser_add_node(parser, token);
                break;
            case ',':
                parser_add_node(parser, token);
                break;
            default:
                parser->syntaxError = 1;
                break;
        }

        parser->position++;
    }
}

int main() {
    Parser* parser = parser_init(10);
    parser->buffer = "((,))";

    parser_parse(parser);

    if (parser->syntaxError) {
        printf("Syntax error.\n");
    } else {
        printf("Parsing successful.\n");
    }

    return 0;
}