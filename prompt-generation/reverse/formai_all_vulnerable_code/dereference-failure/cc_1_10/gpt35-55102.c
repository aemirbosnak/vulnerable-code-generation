//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *tag;
    char *value;
    struct Node *child;
    struct Node *sibling;
} Node;

Node *createNode(char *tag, char *value) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->tag = tag;
    newNode->value = value;
    newNode->child = NULL;
    newNode->sibling = NULL;
    return newNode;
}

void addChildNode(Node *parent, Node *child) {
    if (parent->child == NULL) {
        parent->child = child;
    } else {
        Node *sibling = parent->child;
        while (sibling->sibling != NULL) {
            sibling = sibling->sibling;
        }
        sibling->sibling = child;
    }
}

void parseXML(Node *parent, char *xml) {
    char *openingTag = strchr(xml, '<');
    while (openingTag != NULL) {
        char *closingTag = strchr(openingTag, '>');
        char *tag = openingTag + 1;
        int tagLength = closingTag - tag;
        char *value = closingTag + 1;
        if (*value != '<') {
            char *closingTagStart = strstr(value, "</");
            if (closingTagStart != NULL) {
                *closingTagStart = '\0';
            }
            Node *child = createNode(tag, value);
            addChildNode(parent, child);
            parseXML(child, closingTagStart + 2);
        } else {
            Node *child = createNode(tag, NULL);
            addChildNode(parent, child);
            parseXML(child, closingTag + 1);
        }
        openingTag = strchr(value, '<');
    }
}

void printXML(Node *node) {
    if (node == NULL) {
        return;
    }
    printf("<%s>", node->tag);
    if (node->value != NULL) {
        printf("%s", node->value);
    }
    if (node->child != NULL) {
        printXML(node->child);
    }
    printf("</%s>", node->tag);
    if (node->sibling != NULL) {
        printXML(node->sibling);
    }
}

int main() {
    char *xml =
            "<root>"
            "<person>"
            "<name>John</name>"
            "<age>25</age>"
            "</person>"
            "<person>"
            "<name>Jane</name>"
            "<age>30</age>"
            "</person>"
            "</root>";
    Node *root = createNode("root", NULL);
    parseXML(root, xml);
    printXML(root);
    return 0;
}