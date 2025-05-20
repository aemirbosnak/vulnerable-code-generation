//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Parser {
    Node* head;
    char** grammar;
    int grammar_size;
    int current_state;
    int next_state;
} Parser;

Parser* parser_init(int grammar_size, char** grammar) {
    Parser* parser = malloc(sizeof(Parser));
    parser->head = NULL;
    parser->grammar = grammar;
    parser->grammar_size = grammar_size;
    parser->current_state = 0;
    parser->next_state = 0;
    return parser;
}

void parser_parse(Parser* parser, char input) {
    // Transition to the next state based on the input and the current state
    parser->next_state = parser->grammar[parser->current_state][input] - 1;

    // If the next state is not -1, create a new node and add it to the linked list
    if (parser->next_state != -1) {
        Node* node = malloc(sizeof(Node));
        node->data = input;
        node->next = parser->head;
        parser->head = node;
    }

    // Update the current state to the next state
    parser->current_state = parser->next_state;
}

void parser_finalize(Parser* parser) {
    free(parser->head);
    free(parser);
}

int main() {
    char** grammar = {"S -> AB", "A -> a", "B -> b"};
    int grammar_size = 3;

    Parser* parser = parser_init(grammar_size, grammar);

    parser_parse(parser, 'a');
    parser_parse(parser, 'b');
    parser_parse(parser, 'b');

    parser_finalize(parser);

    return 0;
}