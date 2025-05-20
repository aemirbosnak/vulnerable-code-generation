//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Futuristic Tree Node Structure
typedef struct Node {
    char data[50]; // Data can be a string for futuristic themes
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node* createNode(char *data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert data into the Binary Search Tree
Node* insert(Node* node, char *data) {
    if (node == NULL) {
        return createNode(data);
    }
    
    // Assume that data follows an alphabetical order
    if (strcmp(data, node->data) < 0) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    
    return node;
}

// Function to search for a given data in the BST
Node* search(Node* root, char *data) {
    if (root == NULL || strcmp(root->data, data) == 0)
        return root;
    
    if (strcmp(data, root->data) < 0)
        return search(root->left, data);
    
    return search(root->right, data);
}

// Function to find the minimum value node
Node* findMin(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, char *data) {
    if (root == NULL) return root;

    if (strcmp(data, root->data) < 0) {
        root->left = deleteNode(root->left, data);
    } else if (strcmp(data, root->data) > 0) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);
        strcpy(root->data, temp->data); // Copy the inorder successor's content to this node
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }
    return root;
}

// An in-order traversal of the BST
void inOrderTraversal(Node* root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    printf("🔷 %s\n", root->data); // Futuristic display format
    inOrderTraversal(root->right);
}

// Main Function: Testing the Binary Search Tree
int main() {
    Node* root = NULL;

    // Futuristic data to insert
    char *futuristicData[] = {
        "QuantumComputing",
        "AIRevolution",
        "SpaceExploration",
        "NeuralNetworks",
        "VirtualReality",
        "CyberSecurity",
        "Bioengineering",
        "Robotics",
        "Blockchain",
        "AugmentedReality"
    };

    // Inserting futuristic ideas into BST
    for (int i = 0; i < 10; i++) {
        root = insert(root, futuristicData[i]);
    }

    printf("📜 In-Order Traversal of the Futuristic BST:\n");
    inOrderTraversal(root);

    // Searching for a futuristic concept
    char *searchTerm = "AIRevolution";
    Node* searchResult = search(root, searchTerm);
    if (searchResult != NULL) {
        printf("🔍 Found: %s\n", searchResult->data);
    } else {
        printf("⚠️ %s not found in the tree.\n", searchTerm);
    }

    // Deleting a futuristic concept from the BST
    printf("🗑️ Deleting: QuantumComputing\n");
    root = deleteNode(root, "QuantumComputing");
    
    printf("📜 In-Order Traversal after deletion:\n");
    inOrderTraversal(root);

    return 0;
}