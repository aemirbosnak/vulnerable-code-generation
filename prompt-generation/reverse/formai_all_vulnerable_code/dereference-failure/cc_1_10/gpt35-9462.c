//FormAI DATASET v1.0 Category: Database Indexing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    int value;
    struct Node* left;
    struct Node* right;
    int height;
};

struct Index {
    char* key;
    int position;
};

// Helper function to get max value
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Helper function to create a new node
struct Node* newNode(int key, int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Helper function to get height of the tree
int height(struct Node* node) {
    if (node == NULL) return 0;
    return node->height;
}

// Helper function to get the balance factor of a node
int getBalanceFactor(struct Node* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

// Helper function to perform a right rotation
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Helper function to perform a left rotation
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Insert a new node into the AVL Tree
struct Node* insert(struct Node* node, int key, int value) {
    // Perform the normal BST insertion
    if (node == NULL) return newNode(key, value);

    if (key < node->key)
        node->left = insert(node->left, key, value);
    else if (key > node->key)
        node->right = insert(node->right, key, value);
    else // Equal keys not allowed
        return node;

    // Update the height of this node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor of this node
    int balance = getBalanceFactor(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}

// Search for a key and return the value
int search(struct Node* root, int key) {
    // Base Cases: root is null or key is present
    if (root == NULL) return -1;
    if (root->key == key) return root->value;

    // Key is greater than root's key
    if (root->key < key) return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

// Print the AVL Tree in-order
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// Recursive function to insert an index
void recursiveInsert(struct Node* node, struct Index index[], int start, int end) {
    if (start > end) return;

    int mid = (start + end) / 2;
    node = insert(node, index[mid].position, index[mid].key);
    recursiveInsert(node, index, start, mid - 1);
    recursiveInsert(node, index, mid + 1, end);
}

// Build an AVL Tree from an array of indexes
struct Node* buildAVLTree(struct Index index[], int n) {
    struct Node* root = NULL;
    recursiveInsert(root, index, 0, n - 1);
    return root;
}

int main() {
    // Example usage of the AVL Tree Indexing System

    // Initialize an array of indexes
    struct Index indexes[] = {
        { "apple", 1 },
        { "banana", 2 },
        { "cherry", 3 },
        { "durian", 4 },
        { "elderberry", 5 },
        { "fig", 6 },
        { "grape", 7 },
        { "honeydew", 8 },
        { "kiwi", 9 },
        { "lemon", 10 }
    };

    int n = sizeof(indexes) / sizeof(indexes[0]);

    // Build the AVL Tree from the array of indexes
    struct Node* root = buildAVLTree(indexes, n);

    // Print the in-order traversal of the AVL Tree
    inOrder(root);

    // Search for a key and return the value
    int value = search(root, 6);
    printf("\nThe value of key 6 is: %d\n", value);

    return 0;
}