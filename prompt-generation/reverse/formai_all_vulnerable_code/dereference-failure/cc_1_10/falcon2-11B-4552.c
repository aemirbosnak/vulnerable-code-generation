//Falcon2-11B DATASET v1.0 Category: Building a XML Parser ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *tag;
    char *value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    char *name;
} XMLParser;

void add_node(Node **node, char *tag, char *value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->tag = strdup(tag);
    newNode->value = strdup(value);
    newNode->next = *node;
    *node = newNode;
}

void add_to_xml(XMLParser *parser, char *tag, char *value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->tag = strdup(tag);
    newNode->value = strdup(value);
    newNode->next = NULL;
    add_node(&parser->head, tag, value);
}

void parse_xml(XMLParser *parser, char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    char line[1000];
    while (fgets(line, sizeof(line), file)) {
        char *tag = strtok(line, " \t\n");
        char *value = strtok(NULL, " \t\n");
        if (strcmp(tag, "") && strcmp(value, "")) {
            add_to_xml(parser, tag, value);
        }
    }
    fclose(file);
}

void print_xml(XMLParser *parser) {
    Node *node = parser->head;
    while (node!= NULL) {
        printf("  %s %s\n", node->tag, node->value);
        node = node->next;
    }
}

int main() {
    XMLParser parser;
    parser.name = "root";
    add_to_xml(&parser, "tag1", "value1");
    add_to_xml(&parser, "tag2", "value2");
    parse_xml(&parser, "example.xml");
    print_xml(&parser);
    return 0;
}