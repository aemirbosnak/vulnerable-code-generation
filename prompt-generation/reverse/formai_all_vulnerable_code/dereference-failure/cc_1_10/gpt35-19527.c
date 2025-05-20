//FormAI DATASET v1.0 Category: Data structures visualization ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the binary tree
typedef struct _Node {
    int value;
    struct _Node* left;
    struct _Node* right;
} Node;

// Function to create a new node with the specified value
Node* createNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the binary tree
void insert(Node* root, int val) {
    Node* current = root;
    while (1) {
        // If the new value is less than the current node's value, go left
        if (val < current->value) {
            // If there is no left child, insert the new node as the left child
            if (current->left == NULL) {
                current->left = createNode(val);
                return;
            }
            // Otherwise, continue down the left branch
            else {
                current = current->left;
            }
        }
        // If the new value is greater than or equal to the current node's value, go right
        else {
            // If there is no right child, insert the new node as the right child
            if (current->right == NULL) {
                current->right = createNode(val);
                return;
            }
            // Otherwise, continue down the right branch
            else {
                current = current->right;
            }
        }
    }
}

// Function to print out the binary tree using ASCII art
void printTree(Node* root, int depth) {
    if (root == NULL) {
        return;
    }
    // Print out the right branch first
    printTree(root->right, depth + 1);
    for (int i = 0; i < depth; i++) {
        printf("   ");
    }
    printf("%d\n", root->value);
    // Print out the left branch next
    printTree(root->left, depth + 1);
}

int main() {
    // Create the root node
    Node* root = createNode(10);

    // Insert some values into the binary tree
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 13);
    insert(root, 17);
    insert(root, 1);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);
    insert(root, 12);
    insert(root, 14);
    insert(root, 16);
    insert(root, 18);

    // Print out the binary tree using ASCII art
    printTree(root, 0);

    return 0;
}