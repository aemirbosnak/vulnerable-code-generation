//FormAI DATASET v1.0 Category: Data structures visualization ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// function to create a new node
struct node* createNewNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// function to insert a node into binary tree
struct node* insertNode(struct node* root, int data) {
    if (root == NULL) {
        return createNewNode(data);
    }
    else if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// function to print nodes in inorder traversal
void inorderTraversal(struct node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    struct node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("\n\n           50\n");
    printf("       /       \\\n");
    printf("      30        70\n");
    printf("     /  \\      /  \\\n");
    printf("   20   40    60   80\n\n\n");

    printf("Inorder Traversal: ");
    inorderTraversal(root);

    return 0;
}