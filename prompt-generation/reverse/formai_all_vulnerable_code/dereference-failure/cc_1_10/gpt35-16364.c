//FormAI DATASET v1.0 Category: Binary search trees ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

/* Structure of a node */
struct node {
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node Node;

/* Function to create a new node */
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Function to insert a node into BST */
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data >= root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

/* Function to search for a node in BST */
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (root->data < data) {
        return search(root->right, data);
    }
    return search(root->left, data);
}

/* Function to print the BST in inorder traversal */
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    printf("Welcome to the Binary Search Tree program!\n");

    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 10);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    int searchKey = 40;
    Node* searchResult = search(root, searchKey);
    if (searchResult != NULL) {
        printf("Node with value %d found in BST\n", searchKey);
    }
    else {
        printf("Node with value %d not found in BST\n", searchKey);
    }

    printf("Thank you for using the Binary Search Tree program!\n");
    return 0;
}