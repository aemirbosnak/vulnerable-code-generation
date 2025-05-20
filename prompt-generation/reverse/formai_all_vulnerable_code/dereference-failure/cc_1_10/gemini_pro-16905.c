//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node
{
    int val;
    struct tree_node *left;
    struct tree_node *right;
} tree_node;

tree_node *create_node(int val)
{
    tree_node *new_node = (tree_node *)malloc(sizeof(tree_node));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

tree_node *insert_node(tree_node *root, int val)
{
    if (root == NULL)
        return create_node(val);
    if (val < root->val)
        root->left = insert_node(root->left, val);
    else
        root->right = insert_node(root->right, val);
    return root;
}

void print_tree(tree_node *root)
{
    if (root == NULL)
        return;
    print_tree(root->left);
    printf("%d ", root->val);
    print_tree(root->right);
}

void free_tree(tree_node *root)
{
    if (root == NULL)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main()
{
    tree_node *root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 5);
    root = insert_node(root, 15);
    root = insert_node(root, 2);
    root = insert_node(root, 7);
    root = insert_node(root, 12);
    root = insert_node(root, 20);
    printf("The binary search tree is: ");
    print_tree(root);
    printf("\n");
    free_tree(root);
    return 0;
}