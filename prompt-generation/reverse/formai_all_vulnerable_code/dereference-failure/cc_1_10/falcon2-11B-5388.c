//Falcon2-11B DATASET v1.0 Category: Building a XML Parser ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a struct to hold the XML node
struct XMLNode {
    char *name;
    char *value;
    struct XMLNode *children;
};

// A function to create a new XML node
struct XMLNode *newXMLNode(char *name, char *value, struct XMLNode *children) {
    struct XMLNode *node = (struct XMLNode *)malloc(sizeof(struct XMLNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    node->name = strdup(name);
    node->value = strdup(value);
    node->children = children;
    return node;
}

// A function to parse an XML node
struct XMLNode *parseXMLNode(char *node, struct XMLNode *parent) {
    char *name = strtok(node, " \t\n");
    char *value = strtok(NULL, " \t\n");

    struct XMLNode *nodePtr = newXMLNode(name, value, NULL);
    parent->children = nodePtr;
    return parent;
}

// A function to parse the entire XML document
struct XMLNode *parseXML(char *xml) {
    struct XMLNode *root = newXMLNode("root", xml, NULL);
    return root;
}

int main() {
    char xml[] = "<root> <node1>text1</node1> <node2>text2</node2> </root>";
    struct XMLNode *root = parseXML(xml);
    printf("Root Node: %s %s\n", root->name, root->value);
    struct XMLNode *node1 = root->children;
    printf("Node 1: %s %s\n", node1->name, node1->value);
    struct XMLNode *node2 = node1->children;
    printf("Node 2: %s %s\n", node2->name, node2->value);
    return 0;
}