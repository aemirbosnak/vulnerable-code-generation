//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct node {
    int data;
    struct node *left, *right;
};

// Function to create a new node with given data
struct node* new_node(int data) {
    struct node* node = malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a node into the binary search tree
struct node* insert(struct node** root, int data) {
    struct node* current = *root;

    if (current == NULL) {
        current = new_node(data);
        *root = current;
        return current;
    }

    if (data < current->data) {
        current->left = insert(current->left, data);
    } else {
        current->right = insert(current->right, data);
    }

    return current;
}

// Function to search for a node in the binary search tree
struct node* search(struct node* root, int data) {
    struct node* current = root;

    while (current != NULL) {
        if (data == current->data) {
            return current;
        }

        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return NULL;
}

int main() {
    struct node* root = NULL;

    root = insert(&root, 5);
    root = insert(&root, 2);
    root = insert(&root, 8);
    root = insert(&root, 3);
    root = insert(&root, 1);
    root = insert(&root, 6);

    printf("Binary Search Tree: \n");

    struct node* current = root;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->left;
    }

    printf("\n");

    current = search(root, 8);
    if (current != NULL) {
        printf("Found %d at position %d\n", current->data, current->left == NULL ? 0 : 1 + (current->left->data - current->data));
    } else {
        printf("Not found\n");
    }

    return 0;
}