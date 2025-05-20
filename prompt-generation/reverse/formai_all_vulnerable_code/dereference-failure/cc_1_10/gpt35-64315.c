//FormAI DATASET v1.0 Category: Binary search trees ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

void insert(struct node* node, int data) {
    if (data < node->data) {
        if (node->left != NULL) {
            insert(node->left, data);
        } else {
            node->left = newNode(data);
        }
    } else {
        if (node->right != NULL) {
            insert(node->right, data);
        } else {
            node->right = newNode(data);
        }
    }
}

void inorderTraversal(struct node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

int main() {
    // Create root node
    struct node* root = newNode(50);

    // Insert nodes
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Traverse tree inorder
    printf("Inorder traversal: ");
    inorderTraversal(root);

    return 0;
}