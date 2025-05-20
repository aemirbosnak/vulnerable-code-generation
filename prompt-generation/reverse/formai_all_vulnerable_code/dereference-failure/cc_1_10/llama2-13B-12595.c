//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_SIZE 1024
#define MAX_TREE_SIZE 1024

// Node structure
struct node {
    int key;
    struct node *left, *right;
    char name[20];
};

// Function to create a new node
struct node* new_node(int key, char name[20]) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->key = key;
    node->left = node->right = NULL;
    strcpy(node->name, name);
    return node;
}

// Function to insert a node into the tree
void insert_node(struct node** root, int key, char name[20]) {
    if (*root == NULL) {
        *root = new_node(key, name);
    } else if (key < (*root)->key) {
        insert_node(&(*root)->left, key, name);
    } else if (key > (*root)->key) {
        insert_node(&(*root)->right, key, name);
    }
}

// Function to search for a node in the tree
struct node* search_node(struct node* root, int key) {
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

// Function to print the tree
void print_tree(struct node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d: %s\n", root->key, root->name);
    print_tree(root->left);
    print_tree(root->right);
}

int main() {
    struct node* root = NULL;

    // Insert some nodes into the tree
    insert_node(&root, 5, "John");
    insert_node(&root, 10, "Jane");
    insert_node(&root, 8, "Bob");
    insert_node(&root, 3, "Alice");
    insert_node(&root, 6, "Mike");

    // Search for a node in the tree
    struct node* node = search_node(root, 8);
    if (node != NULL) {
        printf("Found node with key %d and name %s\n", node->key, node->name);
    } else {
        printf("Node not found\n");
    }

    // Print the tree
    print_tree(root);

    return 0;
}