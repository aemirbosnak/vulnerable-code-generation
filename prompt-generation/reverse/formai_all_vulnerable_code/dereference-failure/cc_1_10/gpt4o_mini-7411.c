//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct XMLNode {
    char *name;
    char *value;
    struct XMLNode *next;
    struct XMLNode *child;
} XMLNode;

XMLNode* createNode(const char *name, const char *value) {
    XMLNode *node = (XMLNode*)malloc(sizeof(XMLNode));
    if (!node) {
        perror("Failed to allocate memory for XMLNode");
        exit(EXIT_FAILURE);
    }
    node->name = strdup(name);
    node->value = strdup(value);
    node->next = NULL;
    node->child = NULL;
    return node;
}

void freeNode(XMLNode *node) {
    if (node) {
        free(node->name);
        free(node->value);
        freeNode(node->next);
        freeNode(node->child);
        free(node);
    }
}

void addChild(XMLNode *parent, XMLNode *child) {
    if (!parent->child) {
        parent->child = child;
    } else {
        XMLNode *temp = parent->child;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = child;
    }
}

void printXML(XMLNode *node, int depth) {
    if (!node) return;
    for (int i = 0; i < depth; ++i) {
        printf("  ");
    }
    printf("<%s>%s</%s>\n", node->name, node->value ? node->value : "", node->name);
    printXML(node->child, depth + 1);
    printXML(node->next, depth);
}

void parseXML(const char *xml, XMLNode **root) {
    const char *ptr = xml;
    char tagName[256], tagValue[256];
    while (*ptr) {
        // Skip whitespaces
        while (*ptr && (*ptr == ' ' || *ptr == '\n' || *ptr == '\t')) ptr++;

        if (*ptr == '<') {
            ptr++; // skip '<'
            if (*ptr == '/') {
                // Closing tag
                while (*ptr && *ptr != '>') ptr++;
                ptr++; // skip '>'
                return;
            }

            // Read tag name
            int i = 0;
            while (*ptr && *ptr != '>' && *ptr != ' ') {
                tagName[i++] = *ptr++;
            }
            tagName[i] = '\0';

            // Read tag value if any
            if (*ptr == ' ') {
                while (*ptr && *ptr != '>') {
                    ptr++;
                }
            }
            if (*ptr == '>') {
                ptr++; // skip '>'
            }

            // Check for nested tags
            XMLNode *node = createNode(tagName, NULL);
            if (*root) {
                addChild(*root, node);
            } else {
                *root = node;
            }
            parseXML(ptr, &node->child);
        } else {
            // Read tag value
            int i = 0;
            while (*ptr && *ptr != '<') {
                tagValue[i++] = *ptr++;
            }
            tagValue[i] = '\0';

            // Assign value to the last node
            if (*root) {
                (*root)->value = strdup(tagValue);
            }
        }
    }
}

int main() {
    const char *xmlData = "<root><child1>Hello</child1><child2>World</child2></root>";
    
    XMLNode *rootNode = NULL;
    parseXML(xmlData, &rootNode);
    
    printf("Parsed XML:\n");
    printXML(rootNode, 0);
    
    freeNode(rootNode);
    return 0;
}