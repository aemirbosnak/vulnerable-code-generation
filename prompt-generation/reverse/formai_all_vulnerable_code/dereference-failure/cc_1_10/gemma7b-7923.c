//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Parser {
    Node* head;
    Node* tail;
    char current_symbol;
    int state;
} Parser;

#define MAX_STATE 5

void init_parser(Parser* parser) {
    parser->head = NULL;
    parser->tail = NULL;
    parser->current_symbol = '\0';
    parser->state = 0;
}

void add_node(Parser* parser, char symbol) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = symbol;
    new_node->next = NULL;

    if (parser->head == NULL) {
        parser->head = new_node;
        parser->tail = new_node;
    } else {
        parser->tail->next = new_node;
        parser->tail = new_node;
    }
}

void parse_expression(Parser* parser) {
    switch (parser->state) {
        case 0:
            if (parser->current_symbol == '(') {
                add_node(parser, parser->current_symbol);
                parser->state = 1;
            } else if (parser->current_symbol == ')') {
                printf("Syntax error: Missing parenthesis.\n");
            } else {
                add_node(parser, parser->current_symbol);
                parser->state = 2;
            }
            break;
        case 1:
            if (parser->current_symbol == ')') {
                add_node(parser, parser->current_symbol);
                parser->state = 0;
            } else {
                add_node(parser, parser->current_symbol);
                parser->state = 2;
            }
            break;
        case 2:
            if (parser->current_symbol == '+') {
                add_node(parser, parser->current_symbol);
                parser->state = 3;
            } else if (parser->current_symbol == '-') {
                add_node(parser, parser->current_symbol);
                parser->state = 3;
            } else if (parser->current_symbol == '*') {
                add_node(parser, parser->current_symbol);
                parser->state = 3;
            } else if (parser->current_symbol == '/') {
                add_node(parser, parser->current_symbol);
                parser->state = 3;
            } else if (parser->current_symbol == ')') {
                printf("Syntax error: Unexpected symbol.\n");
            } else {
                add_node(parser, parser->current_symbol);
                parser->state = 0;
            }
            break;
        default:
            printf("Syntax error: Invalid state.\n");
    }
}

int main() {
    Parser parser;
    init_parser(&parser);

    parser.current_symbol = 'a';
    parse_expression(&parser);

    parser.current_symbol = 'b';
    parse_expression(&parser);

    parser.current_symbol = ')';
    parse_expression(&parser);

    return 0;
}