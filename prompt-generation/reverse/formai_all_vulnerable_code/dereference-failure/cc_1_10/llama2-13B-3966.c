//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_KEY_LEN 20

// Node structure
typedef struct node {
    int key;
    char name[MAX_KEY_LEN];
    struct node *left, *right;
} Node;

// Function to create a new node
Node* new_node(int key, char name[MAX_KEY_LEN]) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->key = key;
    strcpy(node->name, name);
    node->left = node->right = NULL;
    return node;
}

// Function to search a node
Node* search_node(Node* root, int key) {
    if (root == NULL) return NULL;
    if (root->key == key) return root;
    if (key < root->key) return search_node(root->left, key);
    return search_node(root->right, key);
}

// Function to insert a node
void insert_node(Node** root_ref, int key, char name[]) {
    Node* root = *root_ref;
    if (root == NULL) {
        *root_ref = new_node(key, name);
        return;
    }
    if (key < root->key) {
        insert_node(&root->left, key, name);
    } else {
        insert_node(&root->right, key, name);
    }
}

// Function to traverse the tree
void traverse(Node* root) {
    if (root == NULL) return;
    printf("%d %s\n", root->key, root->name);
    traverse(root->left);
    traverse(root->right);
}

int main() {
    Node* root = NULL;
    insert_node(&root, 5, "Alice");
    insert_node(&root, 10, "Bob");
    insert_node(&root, 15, "Charlie");
    insert_node(&root, 20, "David");
    traverse(root);
    return 0;
}