//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node *createNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a new node into the binary search tree
struct Node *insertNode(struct Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Search for a node in the binary search tree
struct Node *searchNode(struct Node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data == root->data) {
        return root;
    } else if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

// Find the minimum value in the binary search tree
struct Node *findMinNode(struct Node *root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Find the maximum value in the binary search tree
struct Node *findMaxNode(struct Node *root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Delete a node from the binary search tree
struct Node *deleteNode(struct Node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node to be deleted found
        if (root->left == NULL && root->right == NULL) {
            // Node has no children
            free(root);
            root = NULL;
        } else if (root->left == NULL) {
            // Node has only right child
            struct Node *temp = root->right;
            free(root);
            root = temp;
        } else if (root->right == NULL) {
            // Node has only left child
            struct Node *temp = root->left;
            free(root);
            root = temp;
        } else {
            // Node has both children
            struct Node *temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Print the binary search tree in preorder traversal
void preorderTraversal(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Print the binary search tree in inorder traversal
void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Print the binary search tree in postorder traversal
void postorderTraversal(struct Node *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Main function
int main() {
    // Create a binary search tree
    struct Node *root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 2);
    root = insertNode(root, 7);
    root = insertNode(root, 12);
    root = insertNode(root, 20);

    // Search for a node in the binary search tree
    struct Node *node = searchNode(root, 15);
    if (node != NULL) {
        printf("Node found: %d\n", node->data);
    } else {
        printf("Node not found\n");
    }

    // Find the minimum value in the binary search tree
    node = findMinNode(root);
    if (node != NULL) {
        printf("Minimum value: %d\n", node->data);
    } else {
        printf("Binary search tree is empty\n");
    }

    // Find the maximum value in the binary search tree
    node = findMaxNode(root);
    if (node != NULL) {
        printf("Maximum value: %d\n", node->data);
    } else {
        printf("Binary search tree is empty\n");
    }

    // Delete a node from the binary search tree
    root = deleteNode(root, 15);
    printf("Node deleted: 15\n");

    // Print the binary search tree in preorder traversal
    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    // Print the binary search tree in inorder traversal
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Print the binary search tree in postorder traversal
    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}