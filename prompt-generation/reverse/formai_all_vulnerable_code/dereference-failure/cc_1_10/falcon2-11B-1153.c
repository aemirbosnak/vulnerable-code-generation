//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else {
        if (data < root->data) {
            if (root->left == NULL) {
                root->left = createNode(data);
            } else {
                insert(root->left, data);
            }
        } else {
            if (root->right == NULL) {
                root->right = createNode(data);
            } else {
                insert(root->right, data);
            }
        }
    }
}

void inorder(struct Node* root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 20);
    insert(root, 25);
    insert(root, 30);
    insert(root, 35);
    insert(root, 40);
    insert(root, 45);
    insert(root, 50);
    insert(root, 55);
    insert(root, 60);
    insert(root, 65);
    insert(root, 70);
    insert(root, 75);
    insert(root, 80);
    insert(root, 85);
    insert(root, 90);
    insert(root, 95);
    inorder(root);
    return 0;
}