//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: thoughtful
#include <stdio.h>

// Binary search tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to insert a node into the binary search tree
void insert(struct Node* root, int data) {
    // If the tree is empty, create a new root node
    if (root == NULL) {
        root = (struct Node*) malloc(sizeof(struct Node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    } else {
        // Find the appropriate position to insert the new node
        if (data < root->data) {
            // If the data is smaller, traverse left
            insert(root->left, data);
        } else {
            // If the data is larger, traverse right
            insert(root->right, data);
        }
    }
}

// Function to print the binary search tree inorder
void inorder(struct Node* root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Insert elements into the binary search tree
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    insert(root, 60);

    // Print the binary search tree inorder
    printf("Inorder traversal of the binary search tree: ");
    inorder(root);

    return 0;
}