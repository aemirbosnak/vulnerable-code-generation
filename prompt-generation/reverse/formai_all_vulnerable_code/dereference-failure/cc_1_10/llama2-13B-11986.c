//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_SIZE 1024
#define MAX_TREE_SIZE 1024

// Structure to represent a node in the binary search tree
struct node {
    int key;
    struct node *left, *right;
    char name[20];
};

// Function to create a new node
struct node* new_node(int key, char name[]) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->key = key;
    node->left = node->right = NULL;
    strcpy(node->name, name);
    return node;
}

// Function to insert a node into the tree
void insert(struct node** root, int key, char name[]) {
    if (*root == NULL) {
        *root = new_node(key, name);
    } else if (key < (*root)->key) {
        insert(&(*root)->left, key, name);
    } else {
        insert(&(*root)->right, key, name);
    }
}

// Function to search for a node in the tree
struct node* search(struct node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Function to print the tree
void print(struct node* root) {
    if (root == NULL) {
        return;
    }

    printf("%s (%d)\n", root->name, root->key);

    print(root->left);
    print(root->right);
}

int main() {
    struct node* root = NULL;

    insert(&root, 5, "John");
    insert(&root, 3, "Jane");
    insert(&root, 7, "Bob");
    insert(&root, 2, "Alice");
    insert(&root, 4, "David");

    struct node* node = search(root, 5);

    if (node != NULL) {
        printf("Found %d at %s\n", node->key, node->name);
    } else {
        printf("Not found\n");
    }

    print(root);

    return 0;
}