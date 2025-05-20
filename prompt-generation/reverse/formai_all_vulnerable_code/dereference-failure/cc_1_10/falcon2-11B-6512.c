//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *left, *right;
} node;

// Function to create a new node
node* create_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

// Function to insert a new node into the tree
node* insert(node* root, int data) {
    if (root == NULL) {
        root = create_node(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to traverse the tree in inorder
void inorder(node* root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    // Create the root node
    node* root = NULL;

    // Insert some nodes into the tree
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);

    // Traverse the tree in inorder
    inorder(root);

    return 0;
}