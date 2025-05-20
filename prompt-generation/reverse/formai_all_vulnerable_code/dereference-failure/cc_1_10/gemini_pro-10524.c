//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Let's imagine a binary search tree
struct BSTNode {
    int data;
    struct BSTNode *left, *right;
};

// And some helper functions
struct BSTNode *createNode(int data) {
    struct BSTNode *node = malloc(sizeof(struct BSTNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void insertNode(struct BSTNode **root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }
    if (data < (*root)->data) {
        insertNode(&(*root)->left, data);
    } else {
        insertNode(&(*root)->right, data);
    }
}

struct BSTNode *searchNode(struct BSTNode *root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == data) {
        return root;
    }
    if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

void printTree(struct BSTNode *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    printTree(root->left);
    printTree(root->right);
}

// Let's play around with our BST
int main() {
    // Create a root node
    struct BSTNode *root = NULL;

    // Insert some data into our tree
    insertNode(&root, 50);
    insertNode(&root, 30);
    insertNode(&root, 20);
    insertNode(&root, 40);
    insertNode(&root, 70);
    insertNode(&root, 60);
    insertNode(&root, 80);

    // Let's see what we have
    printf("Inorder Traversal: ");
    printTree(root);
    printf("\n");

    // Search for a value
    struct BSTNode *foundNode = searchNode(root, 40);
    if (foundNode != NULL) {
        printf("Found node with data %d\n", foundNode->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}