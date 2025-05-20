//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 256

typedef struct XMLNode {
    char tag[MAX_TAG_LENGTH];
    char value[MAX_LINE_LENGTH];
    struct XMLNode *next;
    struct XMLNode *child;
} XMLNode;

// Function declarations
XMLNode* createNode(const char* tag);
void freeXML(XMLNode* node);
void parseXML(FILE* file, XMLNode* currentNode);
void printXML(XMLNode* node, int depth);
void handleTag(char* line, XMLNode* currentNode);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Create a root node
    XMLNode* rootNode = createNode("root");
    parseXML(file, rootNode);
    fclose(file);

    // Print the parsed XML structure
    printXML(rootNode, 0);

    // Free allocated memory
    freeXML(rootNode);
    return 0;
}

// Function implementations
XMLNode* createNode(const char* tag) {
    XMLNode* newNode = (XMLNode*)malloc(sizeof(XMLNode));
    strcpy(newNode->tag, tag);
    newNode->value[0] = '\0';
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

void freeXML(XMLNode* node) {
    if (!node) return;
    freeXML(node->child);
    freeXML(node->next);
    free(node);
}

void parseXML(FILE* file, XMLNode* currentNode) {
    char line[MAX_LINE_LENGTH];
    XMLNode* lastChild = NULL;

    while (fgets(line, sizeof(line), file)) {
        handleTag(line, currentNode);
    }
}

void handleTag(char* line, XMLNode* currentNode) {
    char* tagStart = strchr(line, '<');
    char* tagEnd = strchr(line, '>');

    if (tagStart && tagEnd && tagStart < tagEnd) {
        *tagEnd = '\0'; // Temporarily terminate string
        char tag[MAX_TAG_LENGTH];

        // Extract tag name
        sscanf(tagStart + 1, "%s", tag);
        *tagEnd = '>'; // Restore delimiter

        // Create a new node
        XMLNode* newNode = createNode(tag);

        // Check for closing tag or standalone tag
        if (strstr(tag, "/") == NULL) {
            // Handle potential child nodes
            if (currentNode->child == NULL) {
                currentNode->child = newNode;
            } else {
                XMLNode* temp = currentNode->child;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            // Recurse into the child
            currentNode = newNode;
        } else {
            // Reset to the previous node
            currentNode = currentNode->next;
        }

        // Capture content for elements (simple case for illustrative purposes)
        char* contentStart = strrchr(line, '>') + 1;
        if (contentStart) {
            char* contentEnd = strchr(contentStart, '<');
            if (contentEnd) {
                size_t contentLength = contentEnd - contentStart;
                strncpy(newNode->value, contentStart, contentLength);
                newNode->value[contentLength] = '\0'; // Null-terminate value
            }
        }
    }
}

void printXML(XMLNode* node, int depth) {
    if (!node) return;

    for (int i = 0; i < depth; i++) {
        printf("    "); // Indentation for nested tags
    }
    printf("<%s>%s</%s>\n", node->tag, node->value, node->tag);
    
    printXML(node->child, depth + 1);
    printXML(node->next, depth);
}