//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_KEY_LEN 20

// Node structure
struct node {
    int key;
    char name[MAX_KEY_LEN];
    struct node *left, *right;
};

// Function to create a new node
struct node* new_node(int key, char name[MAX_KEY_LEN]) {
    struct node* node = malloc(sizeof(struct node));
    node->key = key;
    strcpy(node->name, name);
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the binary search tree
struct node* insert_node(struct node** root, int key, char name[MAX_KEY_LEN]) {
    if (*root == NULL) {
        *root = new_node(key, name);
        return *root;
    }

    if (key < (*root)->key) {
        if ((*root)->left == NULL) {
            (*root)->left = new_node(key, name);
            return *root;
        } else {
            insert_node(&((*root)->left), key, name);
            return *root;
        }
    } else if (key > (*root)->key) {
        if ((*root)->right == NULL) {
            (*root)->right = new_node(key, name);
            return *root;
        } else {
            insert_node(&((*root)->right), key, name);
            return *root;
        }
    } else {
        // Key already exists, do nothing
        return *root;
    }
}

// Function to search for a node in the binary search tree
struct node* search_node(struct node** root, int key) {
    if (*root == NULL) {
        return NULL;
    }

    if (key < (*root)->key) {
        return search_node(&((*root)->left), key);
    } else if (key > (*root)->key) {
        return search_node(&((*root)->right), key);
    } else {
        return *root;
    }
}

// Function to traverse the binary search tree
void traverse(struct node* root) {
    if (root != NULL) {
        traverse(root->left);
        printf("%d (%s)\n", root->key, root->name);
        traverse(root->right);
    }
}

int main() {
    srand(time(NULL));

    struct node* root = NULL;

    for (int i = 0; i < 10; i++) {
        int key = rand() % 100;
        char name[MAX_KEY_LEN] = "Unknown";
        insert_node(&root, key, name);
    }

    traverse(root);

    return 0;
}