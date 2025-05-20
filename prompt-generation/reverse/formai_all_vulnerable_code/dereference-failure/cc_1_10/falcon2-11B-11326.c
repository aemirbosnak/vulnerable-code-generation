//Falcon2-11B DATASET v1.0 Category: Building a XML Parser ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* tag;
    char* content;
    struct Node* next;
} Node;

typedef struct XMLParser {
    Node* head;
    Node* tail;
    Node* current;
} XMLParser;

XMLParser* createXMLParser() {
    XMLParser* parser = (XMLParser*)malloc(sizeof(XMLParser));
    parser->head = NULL;
    parser->tail = NULL;
    parser->current = NULL;
    return parser;
}

void appendToParser(XMLParser* parser, char* tag, char* content) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->tag = tag;
    newNode->content = content;
    newNode->next = NULL;

    if (parser->head == NULL) {
        parser->head = newNode;
        parser->tail = newNode;
    } else {
        parser->tail->next = newNode;
        parser->tail = newNode;
    }
}

void printXML(XMLParser* parser) {
    Node* current = parser->head;
    while (current!= NULL) {
        printf("%s%s%s\n", current->tag, current->content, current->next? " " : "");
        current = current->next;
    }
}

int main() {
    XMLParser* parser = createXMLParser();

    appendToParser(parser, "root", "This is the root node");
    appendToParser(parser, "child", "This is a child node");
    appendToParser(parser, "another-child", "This is another child node");

    printXML(parser);

    return 0;
}