//FormAI DATASET v1.0 Category: Binary search trees ; Style: calm
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

struct node *insert_node(struct node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    }

    if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }

    return root;
}

struct node *find_minimum(struct node *node) {
    struct node *current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

struct node *delete_node(struct node *root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = delete_node(root->left, data);
    } else if (data > root->data) {
        root->right = delete_node(root->right, data);
    } else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = find_minimum(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }

    return root;
}

void inorder_traversal(struct node *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

int main() {
    struct node *root = NULL;

    root = insert_node(root, 10);
    root = insert_node(root, 20);
    root = insert_node(root, 30);
    root = insert_node(root, 40);
    root = insert_node(root, 50);

    printf("Binary Search Tree Inorder Traversal: ");
    inorder_traversal(root);
    printf("\n");

    root = delete_node(root, 20);
    printf("After deleting node with value 20: ");
    inorder_traversal(root);
    printf("\n");

    return 0;
}