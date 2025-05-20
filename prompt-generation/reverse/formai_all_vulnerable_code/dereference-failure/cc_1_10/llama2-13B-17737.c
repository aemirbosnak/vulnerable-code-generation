//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Node struct for binary search tree
struct Node {
    int data;
    struct Node* left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the tree
struct Node* insert(struct Node** root, int data) {
    if (*root == NULL) {
        return newNode(data);
    }

    if (data < (*root)->data) {
        (*root)->left = insert(&(*root)->left, data);
    } else {
        (*root)->right = insert(&(*root)->right, data);
    }

    return *root;
}

// Function to search for a node in the tree
struct Node* search(struct Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else if (data > root->data) {
        return search(root->right, data);
    } else {
        return root;
    }
}

// Function to traverse the tree
void traverse(struct Node* root) {
    if (root != NULL) {
        traverse(root->left);
        printf("%d ", root->data);
        traverse(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    root = insert(&root, 5);
    root = insert(&root, 2);
    root = insert(&root, 8);
    root = insert(&root, 3);
    root = insert(&root, 9);
    root = insert(&root, 1);

    printf("Pre-order traversal: ");
    traverse(root);
    printf("\n");

    struct Node* found = search(root, 5);
    if (found != NULL) {
        printf("5 found at %p\n", found);
    } else {
        printf("5 not found\n");
    }

    return 0;
}