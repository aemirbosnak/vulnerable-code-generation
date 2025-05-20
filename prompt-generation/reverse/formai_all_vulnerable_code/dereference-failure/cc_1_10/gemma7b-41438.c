//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a graph structure
typedef struct Node {
    char name[20];
    struct Node** children;
    int numChildren;
} Node;

// Create a new node
Node* newNode(char* name) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->children = NULL;
    node->numChildren = 0;
    return node;
}

// Add a child to a node
void addChild(Node* node, Node* child) {
    node->children = (Node**)realloc(node->children, (node->numChildren + 1) * sizeof(Node*));
    node->children[node->numChildren++] = child;
}

// Traverse the graph
void traverse(Node* node) {
    printf("%s ", node->name);
    for (int i = 0; i < node->numChildren; i++) {
        traverse(node->children[i]);
    }
}

int main() {
    // Create a root node
    Node* root = newNode("John");

    // Add children to the root node
    addChild(root, newNode("Mary"));
    addChild(root, newNode("Bob"));

    // Add grandchildren to the root node's children
    addChild(root->children[0], newNode("Alice"));
    addChild(root->children[0], newNode("Tom"));

    // Traverse the graph
    traverse(root);

    return 0;
}