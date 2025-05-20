//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the binary search tree (BST)
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new BST node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary search tree
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(data);
    }
    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    // Return the unchanged node pointer
    return root;
}

// Function for inorder traversal of the BST
void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to search for a specific key in the BST
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key) {
        return root;
    }
    // Key is greater than root's data
    if (key > root->data) {
        return search(root->right, key);
    }
    // Key is smaller than root's data
    return search(root->left, key);
}

// Function to find the node with the minimum value
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    // Loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    // Recur down the tree
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
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

        // Node with two children: Get the inorder successor
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// User interface function to manage the BST
void userInterface() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Inorder Traversal\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inserted %d into the BST.\n", value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Deleted %d from the BST.\n", value);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* foundNode = search(root, value);
                if (foundNode != NULL) {
                    printf("%d found in the BST.\n", value);
                } else {
                    printf("%d not found in the BST.\n", value);
                }
                break;
            case 5:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);
}

// Main function to drive the program
int main() {
    userInterface();
    return 0;
}