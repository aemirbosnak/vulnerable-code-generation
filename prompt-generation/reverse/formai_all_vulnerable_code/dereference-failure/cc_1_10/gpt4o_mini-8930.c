//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_TAG_NAME 50
#define MAX_CONTENT_LENGTH 200

typedef struct XMLNode {
    char tagName[MAX_TAG_NAME];
    char content[MAX_CONTENT_LENGTH];
    struct XMLNode* children[MAX_ELEMENTS];
    int childCount;
} XMLNode;

void initXMLNode(XMLNode* node, const char* tagName) {
    strncpy(node->tagName, tagName, MAX_TAG_NAME - 1);
    node->tagName[MAX_TAG_NAME - 1] = '\0';
    node->content[0] = '\0';
    node->childCount = 0;
}

void addChild(XMLNode* parent, XMLNode* child) {
    if (parent->childCount < MAX_ELEMENTS) {
        parent->children[parent->childCount++] = child;
    } else {
        fprintf(stderr, "Cannot add more children to %s\n", parent->tagName);
    }
}

void freeXMLNode(XMLNode* node) {
    for (int i = 0; i < node->childCount; i++) {
        freeXMLNode(node->children[i]);
    }
    free(node);
}

void parseXML(const char* input, XMLNode* root) {
    const char* cursor = input;
    char tagName[MAX_TAG_NAME];
    char content[MAX_CONTENT_LENGTH];
    int index = 0;
    XMLNode* currentNode = root;

    while (*cursor) {
        if (*cursor == '<') {
            cursor++; // Skip the '<'
            if (*cursor == '/') break; // End of the document
            
            // Read the tag name
            while (*cursor != '>' && *cursor != ' ' && *cursor) {
                tagName[index++] = *cursor++;
            }
            tagName[index] = '\0'; // Null-terminate the tag name
            index = 0;

            // Create a new node
            XMLNode* newNode = (XMLNode*)malloc(sizeof(XMLNode));
            initXMLNode(newNode, tagName);
            addChild(currentNode, newNode);

            currentNode = newNode; // Move the current node

            while (*cursor != '>' && *cursor) { 
                cursor++; // Skip any attributes
            }
            cursor++; // Skip '>'
        } else {
            // Read content until next tag
            while (*cursor && *cursor != '<') {
                if (index < MAX_CONTENT_LENGTH - 1) {
                    content[index++] = *cursor++;
                }
            }
            content[index] = '\0'; // Null-terminate the content

            // Set content for the current node
            strncpy(currentNode->content, content, MAX_CONTENT_LENGTH - 1);
            currentNode->content[MAX_CONTENT_LENGTH - 1] = '\0';
        }
    }
}

void printXMLNode(XMLNode* node, int level) {
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    printf("<%s>%s\n", node->tagName, node->content);
    for (int i = 0; i < node->childCount; i++) {
        printXMLNode(node->children[i], level + 1);
    }
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    printf("</%s>\n", node->tagName);
}

int main() {
    const char* xmlInput = "<root>Hello <child>World</child></root>";
    XMLNode* rootNode = (XMLNode*)malloc(sizeof(XMLNode));
    initXMLNode(rootNode, "root");

    parseXML(xmlInput, rootNode);
    printXMLNode(rootNode, 0);

    freeXMLNode(rootNode);
    return 0;
}