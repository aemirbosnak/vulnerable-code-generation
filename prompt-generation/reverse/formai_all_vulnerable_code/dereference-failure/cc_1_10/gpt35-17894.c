//FormAI DATASET v1.0 Category: Binary search trees ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *left, *right;
};

struct node *newNode(int item) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->val = item;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* insert(struct node* node, int val) {
    if (node == NULL) return newNode(val);

    if (val < node->val)
        node->left = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);

    return node;
}

struct node *search(struct node* root, int val) {
    if (root == NULL || root->val == val)
        return root;

    if (root->val < val)
        return search(root->right, val);

    return search(root->left, val);
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

int main() {
    struct node *root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the binary search tree: ");
    inorder(root);
    printf("\n");

    int val = 60;
    struct node* result = search(root, val);
    if (result == NULL)
        printf("Value %d is not present in the tree\n", val);
    else
        printf("Value %d is present in the tree\n", result->val);

    return 0;
}