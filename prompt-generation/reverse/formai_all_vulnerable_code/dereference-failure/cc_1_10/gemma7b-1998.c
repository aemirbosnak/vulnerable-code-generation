//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

typedef struct XMLParser {
    Node **root;
    int current_level;
    char **buffer;
    int buffer_size;
    int buffer_position;
} XMLParser;

void XMLParser_init(XMLParser *parser) {
    parser->root = NULL;
    parser->current_level = 0;
    parser->buffer = NULL;
    parser->buffer_size = MAX_BUFFER_SIZE;
    parser->buffer_position = 0;
}

void XMLParser_parse(XMLParser *parser, char *xml_data) {
    parser->buffer = realloc(parser->buffer, parser->buffer_size * sizeof(char) * (parser->buffer_position + 1));
    parser->buffer[parser->buffer_position++] = xml_data[0];

    if (xml_data[0] == '<') {
        parser->current_level++;
        Node *newNode = malloc(sizeof(Node));
        newNode->data = strdup(xml_data);
        newNode->next = parser->root;
        parser->root = newNode;
    } else if (xml_data[0] == '>') {
        parser->current_level--;
    }
}

int main() {
    XMLParser parser;
    XMLParser_init(&parser);

    char xml_data[] = "<root><child>This is a sample XML data</child></root>";
    XMLParser_parse(&parser, xml_data);

    Node *node = parser.root;
    while (node) {
        printf("%s\n", node->data);
        node = node->next;
    }

    return 0;
}