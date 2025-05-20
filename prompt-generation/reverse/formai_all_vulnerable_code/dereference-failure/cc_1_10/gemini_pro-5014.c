//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: expert-level
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
    } else {
        insert_node(&(*root)->right, data);
    }
}

void print_tree(node *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}

int main() {
    node *root = NULL;
    int n, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int data;
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        insert_node(&root, data);
    }
    printf("The inorder traversal of the tree is: ");
    print_tree(root);
    return 0;
}