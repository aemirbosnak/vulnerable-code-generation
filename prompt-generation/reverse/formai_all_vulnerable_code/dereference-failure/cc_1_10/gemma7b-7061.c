//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CHILDREN 10

typedef struct Node {
    char name[256];
    struct Node** children;
    int numChildren;
} Node;

void createNode(Node* node, char* name) {
    strcpy(node->name, name);
    node->children = malloc(sizeof(struct Node*) * MAX_CHILDREN);
    node->numChildren = 0;
}

void addChild(Node* node, Node* child) {
    node->children[node->numChildren++] = child;
}

void printNode(Node* node) {
    printf("%s\n", node->name);
    for (int i = 0; i < node->numChildren; i++) {
        printNode(node->children[i]);
    }
}

int main() {
    Node* root = malloc(sizeof(struct Node));
    createNode(root, "Root");

    Node* child1 = malloc(sizeof(struct Node));
    createNode(child1, "Child 1");
    addChild(root, child1);

    Node* child2 = malloc(sizeof(struct Node));
    createNode(child2, "Child 2");
    addChild(root, child2);

    Node* grandchild1 = malloc(sizeof(struct Node));
    createNode(grandchild1, "Grandchild 1");
    addChild(child1, grandchild1);

    printNode(root);

    return 0;
}