//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the binary search tree node
struct BSTNode {
    int key;
    struct BSTNode *left;
    struct BSTNode *right;
};

// Function to create a new BST node
struct BSTNode* createNode(int key) {
    struct BSTNode* newNode = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new key into the BST
struct BSTNode* insert(struct BSTNode* node, int key) {
    if (node == NULL) {
        return createNode(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    return node;
}

// Function to search for a key in the BST
struct BSTNode* search(struct BSTNode* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Function to find the minimum value in the BST
struct BSTNode* minValueNode(struct BSTNode* node) {
    struct BSTNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a given key from the BST
struct BSTNode* deleteNode(struct BSTNode* root, int key) {
    if (root == NULL) return root;
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct BSTNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct BSTNode* temp = root->left;
            free(root);
            return temp;
        }
        struct BSTNode* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Function to perform inorder traversal of the BST
void inorderTraversal(struct BSTNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Function to perform preorder traversal of the BST
void preorderTraversal(struct BSTNode* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform postorder traversal of the BST
void postorderTraversal(struct BSTNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
    }
}

// Function to free the BST
void freeBST(struct BSTNode* root) {
    if (root != NULL) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}

// Main function to demonstrate the BST operations
int main() {
    struct BSTNode* root = NULL;
    int keys[] = {15, 10, 20, 8, 12, 17, 25};
    int i;

    // Insert keys into the BST
    for (i = 0; i < sizeof(keys)/sizeof(keys[0]); i++) {
        root = insert(root, keys[i]);
    }

    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal of the BST: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal of the BST: ");
    postorderTraversal(root);
    printf("\n");

    // Search for a key
    int keyToSearch = 12;
    struct BSTNode* searchResult = search(root, keyToSearch);
    if (searchResult != NULL) {
        printf("Key %d found in the BST.\n", keyToSearch);
    } else {
        printf("Key %d not found in the BST.\n", keyToSearch);
    }

    // Delete a key
    int keyToDelete = 10;
    root = deleteNode(root, keyToDelete);
    printf("Inorder traversal after deleting %d: ", keyToDelete);
    inorderTraversal(root);
    printf("\n");

    // Free the allocated memory for the BST
    freeBST(root);
    
    return 0;
}