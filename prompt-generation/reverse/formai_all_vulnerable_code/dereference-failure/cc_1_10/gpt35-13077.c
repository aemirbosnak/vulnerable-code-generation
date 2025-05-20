//FormAI DATASET v1.0 Category: Binary search trees ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

/* Structure for a node in the binary search tree */
struct node {
    int data;
    struct node *left;
    struct node *right;
};

/* Function to create a new node */
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

/* Insert function for the binary search tree */
struct node* insert(struct node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    }
    else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

/* Function to do inorder traversal of the binary search tree */
void inorderTraversal(struct node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

/* Main function */
int main() {
    struct node* root = NULL;
    int n, i, x;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the values of the nodes: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Inorder traversal of the binary search tree: ");
    inorderTraversal(root);

    return 0;
}