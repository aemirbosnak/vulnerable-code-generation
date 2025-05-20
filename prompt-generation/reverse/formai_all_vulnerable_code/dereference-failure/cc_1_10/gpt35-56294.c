//FormAI DATASET v1.0 Category: Binary search trees ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        return newNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int search(struct node* root, int value) {
    if (root == NULL || root->data == value) {
        return root != NULL;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    else {
        return search(root->right, value);
    }
}

int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the BST: ");
    inorder(root);

    int value = 60;
    if (search(root, value)) {
        printf("\n%d can be found in the BST.\n", value);
    }
    else {
        printf("\n%d cannot be found in the BST.\n", value);
    }

    return 0;
}