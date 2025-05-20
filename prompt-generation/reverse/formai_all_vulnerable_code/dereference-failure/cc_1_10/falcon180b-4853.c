//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

Node* searchNode(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

void inOrderTraversal(Node* root) {
    if (root!= NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice, data;
    while (1) {
        printf("\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. In-order Traversal\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the data to be inserted: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                printf("\nData inserted successfully!\n");
                break;
            case 2:
                printf("\nEnter the data to be searched: ");
                scanf("%d", &data);
                Node* result = searchNode(root, data);
                if (result!= NULL) {
                    printf("\nData found in the tree!\n");
                } else {
                    printf("\nData not found in the tree!\n");
                }
                break;
            case 3:
                printf("\nIn-order Traversal of the tree:\n");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}