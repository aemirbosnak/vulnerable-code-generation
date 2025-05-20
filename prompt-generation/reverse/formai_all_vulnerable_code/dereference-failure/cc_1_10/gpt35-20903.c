//FormAI DATASET v1.0 Category: Binary search trees ; Style: calm
#include <stdio.h>
#include <stdlib.h>

/* Defining a structure for the Binary Search Tree node */
typedef struct node {
    int data;
    struct node *left, *right;
} Node;

/* Function to create a new node with given data */
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* Function to insert a new node in the BST */
void insert(Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }
    if (data < (*root)->data)
        insert(&((*root)->left), data);
    else
        insert(&((*root)->right), data);
}

/* Function to search a node in the BST */
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;
    if (root->data < data)
        return search(root->right, data);
    return search(root->left, data);
}

/* Function to find the minimum value node in a BST */
Node* minValue(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

/* Function to delete a node from the BST */
Node* deleteNode(Node* root, int data) {
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
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
        Node* temp = minValue(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

/* Function to print the in-order traversal of the BST */
void inorderTraversal(Node* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

/* Function to print the pre-order traversal of the BST */
void preorderTraversal(Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

/* Function to print the post-order traversal of the BST */
void postorderTraversal(Node* root) {
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

/* Main Function */
int main() {
    Node* root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\nPreorder Traversal: ");
    preorderTraversal(root);
    printf("\nPostorder Traversal: ");
    postorderTraversal(root);
    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\nDelete 40\n");
    root = deleteNode(root, 40);
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\nDelete 60\n");
    root = deleteNode(root, 60);
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    return 0;
}