//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// A node in a binary tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a new node into a binary tree
struct node *insert_node(struct node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else {
        if (data <= root->data) {
            root->left = insert_node(root->left, data);
        } else {
            root->right = insert_node(root->right, data);
        }
        return root;
    }
}

// Function to print a binary tree in a visual format
void print_tree(struct node *root, int space) {
    if (root == NULL) {
        return;
    }

    space += 5;

    print_tree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    print_tree(root->left, space);
}

int main() {
    // Create a binary tree
    struct node *root = NULL;
    root = insert_node(root, 100);
    root = insert_node(root, 50);
    root = insert_node(root, 150);
    root = insert_node(root, 25);
    root = insert_node(root, 75);
    root = insert_node(root, 125);
    root = insert_node(root, 175);

    // Print the binary tree in a visual format
    print_tree(root, 0);

    return 0;
}