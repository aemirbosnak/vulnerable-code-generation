//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE_SIZE 1024
#define MAX_TREE_SIZE 1024*1024

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* createNode(int key) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

void insert(Node** root, int key) {
    Node* node = *root;
    if (!node) {
        *root = createNode(key);
        return;
    }

    if (key < node->key) {
        insert(&node->left, key);
    } else if (key > node->key) {
        insert(&node->right, key);
    }
}

void traverse(Node* root) {
    if (root) {
        traverse(root->left);
        printf("%d ", root->key);
        traverse(root->right);
    }
}

int search(Node* root, int key) {
    if (!root) {
        return -1;
    }

    if (key < root->key) {
        return search(root->left, key);
    } else if (key > root->key) {
        return search(root->right, key);
    } else {
        return 0;
    }
}

int main() {
    Node* root = NULL;

    // Insert some nodes
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 1);
    insert(&root, 3);
    insert(&root, 5);

    // Traverse the tree
    traverse(root);

    // Search for a specific key
    int result = search(root, 4);
    printf("Result of searching for 4: %d\n", result);

    return 0;
}