//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_NAME_LEN 100
#define MAX_NODE_VALUE_LEN 1000

typedef struct Node {
    char name[MAX_NODE_NAME_LEN];
    char value[MAX_NODE_VALUE_LEN];
    struct Node* next;
} Node;

typedef struct {
    Node* root;
} XMLParser;

XMLParser* createXMLParser() {
    XMLParser* parser = (XMLParser*)malloc(sizeof(XMLParser));
    parser->root = NULL;
    return parser;
}

void destroyXMLParser(XMLParser* parser) {
    Node* curr = parser->root;
    Node* next = NULL;

    while (curr!= NULL) {
        next = curr->next;
        free(curr->name);
        free(curr->value);
        free(curr);
        curr = next;
    }

    free(parser);
}

void startElement(XMLParser* parser, const char* name, const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->name, name, MAX_NODE_NAME_LEN);
    strncpy(newNode->value, value, MAX_NODE_VALUE_LEN);
    newNode->next = parser->root;
    parser->root = newNode;
}

void endElement(XMLParser* parser) {
    parser->root = parser->root->next;
}

void characterData(XMLParser* parser, const char* data) {
    Node* curr = parser->root;

    while (curr!= NULL && strcmp(curr->name, "text")!= 0) {
        curr = curr->next;
    }

    if (curr == NULL) {
        curr = (Node*)malloc(sizeof(Node));
        strcpy(curr->name, "text");
        strncpy(curr->value, data, MAX_NODE_VALUE_LEN);
        curr->next = parser->root;
        parser->root = curr;
    } else {
        strcat(curr->value, data);
    }
}

int main() {
    XMLParser* parser = createXMLParser();

    char xmlData[] = "<root><child name=\"John\">23</child><child name=\"Jane\">25</child></root>";

    startElement(parser, "root", NULL);

    characterData(parser, "\n  ");
    startElement(parser, "child", "John");
    characterData(parser, "23");
    endElement(parser);

    characterData(parser, "\n  ");
    startElement(parser, "child", "Jane");
    characterData(parser, "25");
    endElement(parser);

    destroyXMLParser(parser);

    return 0;
}