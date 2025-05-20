//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct BSTNode {
    int data;
    struct BSTNode *left, *right;
};

// Function to create a new node with given data
struct BSTNode *newNode(int data) {
    struct BSTNode *node = (struct BSTNode *)malloc(sizeof(struct BSTNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a node into the binary search tree
void insert(struct BSTNode **root, int data) {
    struct BSTNode *node = *root;

    // If the tree is empty, create a new node with the given data
    if (*root == NULL) {
        *root = newNode(data);
        return;
    }

    // Search for the appropriate location to insert the new node
    while (node != NULL) {
        if (data < node->data) {
            if (node->left == NULL) {
                node->left = newNode(data);
                break;
            } else {
                insert( &node->left, data );
                break;
            }
        } else if (data > node->data) {
            if (node->right == NULL) {
                node->right = newNode(data);
                break;
            } else {
                insert( &node->right, data );
                break;
            }
        } else {
            // Data already exists in the tree, do nothing
            return;
        }
        node = node->left != NULL ? node->left : node->right;
    }
}

// Function to search for a node in the binary search tree
int search(struct BSTNode *root, int data) {
    int found = 0;
    struct BSTNode *node = root;

    while (node != NULL) {
        if (data < node->data) {
            node = node->left;
        } else if (data > node->data) {
            node = node->right;
        } else {
            found = 1;
            break;
        }
    }
    return found;
}

// Function to print the contents of the binary search tree
void print(struct BSTNode *root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    printf("%d ", root->data);
    print(root->left);
    print(root->right);
    printf("\n");
}

int main() {
    struct BSTNode *root = NULL;

    // Insert some nodes into the tree
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 9);

    // Search for a node in the tree
    if (search(root, 7)) {
        printf("Found node with value 7\n");
    } else {
        printf("Node with value 7 not found\n");
    }

    // Print the contents of the tree
    print(root);

    return 0;
}