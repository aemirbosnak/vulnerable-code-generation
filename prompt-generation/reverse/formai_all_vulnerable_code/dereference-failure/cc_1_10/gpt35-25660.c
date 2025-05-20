//FormAI DATASET v1.0 Category: Binary search trees ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>

// Define a node structure for binary trees
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// Function to insert a new node given a binary search tree
struct node* insert(struct node* node, int data) {
    // If the tree is empty, return a new node
    if (node == NULL) return newNode(data);

    // Otherwise, recur down the tree
    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    // Return the (unchanged) node pointer
    return node;
}

// Function to search for a node with a given key
struct node* search(struct node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
       return root;

    // Key is greater than root's key
    if (root->data < key)
       return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

// Function to delete a node with a given key
struct node* deleteNode(struct node* root, int key) {
    // Base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // If key is same as root's key, then This is the node
    // to be deleted
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to print binary tree in 2D
void print2DUtil(struct node *root, int space) {
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper function for print2DUtil
void print2D(struct node *root) {
   // Pass initial space count as 0
   print2DUtil(root, 0);
}

// Main function
int main() {
    struct node *root = NULL;

    // Insert nodes into the binary search tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print the binary search tree
    printf("Original binary search tree:\n");
    print2D(root);

    // Search for a node in the binary search tree
    int key = 20;
    struct node* result = search(root, key);
    if (result != NULL) {
        printf("Key %d found in binary search tree!\n", key);
    } else {
        printf("Key %d not found in binary search tree.\n", key);
    }

    // Delete a node from the binary search tree
    key = 30;
    root = deleteNode(root, key);
    printf("\nBinary search tree after deleting node with key %d:\n", key);
    print2D(root);

    return 0;
}