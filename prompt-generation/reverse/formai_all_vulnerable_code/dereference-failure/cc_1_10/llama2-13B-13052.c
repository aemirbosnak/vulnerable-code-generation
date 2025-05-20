//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Node structure to represent the BST
struct node {
    int key;
    struct node *left, *right;
};

// Function to create a new node
struct node* new_node(int key) {
    struct node* node = malloc(sizeof(struct node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node into the BST
void insert(struct node** root, int key) {
    if (*root == NULL) {
        *root = new_node(key);
    } else if (key < (*root)->key) {
        insert(&(*root)->left, key);
    } else {
        insert(&(*root)->right, key);
    }
}

// Function to search for a key in the BST
struct node* search(struct node* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (key < root->key) {
        return search(root->left, key);
    } else if (key > root->key) {
        return search(root->right, key);
    } else {
        return root;
    }
}

// Function to delete a node from the BST
void delete(struct node** root, int key) {
    if (*root == NULL) {
        return;
    }
    if (key < (*root)->key) {
        delete(&(*root)->left, key);
    } else {
        delete(&(*root)->right, key);
    }
    if ((*root)->left == NULL && (*root)->right == NULL) {
        free(*root);
        *root = NULL;
    }
}

int main() {
    struct node* root = NULL;

    // Insert some nodes
    insert(&root, 5);
    insert(&root, 2);
    insert(&root, 8);
    insert(&root, 3);
    insert(&root, 1);
    insert(&root, 6);

    // Search for some keys
    printf("Searching for 5: %p\n", search(root, 5));
    printf("Searching for 2: %p\n", search(root, 2));
    printf("Searching for 8: %p\n", search(root, 8));
    printf("Searching for 3: %p\n", search(root, 3));
    printf("Searching for 1: %p\n", search(root, 1));
    printf("Searching for 6: %p\n", search(root, 6));

    // Delete some nodes
    delete(&root, 5);
    delete(&root, 2);
    delete(&root, 8);
    delete(&root, 3);
    delete(&root, 1);

    return 0;
}