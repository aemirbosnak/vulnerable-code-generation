//FormAI DATASET v1.0 Category: Binary search trees ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int item) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data) node->left = insert(node->left, data);
    else if (data > node->data) node->right = insert(node->right, data);
    return node;
}

void printInOrder(struct node* node) {
    if (node == NULL) return;
    printInOrder(node->left);
    printf("%d ", node->data);
    printInOrder(node->right);
}

struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL) current = current->left;
    return current;
}

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) return root;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct node *root = NULL;
    int nums[10] = {5, 3, 8, 1, 4, 7, 9, 2, 6, 10};
    int size = sizeof(nums) / sizeof(nums[0]);
    int i;
    for (i = 0; i < size; i++) {
        root = insert(root, nums[i]);
    }
    printf("In Order Traversal: ");
    printInOrder(root);
    printf("\n");

    root = deleteNode(root, 3);
    printf("In Order Traversal after deleting 3: ");
    printInOrder(root);
    printf("\n");

    return 0;
}