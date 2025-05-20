//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the core data structures
typedef struct XMLNode {
    char* name;
    char* value;
    struct XMLNode* children;
    struct XMLNode* siblings;
} XMLNode;

// Our steadfast sentinel, the XML parser
XMLNode* parseXML(const char* xml) {
    // Initialize the root node
    XMLNode* root = malloc(sizeof(XMLNode));
    memset(root, 0, sizeof(XMLNode));

    // Navigate the XML labyrinth
    const char* start = xml;
    const char* end = start;
    while (*end != '\0') {
        // Isolate a node
        while (*end != '<' && *end != '\0') {
            end++;
        }

        // Retrieve the node's name
        if (*end == '<') {
            const char* nameStart = start + 1;
            const char* nameEnd = end;
            root->name = strndup(nameStart, nameEnd - nameStart);
        }

        // Isolate the node's value
        start = end;
        while (*end != '>' && *end != '\0') {
            end++;
        }

        if (*end == '>') {
            const char* valueStart = start + 1;
            const char* valueEnd = end;
            root->value = strndup(valueStart, valueEnd - valueStart);
        }

        // Parse child nodes
        if (*end == '>') {
            root->children = parseXML(end + 1);
        }

        // Increment the end pointer
        end++;
        start = end;
    }

    return root;
}

// A quaint function to traverse the parsed XML
void printXML(XMLNode* node) {
    // Display node information
    printf("%s: ", node->name);
    if (node->value != NULL) {
        printf("%s\n", node->value);
    } else {
        printf("\n");
    }

    // Recursively traverse the XML tree
    XMLNode* child = node->children;
    while (child != NULL) {
        printXML(child);
        child = child->siblings;
    }
}

// Release the allocated memory
void freeXML(XMLNode* node) {
    if (node == NULL) {
        return;
    }

    freeXML(node->children);
    freeXML(node->siblings);

    free(node->name);
    free(node->value);
    free(node);
}

int main() {
    // The XML document we wish to decipher
    const char* xml = "<root><child1>Hello</child1><child2><grandchild1>World</grandchild1><grandchild2>!</grandchild2></child2></root>";

    // Invoke the XML parser
    XMLNode* root = parseXML(xml);

    // Traverse and display the parsed XML structure
    printXML(root);

    // Liberate the allocated memory
    freeXML(root);

    return 0;
}