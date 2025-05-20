//FormAI DATASET v1.0 Category: Binary search trees ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

//Node structure for the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

//Function to create a new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//Function to insert a new node in the binary search tree
struct Node* insertNode(struct Node* node, int data) {
    if(node == NULL) {
        return createNode(data);
    }
    if(data < node->data) {
        node->left = insertNode(node->left, data);
    }
    else {
        node->right = insertNode(node->right, data);
    }
    return node;
}

//Function to search for a node in the binary search tree
struct Node* searchNode(struct Node* root, int data) {
    if(root == NULL || root->data == data) {
        return root;
    }
    if(root->data < data) {
        return searchNode(root->right, data);
    }
    return searchNode(root->left, data);
}

//Function to delete a node from the binary search tree
struct Node* deleteNode(struct Node* root, int data) {
    if(root == NULL) {
        return root;
    }
    if(data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if(data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        if(root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = root->right;
        while(temp && temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

//Function to print nodes in inorder traversal
void inorderTraversal(struct Node* root) {
    if(root != NULL) {
        inorderTraversal(root->left);
        printf("%d--> ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    root = insertNode(root, 15);
    insertNode(root, 10);
    insertNode(root, 20);
    insertNode(root, 8);
    insertNode(root, 12);
    insertNode(root, 25);
    printf("Inorder traversal of binary search tree: ");
    inorderTraversal(root);

    printf("\n\nSearching for node with data 20:\n");
    struct Node* node = searchNode(root, 20);
    if(node == NULL) {
        printf("Node not found in tree.\n");
    }
    else {
        printf("Node found with data: %d\n", node->data);
    }

    printf("\nDeleting node with data 10 from binary search tree:\n");
    root = deleteNode(root, 10);
    printf("Inorder traversal of binary search tree: ");
    inorderTraversal(root);
}