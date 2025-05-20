//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct XMLNode {
    char *tagName;
    char *value;
    struct XMLNode **children;
    int childrenCount;
} XMLNode;

// Function to create a new XML node
XMLNode *createXMLNode(const char *tagName, const char *value) {
    XMLNode *node = (XMLNode *)malloc(sizeof(XMLNode));
    node->tagName = strdup(tagName);
    node->value = value ? strdup(value) : NULL;
    node->children = NULL;
    node->childrenCount = 0;
    return node;
}

// Function to add child node
void addChild(XMLNode *parent, XMLNode *child) {
    parent->childrenCount++;
    parent->children = (XMLNode **)realloc(parent->children, sizeof(XMLNode *) * parent->childrenCount);
    parent->children[parent->childrenCount - 1] = child;
}

// Function to free XML node
void freeXMLNode(XMLNode *node) {
    if (node->tagName) free(node->tagName);
    if (node->value) free(node->value);
    for (int i = 0; i < node->childrenCount; i++) {
        freeXMLNode(node->children[i]);
    }
    free(node->children);
    free(node);
}

// Function to parse XML string into XMLNode structure
XMLNode *parseXML(const char *xml) {
    XMLNode *root = NULL;
    XMLNode *currentNode = NULL;
    char tagName[256];
    char value[256];
    int i = 0, j = 0;
    
    while (xml[i]) {
        if (xml[i] == '<') {
            // Close tag
            if (xml[i + 1] == '/') {
                i += 2; // Move past </
                while (xml[i] != '>') {
                    i++;
                }
                i++; // Move past >
                currentNode = currentNode->childrenCount > 0 ? currentNode : root; // End current node
            } else {
                // Open tag
                i++; // Move past <
                j = 0;
                while (xml[i] != '>' && xml[i] != ' ') {
                    tagName[j++] = xml[i++];
                }
                tagName[j] = '\0';
                j = 0;

                // Handle value
                while (xml[i] == ' ') i++; // Skip whitespace
                while (xml[i] != '<') {
                    value[j++] = xml[i++];
                }
                value[j] = '\0';
                i--; // To fall back to '<' for the next loop

                XMLNode *newNode = createXMLNode(tagName, value);
                if (!root) root = newNode; // Set root node
                if (currentNode) addChild(currentNode, newNode); // Add child to current node
                currentNode = newNode; // Move current node
            }
        }
        i++;
    }
    return root;
}

// Function to print XML tree
void printXML(XMLNode *node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>", node->tagName);
    if (node->value) {
        printf("%s", node->value);
    }
    printf("\n");
    for (int i = 0; i < node->childrenCount; i++) {
        printXML(node->children[i], depth + 1);
    }
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("</%s>\n", node->tagName);
}

int main() {
    const char *xmlData = "<root> <child1>Value 1</child1> <child2>Value 2</child2> </root>";
    
    XMLNode *parsedXML = parseXML(xmlData);
    if (parsedXML) {
        printXML(parsedXML, 0);
        freeXMLNode(parsedXML);
    } else {
        printf("Failed to parse XML\n");
    }
    
    return 0;
}