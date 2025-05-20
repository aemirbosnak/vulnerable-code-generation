//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a binary search tree node
struct BSTNode {
    int data;
    struct BSTNode *left, *right;
};

// Function to create a new binary search tree node
struct BSTNode* newBSTNode(int data) {
    struct BSTNode* node = malloc(sizeof(struct BSTNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node into the binary search tree
void insertBST(struct BSTNode** root, int data) {
    if (*root == NULL) {
        *root = newBSTNode(data);
    } else {
        struct BSTNode* current = *root;
        while (current != NULL) {
            if (data < current->data) {
                if (current->left == NULL) {
                    current->left = newBSTNode(data);
                    break;
                } else {
                    insertBST(&current->left, data);
                }
            } else if (data > current->data) {
                if (current->right == NULL) {
                    current->right = newBSTNode(data);
                    break;
                } else {
                    insertBST(&current->right, data);
                }
            }
            current = current->left != NULL ? current->left : current->right;
        }
    }
}

// Function to search for a node in the binary search tree
struct BSTNode* searchBST(struct BSTNode* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (data < root->data) {
        return searchBST(root->left, data);
    } else if (data > root->data) {
        return searchBST(root->right, data);
    } else {
        return root;
    }
}

// Function to traverse the binary search tree
void traverseBST(struct BSTNode* root) {
    if (root != NULL) {
        traverseBST(root->left);
        printf("%d ", root->data);
        traverseBST(root->right);
    }
}

int main() {
    struct BSTNode* root = NULL;
    insertBST(&root, 5);
    insertBST(&root, 2);
    insertBST(&root, 8);
    insertBST(&root, 3);
    insertBST(&root, 1);
    insertBST(&root, 6);
    insertBST(&root, 4);

    struct BSTNode* node = searchBST(root, 5);
    if (node != NULL) {
        printf("Found %d\n", node->data);
    } else {
        printf("Not found\n");
    }

    traverseBST(root);

    return 0;
}