//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Alan Touring
#include <stdio.h>

/* Define a struct for a binary tree node */
struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

/* Function to create a new binary tree node */
struct Node* createNode(int value) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Function to insert a node into a binary tree */
struct Node* insert(struct Node* node, int value) {
    if (node == NULL) {
        return createNode(value);
    } else if (value < node->value) {
        node->left = insert(node->left, value);
    } else if (value > node->value) {
        node->right = insert(node->right, value);
    }
    return node;
}

/* Function to print a binary tree in order */
void printInOrder(struct Node* node) {
    if (node != NULL) {
        printInOrder(node->left);
        printf("%d ", node->value);
        printInOrder(node->right);
    }
}

/* Main program */
int main() {
    struct Node* root = insert(NULL, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);
    
    printf("Binary Tree Visualization:\n");
    printf("          [%d]\n", root->value);
    printf("        /       \\\n");
    printf("     [%d]       [%d]\n", root->left->value, root->right->value);
    printf("   /     \\     /     \\\n");
    printf(" [%d]   [%d]   [%d]     [%d]\n", root->left->left->value, root->left->right->value,
                                           root->right->left->value, root->right->right->value);
    
    printf("In Order Traversal:\n");
    printInOrder(root);
    printf("\n");
    
    return 0;
}