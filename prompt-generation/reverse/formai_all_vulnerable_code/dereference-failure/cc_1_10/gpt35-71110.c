//FormAI DATASET v1.0 Category: Binary search trees ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

void insert(Node** root, int data) {
    if (*root == NULL) {
        *root = (Node*)malloc(sizeof(Node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else if (data < (*root)->data) {
        insert(&((*root)->left), data);
    } else {
        insert(&((*root)->right), data);
    }
}

Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

Node* findMinNode(Node* node) {
    Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* delete(Node* root, int data) {
    if (root == NULL) {
        return root;
    } else if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        } else {
            Node* temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

void displayInOrder(Node* root) {
    if (root != NULL) {
        displayInOrder(root->left);
        printf("%d ", root->data);
        displayInOrder(root->right);
    }
}

int main() {
    Node* root = NULL;

    printf("Welcome to the peaceful binary search tree program!\n\n");

    while (1) {
        printf("Enter 1 to insert a node\n");
        printf("Enter 2 to search for a node\n");
        printf("Enter 3 to delete a node\n");
        printf("Enter 4 to display all nodes in order\n");
        printf("Enter 5 to exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter the value to insert: ");
                int data;
                scanf("%d", &data);
                insert(&root, data);
                printf("Node inserted!\n\n");
                break;
            }
            case 2: {
                printf("Enter the value to search for: ");
                int data;
                scanf("%d", &data);
                Node* result = search(root, data);
                if (result == NULL) {
                    printf("Node not found!\n\n");
                } else {
                    printf("Node found!\n\n");
                }
                break;
            }
            case 3: {
                printf("Enter the value to delete: ");
                int data;
                scanf("%d", &data);
                root = delete(root, data);
                printf("Node deleted!\n\n");
                break;
            }
            case 4: {
                printf("All nodes in order: ");
                displayInOrder(root);
                printf("\n\n");
                break;
            }
            case 5: {
                printf("Exiting...\n");
                exit(0);
            }
            default: {
                printf("Invalid choice! Please try again.\n\n");
                break;
            }
        }
    }

    return 0;
}