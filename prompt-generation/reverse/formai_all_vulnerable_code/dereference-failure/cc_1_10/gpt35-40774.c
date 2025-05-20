//FormAI DATASET v1.0 Category: Binary search trees ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* left;
    struct node* right;
};

struct node* create_node(int value) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(struct node** root, struct node* new_node) {
    if (*root == NULL) {
        *root = new_node;
        return;
    }

    if (new_node->value < (*root)->value)
        insert_node(&((*root)->left), new_node);
    else
        insert_node(&((*root)->right), new_node);
}

void inorder_traversal(struct node* root) {
    if (root == NULL)
        return;

    inorder_traversal(root->left);
    printf("%d ", root->value);
    inorder_traversal(root->right);
}

int main() {
    struct node* root = NULL;

    insert_node(&root, create_node(8));
    insert_node(&root, create_node(3));
    insert_node(&root, create_node(10));
    insert_node(&root, create_node(1));
    insert_node(&root, create_node(6));
    insert_node(&root, create_node(14));

    printf("Inorder traversal: ");
    inorder_traversal(root);

    return 0;
}