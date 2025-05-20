//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// A binary search tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new binary search tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// Insert a new node with the given key into the binary search tree
struct Node* insert(struct Node* node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->data)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    // Return the (possibly updated) node
    return node;
}

// Search for a key in the binary search tree
struct Node* search(struct Node* node, int key) {
    // If the tree is empty, return NULL
    if (node == NULL) return NULL;

    // Otherwise, recur down the tree
    if (key == node->data)
        return node;
    else if (key < node->data)
        return search(node->left, key);
    else
        return search(node->right, key);
}

// Print the binary search tree in preorder traversal
void preorder(struct Node* node) {
    if (node == NULL) return;

    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

// Print the binary search tree in inorder traversal
void inorder(struct Node* node) {
    if (node == NULL) return;

    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

// Print the binary search tree in postorder traversal
void postorder(struct Node* node) {
    if (node == NULL) return;

    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

// Find the minimum value in the binary search tree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    // Loop down to find the leftmost leaf
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Find the maximum value in the binary search tree
struct Node* maxValueNode(struct Node* node) {
    struct Node* current = node;

    // Loop down to find the rightmost leaf
    while (current->right != NULL)
        current = current->right;

    return current;
}

// Delete a node with the given key from the binary search tree
struct Node* deleteNode(struct Node* node, int key) {
    // If the tree is empty, return NULL
    if (node == NULL) return NULL;

    // Otherwise, recur down the tree
    if (key < node->data)
        node->left = deleteNode(node->left, key);
    else if (key > node->data)
        node->right = deleteNode(node->right, key);
    else {
        // If the node has no children, simply delete it
        if (node->left == NULL && node->right == NULL) {
            free(node);
            node = NULL;
            return NULL;
        }

        // If the node has one child, replace the node with its child
        else if (node->left == NULL) {
            struct Node* temp = node;
            node = node->right;
            free(temp);
            temp = NULL;
            return node;
        } else if (node->right == NULL) {
            struct Node* temp = node;
            node = node->left;
            free(temp);
            temp = NULL;
            return node;
        }

        // If the node has two children, replace the node with the minimum value in the right subtree
        else {
            struct Node* temp = minValueNode(node->right);

            node->data = temp->data;

            node->right = deleteNode(node->right, temp->data);
            return node;
        }
    }

    // Return the (possibly updated) node
    return node;
}

// Count the number of nodes in the binary search tree
int countNodes(struct Node* node) {
    if (node == NULL) return 0;

    return 1 + countNodes(node->left) + countNodes(node->right);
}

// Calculate the height of the binary search tree
int height(struct Node* node) {
    if (node == NULL) return 0;

    int left_height = height(node->left);
    int right_height = height(node->right);

    return 1 + (left_height > right_height ? left_height : right_height);
}

// Check if the binary search tree is balanced
int isBalanced(struct Node* node) {
    if (node == NULL) return 1;

    int left_height = height(node->left);
    int right_height = height(node->right);

    return abs(left_height - right_height) <= 1 && isBalanced(node->left) && isBalanced(node->right);
}

// Main function
int main() {
    struct Node* root = NULL;

    // Insert some keys into the binary search tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print the binary search tree in preorder traversal
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    // Print the binary search tree in inorder traversal
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    // Print the binary search tree in postorder traversal
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    // Search for a key in the binary search tree
    struct Node* node = search(root, 40);
    if (node != NULL)
        printf("Key 40 found in the binary search tree.\n");
    else
        printf("Key 40 not found in the binary search tree.\n");

    // Find the minimum value in the binary search tree
    node = minValueNode(root);
    printf("Minimum value in the binary search tree: %d\n", node->data);

    // Find the maximum value in the binary search tree
    node = maxValueNode(root);
    printf("Maximum value in the binary search tree: %d\n", node->data);

    // Delete a node with the given key from the binary search tree
    root = deleteNode(root, 20);
    printf("After deleting key 20, the binary search tree is:\n");
    inorder(root);
    printf("\n");

    // Count the number of nodes in the binary search tree
    int count = countNodes(root);
    printf("Number of nodes in the binary search tree: %d\n", count);

    // Calculate the height of the binary search tree
    int height_of_tree = height(root);
    printf("Height of the binary search tree: %d\n", height_of_tree);

    // Check if the binary search tree is balanced
    int is_balanced = isBalanced(root);
    if (is_balanced)
        printf("The binary search tree is balanced.\n");
    else
        printf("The binary search tree is not balanced.\n");

    return 0;
}