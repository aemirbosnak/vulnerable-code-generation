//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 64
#define MAX_TEXT_LENGTH 256
#define MAX_CHILDREN 10

typedef struct XMLNode {
    char tagName[MAX_TAG_NAME];
    char text[MAX_TEXT_LENGTH];
    struct XMLNode *children[MAX_CHILDREN];
    int childCount;
} XMLNode;

XMLNode* createNode(const char *tagName) {
    XMLNode *node = (XMLNode *)malloc(sizeof(XMLNode));
    strncpy(node->tagName, tagName, MAX_TAG_NAME);
    node->text[0] = '\0'; // Initialize text to empty
    node->childCount = 0; // Initialize child count to 0
    return node;
}

void freeNode(XMLNode *node) {
    if (node) {
        for (int i = 0; i < node->childCount; i++) {
            freeNode(node->children[i]);
        }
        free(node);
    }
}

void addChild(XMLNode *parent, XMLNode *child) {
    if (parent->childCount < MAX_CHILDREN) {
        parent->children[parent->childCount++] = child;
    } else {
        printf("Error: Maximum number of children reached for tag: %s\n", parent->tagName);
    }
}

void parseXML(const char *xml, XMLNode *currentNode) {
    const char *cursor = xml;
    char tag[MAX_TAG_NAME];
    char textBuffer[MAX_TEXT_LENGTH];
    
    while (*cursor) {
        // If a tag starts
        if (*cursor == '<') {
            cursor++;
            if (*cursor == '/') { // Closing tag
                // Move to the end of the closing tag
                while (*cursor != '>' && *cursor) cursor++;
                cursor++; // Skip '>'
                return; // Exit this function to go back to parent node
            }

            // Read tag name
            int tagIndex = 0;
            while (*cursor && *cursor != '>' && *cursor != ' ') {
                tag[tagIndex++] = *cursor++;
            }
            tag[tagIndex] = '\0'; // Null-terminate

            XMLNode *newNode = createNode(tag);
            addChild(currentNode, newNode);

            // Skip to the end of the opening tag
            while (*cursor != '>' && *cursor) cursor++;
            cursor++; // Skip '>'
        } else if (*cursor != '<') {
            // Read text if it is not a tag
            int textIndex = 0;
            while (*cursor && *cursor != '<') {
                if (textIndex < MAX_TEXT_LENGTH - 1) {
                    textBuffer[textIndex++] = *cursor++;
                }
            }
            textBuffer[textIndex] = '\0'; // Null-terminate
            // Append text to the current node's text
            strncpy(currentNode->text, textBuffer, MAX_TEXT_LENGTH);
        }
    }
}

void printNode(XMLNode *node, int depth) {
    if (node) {
        for (int i = 0; i < depth; i++)
            printf("  "); // Indentation
        printf("<%s>", node->tagName);
        if (strlen(node->text) > 0) {
            printf("%s", node->text);
        }
        printf("\n");
        for (int i = 0; i < node->childCount; i++) {
            printNode(node->children[i], depth + 1);
        }
        for (int i = 0; i < depth; i++)
            printf("  "); // Indentation
        printf("</%s>\n", node->tagName);
    }
}

int main() {
    const char *xmlData = "<root><child>Hello</child><child>World</child></root>";

    XMLNode *rootNode = createNode("root");
    parseXML(xmlData, rootNode);

    printf("Parsed XML Structure:\n");
    printNode(rootNode, 0);

    freeNode(rootNode); // Cleanup memory
    return 0;
}