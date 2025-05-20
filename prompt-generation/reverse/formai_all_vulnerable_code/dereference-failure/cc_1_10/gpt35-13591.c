//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Donald Knuth
/* Binary Search Tree Visualization using ASCII art */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printTree(Node* root, int space) {
    if (root == NULL) {
        return;
    }

    int i;
    for (i = 0; i < space; i++) {
        printf(" ");
    }

    printf("%d\n", root->data);

    printTree(root->left, space + 5);

    printTree(root->right, space + 5);
}

int main() {
    Node* root = createNode(10);
    root->left = createNode(4);
    root->right = createNode(16);
    root->left->left = createNode(2);
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->right->right = createNode(21);

    // Visualize the tree
    printf("Binary Search Tree Visualization:\n");
    printTree(root, 0);

    return 0;
}