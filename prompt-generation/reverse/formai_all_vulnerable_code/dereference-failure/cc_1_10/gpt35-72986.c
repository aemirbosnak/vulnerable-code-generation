//FormAI DATASET v1.0 Category: Binary search trees ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the BST node
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
void insert(Node** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
    }
    else {
        if (value < (*root)->data) {
            insert(&((*root)->left), value);
        }
        else if (value > (*root)->data) {
            insert(&((*root)->right), value);
        }
    }
}

// Function to search for a value in the BST
Node* search(Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    else if (value < root->data) {
        return search(root->left, value);
    }
    else {
        return search(root->right, value);
    }
}

// Function to delete a value from the BST
Node* delete(Node* root, int value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->data) {
        root->left = delete(root->left, value);
    }
    else if (value > root->data) {
        root->right = delete(root->right, value);
    }
    else {
        // Case 1: Leaf node
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        // Case 2: Node with one child
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: Node with two children
        else {
            Node* temp = root->right;
            while (temp && temp->left != NULL) {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

// Function to print the BST in inorder traversal
void printInorder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

// Main function
int main() {
    Node* root = NULL;
    int choice, value;
    while (1) {
        printf("1. Insert a node\n");
        printf("2. Search for a node\n");
        printf("3. Delete a node\n");
        printf("4. Print the tree\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(&root, value);
                printf("Node inserted successfully!\n");
                break;
            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("Node found!\n");
                }
                else {
                    printf("Node not found.\n");
                }
                break;
            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = delete(root, value);
                printf("Node deleted successfully!\n");
                break;
            case 4:
                printf("BST in inorder traversal:\n");
                printInorder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}