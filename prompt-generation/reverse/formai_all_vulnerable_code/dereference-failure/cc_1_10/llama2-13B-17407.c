//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node struct for the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the binary search tree
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

// Function to search for a node in the binary search tree
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

// Function to delete a node from the binary search tree
struct Node* delete(struct Node** root, int data) {
    if (*root == NULL) {
        return NULL;
    }

    if (data < (*root)->data) {
        (*root)->left = delete(&(*root)->left, data);
    } else if (data > (*root)->data) {
        (*root)->right = delete(&(*root)->right, data);
    } else {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
            return NULL;
        }

        if ((*root)->left == NULL) {
            (*root)->right = delete(&(*root)->right, data);
        } else if ((*root)->right == NULL) {
            (*root)->left = delete(&(*root)->left, data);
        } else {
            struct Node* temp = (*root)->right;
            while (temp->left != NULL) {
                (*root)->right = temp->left;
                temp = temp->left;
            }
            temp->left = NULL;
            (*root)->right = temp;
        }
    }

    return *root;
}

int main() {
    struct Node* root = NULL;

    // Test cases
    root = insert(&root, 5);
    root = insert(&root, 2);
    root = insert(&root, 8);
    root = insert(&root, 3);
    root = insert(&root, 1);
    root = insert(&root, 6);

    // Search for nodes
    printf("5: %p\n", search(root, 5));
    printf("2: %p\n", search(root, 2));
    printf("8: %p\n", search(root, 8));
    printf("3: %p\n", search(root, 3));
    printf("1: %p\n", search(root, 1));
    printf("6: %p\n", search(root, 6));

    // Delete nodes
    root = delete(&root, 5);
    root = delete(&root, 2);
    root = delete(&root, 8);
    root = delete(&root, 3);
    root = delete(&root, 1);
    root = delete(&root, 6);

    return 0;
}