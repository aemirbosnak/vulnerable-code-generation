//FormAI DATASET v1.0 Category: Data structures visualization ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

/* Structure of a node */
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

/* Function to create a new node */
node_t *create_node(int data) {
    node_t *new_node = (node_t*) malloc(sizeof(node_t));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

/* Recursive function to insert a node in a BST */
node_t *insert_node(node_t *root, int data) {
    if (root == NULL) {
        return create_node(data);
    }
    if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

/* Recursive function to print the nodes in a BST */
void display_tree(node_t *root, int level) {
    if (root != NULL) {
        display_tree(root->right, level+1);
        printf("\n");
        for (int i = 0; i < level; i++) {
            printf(" ");
        }
        printf("%d\n", root->data);
        display_tree(root->left, level+1);
    }
}

int main() {
    /* Create a BST */
    node_t *root = NULL;
    root = insert_node(root, 8);
    insert_node(root, 3);
    insert_node(root, 10);
    insert_node(root, 1);
    insert_node(root, 6);
    insert_node(root, 14);
    insert_node(root, 4);
    insert_node(root, 7);
    insert_node(root, 13);

    /* Display the BST */
    printf("BST Visualization:\n");
    display_tree(root, 0);

    return 0;
}