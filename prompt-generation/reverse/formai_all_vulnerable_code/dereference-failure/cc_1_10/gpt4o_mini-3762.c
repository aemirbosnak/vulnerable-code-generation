//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int key;
    struct TreeNode *left, *right;
};

// Function to create a new tree node
struct TreeNode* newNode(int item) {
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->key = item;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node with given key
struct TreeNode* insert(struct TreeNode* node, int key) {
    if (node == NULL) return newNode(key);
    
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    
    return node;
}

// Function to display the tree in an ASCII format
void printTree(struct TreeNode* root, int space) {
    if (root == NULL) return;

    space += 10; // Increase distance between levels

    printTree(root->right, space);
    
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    printTree(root->left, space);
}

// Function to find the minimum value node
struct TreeNode* minValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node with given key
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Main function to run the program
int main() {
    struct TreeNode* root = NULL;
    int choice, value;

    while (1) {
        printf("\nBinary Search Tree Visualization\n");
        printf("1. Insert\n2. Delete\n3. Display Tree\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inserted %d into the tree.\n", value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Deleted %d from the tree.\n", value);
                break;
            case 3:
                printf("Current state of the Binary Search Tree:\n");
                printTree(root, 0);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}