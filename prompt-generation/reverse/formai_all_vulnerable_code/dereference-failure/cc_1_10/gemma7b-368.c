//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: protected
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Parser {
    Node* head;
    int state;
    char current_symbol;
} Parser;

Parser* parser_init() {
    Parser* parser = malloc(sizeof(Parser));
    parser->head = NULL;
    parser->state = 0;
    parser->current_symbol = '\0';
    return parser;
}

void parser_add_symbol(Parser* parser, char symbol) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = symbol;
    new_node->next = NULL;

    if (parser->head == NULL) {
        parser->head = new_node;
    } else {
        parser->head->next = new_node;
        parser->head = new_node;
    }
}

void parser_parse(Parser* parser) {
    switch (parser->state) {
        case 0:
            if (parser->current_symbol == 'a') {
                parser_add_symbol(parser, 'b');
                parser->state = 1;
            } else {
                printf("Error: expected a\n");
            }
            break;
        case 1:
            if (parser->current_symbol == 'b') {
                parser_add_symbol(parser, 'c');
                parser->state = 2;
            } else {
                printf("Error: expected b\n");
            }
            break;
        case 2:
            if (parser->current_symbol == 'c') {
                printf("Success!\n");
                free(parser);
            } else {
                printf("Error: expected c\n");
            }
            break;
    }
}

int main() {
    Parser* parser = parser_init();
    parser_add_symbol(parser, 'a');
    parser_add_symbol(parser, 'b');
    parser_add_symbol(parser, 'c');
    parser_parse(parser);

    return 0;
}