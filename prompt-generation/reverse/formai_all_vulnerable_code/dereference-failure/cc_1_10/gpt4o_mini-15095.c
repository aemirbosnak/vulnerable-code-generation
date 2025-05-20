//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME_LENGTH 256
#define MAX_BUFFER_LENGTH 1024
#define MAX_XML_DEPTH 32

typedef struct Node {
    char tagName[MAX_TAG_NAME_LENGTH];
    struct Node *parent;
    struct Node *children[MAX_XML_DEPTH];
    int childCount;
} Node;

Node* createNode(const char *tagName, Node *parent) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strncpy(newNode->tagName, tagName, MAX_TAG_NAME_LENGTH - 1);
    newNode->tagName[MAX_TAG_NAME_LENGTH - 1] = '\0'; // Ensuring null termination
    newNode->parent = parent;
    newNode->childCount = 0;
    return newNode;
}

void addChild(Node *parent, Node *child) {
    if (parent->childCount < MAX_XML_DEPTH) {
        parent->children[parent->childCount++] = child;
    }
}

void freeNode(Node *node) {
    for (int i = 0; i < node->childCount; i++) {
        freeNode(node->children[i]);
    }
    free(node);
}

Node* parseXML(FILE *file) {
    char buffer[MAX_BUFFER_LENGTH];
    Node *root = createNode("root", NULL);
    Node *currentNode = root;

    while (fgets(buffer, sizeof(buffer), file)) {
        char *startTag = strchr(buffer, '<');
        char *endTag = strchr(buffer, '>');
        if (startTag && endTag && startTag < endTag) {
            char tagName[MAX_TAG_NAME_LENGTH];
            strncpy(tagName, startTag + 1, endTag - startTag - 1);
            tagName[endTag - startTag - 1] = '\0'; // Ensuring null termination

            if (tagName[0] != '/') { // Opening tag
                Node *newNode = createNode(tagName, currentNode);
                addChild(currentNode, newNode);
                currentNode = newNode; // Now the current node is the child
            } else { // Closing tag
                if (currentNode->parent) {
                    currentNode = currentNode->parent; // Move back to parent
                }
            }
        }
    }
    return root;
}

void printXML(Node *node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>\n", node->tagName);
    for (int i = 0; i < node->childCount; i++) {
        printXML(node->children[i], depth + 1);
    }
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("</%s>\n", node->tagName);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Could not open file");
        return EXIT_FAILURE;
    }

    Node *xmlTree = parseXML(file);
    fclose(file);

    printXML(xmlTree, 0);
    freeNode(xmlTree);

    return EXIT_SUCCESS;
}