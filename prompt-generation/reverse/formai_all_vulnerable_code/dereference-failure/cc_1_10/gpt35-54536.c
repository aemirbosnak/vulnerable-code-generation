//FormAI DATASET v1.0 Category: Binary search trees ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// function to insert a new node in BST
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    }
    else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

// function to search for a node in BST
struct Node* search(struct Node* node, int data) {
    if (node == NULL || node->data == data) {
        return node;
    }
    if (data < node->data) {
        return search(node->left, data);
    }
    else {
        return search(node->right, data);
    }
}

// function to find the minimum value node in BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// function to delete a node from BST
struct Node* deleteNode(struct Node* root, int data) {
    // base case
    if (root == NULL) {
        return root;
    }

    // search for the node to be deleted
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // node with two children
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// function to print the BST in inorder traversal
void inorderTraversal(struct Node* node) {
    if (node == NULL) {
        return;
    }
    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

// main function
int main() {
    printf("Welcome to Binary Search Tree\n");
    struct Node* root = NULL;

    // insert nodes in BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // print BST in inorder traversal
    printf("Inorder traversal of BST: ");
    inorderTraversal(root);
    printf("\n");

    // search for node in BST
    int searchValue = 60;
    struct Node* searchResult = search(root, searchValue);
    if (searchResult != NULL) {
        printf("Node with value %d found in BST\n", searchValue);
    }
    else {
        printf("Node with value %d not found in BST\n", searchValue);
    }

    // delete node from BST
    int deleteValue = 40;
    root = deleteNode(root, deleteValue);
    printf("Inorder traversal after deletion of node %d: ", deleteValue);
    inorderTraversal(root);
    printf("\n");

    // add new node to BST
    int addValue = 90;
    insert(root, addValue);
    printf("Inorder traversal after adding new node with value %d: ", addValue);
    inorderTraversal(root);
    printf("\n");

    return 0;
}