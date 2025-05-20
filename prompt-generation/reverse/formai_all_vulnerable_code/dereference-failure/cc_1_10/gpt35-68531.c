//FormAI DATASET v1.0 Category: Binary search trees ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

// Define BST Node structure
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Function to create BST Node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert Node in BST
Node* insertNode(Node* head, int data) {
    if (head == NULL) {
        return createNode(data);
    }
    else if (data < head->data) {
        head->left = insertNode(head->left, data);
    }
    else if (data > head->data) {
        head->right = insertNode(head->right, data);
    }
    return head;
}

// Function to search Node in BST
Node* searchNode(Node* head, int data) {
    if (head == NULL || head->data == data) {
        return head;
    }
    else if (data < head->data) {
        return searchNode(head->left, data);
    }
    else if (data > head->data) {
        return searchNode(head->right, data);
    }
}

// Function to print Inorder traversal of BST
void inorderTraversal(Node* head) {
    if (head == NULL) {
        return;
    }
    inorderTraversal(head->left);
    printf("%d ", head->data);
    inorderTraversal(head->right);
}

int main() {
    Node* head = NULL;
    head = insertNode(head, 5);
    head = insertNode(head, 3);
    head = insertNode(head, 7);
    head = insertNode(head, 1);
    head = insertNode(head, 9);
    head = insertNode(head, 6);
    printf("Inorder traversal of BST: ");
    inorderTraversal(head);
    printf("\n");
    int searchValue = 7;
    Node* result = searchNode(head, searchValue);
    if (result == NULL) {
        printf("%d not found in BST\n", searchValue);
    }
    else {
        printf("%d found in BST\n", result->data);
    }
    return 0;
}