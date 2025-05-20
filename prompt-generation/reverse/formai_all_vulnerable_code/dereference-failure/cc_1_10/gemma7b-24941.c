//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Parser {
    Node* head;
    char* input_string;
    int position;
} Parser;

void parse_string(Parser* parser) {
    parser->head = NULL;
    parser->input_string = parser->input_string;
    parser->position = 0;

    while (parser->position < strlen(parser->input_string)) {
        char current_char = parser->input_string[parser->position];

        Node* new_node = malloc(sizeof(Node));
        new_node->data = current_char;
        new_node->next = NULL;

        if (parser->head == NULL) {
            parser->head = new_node;
        } else {
            parser->head->next = new_node;
            parser->head = new_node;
        }

        parser->position++;
    }
}

int main() {
    Parser* parser = malloc(sizeof(Parser));
    parser->head = NULL;
    parser->input_string = "abc";
    parser->position = 0;

    parse_string(parser);

    Node* current_node = parser->head;
    while (current_node) {
        printf("%c ", current_node->data);
        current_node = current_node->next;
    }

    free(parser);

    return 0;
}