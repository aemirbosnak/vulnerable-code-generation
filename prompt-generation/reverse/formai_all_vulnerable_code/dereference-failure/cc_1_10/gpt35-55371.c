//FormAI DATASET v1.0 Category: Binary search trees ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Node struct definition
typedef struct Node_t {
    int value;
    struct Node_t* left;
    struct Node_t* right;
} Node;

// Function prototypes
Node* createNode(int value);
Node* insert(Node* node, int value);
Node* delete(Node* root, int value);
int search(Node* node, int value);
void display(Node* node);
void clearTree(Node* node);

// Main function
int main() {
    Node* root = NULL;

    printf("Welcome to the Cyberpunk Binary Search Tree!\n");

    while (1) {
        printf("\nChoose an action:\n");
        printf("1. Insert a value\n");
        printf("2. Delete a value\n");
        printf("3. Search for a value\n");
        printf("4. Display the tree\n");
        printf("5. Clear the tree\n");
        printf("6. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to insert: ");
                int value;
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d has been inserted!\n", value);
                break;
            case 2:
                printf("Enter a value to delete: ");
                int delValue;
                scanf("%d", &delValue);
                root = delete(root, delValue);
                printf("%d has been deleted!\n", delValue);
                break;
            case 3:
                printf("Enter a value to search for: ");
                int searchValue;
                scanf("%d", &searchValue);
                if (search(root, searchValue)) {
                    printf("%d has been found!\n", searchValue);
                } else {
                    printf("%d was not found.\n", searchValue);
                }
                break;
            case 4:
                display(root);
                break;
            case 5:
                clearTree(root);
                printf("The tree has been cleared!\n");
                root = NULL;
                break;
            case 6:
                clearTree(root);
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the tree
Node* insert(Node* node, int value) {
    if (!node) {
        return createNode(value);
    }
    if (value < node->value) {
        node->left = insert(node->left, value);
    } else if (value > node->value) {
        node->right = insert(node->right, value);
    } else {
        printf("Value already exists in tree!\n");
    }
    return node;
}

// Function to delete a value from the tree
Node* delete(Node* root, int value) {
    if (!root) {
        return NULL;
    }
    if (value < root->value) {
        root->left = delete(root->left, value);
    } else if (value > root->value) {
        root->right = delete(root->right, value);
    } else {
        if (!root->left) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = root->right;
        while (temp->left) {
            temp = temp->left;
        }
        root->value = temp->value;
        root->right = delete(root->right, temp->value);
    }
    return root;
}

// Function to search for a value in the tree
int search(Node* node, int value) {
    if (!node) {
        return 0;
    }
    if (value == node->value) {
        return 1;
    }
    if (value < node->value) {
        return search(node->left, value);
    } else {
        return search(node->right, value);
    }
}

// Function to display the tree
void display(Node* node) {
    if (!node) {
        return;
    }
    display(node->left);
    printf("%d ", node->value);
    display(node->right);
}

// Function to clear the tree
void clearTree(Node* node) {
    if (!node) {
        return;
    }
    clearTree(node->left);
    clearTree(node->right);
    free(node);
}