//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a single tree node
typedef struct Node {
    char name[30];
    int age;
    struct Node *left, *right;
} Node;

// Function to create a new Node
Node* createNode(char *name, int age) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new Node into the BST
Node* insert(Node* root, char *name, int age) {
    if (root == NULL) {
        return createNode(name, age);
    }
    
    if (age < root->age) {
        root->left = insert(root->left, name, age);
    } else {
        root->right = insert(root->right, name, age);
    }
    return root;
}

// Function to search for a Node by name
Node* search(Node* root, char *name) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }
    if (strcmp(name, root->name) < 0) {
        return search(root->left, name);
    }
    return search(root->right, name);
}

// Function to perform inorder traversal of the BST
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("Name: %s, Age: %d\n", root->name, root->age);
        inorder(root->right);
    }
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, char *name) {
    if (root == NULL) {
        return root;
    }
    
    if (strcmp(name, root->name) < 0) {
        root->left = deleteNode(root->left, name);
    } else if (strcmp(name, root->name) > 0) {
        root->right = deleteNode(root->right, name);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
        Node* temp = root->right; 
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }
        
        strcpy(root->name, temp->name);
        root->age = temp->age;
        root->right = deleteNode(root->right, temp->name);
    }
    return root;
}

// Function to free memory for nodes
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function
int main() {
    Node* root = NULL;
    int choice, age;
    char name[30];

    do {
        printf("\n--- BST Menu ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display All (Inorder)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                root = insert(root, name, age);
                printf("Inserted: %s, Age: %d\n", name, age);
                break;

            case 2:
                printf("Enter name to search: ");
                scanf("%s", name);
                Node* foundNode = search(root, name);
                if (foundNode) {
                    printf("Found: %s, Age: %d\n", foundNode->name, foundNode->age);
                } else {
                    printf("Node not found.\n");
                }
                break;

            case 3:
                printf("Enter name to delete: ");
                scanf("%s", name);
                root = deleteNode(root, name);
                printf("Deleted: %s\n", name);
                break;

            case 4:
                printf("All Nodes (Inorder):\n");
                inorder(root);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    freeTree(root);
    return 0;
}