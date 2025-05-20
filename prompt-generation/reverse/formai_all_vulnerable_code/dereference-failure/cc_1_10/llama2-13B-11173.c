//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Node representing a binary search tree
struct BSTNode {
    int data;
    struct BSTNode *left, *right;
};

// Function to create a new node with given data
struct BSTNode* newNode(int data) {
    struct BSTNode* node = (struct BSTNode*) malloc(sizeof(struct BSTNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the tree
void insert(struct BSTNode** root, int data) {
    if (*root == NULL) {
        *root = newNode(data);
        return;
    }

    if (data < (*root)->data) {
        if ((*root)->left == NULL) {
            (*root)->left = newNode(data);
        } else {
            insert((*root)->left, data);
        }
    } else {
        if ((*root)->right == NULL) {
            (*root)->right = newNode(data);
        } else {
            insert((*root)->right, data);
        }
    }
}

// Function to search for a node in the tree
struct BSTNode* search(struct BSTNode* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else if (data > root->data) {
        return search(root->right, data);
    } else {
        return root;
    }
}

// Function to traverse the tree
void traverse(struct BSTNode* root) {
    if (root != NULL) {
        traverse(root->left);
        printf("%d ", root->data);
        traverse(root->right);
    }
}

int main() {
    struct BSTNode* root = NULL;
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 9);
    insert(&root, 1);
    insert(&root, 4);

    struct BSTNode* node = search(root, 5);
    if (node != NULL) {
        printf("Found %d\n", node->data);
    } else {
        printf("Not found\n");
    }

    traverse(root);

    return 0;
}