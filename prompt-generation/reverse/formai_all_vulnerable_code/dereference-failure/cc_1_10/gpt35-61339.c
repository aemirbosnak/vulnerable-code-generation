//FormAI DATASET v1.0 Category: Binary search trees ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node *createNode(int key) {
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return createNode(key);

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

struct Node *search(struct Node* root, int key) {
    if (root == NULL || root->key == key)
       return root;

    if (root->key < key)
       return search(root->right, key);

    return search(root->left, key);
}

void paranoid(struct Node* root) {
    if (root != NULL) {
        printf("Current Node: [%d]\n", root->key);

        if (root->left != NULL) {
            printf("Left Child: [%d]\n", root->left->key);
            if (root->left->key >= root->key) {
                printf("Left child is larger than root, something is fishy..\n");
                exit(EXIT_FAILURE);
            }
            paranoid(root->left);
        }

        if (root->right != NULL) {
            printf("Right Child: [%d]\n", root->right->key);
            if (root->right->key <= root->key) {
                printf("Right child is smaller than root, something is fishy..\n");
                exit(EXIT_FAILURE);
            }
            paranoid(root->right);
        }
    }
}

int main() {
    struct Node *root = NULL;
    root = insert(root, 10);
    insert(root, 7);
    insert(root, 5);
    insert(root, 3);
    insert(root, 11);
    insert(root, 14);
    paranoid(root);
    printf("Binary search tree is valid, no fishy elements found.\n");
    return 0;
}