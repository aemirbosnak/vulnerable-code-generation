//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insertNode(struct Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

struct Node* findMin(struct Node *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL) {
        return root;
    } else {
        return findMin(root->left);
    }
}

struct Node* findMax(struct Node *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->right == NULL) {
        return root;
    } else {
        return findMax(root->right);
    }
}

int findHeight(struct Node *root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}

void printTree(struct Node *root) {
    if (root == NULL) {
        return;
    } else {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}

int main() {
    // Create a binary search tree.
    struct Node *root = NULL;
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        int data = rand() % 100;
        root = insertNode(root, data);
    }

    // Find the minimum and maximum values in the tree.
    struct Node *min = findMin(root);
    struct Node *max = findMax(root);
    printf("Minimum value: %d\n", min->data);
    printf("Maximum value: %d\n", max->data);

    // Find the height of the tree.
    int height = findHeight(root);
    printf("Height of the tree: %d\n", height);

    // Print the tree.
    printf("Inorder traversal: ");
    printTree(root);
    printf("\n");

    return 0;
}