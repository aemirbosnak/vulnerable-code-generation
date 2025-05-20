//FormAI DATASET v1.0 Category: Binary search trees ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct bst_node {
    int key;
    struct bst_node *left, *right;
} bst_node;

bst_node* create_node(int key) {
    bst_node *temp = (bst_node*)malloc(sizeof(bst_node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

bst_node* insert(bst_node* root, int key) {
    if (root == NULL) return create_node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

bst_node* search(bst_node* root, int key) {
    if (root == NULL || root->key == key) return root;
    if (root->key < key) return search(root->right, key);
    return search(root->left, key);
}

bst_node* min_value_node(bst_node* node) {
    bst_node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

bst_node* delete_node(bst_node* root, int key) {
    if (root == NULL) return root;
    if (key < root->key)
        root->left = delete_node(root->left, key);
    else if (key > root->key)
        root->right = delete_node(root->right, key);
    else {
        if (root->left == NULL) {
            bst_node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            bst_node* temp = root->left;
            free(root);
            return temp;
        }
        bst_node* temp = min_value_node(root->right);
        root->key = temp->key;
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

void inorder_traversal(bst_node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->key);
        inorder_traversal(root->right);
    }
}

int main() {
    bst_node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Inorder traversal of binary search tree: \n");
    inorder_traversal(root);
    printf("\nAfter deleting 20: \n");
    root = delete_node(root, 20);
    inorder_traversal(root);
    printf("\nAfter deleting 30: \n");
    root = delete_node(root, 30);
    inorder_traversal(root);
    printf("\nAfter deleting 50: \n");
    root = delete_node(root, 50);
    inorder_traversal(root);
    return 0;
}