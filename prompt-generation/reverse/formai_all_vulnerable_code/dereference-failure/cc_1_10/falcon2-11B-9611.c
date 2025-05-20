//Falcon2-11B DATASET v1.0 Category: Building a XML Parser ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the structure for holding XML node data
typedef struct {
    char *name;
    char *value;
    struct {
        char *name;
        char *value;
        struct {
            char *name;
            char *value;
        } *children;
    } *children;
} Node;

// Recursive function to parse XML data
Node* parseXML(char *data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->name = strdup(data);
    node->value = strdup(data);
    node->children = NULL;

    if (data[0] == '<') {
        char *tag = strstr(data, "<");
        if (tag == NULL) {
            return NULL;
        }
        char *endTag = strstr(data, ">");
        if (endTag == NULL) {
            return NULL;
        }

        // Extract tag name and value
        char *name = strndup(data, tag - data);
        char *value = strndup(data + 1, endTag - data - 1);

        // Create a new node
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->name = strdup(name);
        newNode->value = strdup(value);
        newNode->children = NULL;

        // Recursively parse child nodes
        parseXML(data + strlen(name) + 1);

        // Add the new node as a child of the current node
        node->children = (struct {
            char *name;
            char *value;
            struct {
                char *name;
                char *value;
            } *children;
        } *)malloc(sizeof(struct {
            char *name;
            char *value;
            struct {
                char *name;
                char *value;
            } *children;
        }));
        node->children->name = strdup(name);
        node->children->value = strdup(value);
        node->children->children = newNode;

        free(tag);
        free(endTag);
    }

    return node;
}

int main() {
    char *data = "<root><child>Hello</child><child>World</child></root>";
    Node *root = parseXML(data);

    if (root!= NULL) {
        printf("Root Node: %s %s\n", root->name, root->value);
        for (Node *child = root->children; child!= NULL; child = child->children) {
            printf("Child Node: %s %s\n", child->name, child->value);
        }
    }

    return 0;
}