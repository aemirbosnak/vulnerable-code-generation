//Falcon2-11B DATASET v1.0 Category: Building a XML Parser ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

#define MAX_LEN 1000
#define PI 3.14159

typedef struct node {
    char *value;
    struct node *next;
} node;

typedef struct xml_parser {
    node *head;
    node *tail;
} xml_parser;

void append(xml_parser *parser, char *str) {
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    temp->value = strdup(str);
    temp->next = NULL;

    if (parser->tail == NULL) {
        parser->head = temp;
        parser->tail = temp;
    } else {
        parser->tail->next = temp;
        parser->tail = parser->tail->next;
    }
}

void print_xml(xml_parser *parser) {
    if (parser->head == NULL) {
        printf("Empty XML parser.\n");
        return;
    }

    node *current = parser->head;
    while (current!= NULL) {
        printf("%s", current->value);
        current = current->next;
    }
}

int main() {
    xml_parser parser;
    parser.head = NULL;
    parser.tail = NULL;

    append(&parser, "<?xml version=\"1.0\"?>");
    append(&parser, "<book>");
    append(&parser, "  <title>The Great Gatsby</title>");
    append(&parser, "  <author>F. Scott Fitzgerald</author>");
    append(&parser, "  <year>1925</year>");
    append(&parser, "</book>");

    print_xml(&parser);

    return 0;
}