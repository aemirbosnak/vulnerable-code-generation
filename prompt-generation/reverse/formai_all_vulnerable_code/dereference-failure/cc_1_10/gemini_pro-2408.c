//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a node in a binary tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// A function to create a new node with the given data
struct node* createNode(int data) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// A function to insert a node into a binary tree
struct node* insertNode(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }
        return root;
    }
}

// A function to find the minimum value in a binary tree
int findMin(struct node* root) {
    if (root == NULL) {
        return -1;
    } else {
        while (root->left != NULL) {
            root = root->left;
        }
        return root->data;
    }
}

// A function to find the maximum value in a binary tree
int findMax(struct node* root) {
    if (root == NULL) {
        return -1;
    } else {
        while (root->right != NULL) {
            root = root->right;
        }
        return root->data;
    }
}

// A function to find the height of a binary tree
int findHeight(struct node* root) {
    if (root == NULL) {
        return -1;
    } else {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}

// A function to print the nodes of a binary tree in preorder
void printPreorder(struct node* root) {
    if (root == NULL) {
        return;
    } else {
        printf("%d ", root->data);
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

// A function to print the nodes of a binary tree in inorder
void printInorder(struct node* root) {
    if (root == NULL) {
        return;
    } else {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}

// A function to print the nodes of a binary tree in postorder
void printPostorder(struct node* root) {
    if (root == NULL) {
        return;
    } else {
        printPostorder(root->left);
        printPostorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    // Create a binary tree
    struct node* root = createNode(10);
    insertNode(root, 5);
    insertNode(root, 15);
    insertNode(root, 2);
    insertNode(root, 7);
    insertNode(root, 12);
    insertNode(root, 20);

    // Find the minimum value in the binary tree
    int min = findMin(root);
    printf("The minimum value in the binary tree is: %d\n", min);

    // Find the maximum value in the binary tree
    int max = findMax(root);
    printf("The maximum value in the binary tree is: %d\n", max);

    // Find the height of the binary tree
    int height = findHeight(root);
    printf("The height of the binary tree is: %d\n", height);

    // Print the nodes of the binary tree in preorder
    printf("The nodes of the binary tree in preorder are: ");
    printPreorder(root);
    printf("\n");

    // Print the nodes of the binary tree in inorder
    printf("The nodes of the binary tree in inorder are: ");
    printInorder(root);
    printf("\n");

    // Print the nodes of the binary tree in postorder
    printf("The nodes of the binary tree in postorder are: ");
    printPostorder(root);
    printf("\n");

    return 0;
}