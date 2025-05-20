//FormAI DATASET v1.0 Category: Binary search trees ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* root = malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

struct node* search(struct node* root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

void printInorder(struct node* root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}

int main() {
    struct node* tree = NULL;
    int data[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    int i;
    for (i = 0; i < 9; i++) {
        tree = insert(tree, data[i]);
    }
    printf("Inorder traversal of the binary search tree:\n");
    printInorder(tree);

    int num;
    printf("\nEnter a number to search for: ");
    scanf("%d", &num);
    struct node* result = search(tree, num);
    if (result == NULL) {
        printf("%d is not in the binary search tree.\n", num);
    } else {
        printf("%d is in the binary search tree.\n", num);
    }
    return 0;
}