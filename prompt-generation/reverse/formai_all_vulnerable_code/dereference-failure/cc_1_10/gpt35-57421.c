//FormAI DATASET v1.0 Category: Binary search trees ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the Binary Search Tree Node
typedef struct bst_node {
    int value;
    struct bst_node* left;
    struct bst_node* right;
} BSTNode;

// Function to add a node to the BST
BSTNode* bst_add_node(BSTNode* node, int value) {
    // If tree is empty, create a new node
    if (node == NULL) {
        node = (BSTNode*) malloc(sizeof(BSTNode));
        node->value = value;
        node->left = NULL;
        node->right = NULL;
    }
    // If value is less than node value, go to left subtree
    else if (value < node->value) {
        node->left = bst_add_node(node->left, value);
    }
    // If value is greater or equal to node value, go to right subtree
    else {
        node->right = bst_add_node(node->right, value);
    }

    return node;
}

// Function to search for a value in the BST
BSTNode* bst_search(BSTNode* node, int value) {
    // If tree is empty or value is found, return the node
    if (node == NULL || node->value == value) {
        return node;
    }
    // If value is less than node value, search in left subtree
    else if (value < node->value) {
        bst_search(node->left, value);
    }
    // If value is greater or equal to node value, search in right subtree
    else {
        bst_search(node->right, value);
    }
}

// Function to print the BST in ascending order
void bst_print_inorder(BSTNode* node) {
    if (node != NULL) {
        bst_print_inorder(node->left);
        printf("%d ", node->value);
        bst_print_inorder(node->right);
    }
}

int main() {
    BSTNode* root = NULL;
    int n, val;

    // Taking user input to generate a BST with n nodes
    printf("Greetings, dear friend! I am Sherlock, and I am a detective, not a programmer. However, I do have a challenge for you. Can you write a program that can create a Binary Search Tree?\n\n");

    printf("How many values do you want to add to the Binary Search Tree?: ");
    scanf("%d", &n);

    printf("\nExcellent! Kindly input %d values in any order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = bst_add_node(root, val);
    }

    printf("\nBrilliant! Here is the Binary Search Tree you created (in ascending order):\n");
    bst_print_inorder(root);

    printf("\n\nThank you for taking up my challenge, it was a pleasure to work with you! Until next time, farewell!\n");

    return 0;
}