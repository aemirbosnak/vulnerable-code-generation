//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME_LENGTH 100
#define MAX_XML_STRING_LENGTH 1024

typedef struct Node {
    char tagName[MAX_TAG_NAME_LENGTH];
    char *content;
    struct Node **children;
    int childCount;
} Node;

Node* createNode(const char* tagName) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->tagName, tagName, MAX_TAG_NAME_LENGTH);
    newNode->content = NULL;
    newNode->children = NULL;
    newNode->childCount = 0;
    return newNode;
}

void addChildNode(Node* parent, Node* child) {
    parent->children = realloc(parent->children, sizeof(Node*) * (parent->childCount + 1));
    parent->children[parent->childCount] = child;
    parent->childCount++;
}

void freeNode(Node* node) {
    if (node) {
        for (int i = 0; i < node->childCount; i++) {
            freeNode(node->children[i]);
        }
        free(node->children);
        free(node->content);
        free(node);
    }
}

void printXML(Node* node, int level) {
    for (int i = 0; i < level; i++) {
        printf("\t");
    }
    printf("<%s>", node->tagName);
    if (node->content) {
        printf("%s", node->content);
    }
    printf("\n");
    
    for (int i = 0; i < node->childCount; i++) {
        printXML(node->children[i], level + 1);
    }
    
    for (int i = 0; i < level; i++) {
        printf("\t");
    }
    printf("</%s>\n", node->tagName);
}

Node* parseXML(const char* xml) {
    Node* root = NULL;
    Node* currentNode = NULL;
    const char* p = xml;
    int isClosingTag = 0;
    char tagName[MAX_TAG_NAME_LENGTH];
    
    while (*p) {
        if (*p == '<') {
            p++;  // Move past '<'
            if (*p == '/') {
                isClosingTag = 1;
                p++;  // Move past '/'
            }

            int i = 0;
            while (*p && *p != '>' && i < MAX_TAG_NAME_LENGTH - 1) {
                tagName[i++] = *p;
                p++;
            }
            tagName[i] = '\0';  // Null-terminate

            if (*p == '>') {
                p++;  // Move past '>'

                if (isClosingTag) {
                    isClosingTag = 0;
                    currentNode = NULL;  // Close current node
                } else {
                    Node* newNode = createNode(tagName);
                    if (!root) {
                        root = newNode;  // Set root node
                    }
                    if (currentNode) {
                        addChildNode(currentNode, newNode);
                    }
                    currentNode = newNode;
                }
            }
        } else {
            if (currentNode) {
                size_t length = strlen(currentNode->content ? currentNode->content : "") + strlen(p) + 1;
                currentNode->content = realloc(currentNode->content, length);
                if (!currentNode->content) {
                    fprintf(stderr, "Memory allocation failed\n");
                    exit(1);
                }
                
                if (currentNode->content[0] == '\0') {
                    strcpy(currentNode->content, p);
                } else {
                    strcat(currentNode->content, p);
                }

                while (*p && *p != '<') {
                    p++;
                }
            }
        }
    }

    return root;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <xml_string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Node* xmlTree = parseXML(argv[1]);
    
    printf("Parsed XML Structure:\n");
    printXML(xmlTree, 0);

    freeNode(xmlTree);
    return EXIT_SUCCESS;
}