//FormAI DATASET v1.0 Category: Binary search trees ; Style: safe
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
};

// Function to create a new node with the given data
struct node* create_node(int key) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a new node in the binary search tree
struct node* insert_node(struct node* root, int key) {
    if (root == NULL) {
        return create_node(key);
    }
    if (key < root->key) {
        root->left  = insert_node(root->left, key);
    }
    else if (key > root->key) {
        root->right = insert_node(root->right, key);
    }
    return root;
}

// Function to search for a node with the given key
int search_node(struct node* root, int key) {
    if (root == NULL) {
        return 0;
    }
    if (key == root->key) {
        return 1;
    }
    else if (key < root->key) {
        return search_node(root->left, key);
    }
    else {
        return search_node(root->right, key);
    }
}

// Function to print the contents of the binary search tree in sorted order
void inorder_traversal(struct node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->key);
        inorder_traversal(root->right);
    }
}

// Function to find the minimum value node in a given binary search tree
struct node* find_min_node(struct node* node) {
    struct node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node with the given key from the binary search tree
struct node* delete_node(struct node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = delete_node(root->left, key);
    }
    else if (key > root->key) {
        root->right = delete_node(root->right, key);
    }
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        // node with two children
        struct node* temp = find_min_node(root->right);
        root->key = temp->key;
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

int main() {
    struct node* root = NULL;

    // Insert nodes into the binary search tree
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 70);
    root = insert_node(root, 60);
    root = insert_node(root, 80);

    printf("Binary Search Tree in sorted order: ");
    inorder_traversal(root);

    int key = 55;
    if (search_node(root, key)) {
        printf("\nKey %d is present in the binary search tree.", key);
    }
    else {
        printf("\nKey %d is not present in the binary search tree.", key);
    }

    key = 20;
    root = delete_node(root, key);
    printf("\nBinary Search Tree after deleting node with key %d: ", key);
    inorder_traversal(root);

    return 0;
}