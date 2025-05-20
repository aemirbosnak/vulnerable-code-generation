//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DEPTH 10
#define MAX_NAME_LEN 256
#define MAX_CHILDREN 32

typedef struct Node {
    char name[MAX_NAME_LEN];
    int depth;
    int childrenCount;
    struct Node *children[MAX_CHILDREN];
} Node;

Node *createNode(const char *name) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->depth = 0;
    newNode->childrenCount = 0;
    return newNode;
}

void addChild(Node *parent, Node *child) {
    parent->children[parent->childrenCount++] = child;
}

void traverseTree(Node *node, int depth) {
    printf("%*s%s\n", depth * 4, "", node->name);
    for (int i = 0; i < node->childrenCount; ++i) {
        traverseTree(node->children[i], depth + 1);
    }
}

int main() {
    Node *root = createNode("ROOT");
    Node *child1 = createNode("Child1");
    Node *child2 = createNode("Child2");
    Node *grandChild1 = createNode("GrandChild1");
    Node *grandChild2 = createNode("GrandChild2");

    addChild(root, child1);
    addChild(root, child2);

    addChild(child1, grandChild1);
    addChild(child1, grandChild2);

    traverseTree(root, 0);

    for (int i = 0; i < MAX_CHILDREN && i < root->childrenCount; ++i) {
        free(root->children[i]);
    }
    free(root);

    return 0;
}