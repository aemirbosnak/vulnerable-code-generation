//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Structure for a binary search tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into a binary search tree
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to search for a value in the binary search tree
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);
    }

    return search(root->right, value);
}

// Function to find the node with the minimum value
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the binary search tree
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
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
        
        // Node with two children: get the inorder successor (smallest in the right subtree)
        struct Node* temp = findMin(root->right);
        root->data = temp->data; // Copy the successor's value to this node
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }
    return root;
}

// Function to perform an inorder traversal of the binary search tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function to drive the program
int main() {
    struct Node* root = NULL;

    // Let's have some fun by inserting numbers to the binary search tree
    int numbers[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    printf("Inserting numbers into the BST: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
        root = insert(root, numbers[i]);
    }
    printf("\n");

    // Display inorder traversal
    printf("Inorder Traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    // Search for some numbers
    int toSearch[] = {25, 30, 85, 70};
    printf("Searching for numbers: ");
    for(int i = 0; i < 4; i++) {
        printf("%d ", toSearch[i]);
        struct Node* foundNode = search(root, toSearch[i]);
        if (foundNode != NULL) {
            printf("(Found %d!) ", foundNode->data);
        } else {
            printf("(Not found %d) ", toSearch[i]);
        }
    }
    printf("\n");

    // Deleting numbers and showing how it works
    int toDelete[] = {20, 30, 50};
    printf("Deleting numbers: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", toDelete[i]);
        root = deleteNode(root, toDelete[i]);
        printf("-> Inorder now: ");
        inorderTraversal(root);
        printf("\n");
    }

    // Final state of the tree
    printf("Final Inorder Traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    // Cleanup: free the memory allocated for the nodes
    // (For simplicity, we won't implement a full cleanup function)
    
    return 0;
}