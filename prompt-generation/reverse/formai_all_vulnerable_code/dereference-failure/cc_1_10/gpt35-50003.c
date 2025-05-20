//FormAI DATASET v1.0 Category: Binary search trees ; Style: portable
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node *insert_node(struct node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    }
    else {
        if (data < root->data) {
            root->left = insert_node(root->left, data);
        }
        else if (data > root->data) {
            root->right = insert_node(root->right, data);
        }
        return root;
    }
}

struct node *search_node(struct node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    else if (data < root->data) {
        return search_node(root->left, data);
    }
    else {
        return search_node(root->right, data);
    }
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
    int n, val;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the value of node %d: ", i+1);
        scanf("%d", &val);
        root = insert_node(root, val);
    }
    printf("\nInorder traversal of binary search tree: ");
    inorder_traversal(root);
    printf("\nEnter the value to be searched: ");
    scanf("%d", &val);
    struct node *search_result = search_node(root, val);
    if (search_result == NULL) {
        printf("%d not found in the binary search tree.\n", val);
    }
    else {
        printf("%d found in the binary search tree.\n", val);
    }
    return 0;
}