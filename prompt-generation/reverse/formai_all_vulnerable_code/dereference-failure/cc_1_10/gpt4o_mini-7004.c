//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary search tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert data into the binary search tree
Node* insert(Node* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(data);
    }

    // Otherwise, recurse down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    // Return the unchanged node pointer
    return root;
}

// Function to perform in-order traversal of the tree
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);     // Visit left subtree
        printf("%d ", root->data); // Print node data
        inOrder(root->right);    // Visit right subtree
    }
}

// Function to perform pre-order traversal of the tree
void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data); // Print node data
        preOrder(root->left);      // Visit left subtree
        preOrder(root->right);     // Visit right subtree
    }
}

// Function to perform post-order traversal of the tree
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);     // Visit left subtree
        postOrder(root->right);    // Visit right subtree
        printf("%d ", root->data); // Print node data
    }
}

// Function to search for a specific value in the binary search tree
Node* search(Node* root, int data) {
    // Base cases: root is null or data is present at root
    if (root == NULL || root->data == data) {
        return root;
    }

    // Value is greater than root's data
    if (data > root->data) {
        return search(root->right, data);
    }

    // Value is smaller than root's data
    return search(root->left, data);
}

// Function to find the minimum value node in a tree
Node* minValueNode(Node* node) {
    Node* current = node;

    // Loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Function to delete a node from the binary search tree
Node* deleteNode(Node* root, int data) {
    // Base case
    if (root == NULL) {
        return root;
    }

    // Recursive calls for ancestors of the node to be deleted
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: get the inorder successor (smallest in the right subtree)
        Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Main function to demonstrate binary search tree operations
int main() {
    Node* root = NULL;

    // Insert values into the binary search tree
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 17);
    root = insert(root, 25);

    printf("In-order traversal of the binary search tree:\n");
    inOrder(root);
    printf("\n");

    printf("Pre-order traversal of the binary search tree:\n");
    preOrder(root);
    printf("\n");

    printf("Post-order traversal of the binary search tree:\n");
    postOrder(root);
    printf("\n");

    // Search for a value in the tree
    int searchValue = 12;
    Node* foundNode = search(root, searchValue);
    if (foundNode != NULL) {
        printf("Value %d found in the tree.\n", searchValue);
    } else {
        printf("Value %d not found in the tree.\n", searchValue);
    }

    // Delete a node
    int deleteValue = 10;
    printf("Deleting value %d from the tree...\n", deleteValue);
    root = deleteNode(root, deleteValue);

    printf("In-order traversal after deletion:\n");
    inOrder(root);
    printf("\n");

    // Freeing allocated memory
    // (In a real-world scenario, a function to free all nodes would be necessary)

    return 0;
}