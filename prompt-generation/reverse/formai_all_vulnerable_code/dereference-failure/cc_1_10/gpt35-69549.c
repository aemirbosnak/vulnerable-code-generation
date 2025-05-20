//FormAI DATASET v1.0 Category: Binary search trees ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

int search(struct node* root, int data) {
    if (root == NULL) {
        return 0;
    } else if (data == root->data) {
        return 1;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;

    // Inserting nodes
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 7);
    root = insert(root, 3);
    root = insert(root, 15);
    root = insert(root, 25);

    // Searching nodes
    int element1 = 7;
    int element2 = 50;

    if (search(root, element1) == 1) {
        printf("%d exists in the tree\n", element1);
    } else {
        printf("%d does not exist in the tree\n", element1);
    }

    if (search(root, element2) == 1) {
        printf("%d exists in the tree\n", element2);
    } else {
        printf("%d does not exist in the tree\n", element2);
    }

    // Printing inorder traversal of tree
    printf("Inorder Traversal: ");
    inorder(root);

    return 0;
}