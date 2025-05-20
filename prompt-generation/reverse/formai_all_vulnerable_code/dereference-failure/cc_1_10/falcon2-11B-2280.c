//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Function to create a new node
struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search a node
int search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return 1;
    }
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

int main() {
    struct Node* root = NULL;

    // Insert some nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);

    // Search some nodes
    printf("Node 40 found: %d\n", search(root, 40));
    printf("Node 70 found: %d\n", search(root, 70));
    printf("Node 100 not found: %d\n", search(root, 100));

    return 0;
}