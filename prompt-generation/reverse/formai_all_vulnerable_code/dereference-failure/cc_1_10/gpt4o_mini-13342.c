//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Structure for a Binary Search Tree Node
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new Node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new Node into the BST
Node* insert(Node* root, int data) {
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

// Function to calculate the height of the BST
int height(Node* root) {
    if (root == NULL) {
        return -1; // height of an empty tree is -1
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to print the nodes in in-order traversal
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Function to print the nodes in pre-order traversal
void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function to print the nodes in post-order traversal
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Function to search for a value in the BST
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Function to free the allocated memory for the BST
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Utility function to generate random numbers and insert them into the BST
void generateRandomNumbers(Node** root, int n) {
    for (int i = 0; i < n; i++) {
        int randNum = rand() % 100; // Random number from 0 to 99
        printf("Inserting %d into the BST.\n", randNum);
        *root = insert(*root, randNum);
    }
}

// Main function
int main() {
    Node* bstRoot = NULL;

    // Generate random numbers and construct the BST
    printf("Generating 10 random numbers and inserting them into the BST.\n");
    generateRandomNumbers(&bstRoot, 10);

    // Display the height of the tree
    printf("Height of the BST: %d\n", height(bstRoot));

    // Display the nodes in different tree traversals
    printf("In-order Traversal: ");
    inOrder(bstRoot);
    printf("\n");

    printf("Pre-order Traversal: ");
    preOrder(bstRoot);
    printf("\n");

    printf("Post-order Traversal: ");
    postOrder(bstRoot);
    printf("\n");

    // Search for a specific value in the BST
    int searchValue = 50; // Example search value
    Node* searchResult = search(bstRoot, searchValue);
    if (searchResult) {
        printf("Value %d found in the BST.\n", searchValue);
    } else {
        printf("Value %d not found in the BST.\n", searchValue);
    }

    // Free the allocated memory for the BST
    freeTree(bstRoot);
    return 0;
}