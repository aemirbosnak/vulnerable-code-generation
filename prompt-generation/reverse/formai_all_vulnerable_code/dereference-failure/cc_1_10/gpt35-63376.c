//FormAI DATASET v1.0 Category: Binary search trees ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(Node** rootPtr, int value) {
    if (*rootPtr == NULL) {
        *rootPtr = createNode(value);
        return;
    }
    if (value < (*rootPtr)->data)
        insertNode(&((*rootPtr)->left), value);
    else
        insertNode(&((*rootPtr)->right), value);
}

void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

Node* searchNode(Node* root, int value) {
    if (root == NULL || root->data == value)
        return root;
    if (value < root->data)
        return searchNode(root->left, value);
    else
        return searchNode(root->right, value);
}

Node* findMinimum(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int value) {
    if (root == NULL)
        return root;
    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMinimum(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    Node* root = NULL;
    insertNode(&root, 50);
    insertNode(&root, 40);
    insertNode(&root, 60);
    insertNode(&root, 30);
    insertNode(&root, 70);
    insertNode(&root, 55);
    insertNode(&root, 80);
    printf("Inorder Traversal before Deletion: ");
    inorderTraversal(root);
    printf("\nDeleting value 60...\n");
    root = deleteNode(root, 60);
    printf("Inorder Traversal after Deletion: ");
    inorderTraversal(root);
    printf("\n");
    return 0;
}