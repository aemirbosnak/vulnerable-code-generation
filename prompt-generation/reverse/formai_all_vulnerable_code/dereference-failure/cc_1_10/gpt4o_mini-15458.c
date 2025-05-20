//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary search tree
struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new node with love
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new node into the binary search tree
struct Node* insert(struct Node* node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }

    // Return the (unchanged) node pointer
    return node;
}

// Inorder traversal to display the nodes in a romantic way
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        // A whisper of the heart beats with every node
        printf("I love %d\n", root->key);
        inorder(root->right);
    }
}

// Function to search for a key in the tree
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key) return root;

    // Key is greater than root's key; search right
    if (root->key < key) return search(root->right, key);

    // Key is smaller than root's key; search left
    return search(root->left, key);
}

// Function to find the node with minimum key value
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    // Loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete a node from the binary search tree
struct Node* deleteNode(struct Node* root, int key) {
    // Base Case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    // If the key to be deleted is greater than the root's key
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    // If key is same as root's key, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Main function to capture the love story of nodes
int main() {
    struct Node* root = NULL; // The beautiful starting point of our love tree
    int choice, key;

    do {
        printf("\nWelcome to the Love Tree Program!\n");
        printf("1. Insert a key\n");
        printf("2. Inorder traversal (Display all keys)\n");
        printf("3. Search for a key\n");
        printf("4. Delete a key\n");
        printf("5. Exit\n");
        printf("Choose your love wisely (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Key %d has been beautifully grafted into the tree!\n", key);
                break;

            case 2:
                printf("The keys in our love tree are:\n");
                inorder(root);
                break;

            case 3:
                printf("Enter the key to search for: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("Yes, I have found the love for %d!\n", key);
                else
                    printf("Alas, the love for %d is lost in the woods...\n", key);
                break;

            case 4:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("The love for %d has been gently set free...\n", key);
                break;

            case 5:
                printf("Ending our little love story... Goodbye!\n");
                break;

            default:
                printf("Please choose a valid option (1-5).\n");
        }
    } while (choice != 5);

    return 0;
}