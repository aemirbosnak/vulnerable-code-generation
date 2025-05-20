//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = NULL;
    int nums[] = {10, 5, 15, 3, 7, 12, 18, 21};
    int i, j;
    for (i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        root = insert(root, nums[i]);
    }
    preorder(root);
    printf("\n");
    return 0;
}