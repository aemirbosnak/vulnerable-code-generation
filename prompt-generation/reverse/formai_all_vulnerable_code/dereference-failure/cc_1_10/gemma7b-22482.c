//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Parser {
    Node* head;
    char* current_string;
    int current_position;
} Parser;

Parser* parser_init(char* str) {
    Parser* parser = malloc(sizeof(Parser));
    parser->head = NULL;
    parser->current_string = str;
    parser->current_position = 0;
    return parser;
}

void parser_parse(Parser* parser) {
    char c = parser->current_string[parser->current_position];
    if (c == '\0') {
        return;
    }

    Node* node = malloc(sizeof(Node));
    node->data = c;
    node->next = parser->head;
    parser->head = node;

    parser->current_position++;
    parser_parse(parser);
}

int main() {
    char* str = "abc";
    Parser* parser = parser_init(str);
    parser_parse(parser);

    Node* node = parser->head;
    while (node) {
        printf("%c ", node->data);
        node = node->next;
    }

    return 0;
}