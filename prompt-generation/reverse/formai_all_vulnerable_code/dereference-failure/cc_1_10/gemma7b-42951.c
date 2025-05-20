//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Parser {
    Node* head;
    char* buffer;
    int position;
    int state;
} Parser;

Parser* parser_init() {
    Parser* parser = malloc(sizeof(Parser));
    parser->head = NULL;
    parser->buffer = NULL;
    parser->position = 0;
    parser->state = 0;
    return parser;
}

void parser_parse(Parser* parser) {
    switch (parser->state) {
        case 0:
            if (parser->buffer[parser->position] == '(') {
                parser->state = 1;
            } else if (parser->buffer[parser->position] == ')') {
                parser->state = 3;
            } else {
                parser->state = 2;
            }
            break;
        case 1:
            if (parser->buffer[parser->position] == ')') {
                parser->state = 2;
            } else {
                parser->state = 1;
            }
            break;
        case 2:
            if (parser->buffer[parser->position] == ')') {
                parser->state = 3;
            } else {
                parser->state = 0;
            }
            break;
        case 3:
            parser->state = 0;
            break;
    }

    parser->position++;
}

int main() {
    char* str = "((())())";
    Parser* parser = parser_init();
    parser->buffer = str;

    while (parser->buffer[parser->position] != '\0') {
        parser_parse(parser);
    }

    free(parser);

    return 0;
}