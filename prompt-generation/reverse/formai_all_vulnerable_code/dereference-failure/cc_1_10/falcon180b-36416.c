//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* buildTree(int arr[], int start, int end) {
    Node* root = NULL;
    int mid = (start + end) / 2;
    root = (Node*)malloc(sizeof(Node));
    root->data = arr[mid];
    root->left = buildTree(arr, start, mid - 1);
    root->right = buildTree(arr, mid + 1, end);
    return root;
}

void inorderTraversal(Node* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    int arr[] = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };
    buildTree(arr, 0, 8);
    printf("Inorder traversal: ");
    inorderTraversal(arr);
    printf("\n");
    printf("Preorder traversal: ");
    preorderTraversal(arr);
    printf("\n");
    printf("Postorder traversal: ");
    postorderTraversal(arr);
    printf("\n");
    return 0;
}