//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DEPTH 5
#define MAX_LEN 100

// Structure to represent a node in the tree
typedef struct node {
    char *name;
    int value;
    struct node *left;
    struct node *right;
} node_t;

// Function to create a new node
node_t *new_node(char *name, int value) {
    node_t *node = (node_t *) malloc(sizeof(node_t));
    node->name = name;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the tree
void insert_node(node_t **root, char *name, int value) {
    if (*root == NULL) {
        *root = new_node(name, value);
    } else {
        if (strcmp(name, (*root)->name) < 0) {
            insert_node(&(*root)->left, name, value);
        } else {
            insert_node(&(*root)->right, name, value);
        }
    }
}

// Function to traverse the tree
void traverse(node_t *root) {
    if (root != NULL) {
        printf("%s: %d\n", root->name, root->value);
        traverse(root->left);
        traverse(root->right);
    }
}

// Function to find the maximum value in the tree
int find_max(node_t *root) {
    if (root == NULL) {
        return 0;
    }
    int max = root->value;
    if (root->left != NULL) {
        max = max > root->left->value ? max : root->left->value;
    }
    if (root->right != NULL) {
        max = max > root->right->value ? max : root->right->value;
    }
    return max;
}

int main() {
    node_t *root = NULL;
    insert_node(&root, "A", 1);
    insert_node(&root, "B", 2);
    insert_node(&root, "C", 3);
    insert_node(&root, "D", 4);
    insert_node(&root, "E", 5);
    traverse(root);
    printf("Max value: %d\n", find_max(root));
    return 0;
}