//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

Node *newNode(int key) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int height(Node *root) {
    if (!root) {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight? leftHeight : rightHeight);
}

Node *insert(Node *root, int key) {
    if (!root) {
        root = newNode(key);
        return root;
    }

    int cmp = root->key - key;
    if (cmp == 0) {
        return root;
    }
    if (cmp < 0) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

void inorder(Node *root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

int main() {
    Node *root = NULL;
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    return 0;
}