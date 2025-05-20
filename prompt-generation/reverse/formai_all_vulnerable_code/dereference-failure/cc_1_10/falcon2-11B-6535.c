//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: active
#include<stdio.h>
#include<stdlib.h>

// Node definition
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Insert function
void insert(struct node **root, int data) {
    if (*root == NULL) {
        *root = (struct node *) malloc(sizeof(struct node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if (data < (*root)->data)
        insert(&((*root)->left), data);
    else if (data > (*root)->data)
        insert(&((*root)->right), data);
}

// Inorder traversal function
void inorder(struct node *node) {
    if (node!= NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

// Main function
int main() {
    struct node *root = NULL;

    // Inserting elements
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    // Inorder traversal
    inorder(root);
    return 0;
}