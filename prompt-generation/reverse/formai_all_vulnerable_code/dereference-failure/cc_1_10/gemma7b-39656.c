//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Parser {
    Node* head;
    char current_state;
    char previous_state;
} Parser;

void parser_init(Parser* parser) {
    parser->head = NULL;
    parser->current_state = 'S';
    parser->previous_state = 'N';
}

void parser_parse(Parser* parser, char symbol) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = symbol;
    new_node->next = NULL;

    if (parser->head == NULL) {
        parser->head = new_node;
    } else {
        parser->head->next = new_node;
        parser->head = new_node;
    }

    switch (symbol) {
        case 'a':
            parser->current_state = 'a';
            break;
        case 'b':
            parser->current_state = 'b';
            break;
        case 'c':
            parser->current_state = 'c';
            break;
        default:
            parser->current_state = 'S';
            break;
    }

    parser->previous_state = parser->current_state;
}

int main() {
    Parser parser;
    parser_init(&parser);

    parser_parse(&parser, 'a');
    parser_parse(&parser, 'b');
    parser_parse(&parser, 'c');

    printf("Current state: %c\n", parser.current_state);
    printf("Previous state: %c\n", parser.previous_state);

    return 0;
}