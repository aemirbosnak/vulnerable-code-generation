//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_TAG_NAME 64
#define MAX_TAG_VALUE 128

typedef struct XmlNode {
    char tag[MAX_TAG_NAME];
    char value[MAX_TAG_VALUE];
    struct XmlNode *next;
    struct XmlNode *children;
} XmlNode;

XmlNode* createNode(const char *tag, const char *value) {
    XmlNode *newNode = (XmlNode*)malloc(sizeof(XmlNode));
    if (!newNode) {
        fprintf(stderr, "Failed to allocate memory for a new XML node.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->tag, tag, MAX_TAG_NAME);
    strncpy(newNode->value, value, MAX_TAG_VALUE);
    newNode->next = NULL;
    newNode->children = NULL;
    return newNode;
}

void appendChild(XmlNode *parent, XmlNode *child) {
    if (!parent->children) {
        parent->children = child; // If no children, the child becomes the first child
    } else {
        XmlNode *current = parent->children;
        while (current->next) {
            current = current->next; // Traverse to the last child
        }
        current->next = child; // Append the new child
    }
}

void freeNode(XmlNode *node) {
    if (!node) return;
    freeNode(node->children); // Recursively free children
    freeNode(node->next); // Free next sibling
    free(node); // Free current node
}

void printXmlNode(XmlNode *node, int depth) {
    if (!node) return;

    for (int i = 0; i < depth; i++) printf("\t"); // Indention for nested structure
    printf("<%s>%s</%s>\n", node->tag, node->value, node->tag);
    printXmlNode(node->children, depth + 1);
    printXmlNode(node->next, depth);
}

int parseXml(const char *filename, XmlNode **root) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open XML file: %s\n", filename);
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    XmlNode *currentNode = NULL;

    while (fgets(line, sizeof(line), file)) {
        char tag[MAX_TAG_NAME];
        char value[MAX_TAG_VALUE];
        if (sscanf(line, "<%63[^>]>%127[^<]</%63[^>]", tag, value, tag) == 3) {
            XmlNode *newNode = createNode(tag, value);
            if (!currentNode) {
                *root = newNode; // This is the root node
            } else {
                appendChild(currentNode, newNode); // Append new node to the current node
            }
            currentNode = newNode; // Set current node to the newly created node
        } else if (sscanf(line, "</%63[^>]", tag) == 1) {
            if (currentNode) {
                currentNode = NULL; // Close current node
            }
        }
    }

    fclose(file);
    return 0;
}

int main() {
    XmlNode *xmlRoot = NULL;

    const char *filename = "data.xml"; // XML file containing sample data
    if (parseXml(filename, &xmlRoot) == 0) {
        printf("Parsed XML file successfully. Here is the structure:\n");
        printXmlNode(xmlRoot, 0);
    }

    // Free allocated memory for the XML nodes
    freeNode(xmlRoot);
    return 0;
}