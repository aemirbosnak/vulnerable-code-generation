//FormAI DATASET v1.0 Category: Binary search trees ; Style: complex
#include <stdio.h>
#include <stdlib.h>

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
        return createNode(data);
    }
    else if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    else if (key < root->data) {
        return search(root->left, key);
    }
    else {
        return search(root->right, key);
    }
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* delete(Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    else if (key < root->data) {
        root->left = delete(root->left, key);
    }
    else if (key > root->data) {
        root->right = delete(root->right, key);
    }
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");
    Node* searchResult = search(root, 60);
    if (searchResult == NULL) {
        printf("Key is not present in the BST.\n");
    }
    else {
        printf("Key is present in the BST.\n");
    }
    root = delete(root, 50);
    printf("Inorder traversal of the BST after deleting 50: ");
    inorderTraversal(root);
    printf("\n");
    return 0;
}