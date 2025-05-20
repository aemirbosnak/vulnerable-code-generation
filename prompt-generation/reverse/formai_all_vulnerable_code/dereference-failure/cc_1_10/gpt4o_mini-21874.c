//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 256
#define MAX_XML_SIZE 4096

typedef struct Node {
    char tagName[MAX_TAG_NAME];
    char *content;
    struct Node *next;
    struct Node *children;
} Node;

Node* createNode(const char *tagName, const char *content) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strncpy(newNode->tagName, tagName, MAX_TAG_NAME);
    newNode->content = content ? strdup(content) : NULL;
    newNode->next = NULL;
    newNode->children = NULL;
    return newNode;
}

void freeTree(Node *node) {
    if (node == NULL) return;
    freeTree(node->children);
    freeTree(node->next);
    free(node->content);
    free(node);
}

void addChild(Node *parent, Node *child) {
    if (parent->children) {
        Node *sibling = parent->children;
        while (sibling->next) {
            sibling = sibling->next;
        }
        sibling->next = child;
    } else {
        parent->children = child;
    }
}

void printXML(Node *node, int depth) {
    if (node == NULL) return;
    for (int i = 0; i < depth; i++) printf("  ");
    
    printf("<%s>", node->tagName);
    if (node->content) printf("%s", node->content);
    printf("\n");

    printXML(node->children, depth + 1);
    
    for (int i = 0; i < depth; i++) printf("  ");
    printf("</%s>\n", node->tagName);
    
    printXML(node->next, depth);
}

Node* parseXML(const char *xml) {
    Node *root = NULL, *currentNode = NULL;
    char tagName[MAX_TAG_NAME];
    char *contentStart;
    char *ptr = (char *)xml;

    while (*ptr) {
        if (*ptr == '<') {
            if (*(ptr + 1) == '/') {
                // Closing tag
                ptr = strchr(ptr, '>') + 1;
                if (currentNode) currentNode = NULL;
            } else {
                // Opening tag
                ptr++;
                contentStart = strchr(ptr, '>');

                if (contentStart) {
                    size_t tagLength = contentStart - ptr;
                    strncpy(tagName, ptr, tagLength);
                    tagName[tagLength] = '\0';
                    Node *newNode = createNode(tagName, NULL);
                    
                    if (!root) {
                        root = newNode;
                    } else if (currentNode) {
                        addChild(currentNode, newNode);
                    }
                    currentNode = newNode;

                    ptr = contentStart + 1;
                    if (*ptr != '<') {
                        contentStart = strchr(ptr, '<');
                        if (contentStart) {
                            size_t contentLength = contentStart - ptr;
                            char *content = (char *)malloc(contentLength + 1);
                            strncpy(content, ptr, contentLength);
                            content[contentLength] = '\0';
                            currentNode->content = content;
                        }
                    }
                }
            }
        }
        ptr++;
    }

    return root;
}

int main() {
    const char *xmlData = "<root>Hello<child>World</child><child>XML</child></root>";
    
    Node *xmlTree = parseXML(xmlData);
    if (xmlTree) {
        printf("Parsed XML:\n");
        printXML(xmlTree, 0);
        freeTree(xmlTree);
    } else {
        fprintf(stderr, "Failed to parse XML.\n");
    }
    
    return 0;
}