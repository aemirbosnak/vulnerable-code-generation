//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_KEY 100

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

// Brave style, yo!
Node* brave_bs_insert(Node** root, int key) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->key = key;

    if (*root == NULL) {
        *root = new_node;
        return new_node;
    }

    if (key < (*root)->key) {
        new_node->left = brave_bs_insert(&(*root)->left, key);
        (*root)->left = new_node;
    } else if (key > (*root)->key) {
        new_node->right = brave_bs_insert(&(*root)->right, key);
        (*root)->right = new_node;
    }

    return *root;
}

// Brave style, yo!
int brave_bs_search(Node* root, int key) {
    if (root == NULL) {
        return -1;
    }

    if (key < root->key) {
        return brave_bs_search(root->left, key);
    } else if (key > root->key) {
        return brave_bs_search(root->right, key);
    }

    return root->key;
}

int main() {
    Node* root = NULL;

    // Insert some nodes, yo!
    root = brave_bs_insert(&root, 5);
    root = brave_bs_insert(&root, 10);
    root = brave_bs_insert(&root, 20);
    root = brave_bs_insert(&root, 30);

    // Search for some nodes, yo!
    printf("5: %d\n", brave_bs_search(root, 5));
    printf("10: %d\n", brave_bs_search(root, 10));
    printf("20: %d\n", brave_bs_search(root, 20));
    printf("30: %d\n", brave_bs_search(root, 30));

    return 0;
}