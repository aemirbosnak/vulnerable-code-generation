//FormAI DATASET v1.0 Category: Binary search trees ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create new nodes
Node* createNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the tree
void insert(Node* root, Node* newNode) {
    if (newNode->value < root->value) {
        if (root->left == NULL) {
            root->left = newNode;
        } else {
            insert(root->left, newNode);
        }
    } else {
        if (root->right == NULL) {
            root->right = newNode;
        } else {
            insert(root->right, newNode);
        }
    }
}

// Function to find a node in the tree
Node* find(Node* root, int value) {
    if (root == NULL) {
        return NULL;
    } else if (root->value == value) {
        return root;
    } else if (value < root->value) {
        return find(root->left, value);
    } else {
        return find(root->right, value);
    }
}

// Function to find the minimum value in the tree
Node* findMin(Node* root) {
    if (root->left == NULL) {
        return root;
    } else {
        return findMin(root->left);
    }
}

// Function to delete a node from the tree
Node* delete(Node* root, int value) {
    if (root == NULL) {
        return NULL;
    } else if (value < root->value) {
        root->left = delete(root->left, value);
    } else if (value > root->value) {
        root->right = delete(root->right, value);
    } else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: Two children
        else {
            Node* temp = findMin(root->right);
            root->value = temp->value;
            root->right = delete(root->right, temp->value);
        }
    }
    return root;
}

// Function to traverse the tree in pre-order
void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    // Create the root node
    Node* root = createNode(50);

    // Insert some nodes into the tree
    insert(root, createNode(30));
    insert(root, createNode(20));
    insert(root, createNode(40));
    insert(root, createNode(70));
    insert(root, createNode(60));
    insert(root, createNode(80));

    // Traverse the tree in pre-order
    printf("Before deletion: ");
    preOrder(root);
    printf("\n");

    // Delete a node
    root = delete(root, 20);

    // Traverse the tree in pre-order again
    printf("After deletion: ");
    preOrder(root);
    printf("\n");

    return 0;
}