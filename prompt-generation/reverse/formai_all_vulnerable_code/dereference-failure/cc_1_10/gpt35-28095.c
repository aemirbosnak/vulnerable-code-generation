//FormAI DATASET v1.0 Category: Binary search trees ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insertNode(struct Node* node, int value) {
    if (node == NULL) return createNode(value);

    if (value < node->data) node->left = insertNode(node->left, value);
    else if (value > node->data) node->right = insertNode(node->right, value);

    return node;
}

struct Node* searchNode(struct Node* root, int value) {
    if (root == NULL || root->data == value) return root;

    if (root->data < value) return searchNode(root->right, value);

    return searchNode(root->left, value);
}

void inorderTraversal(struct Node* node) {
    if (node == NULL) return;

    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

int main() {
    struct Node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 80);
    insertNode(root, 60);

    printf("Inorder Traversal: ");
    inorderTraversal(root);

    int key = 40;
    struct Node* foundNode = searchNode(root, key);
    if (foundNode == NULL) printf("\nKey %d not found.", key);
    else printf("\nKey %d found.", key);

    return 0;
}