//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
};

struct node* create_node(int key) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node* insert(struct node* root, int key) {
    if (root == NULL) {
        return create_node(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

int search(struct node* root, int key) {
    if (root == NULL) {
        return -1;
    }

    if (root->key == key) {
        return 1;
    }

    if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

void inorder_traversal(struct node* root) {
    if (root!= NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->key);
        inorder_traversal(root->right);
    }
}

int main() {
    struct node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of BST is:\n");
    inorder_traversal(root);

    printf("\nSearching for 60: %d\n", search(root, 60));

    return 0;
}