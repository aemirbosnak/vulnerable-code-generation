//FormAI DATASET v1.0 Category: Binary search trees ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the binary search tree node
typedef struct treeNode {
    int data;
    struct treeNode *left;
    struct treeNode *right;
} TreeNode;

// Function to create a new node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
TreeNode* insertNode(TreeNode* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    }
    else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to search for a node in the binary search tree
TreeNode* searchNode(TreeNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    else if (data <= root->data) {
        return searchNode(root->left, data);
    }
    else {
        return searchNode(root->right, data);
    }
}

// Function to find the minimum value in the binary search tree
TreeNode* findMin(TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the binary search tree
TreeNode* deleteNode(TreeNode* root, int data) {
    if (root == NULL) {
        return root;
    }
    else if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL) {
            TreeNode* temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL) {
            TreeNode* temp = root;
            root = root->left;
            free(temp);
        }
        else {
            TreeNode* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Function to traverse the binary search tree in order
void traverseInOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    traverseInOrder(root->left);
    printf("%d ", root->data);
    traverseInOrder(root->right);
}

int main() {
    TreeNode* root = NULL;
    root = insertNode(root, 5);
    root = insertNode(root, 2);
    root = insertNode(root, 7);
    root = insertNode(root, 3);
    root = insertNode(root, 8);
    root = insertNode(root, 1);
    
    printf("In-order traversal: ");
    traverseInOrder(root);
    printf("\n");
    
    root = deleteNode(root, 7);
    
    printf("In-order traversal after deleting 7: ");
    traverseInOrder(root);
    printf("\n");
    
    return 0;
}