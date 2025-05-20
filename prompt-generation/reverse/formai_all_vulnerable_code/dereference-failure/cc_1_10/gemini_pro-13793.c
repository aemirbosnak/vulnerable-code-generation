//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(node **root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
    } else if (data < (*root)->data) {
        insert_node(&(*root)->left, data);
    } else if (data > (*root)->data) {
        insert_node(&(*root)->right, data);
    }
}

int search_node(node *root, int data) {
    if (root == NULL) {
        return 0;
    } else if (root->data == data) {
        return 1;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else if (data > root->data) {
        return search_node(root->right, data);
    }
}

void print_preorder(node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    print_preorder(root->left);
    print_preorder(root->right);
}

void print_inorder(node *root) {
    if (root == NULL) {
        return;
    }
    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
}

void print_postorder(node *root) {
    if (root == NULL) {
        return;
    }
    print_postorder(root->left);
    print_postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    node *root = NULL;
    insert_node(&root, 10);
    insert_node(&root, 5);
    insert_node(&root, 15);
    insert_node(&root, 2);
    insert_node(&root, 7);
    insert_node(&root, 12);
    insert_node(&root, 20);
    printf("Preorder: ");
    print_preorder(root);
    printf("\n");
    printf("Inorder: ");
    print_inorder(root);
    printf("\n");
    printf("Postorder: ");
    print_postorder(root);
    printf("\n");
    if (search_node(root, 15)) {
        printf("15 found in the tree\n");
    } else {
        printf("15 not found in the tree\n");
    }
    return 0;
}