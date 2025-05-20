//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void insert(struct node **root, int key) {
    if (*root == NULL) {
        *root = (struct node *)malloc(sizeof(struct node));
        (*root)->data = key;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else if (key < (*root)->data) {
        insert(&((*root)->left), key);
    } else if (key > (*root)->data) {
        insert(&((*root)->right), key);
    }
}

void print_inorder(struct node *root) {
    if (root == NULL)
        return;
    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
}

int main() {
    struct node *root = NULL;
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 5);
    insert(&root, 15);
    insert(&root, 25);
    insert(&root, 35);
    insert(&root, 40);
    insert(&root, 45);
    insert(&root, 50);
    insert(&root, 55);
    insert(&root, 60);
    insert(&root, 65);
    insert(&root, 70);
    insert(&root, 75);
    insert(&root, 80);
    insert(&root, 85);
    insert(&root, 90);
    insert(&root, 95);
    printf("Inorder traversal of the binary search tree is:\n");
    print_inorder(root);
    return 0;
}