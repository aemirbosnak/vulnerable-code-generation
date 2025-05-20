//FormAI DATASET v1.0 Category: Binary search trees ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

struct tree_node {
    int value;
    struct tree_node *left;
    struct tree_node *right;
};

struct tree_node *create_node(int value)
{
    struct tree_node *new_node = (struct tree_node *) malloc(sizeof(struct tree_node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(struct tree_node **root, int value)
{
    if (*root == NULL) {
        *root = create_node(value);
    } else if (value < (*root)->value) {
        insert_node(&(*root)->left, value);
    } else {
        insert_node(&(*root)->right, value);
    }
}

void print_tree(struct tree_node *root)
{
    if (root != NULL) {
        printf("%d ", root->value);
        print_tree(root->left);
        print_tree(root->right);
    }
}

int search_node(struct tree_node *root, int value)
{
    if (root == NULL) {
        return 0;
    } else if (root->value == value) {
        return 1;
    } else if (value < root->value) {
        return search_node(root->left, value);
    } else {
        return search_node(root->right, value);
    }
}

int main()
{
    struct tree_node *root = NULL;
    int num_nodes, i, value, search_val, found;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    
    for (i = 0; i < num_nodes; i++) {
        printf("Enter the value of node %d: ", i + 1);
        scanf("%d", &value);
        insert_node(&root, value);
    }
    
    printf("\nBinary Search Tree: ");
    print_tree(root);
    printf("\n");
    
    printf("\nEnter the value to be searched: ");
    scanf("%d", &search_val);
    
    found = search_node(root, search_val);
    if (found) {
        printf("%d found in the BST.\n", search_val);
    } else {
        printf("%d not found in the BST.\n", search_val);
    }
    
    return 0;
}