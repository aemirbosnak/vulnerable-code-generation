//FormAI DATASET v1.0 Category: Binary search trees ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* root = NULL;

// recursive function to insert a new node onto the BST
struct Node* insert(struct Node* node, int value) {
    // if the node is NULL, create a new node with the given value
    if (node == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    // if the value is less than the current node, insert to the left
    else if (value < node->value) {
        node->left = insert(node->left, value);
    }
    // if the value is greater than or equal to the current node, insert to the right
    else {
        node->right = insert(node->right, value);
    }
    return node;
}

// recursively search for a node with the given value
struct Node* search(struct Node* node, int value) {
    if (node == NULL || node->value == value) {
        return node;
    }
    else if (value < node->value) {
        return search(node->left, value);
    }
    else {
        return search(node->right, value);
    }
}

// recursively print the BST in order
void printTree(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printTree(node->left);
    printf("%d ", node->value);
    printTree(node->right);
}

int main() {
    // insert some nodes into the BST
    root = insert(root, 5);
    insert(root, 2);
    insert(root, 8);
    insert(root, 1);
    insert(root, 4);
    insert(root, 6);
    insert(root, 9);
    insert(root, 3);
    insert(root, 7);
    
    // print the BST in order
    printf("The BST: ");
    printTree(root);
    printf("\n");
    
    // search for a couple nodes
    printf("Search for value 4: ");
    struct Node* result = search(root, 4);
    if (result != NULL) {
        printf("Node found!\n");
    }
    else {
        printf("Node not found.\n");
    }
    printf("Search for value 10: ");
    result = search(root, 10);
    if (result != NULL) {
        printf("Node found!\n");
    }
    else {
        printf("Node not found.\n");
    }
    
    return 0;
}