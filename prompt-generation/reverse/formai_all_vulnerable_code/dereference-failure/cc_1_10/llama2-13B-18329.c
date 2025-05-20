//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define ARRAY_SIZE 100

// Structure to represent a node in the search tree
typedef struct node {
    int key;   // Key of the node
    struct node *left;  // Left child node
    struct node *right; // Right child node
    int freq;    // Frequency of the node
} node_t;

// Function to create a new node
node_t *new_node(int key, int freq) {
    node_t *node = malloc(sizeof(node_t));
    node->key = key;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the tree
void insert_node(node_t **root, int key, int freq) {
    if (*root == NULL) {
        *root = new_node(key, freq);
    } else {
        if (key < (*root)->key) {
            insert_node(&(*root)->left, key, freq);
        } else if (key > (*root)->key) {
            insert_node(&(*root)->right, key, freq);
        } else {
            // Key already exists, update the frequency
            (*root)->freq += freq;
        }
    }
}

// Function to search for a node in the tree
node_t *search_node(node_t *root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->key) {
        return search_node(root->left, key);
    } else if (key > root->key) {
        return search_node(root->right, key);
    } else {
        return root;
    }
}

// Function to print the search tree
void print_tree(node_t *root) {
    if (root == NULL) {
        return;
    }

    printf("%d -> ", root->key);
    print_tree(root->left);
    print_tree(root->right);
}

int main() {
    // Initialize the root node
    node_t *root = NULL;

    // Insert some nodes into the tree
    insert_node(&root, 2, 5);
    insert_node(&root, 4, 2);
    insert_node(&root, 1, 3);
    insert_node(&root, 3, 4);

    // Search for a node
    node_t *node = search_node(root, 2);

    // Print the search tree
    print_tree(root);

    return 0;
}