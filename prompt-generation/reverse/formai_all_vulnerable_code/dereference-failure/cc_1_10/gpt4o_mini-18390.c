//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 100
#define MAX_CONTENT_LENGTH 512
#define MAX_CHILDREN 10

typedef struct XMLNode {
    char tagName[MAX_TAG_NAME];
    char content[MAX_CONTENT_LENGTH];
    struct XMLNode* children[MAX_CHILDREN];
    int childCount;
} XMLNode;

XMLNode* createNode(const char* tagName) {
    XMLNode* node = (XMLNode*)malloc(sizeof(XMLNode));
    strncpy(node->tagName, tagName, MAX_TAG_NAME);
    node->content[0] = '\0';
    node->childCount = 0;
    return node;
}

void freeNode(XMLNode* node) {
    for (int i = 0; i < node->childCount; i++) {
        freeNode(node->children[i]);
    }
    free(node);
}

void parseXML(const char* xmlString, XMLNode* root) {
    const char* cursor = xmlString;
    char tagName[MAX_TAG_NAME];
    char content[MAX_CONTENT_LENGTH];
    
    while (*cursor) {
        if (*cursor == '<') {
            cursor++; // Skip '<'
            if (*cursor == '/') { // Closing tag
                while (*cursor != '>') cursor++; // Skip until '>'
                cursor++; // Skip '>'
                continue;
            }

            // Read tag name
            int i = 0;
            while (*cursor != '>' && *cursor != ' ' && *cursor != '/') {
                tagName[i++] = *cursor++;
            }
            tagName[i] = '\0';

            // Create a new node
            XMLNode* child = createNode(tagName);
            root->children[root->childCount++] = child;

            // Read content (if any)
            if (*cursor == '>') {
                cursor++; // Skip '>'
                i = 0;
                while (*cursor != '<') {
                    if (*cursor == '\0') break; // End of string
                    content[i++] = *cursor++;
                }
                content[i] = '\0';
                strncpy(child->content, content, MAX_CONTENT_LENGTH);
            }
            continue;
        }
        cursor++;
    }
}

void printXML(XMLNode* node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>", node->tagName);
    if (strlen(node->content) > 0) {
        printf("%s", node->content);
    }
    printf("\n");

    for (int i = 0; i < node->childCount; i++) {
        printXML(node->children[i], depth + 1);
    }
    
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("</%s>\n", node->tagName);
}

int main() {
    const char* sampleXML = "<root><child>Hello</child><child>World</child></root>";
    
    XMLNode* rootNode = createNode("root");
    parseXML(sampleXML, rootNode);

    printf("Parsed XML Structure:\n");
    printXML(rootNode, 0);

    freeNode(rootNode);
    return 0;
}