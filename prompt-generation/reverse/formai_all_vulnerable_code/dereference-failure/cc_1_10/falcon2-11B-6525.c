//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: random
#include <stdio.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(struct Node* node, int data) {
    if (node == NULL) {
        node = newNode(data);
        return;
    }

    if (data < node->data) {
        if (node->left == NULL) {
            node->left = newNode(data);
        } else {
            insert(node->left, data);
        }
    } else {
        if (node->right == NULL) {
            node->right = newNode(data);
        } else {
            insert(node->right, data);
        }
    }
}

void inOrder(struct Node* node) {
    if (node!= NULL) {
        inOrder(node->left);
        printf("%d ", node->data);
        inOrder(node->right);
    }
}

int main() {
    struct Node* root = NULL;

    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);

    inOrder(root);

    return 0;
}