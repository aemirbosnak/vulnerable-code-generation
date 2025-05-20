//FormAI DATASET v1.0 Category: Binary search trees ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d -> ", root->data);
    inorderTraversal(root->right);
}

int main() {
    struct Node* root = NULL;

    // Insert nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Traverse the tree
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Search for a node
    struct Node* searchNode = search(root, 70);
    if (searchNode != NULL) {
        printf("Node found: %d\n", searchNode->data);
    } else {
        printf("Node not found.\n");
    }

    return 0;
}