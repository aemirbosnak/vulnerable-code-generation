//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[100];
    struct Node* left;
    struct Node* right;
};

// Creating a new node with a given string
struct Node* newNode(const char* data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(node->data, data);
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Inserting a new string into the binary search tree
struct Node* insert(struct Node* node, const char* data) {
    if (node == NULL) {
        return newNode(data);
    }
    if (strcmp(data, node->data) < 0) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;
}

// In-order traversal of the BST to display elements in sorted fashion
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%s ", root->data);
        inOrder(root->right);
    }
}

// Finding the node with the minimum value in the tree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to remove a string from the binary search tree
struct Node* deleteNode(struct Node* root, const char* data) {
    if (root == NULL) return root;

    if (strcmp(data, root->data) < 0) {
        root->left = deleteNode(root->left, data);
    } else if (strcmp(data, root->data) > 0) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);
        strcpy(root->data, temp->data);
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to free the allocated memory in the tree
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// A romantic way to populate the BST with love-themed strings
struct Node* populateRomanticBST() {
    struct Node* root = NULL;
    root = insert(root, "Adore");
    root = insert(root, "Cherish");
    root = insert(root, "Embrace");
    root = insert(root, "Passion");
    root = insert(root, "Eternal");
    root = insert(root, "Beloved");
    root = insert(root, "Desire");
    root = insert(root, "Forgive");
    root = insert(root, "Kiss");
    root = insert(root, "Heart");
    root = insert(root, "Dream");
    return root;
}

// The main function, a romantic tale of love and nature's beauty
int main() {
    printf("In this romantic journey, let us traverse the forest of love.\n");
    
    struct Node* loveTree = populateRomanticBST();
    
    printf("\nIn-order display of romantic strings: \n");
    inOrder(loveTree);

    printf("\n\nNow, let us remove a memory of a fleeting moment, 'Desire', from our hearts...\n");
    loveTree = deleteNode(loveTree, "Desire");

    printf("\nIn-order display after removing 'Desire': \n");
    inOrder(loveTree);
    
    printf("\n\nFinally, let us free our hearts from these memories...\n");
    freeTree(loveTree);
    printf("All memories set free, leaving space for new love to blossom.\n");

    return 0;
}