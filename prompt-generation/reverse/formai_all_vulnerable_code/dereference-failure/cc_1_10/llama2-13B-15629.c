//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Node structure to represent a binary search tree
struct node {
    int data;
    struct node *left, *right;
};

// Function to create a new node with the given data
struct node* new_node(int data) {
    struct node* node = malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the binary search tree
void insert_node(struct node** root_ref, int data) {
    struct node* root = *root_ref;
    if (!root) {
        root = new_node(data);
        *root_ref = root;
    } else if (data < root->data) {
        insert_node(&root->left, data);
    } else {
        insert_node(&root->right, data);
    }
}

// Function to search for a node in the binary search tree
struct node* search_node(struct node* root, int data) {
    if (!root) {
        return NULL;
    }
    if (data < root->data) {
        return search_node(root->left, data);
    } else if (data > root->data) {
        return search_node(root->right, data);
    } else {
        return root;
    }
}

// Function to print the binary search tree
void print_tree(struct node* root) {
    if (root) {
        print_tree(root->left);
        printf("%d ", root->data);
        print_tree(root->right);
    }
}

int main() {
    struct node* root = NULL;

    // Insert some nodes into the binary search tree
    insert_node(&root, 5);
    insert_node(&root, 2);
    insert_node(&root, 8);
    insert_node(&root, 3);
    insert_node(&root, 1);
    insert_node(&root, 6);
    insert_node(&root, 4);

    // Search for a node in the binary search tree
    struct node* found_node = search_node(root, 5);
    if (found_node) {
        printf("Found node with value %d\n", found_node->data);
    } else {
        printf("Node not found\n");
    }

    // Print the binary search tree
    print_tree(root);

    return 0;
}