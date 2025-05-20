//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LENGTH 100
#define MAX_ATTRIBUTE_LENGTH 100
#define MAX_VALUE_LENGTH 100

typedef struct XMLNode {
    char tag[MAX_TAG_LENGTH];
    struct XMLNode *next;
    struct XMLNode *child;
} XMLNode;

XMLNode* createNode(const char *tag) {
    XMLNode *node = (XMLNode *)malloc(sizeof(XMLNode));
    if (!node) {
        perror("Failed to allocate memory for XMLNode");
        exit(EXIT_FAILURE);
    }
    strcpy(node->tag, tag);
    node->next = NULL;
    node->child = NULL;
    return node;
}

void freeXMLTree(XMLNode *node) {
    if (node) {
        freeXMLTree(node->child);
        freeXMLTree(node->next);
        free(node);
    }
}

XMLNode* parseXML(FILE *file) {
    char buffer[MAX_TAG_LENGTH + 1];
    XMLNode *root = NULL, *lastNode = NULL;

    while (fgets(buffer, sizeof(buffer), file)) {
        char *openTagStart = strchr(buffer, '<');
        if (openTagStart) {
            char *openTagEnd = strchr(openTagStart, '>');
            if (openTagEnd) {
                *openTagEnd = '\0'; // Terminate the string
                XMLNode *newNode = createNode(openTagStart + 1); // Skip '<'

                if (root == NULL) {
                    root = newNode; // First node becomes root
                } else if (lastNode) {
                    lastNode->next = newNode; // Link the nodes
                }

                lastNode = newNode; // Move lastNode to the new one
            }
        }
    }

    return root;
}

void printXML(XMLNode *node, int level) {
    if (node) {
        for (int i = 0; i < level; i++) {
            printf("  "); // Indentation for pretty-printing
        }
        printf("<%s>\n", node->tag); // Print tag
        
        // If there are child nodes, print them recursively
        if (node->child) {
            printXML(node->child, level + 1);
        }

        for (int i = 0; i < level; i++) {
            printf("  "); // Indentation for pretty-printing
        }
        printf("</%s>\n", node->tag); // Closing tag
        
        // Print next sibling if it exists
        if (node->next) {
            printXML(node->next, level);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <xmlfile>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open the XML file");
        return EXIT_FAILURE;
    }

    XMLNode *xmlTree = parseXML(file);
    fclose(file);

    printf("Parsed XML:\n");
    printXML(xmlTree, 0);

    freeXMLTree(xmlTree); // Free allocated memory  
    return EXIT_SUCCESS;
}