//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: brave
#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
    int data;
    struct Tree *left;
    struct Tree *right;
} Tree;

Tree *createNode(int data) {
    Tree *node = (Tree *)malloc(sizeof(Tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(Tree **root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
    } else if (data <= (*root)->data) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}

void preorder(Tree *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Tree *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(Tree *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void printTree(Tree *root) {
    if (root != NULL) {
        printf("Preorder: ");
        preorder(root);
        printf("\n");

        printf("Inorder: ");
        inorder(root);
        printf("\n");

        printf("Postorder: ");
        postorder(root);
        printf("\n");
    }
}

int main() {
    Tree *root = NULL;

    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 15);
    insert(&root, 2);
    insert(&root, 7);
    insert(&root, 12);
    insert(&root, 20);

    printTree(root);

    return 0;
}