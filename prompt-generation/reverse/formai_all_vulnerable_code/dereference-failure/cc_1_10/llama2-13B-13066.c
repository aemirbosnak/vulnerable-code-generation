//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the database
typedef struct node {
    int key;
    char value[50];
    struct node* left;
    struct node* right;
} node_t;

// Function to insert a new node into the database
void insert(node_t** root, int key, char value[50]) {
    // If the root node is null, create a new one
    if (*root == NULL) {
        *root = (node_t*) malloc(sizeof(node_t));
        (*root)->key = key;
        strcpy((*root)->value, value);
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    }

    // If the key is less than the root node's key, insert to the left
    if (key < (*root)->key) {
        insert((*root)->left, key, value);
    } else if (key > (*root)->key) {
        insert((*root)->right, key, value);
    }
}

// Function to search for a node in the database
node_t* search(node_t* root, int key) {
    // If the root node is null, return null
    if (root == NULL) {
        return NULL;
    }

    // If the key is less than the root node's key, search the left subtree
    if (key < root->key) {
        return search(root->left, key);
    } else if (key > root->key) {
        return search(root->right, key);
    } else {
        return root;
    }
}

// Function to traverse the database in pre-order
void pre_order(node_t* root) {
    // If the root node is null, return
    if (root == NULL) {
        return;
    }

    // Print the root node's key and value
    printf("%d: %s\n", root->key, root->value);

    // Traverse the left subtree
    pre_order(root->left);

    // Traverse the right subtree
    pre_order(root->right);
}

int main() {
    // Create a new database with a single node
    node_t* root = (node_t*) malloc(sizeof(node_t));
    root->key = 10;
    strcpy(root->value, "Hello World");
    root->left = NULL;
    root->right = NULL;

    // Insert some nodes into the database
    insert(root, 5, "Hello");
    insert(root, 15, "World");
    insert(root, 20, "C++");

    // Search for a node in the database
    node_t* node = search(root, 12);
    if (node != NULL) {
        printf("Found node with key %d and value %s\n", node->key, node->value);
    } else {
        printf("Node not found\n");
    }

    // Traverse the database in pre-order
    pre_order(root);

    // Free the memory allocated for the database
    free(root);

    return 0;
}