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
    char* current_lexeme;
    int current_position;
    int line_number;
} Parser;

Parser* parser_init(int line_number) {
    Parser* parser = malloc(sizeof(Parser));
    parser->head = NULL;
    parser->current_lexeme = NULL;
    parser->current_position = 0;
    parser->line_number = line_number;
    return parser;
}

void parser_add_node(Parser* parser, char data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = parser->head;
    parser->head = new_node;
}

void parser_lexeme(Parser* parser, char* lexeme) {
    parser->current_lexeme = lexeme;
}

void parser_position(Parser* parser, int position) {
    parser->current_position = position;
}

void parser_line_number(Parser* parser, int line_number) {
    parser->line_number = line_number;
}

int main() {
    Parser* parser = parser_init(1);
    parser_add_node(parser, 'a');
    parser_add_node(parser, 'b');
    parser_add_node(parser, 'c');
    parser_lexeme(parser, "abc");
    parser_position(parser, 2);
    parser_line_number(parser, 2);

    printf("Current Lexeme: %s\n", parser->current_lexeme);
    printf("Current Position: %d\n", parser->current_position);
    printf("Line Number: %d\n", parser->line_number);

    return 0;
}