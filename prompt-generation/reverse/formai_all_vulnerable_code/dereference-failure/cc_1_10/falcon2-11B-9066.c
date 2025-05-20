//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary search tree
typedef struct node {
    int key;
    struct node *left, *right;
} node;

// Function to create a new node with given key
node* new_node(int key) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->key = key;
    new_node->left = new_node->right = NULL;
    return new_node;
}

// Function to insert a new key into the binary search tree
void insert(node* root, int key) {
    if (root == NULL) {
        root = new_node(key);
    } else if (key < root->key) {
        insert(root->left, key);
    } else if (key > root->key) {
        insert(root->right, key);
    }
}

// Function to search for a key in the binary search tree
node* search(node* root, int key) {
    if (root == NULL) {
        return NULL;
    } else if (key < root->key) {
        return search(root->left, key);
    } else if (key > root->key) {
        return search(root->right, key);
    } else {
        return root;
    }
}

// Function to print the binary search tree in inorder traversal
void inorder_traversal(node* root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->key);
    inorder_traversal(root->right);
}

int main() {
    node* root = NULL;

    // Insert some nodes into the binary search tree
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Search for a key in the binary search tree
    node* node_to_search = search(root, 50);
    if (node_to_search!= NULL) {
        printf("Key found at node with value %d\n", node_to_search->key);
    } else {
        printf("Key not found in the binary search tree\n");
    }

    // Print the binary search tree in inorder traversal
    printf("Inorder traversal of the binary search tree:\n");
    inorder_traversal(root);

    return 0;
}