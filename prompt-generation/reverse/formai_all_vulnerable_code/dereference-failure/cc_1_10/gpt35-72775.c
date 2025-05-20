//FormAI DATASET v1.0 Category: Data structures visualization ; Style: high level of detail
/* This C program demonstrates the implementation of a binary search tree data structure.
   We will use this data structure to visualize the relationships between nodes in the tree */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left_child;
    struct node* right_child;
} TreeNode;

TreeNode* create_node(int data) {
    TreeNode* new_node = (TreeNode*) malloc(sizeof(TreeNode));
    new_node->data = data;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
}

TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }
    if (data < root->data) {
        root->left_child = insert(root->left_child, data);
    } else if (data > root->data) {
        root->right_child = insert(root->right_child, data);
    }
    return root;
}

void print_node(TreeNode* node, int level) {
    if (node == NULL) {
        return;
    }
    print_node(node->right_child, level + 1);
    for (int i = 0; i < level; i++) {
        printf("   ");
    }
    printf("%d\n", node->data);
    print_node(node->left_child, level + 1);
}

int main() {
    TreeNode* root = create_node(8);
    insert(root, 4);
    insert(root, 12);
    insert(root, 2);
    insert(root, 6);
    insert(root, 10);
    insert(root, 14);
    insert(root, 1);
    insert(root, 3);
    insert(root, 5);
    insert(root, 7);
    insert(root, 9);
    insert(root, 11);
    insert(root, 13);
    insert(root, 15);
    print_node(root, 0);

    return 0;
}