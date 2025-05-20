//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to perform a recursive binary search
int binarySearch(struct Node* root, int target) {
    if (root == NULL) {
        return -1;
    }

    if (root->data == target) {
        return 0;
    }

    int left = binarySearch(root->left, target);
    int right = binarySearch(root->right, target);

    if (left != -1 && right != -1) {
        return left + right;
    }

    return -1;
}

// Function to insert a new node into the binary search tree
void insert(struct Node** root_ref, int data) {
    struct Node* root = *root_ref;

    if (root == NULL) {
        root = newNode(data);
        *root_ref = root;
        return;
    }

    if (data < root->data) {
        insert(&root->left, data);
    } else {
        insert(&root->right, data);
    }
}

// Example usage of the binary search tree
int main() {
    struct Node* root = NULL;

    insert(&root, 5);
    insert(&root, 2);
    insert(&root, 8);
    insert(&root, 3);
    insert(&root, 9);
    insert(&root, 1);
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 7);

    int result = binarySearch(root, 5);
    printf("Value found at index %d\n", result);

    return 0;
}