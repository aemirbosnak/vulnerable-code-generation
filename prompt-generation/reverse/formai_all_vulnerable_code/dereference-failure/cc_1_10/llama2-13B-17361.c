//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the database
struct node {
    int key;
    char value[50];
    struct node *left;
    struct node *right;
};

// Function to insert a new node into the database
void insert(struct node **root, int key, char value[]) {
    // If the root node is null, create a new node with the given key and value
    if (*root == NULL) {
        *root = (struct node *) malloc(sizeof(struct node));
        (*root)->key = key;
        strcpy((*root)->value, value);
        return;
    }

    // If the key already exists in the database, update the value
    else if ((*root)->key == key) {
        strcpy((*root)->value, value);
        return;
    }

    // Recursively search for the appropriate child node to insert the new node
    if (key < (*root)->key) {
        insert(&(*root)->left, key, value);
    } else {
        insert(&(*root)->right, key, value);
    }
}

// Function to search for a value in the database
struct node* search(struct node* root, int key) {
    // If the root node is null, return null
    if (root == NULL) {
        return NULL;
    }

    // If the key matches the root node's key, return the root node
    if (root->key == key) {
        return root;
    }

    // Recursively search the left and right child nodes
    struct node* left = search(root->left, key);
    struct node* right = search(root->right, key);

    // If the key is found in either the left or right child nodes, return the corresponding node
    if (left != NULL) {
        return left;
    }

    return right;
}

// Function to traverse the database
void traverse(struct node* root) {
    // Print the key and value of each node
    printf("%d: %s\n", root->key, root->value);

    // Recursively traverse the left and right child nodes
    if (root->left != NULL) {
        traverse(root->left);
    }

    if (root->right != NULL) {
        traverse(root->right);
    }
}

int main() {
    // Create a new node with the key 5 and value "hello"
    struct node* root = (struct node*) malloc(sizeof(struct node));
    root->key = 5;
    strcpy(root->value, "hello");

    // Insert additional nodes with keys 2, 3, and 7
    insert(root, 2, "two");
    insert(root, 3, "three");
    insert(root, 7, "seven");

    // Search for the node with key 5
    struct node* found = search(root, 5);
    if (found != NULL) {
        printf("Found node with key 5 and value %s\n", found->value);
    } else {
        printf("Node with key 5 not found\n");
    }

    // Traverse the database
    traverse(root);

    return 0;
}