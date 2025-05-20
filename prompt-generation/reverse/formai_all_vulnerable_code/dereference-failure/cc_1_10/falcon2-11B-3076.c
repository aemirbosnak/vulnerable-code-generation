//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: lively
#include <stdio.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
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

void inOrder(struct Node* root) {
    if (root!= NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 1);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 14);
    root = insert(root, 9);
    root = insert(root, 16);

    printf("Inorder traversal of the BST:\n");
    inOrder(root);

    return 0;
}