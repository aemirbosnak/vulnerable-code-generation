//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary search tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    char name[20];
};

// Function to create a new node
struct Node* newNode(int data, char name[]) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    strcpy(node->name, name);
    return node;
}

// Function to insert a node into the tree
void insertNode(struct Node** root, int data, char name[]) {
    if (*root == NULL) {
        *root = newNode(data, name);
        return;
    }

    if (data < (*root)->data) {
        insertNode(&(*root)->left, data, name);
    } else {
        insertNode(&(*root)->right, data, name);
    }
}

// Function to search for a node in the tree
struct Node* searchNode(struct Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (data < root->data) {
        return searchNode(root->left, data);
    } else if (data > root->data) {
        return searchNode(root->right, data);
    } else {
        return root;
    }
}

// Function to print the tree
void printTree(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    printf("%s\n", root->name);
    printTree(root->left);
    printTree(root->right);
}

int main() {
    struct Node* root = NULL;

    // Insert nodes into the tree
    insertNode(&root, 5, "John");
    insertNode(&root, 10, "Jane");
    insertNode(&root, 8, "Bob");
    insertNode(&root, 20, "Alice");

    // Search for a node in the tree
    struct Node* node = searchNode(root, 15);
    if (node != NULL) {
        printf("Node found: %d %s\n", node->data, node->name);
    } else {
        printf("Node not found\n");
    }

    // Print the tree
    printTree(root);

    return 0;
}