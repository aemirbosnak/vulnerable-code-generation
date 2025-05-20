//FormAI DATASET v1.0 Category: Binary search trees ; Style: lively
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert_node(Node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }
    else if (data < root->data) {
        root->left = insert_node(root->left, data);
    }
    else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

Node* search_node(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    else if (root->data < data) {
        return search_node(root->right, data);
    }
    else {
        return search_node(root->left, data);
    }
}

void inorder_traversal(Node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice, value;
    printf("Welcome to Binary Search Tree Program!\n");
    do {
        printf("\nAvailable Operations:\n");
        printf("1. Insert a value\n");
        printf("2. Search for a value\n");
        printf("3. Display the tree in inorder traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                root = insert_node(root, value);
                printf("Value %d inserted successfully!\n", value);
                break;
            case 2:
                printf("Enter the value to be searched: ");
                scanf("%d", &value);
                if (search_node(root, value) != NULL) {
                    printf("Value %d found in the tree!\n", value);
                }
                else {
                    printf("Value %d not found in the tree!\n", value);
                }
                break;
            case 3:
                if (root == NULL) {
                    printf("The tree is empty!\n");
                }
                else {
                    printf("The inorder traversal of the tree is: ");
                    inorder_traversal(root);
                    printf("\n");
                }
                break;
            case 4:
                printf("Program exited successfully!\n");
                break;
            default:
                printf("Invalid choice entered! Please try again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}