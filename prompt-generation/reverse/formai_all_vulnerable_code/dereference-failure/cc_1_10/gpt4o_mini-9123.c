//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 256

typedef struct XmlNode {
    char tag[MAX_TAG_LENGTH];
    char content[MAX_LINE_LENGTH];
    struct XmlNode* parent;
    struct XmlNode* children;
    struct XmlNode* next;
} XmlNode;

XmlNode* createNode(const char* tag) {
    XmlNode* newNode = (XmlNode*)malloc(sizeof(XmlNode));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->tag, tag, MAX_TAG_LENGTH);
    newNode->content[0] = '\0';
    newNode->parent = NULL;
    newNode->children = NULL;
    newNode->next = NULL;
    return newNode;
}

void addChild(XmlNode* parent, XmlNode* child) {
    if (!parent || !child) return;
    
    child->parent = parent;
    if (!parent->children) {
        parent->children = child;
    } else {
        XmlNode* sibling = parent->children;
        while (sibling->next) {
            sibling = sibling->next;
        }
        sibling->next = child;
    }
}

void freeXmlNode(XmlNode* node) {
    if (!node) return;
    freeXmlNode(node->children);
    freeXmlNode(node->next);
    free(node);
}

XmlNode* parseXml(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    XmlNode* root = NULL;
    XmlNode* current = NULL;

    while (fgets(line, sizeof(line), file)) {
        char* tagStart = strchr(line, '<');
        char* tagEnd = strchr(line, '>');
        
        if (tagStart && tagEnd && tagStart < tagEnd) {
            char tag[MAX_TAG_LENGTH];
            strncpy(tag, tagStart + 1, tagEnd - tagStart - 1);
            tag[tagEnd - tagStart - 1] = '\0';
            
            if (line[strlen(line) - 2] == '/') {
                // Empty tag
                if (!root) {
                    root = createNode(tag);
                    current = root;
                }
                continue;
            }

            // Opening Tag
            XmlNode* newNode = createNode(tag);
            if (!root) {
                root = newNode;
                current = root;
            } else {
                addChild(current, newNode);
            }
            current = newNode;
        }

        char* contentStart = tagEnd + 1;
        char* contentEnd = strchr(contentStart, '<');

        if (contentStart && contentEnd && contentStart < contentEnd) {
            strncat(current->content, contentStart, contentEnd - contentStart);
        }

        // Closing Tag
        if (contentEnd) {
            char closeTag[MAX_TAG_LENGTH];
            char* closeTagEnd = strchr(contentEnd, '>');
            strncpy(closeTag, contentEnd + 2, closeTagEnd - contentEnd - 2);
            closeTag[closeTagEnd - contentEnd - 2] = '\0';

            if (strcmp(current->tag, closeTag) == 0) {
                current = current->parent;
            }
        }
    }

    fclose(file);
    return root;
}

void printXml(XmlNode* node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    if (node) {
        printf("<%s>%s</%s>\n", node->tag, node->content[0] ? node->content : "", node->tag);
        printXml(node->children, depth + 1);
        printXml(node->next, depth);
    }
}

int main() {
    const char* filename = "example.xml";

    XmlNode* xmlDocument = parseXml(filename);
    if (xmlDocument) {
        printf("Parsed XML Structure:\n");
        printXml(xmlDocument, 0);
        freeXmlNode(xmlDocument);
    }

    return 0;
}