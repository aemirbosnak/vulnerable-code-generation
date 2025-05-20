//FormAI DATASET v1.0 Category: Binary search trees ; Style: automated
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int value) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *root, int value) {
    if (root == NULL) {
        return newNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    }
    else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

struct Node *findMin(struct Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node *delete(struct Node *root, int value) {
    if (root == NULL) {
        printf("Node not found");
        return root;
    }
    if (value < root->value) {
        root->left = delete(root->left, value);
    }
    else if (value > root->value) {
        root->right = delete(root->right, value);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL) {
            struct Node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL) {
            struct Node *temp = root;
            root = root->left;
            free(temp);
        }
        else {
            struct Node *temp = findMin(root->right);
            root->value = temp->value;
            root->right = delete(root->right, temp->value);
        }
    }
    return root;
}

int main() {
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the binary search tree: ");
    inorder(root);

    delete(root, 20);
    printf("\nInorder traversal after deleting 20: ");
    inorder(root);

    delete(root, 30);
    printf("\nInorder traversal after deleting 30: ");
    inorder(root);

    delete(root, 50);
    printf("\nInorder traversal after deleting 50: ");
    inorder(root);

    return 0;
}