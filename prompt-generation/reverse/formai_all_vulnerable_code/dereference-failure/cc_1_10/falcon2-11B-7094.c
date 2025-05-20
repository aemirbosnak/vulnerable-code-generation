//Falcon2-11B DATASET v1.0 Category: Building a XML Parser ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *tag;
    char *value;
    struct node *next;
} Node;

typedef struct xml_parser {
    Node *head;
    Node *tail;
} XMLParser;

void add_node(XMLParser *parser, char *tag, char *value) {
    Node *new_node = malloc(sizeof(Node));
    new_node->tag = strdup(tag);
    new_node->value = strdup(value);
    new_node->next = NULL;

    if (parser->tail == NULL) {
        parser->head = new_node;
        parser->tail = new_node;
    } else {
        parser->tail->next = new_node;
        parser->tail = new_node;
    }
}

void print_nodes(XMLParser *parser) {
    Node *curr = parser->head;
    while (curr!= NULL) {
        printf("Tag: %s, Value: %s\n", curr->tag, curr->value);
        curr = curr->next;
    }
}

int main() {
    XMLParser parser;
    parser.head = NULL;
    parser.tail = NULL;

    // Example usage:
    add_node(&parser, "person", "John Doe");
    add_node(&parser, "name", "Jane Doe");
    add_node(&parser, "age", "30");

    print_nodes(&parser);

    return 0;
}