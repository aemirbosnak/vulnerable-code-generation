//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: lively
#include <stdio.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node in the BST
void insert(struct Node* root, int data) {
    if (root == NULL) {
        root = newNode(data);
    } else {
        if (data < root->data) {
            insert(root->left, data);
        } else {
            insert(root->right, data);
        }
    }
}

// Function to print the BST in pre-order traversal
void printPreorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    struct Node* root = NULL;
    insert(root, 10);
    insert(root, 8);
    insert(root, 12);
    insert(root, 15);
    insert(root, 4);
    insert(root, 6);
    insert(root, 2);
    insert(root, 14);
    insert(root, 1);
    insert(root, 11);
    insert(root, 9);
    insert(root, 13);
    insert(root, 7);
    insert(root, 5);

    printf("Pre-order traversal of the BST:\n");
    printPreorder(root);

    return 0;
}