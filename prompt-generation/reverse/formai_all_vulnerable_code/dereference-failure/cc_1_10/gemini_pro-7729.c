//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Node of a binary search tree
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

// Insert a new node into a binary search tree
struct Node *insertNode(struct Node *node, int data) {
    if (node == NULL) {
        return createNode(data);
    } else {
        if (data < node->data) {
            node->left = insertNode(node->left, data);
        } else if (data > node->data) {
            node->right = insertNode(node->right, data);
        }
        return node;
    }
}

// Search for a node in a binary search tree
struct Node *searchNode(struct Node *node, int data) {
    if (node == NULL) {
        return NULL;
    } else {
        if (data == node->data) {
            return node;
        } else if (data < node->data) {
            return searchNode(node->left, data);
        } else {
            return searchNode(node->right, data);
        }
    }
}

// Find the minimum node in a binary search tree
struct Node *findMinNode(struct Node *node) {
    if (node == NULL) {
        return NULL;
    } else {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }
}

// Find the maximum node in a binary search tree
struct Node *findMaxNode(struct Node *node) {
    if (node == NULL) {
        return NULL;
    } else {
        while (node->right != NULL) {
            node = node->right;
        }
        return node;
    }
}

// Delete a node from a binary search tree
struct Node *deleteNode(struct Node *node, int data) {
    if (node == NULL) {
        return NULL;
    } else {
        if (data < node->data) {
            node->left = deleteNode(node->left, data);
        } else if (data > node->data) {
            node->right = deleteNode(node->right, data);
        } else {
            if (node->left == NULL) {
                struct Node *temp = node->right;
                free(node);
                return temp;
            } else if (node->right == NULL) {
                struct Node *temp = node->left;
                free(node);
                return temp;
            } else {
                struct Node *temp = findMinNode(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }
        return node;
    }
}

// Inorder traversal of a binary search tree
void inorderTraversal(struct Node *node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

// Preorder traversal of a binary search tree
void preorderTraversal(struct Node *node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

// Postorder traversal of a binary search tree
void postorderTraversal(struct Node *node) {
    if (node != NULL) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        printf("%d ", node->data);
    }
}

// Driver code
int main() {
    struct Node *root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 2);
    root = insertNode(root, 7);
    root = insertNode(root, 12);
    root = insertNode(root, 20);
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\nPreorder traversal: ");
    preorderTraversal(root);
    printf("\nPostorder traversal: ");
    postorderTraversal(root);
    printf("\n");
    struct Node *node = searchNode(root, 7);
    if (node != NULL) {
        printf("Node found: %d\n", node->data);
    } else {
        printf("Node not found\n");
    }
    root = deleteNode(root, 15);
    printf("Inorder traversal after deleting 15: ");
    inorderTraversal(root);
    printf("\n");
    return 0;
}