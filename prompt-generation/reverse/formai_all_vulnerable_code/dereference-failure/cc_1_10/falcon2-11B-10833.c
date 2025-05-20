//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: creative
#include <stdio.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void insert(struct node *root, int data) {
    if (root == NULL) {
        struct node *newNode = (struct node*) malloc(sizeof(struct node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return;
    }

    if (data < root->data) {
        if (root->left == NULL) {
            root->left = (struct node*) malloc(sizeof(struct node));
            root->left->data = data;
            root->left->left = NULL;
            root->left->right = NULL;
        }
        else {
            insert(root->left, data);
        }
    }
    else if (data > root->data) {
        if (root->right == NULL) {
            root->right = (struct node*) malloc(sizeof(struct node));
            root->right->data = data;
            root->right->left = NULL;
            root->right->right = NULL;
        }
        else {
            insert(root->right, data);
        }
    }
}

void inorder(struct node *root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node *root = NULL;

    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inorder(root);

    return 0;
}