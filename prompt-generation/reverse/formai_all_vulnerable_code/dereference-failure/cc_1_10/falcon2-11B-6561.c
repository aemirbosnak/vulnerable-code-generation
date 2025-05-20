//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

struct node *create_node(int key) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->key = key;
    new_node->left = new_node->right = NULL;
    return new_node;
}

struct node *insert(struct node *root, int key) {
    if (root == NULL) {
        root = create_node(key);
        return root;
    }

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

void inorder(struct node *node) {
    if (node!= NULL) {
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}

void print_tree(struct node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->key);
    print_tree(root->left);
    print_tree(root->right);
}

int main() {
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    inorder(root);
    printf("\n");
    print_tree(root);
    return 0;
}