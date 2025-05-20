//FormAI DATASET v1.0 Category: Binary search trees ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Node definition for the binary search tree
struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};

// Create a new node and fill it with values
struct BSTNode* createNewNode(int value) {
    struct BSTNode* node = (struct BSTNode*) malloc(sizeof(struct BSTNode));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a new node in the binary search tree
struct BSTNode* insert(struct BSTNode* node, int value) {
    if(node == NULL) { // Base case, tree is empty
        return createNewNode(value);
    }
    if(value < node->data) { // Value less than the parent node, move left
        node->left = insert(node->left, value);
    }
    else if(value > node->data) { // Value greater than the parent node, move right
        node->right = insert(node->right, value);
    }
    return node;
}

// Search for a value in the binary search tree
struct BSTNode* search(struct BSTNode* node, int value) {
    if(node == NULL) { // Base case, tree is empty or value not found
        return NULL;
    }
    if(node->data == value) { // Value found
        return node;
    }
    if(value < node->data) { // Value less than the parent node, move left
        return search(node->left, value);
    }
    else { // Value greater than the parent node, move right
        return search(node->right, value);
    }
}

// Traverse the binary search tree in in-order (left-root-right)
void inOrderTraversal(struct BSTNode* node) {
    if(node == NULL) { // Base case, tree is empty
        return;
    }
    inOrderTraversal(node->left);
    printf("%d ", node->data);
    inOrderTraversal(node->right);
}

int main() {
    printf("Welcome to my Binary Search Tree!\n\n");

    // Create the root node and add some values to the tree
    struct BSTNode* root = createNewNode(8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 14);
    insert(root, 4);
    insert(root, 7);
    insert(root, 13);

    // Display the in-order traversal of the tree
    printf("Original Tree: ");
    inOrderTraversal(root);
    printf("\n\n");

    // Search for a value in the tree
    int searchValue = 10;
    struct BSTNode* searchedNode = search(root, searchValue);
    if(searchedNode == NULL) {
        printf("%d not found in the tree.\n", searchValue);
    }
    else {
        printf("%d found at node %p in the tree.\n", searchValue, searchedNode);
    }
    
    // Search for a value not in the tree
    searchValue = 9;
    searchedNode = search(root, searchValue);
    if(searchedNode == NULL) {
        printf("%d not found in the tree.\n", searchValue);
    }
    else {
        printf("%d found at node %p in the tree.\n", searchValue, searchedNode);
    }
    
    // Prompt the user to exit the program
    printf("\nThank you for using my Binary Search Tree. Press any key to exit.\n");
    getchar();
}