//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

void insert(node **root, int data) {
    if (*root == NULL) {
        *root = (node *)malloc(sizeof(node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else if (data < (*root)->data) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}

void print_inorder(node *root) {
    if (root != NULL) {
        print_inorder(root->left);
        printf("%d ", root->data);
        print_inorder(root->right);
    }
}

void print_preorder(node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        print_preorder(root->left);
        print_preorder(root->right);
    }
}

void print_postorder(node *root) {
    if (root != NULL) {
        print_postorder(root->left);
        print_postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    node *root = NULL;
    int n, i, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        insert(&root, data);
    }
    printf("Inorder traversal: ");
    print_inorder(root);
    printf("\nPreorder traversal: ");
    print_preorder(root);
    printf("\nPostorder traversal: ");
    print_postorder(root);
    printf("\n");
    return 0;
}