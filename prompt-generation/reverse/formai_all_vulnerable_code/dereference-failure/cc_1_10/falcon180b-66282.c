//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_TREE_HEIGHT 1000

// Node structure
typedef struct node {
    char name[MAX_NAME_LEN];
    int height;
    struct node *left;
    struct node *right;
} Node;

// Create a new node with the given name and height
Node* create_node(char* name, int height) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->height = height;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node into the tree
void insert_node(Node* node, char* name, int height) {
    if (node == NULL) {
        node = create_node(name, height);
        return;
    }

    if (strcmp(node->name, name) > 0) {
        insert_node(node->left, name, height);
    } else {
        insert_node(node->right, name, height);
    }
}

// Find a node in the tree with the given name
Node* find_node(Node* node, char* name) {
    if (node == NULL || strcmp(node->name, name) == 0) {
        return node;
    }

    if (strcmp(node->name, name) > 0) {
        return find_node(node->left, name);
    } else {
        return find_node(node->right, name);
    }
}

// Print the tree in order traversal
void print_tree(Node* node) {
    if (node == NULL) {
        return;
    }

    print_tree(node->left);
    printf("%s (%d)\n", node->name, node->height);
    print_tree(node->right);
}

// Main function
int main() {
    Node* root = NULL;

    // Insert nodes
    insert_node(root, "Alice", 170);
    insert_node(root, "Bob", 180);
    insert_node(root, "Charlie", 160);
    insert_node(root, "David", 190);

    // Print the tree
    print_tree(root);

    return 0;
}