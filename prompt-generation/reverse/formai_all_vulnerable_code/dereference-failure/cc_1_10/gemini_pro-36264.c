//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of levels for the recursion
#define MAX_LEVELS 10

// Define the structure of a node in the tree
typedef struct node {
    char *data;
    struct node *left;
    struct node *right;
} node;

// Create a new node with the given data
node *create_node(char *data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = strdup(data);
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node into the tree
void insert_node(node **root, char *data) {
    if (*root == NULL) {
        *root = create_node(data);
    } else {
        if (strcmp(data, (*root)->data) < 0) {
            insert_node(&(*root)->left, data);
        } else {
            insert_node(&(*root)->right, data);
        }
    }
}

// Print the tree in preorder
void preorder(node *root) {
    if (root != NULL) {
        printf("%s ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Print the tree in inorder
void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s ", root->data);
        inorder(root->right);
    }
}

// Print the tree in postorder
void postorder(node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%s ", root->data);
    }
}

// Free the memory allocated for the tree
void free_tree(node *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root->data);
        free(root);
    }
}

// Main function
int main() {
    // Create a new tree
    node *root = NULL;

    // Insert some data into the tree
    insert_node(&root, "Hello");
    insert_node(&root, "World");
    insert_node(&root, "This");
    insert_node(&root, "Is");
    insert_node(&root, "A");
    insert_node(&root, "Tree");

    // Print the tree in preorder
    printf("Preorder: ");
    preorder(root);
    printf("\n");

    // Print the tree in inorder
    printf("Inorder: ");
    inorder(root);
    printf("\n");

    // Print the tree in postorder
    printf("Postorder: ");
    postorder(root);
    printf("\n");

    // Free the memory allocated for the tree
    free_tree(root);

    return 0;
}