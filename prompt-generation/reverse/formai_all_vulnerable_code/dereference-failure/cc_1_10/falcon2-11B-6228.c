//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

// Node struct
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Binary Search Tree
struct BinarySearchTree {
    struct Node* root;
};

// Node comparison function
int compare(const void* a, const void* b) {
    struct Node* n1 = *(struct Node**)a;
    struct Node* n2 = *(struct Node**)b;
    return n1->data - n2->data;
}

// Create a new binary search tree
struct BinarySearchTree* createBST(int* data, int size) {
    struct BinarySearchTree* tree = (struct BinarySearchTree*)malloc(sizeof(struct BinarySearchTree));
    if (tree == NULL) {
        fprintf(stderr, "Failed to allocate memory for Binary Search Tree\n");
        exit(1);
    }
    tree->root = NULL;

    for (int i = 0; i < size; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            fprintf(stderr, "Failed to allocate memory for new node\n");
            exit(1);
        }
        newNode->data = data[i];
        newNode->left = NULL;
        newNode->right = NULL;

        if (tree->root == NULL) {
            tree->root = newNode;
        } else {
            struct Node* current = tree->root;
            while (current!= NULL) {
                if (newNode->data < current->data) {
                    if (current->left == NULL) {
                        current->left = newNode;
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == NULL) {
                        current->right = newNode;
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }

    return tree;
}

// Insert a new node into the binary search tree
void insert(struct BinarySearchTree* tree, int data) {
    if (tree->root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            fprintf(stderr, "Failed to allocate memory for new node\n");
            exit(1);
        }
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        tree->root = newNode;
    } else {
        struct Node* current = tree->root;
        while (current!= NULL) {
            if (data < current->data) {
                if (current->left == NULL) {
                    current->left = (struct Node*)malloc(sizeof(struct Node));
                    if (current->left == NULL) {
                        fprintf(stderr, "Failed to allocate memory for left child\n");
                        exit(1);
                    }
                    current->left->data = data;
                    current->left->left = NULL;
                    current->left->right = NULL;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == NULL) {
                    current->right = (struct Node*)malloc(sizeof(struct Node));
                    if (current->right == NULL) {
                        fprintf(stderr, "Failed to allocate memory for right child\n");
                        exit(1);
                    }
                    current->right->data = data;
                    current->right->left = NULL;
                    current->right->right = NULL;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
}

// Search for a node in the binary search tree
struct Node* search(struct BinarySearchTree* tree, int data) {
    struct Node* current = tree->root;
    while (current!= NULL) {
        if (data == current->data) {
            return current;
        } else if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL;
}

// Print the binary search tree in inorder traversal
void printInorder(struct Node* node) {
    if (node!= NULL) {
        printInorder(node->left);
        printf("%d ", node->data);
        printInorder(node->right);
    }
}

// Main function
int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(data) / sizeof(data[0]);
    struct BinarySearchTree* tree = createBST(data, size);

    // Insert some more nodes
    insert(tree, 11);
    insert(tree, 13);
    insert(tree, 15);

    // Search for a node
    struct Node* node = search(tree, 13);
    if (node!= NULL) {
        printf("Node found: %d\n", node->data);
    } else {
        printf("Node not found\n");
    }

    // Print the binary search tree
    printInorder(tree->root);

    return 0;
}