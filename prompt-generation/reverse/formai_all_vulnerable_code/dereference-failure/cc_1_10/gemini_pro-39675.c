//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Node structure for a binary tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node with the given data
struct node *new_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a new node into a binary tree
struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        return new_node(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to print a binary tree in a 2D visualization
void print_tree(struct node *root) {
    if (root == NULL) {
        return;
    }
    // Calculate the height of the tree
    int height = 0;
    struct node *node = root;
    while (node != NULL) {
        height++;
        node = node->left;
    }

    // Create a 2D array to store the tree data
    int **tree_data = (int **)malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        tree_data[i] = (int *)malloc(sizeof(int) * (1 << i));
    }

    // Fill the 2D array with the tree data
    int level = 0;
    int index = 0;
    node = root;
    while (node != NULL) {
        tree_data[level][index] = node->data;
        if (node->left != NULL) {
            index++;
        } else {
            index--;
        }
        level++;
        node = node->left;
    }

    // Print the 2D array
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < (1 << i); j++) {
            printf("%d ", tree_data[i][j]);
        }
        printf("\n");
    }

    // Free the 2D array
    for (int i = 0; i < height; i++) {
        free(tree_data[i]);
    }
    free(tree_data);
}

int main() {
    // Create a binary tree
    struct node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);

    // Print the binary tree in a 2D visualization
    print_tree(root);

    return 0;
}