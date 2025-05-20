//FormAI DATASET v1.0 Category: Binary search trees ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Create a structure to define a binary search tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return node;
}

// Create a function to insert a new node into the tree
struct Node* insert(struct Node* node, int data) {
    // If the tree is empty, return a new node
    if (node == NULL) {
        return newNode(data);
    }
 
    // Otherwise, recur down the tree
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
 
    // Return the (unchanged) node pointer
    return node;
}

// Create a function to search for a given node
struct Node* search(struct Node* node, int data) {
    // Base case: node is null or data is present at node
    if (node == NULL || node->data == data) {
        return node;
    }
 
    // If the data is greater than the node's data, search in the right subtree
    if (node->data < data) {
        return search(node->right, data);
    }
 
    // Otherwise, search in the left subtree
    return search(node->left, data);
}

// Create a function to find the minimum value in the tree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
 
    // Loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
 
    return current;
}

// Create a function to delete a given node
struct Node* deleteNode(struct Node* root, int key) {
    // Base case: if the tree is empty, return root
    if (root == NULL) {
        return root;
    }
 
    // Recur down the tree
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
 
    // If the key to be deleted is the same as the root's key, then this is the node to be deleted
    else {
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
 
        // Copy the inorder successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Create a function to traverse the tree in inorder
void inorderTraversal(struct Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

// Main function to test the above functions
int main() {
    struct Node* root = NULL;
 
    // Insert some nodes into the tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    // Traverse the tree in inorder
    printf("Inorder traversal of the given binary search tree:\n");
    inorderTraversal(root);
 
    // Search for a node and delete it
    int key = 60;
    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("\nNode %d found in the tree.\n", key);
        root = deleteNode(root, key);
        printf("Inorder traversal after deleting node %d:\n", key);
        inorderTraversal(root);
    } else {
        printf("\nNode %d not found in the tree.\n", key);
    }
 
    return 0;
}