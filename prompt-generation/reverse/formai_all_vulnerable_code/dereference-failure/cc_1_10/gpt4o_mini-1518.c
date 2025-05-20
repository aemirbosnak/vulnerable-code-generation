//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Definition of the binary search tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node with specific data into the BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a given value in the BST
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Function to get the minimum value node in the BST
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
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
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to perform in-order traversal of the BST
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Function to perform pre-order traversal of the BST
void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function to perform post-order traversal of the BST
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Main function: the beginning of our mystical journey
int main() {
    Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n----- Binary Search Tree Menu -----\n");
        printf("1. Insert an element\n");
        printf("2. Search for an element\n");
        printf("3. Delete an element\n");
        printf("4. In-order traversal\n");
        printf("5. Pre-order traversal\n");
        printf("6. Post-order traversal\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted into the BST.\n", value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                Node* foundNode = search(root, value);
                if (foundNode != NULL) {
                    printf("%d found in the BST!\n", value);
                } else {
                    printf("%d not found in the BST.\n", value);
                }
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("%d deleted from the BST.\n", value);
                break;
            case 4:
                printf("In-order traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Pre-order traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 6:
                printf("Post-order traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 0:
                printf("Exiting the mystical journey. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}