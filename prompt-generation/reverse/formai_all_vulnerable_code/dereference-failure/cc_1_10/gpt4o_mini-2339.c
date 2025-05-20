//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Structure for a binary search tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary search tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a node in the binary search tree
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Function to find the minimum value in the binary search tree
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the binary search tree
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function for inorder traversal of the tree
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to create a whimsical example of a Binary Search Tree
void whimsicalExample() {
    struct Node* root = NULL;

    printf("Welcome to the Enchanted Forest of Binary Search Trees!\n");
    printf("Let us populate our mystical tree with magical numbers.\n");

    int numbers[] = {10, 20, 5, 15, 30, 25, 35, 2, 7, 27};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    
    for (int i = 0; i < n; i++) {
        root = insert(root, numbers[i]);
        printf("Inserting %d...\n", numbers[i]);
    }

    printf("\nIn-order traversal of the enchanted tree: ");
    inorder(root);
    printf("\n");

    int searchKey = 15;
    struct Node* foundNode = search(root, searchKey);
    if (foundNode) {
        printf("The number %d is hiding in the forest!\n", searchKey);
    } else {
        printf("The number %d is nowhere to be found in this forest...\n", searchKey);
    }

    printf("\nLet's remove a number from our mystical tree! Bye bye, 20...\n");
    root = deleteNode(root, 20);

    printf("\nIn-order traversal after removal: ");
    inorder(root);
    printf("\n");

    printf("In this enchanted forest, numbers come and go, but the magic of the tree remains!\n");
}

// Main function to drive the whimsical example
int main() {
    whimsicalExample();
    return 0;
}