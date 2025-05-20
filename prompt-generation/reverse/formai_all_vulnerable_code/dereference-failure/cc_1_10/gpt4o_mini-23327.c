//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Define a structure for tree nodes
typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* createNode(int key) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new key in a BST
Node* insert(Node* node, int key) {
    if (node == NULL) return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

// Function to search for a key in the BST
Node* search(Node* root, int key) {
    if (root == NULL || root->key == key) return root;

    if (key < root->key)
        return search(root->left, key);
    
    return search(root->right, key);
}

// Function to find the minimum value node in a BST
Node* findMin(Node* node) {
    while (node && node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to delete a key from the BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
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

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Function for inorder traversal of the BST
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Function for preorder traversal of the BST
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to free the memory allocated for the BST
void freeTree(Node* node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

// Function to display menu options
void displayMenu() {
    printf("\nBinary Search Tree Operations Menu\n");
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. Delete\n");
    printf("4. Inorder Traversal\n");
    printf("5. Preorder Traversal\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    Node* root = NULL;
    int choice, key;

    do {
        displayMenu();
        if(scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Inserted %d\n", key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                Node* foundNode = search(root, key);
                if (foundNode != NULL)
                    printf("Key %d found in the BST.\n", key);
                else
                    printf("Key %d not found in the BST.\n", key);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("Deleted %d if it existed in the BST.\n", key);
                break;
            case 4:
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please choose between 1 to 6.\n");
        }
    } while (choice != 6);

    freeTree(root);
    return 0;
}