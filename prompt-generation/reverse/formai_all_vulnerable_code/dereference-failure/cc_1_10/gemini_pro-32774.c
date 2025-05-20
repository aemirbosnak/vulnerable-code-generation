//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// A binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// A utility function to create a new Binary Tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// A utility function to insert a new node with the given key in BST
struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return newNode(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}

// A utility function to search a given key in BST
struct Node* search(struct Node* node, int key) {
    if (node == NULL) return NULL;
    if (key == node->data) return node;
    if (key < node->data)
        return search(node->left, key);
    else
        return search(node->right, key);
}

// A utility function to find the minimum value in BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// A utility function to delete a node with the given key from BST
struct Node* deleteNode(struct Node* node, int key) {
    if (node == NULL) return node;
    if (key < node->data)
        node->left = deleteNode(node->left, key);
    else if (key > node->data)
        node->right = deleteNode(node->right, key);
    else {
        if (node->left == NULL) {
            struct Node *temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            struct Node *temp = node->left;
            free(node);
            return temp;
        }
        struct Node* temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

// A utility function to print the inorder traversal of BST
void inorder(struct Node* node) {
    if (node == NULL) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

// A utility function to print the preorder traversal of BST
void preorder(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

// A utility function to print the postorder traversal of BST
void postorder(struct Node* node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

// Driver program to test the above functions
int main() {
    struct Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the given binary tree:\n");
    inorder(root);
    printf("\n");

    printf("Preorder traversal of the given binary tree:\n");
    preorder(root);
    printf("\n");

    printf("Postorder traversal of the given binary tree:\n");
    postorder(root);
    printf("\n");

    int key = 20;
    struct Node *node = search(root, key);
    if (node != NULL)
        printf("The node with the key %d is present in the tree.\n", node->data);
    else
        printf("The node with the key %d is not present in the tree.\n", key);

    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified binary tree:\n");
    inorder(root);
    printf("\n");

    return 0;
}