//FormAI DATASET v1.0 Category: Binary search trees ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

struct Node* insert(struct Node* node, int data) {
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

void printInorder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main() {
    printf("Creating a Binary Search Tree with statistical data...\n\n");
    struct Node* root = NULL;
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 3);
    insert(root, 30);
    insert(root, 1);
    insert(root, 5);
    insert(root, 70);
    insert(root, 40);
    printf("Inorder traversal of the Binary Search Tree created is:\n");
    printInorder(root);
    printf("\n\nThank you for using our program!\n");

    return 0;
}