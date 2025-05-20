//FormAI DATASET v1.0 Category: Binary search trees ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    } else {
        printf("Data already exists in the tree!\n");
        return root;
    }
    return root;
}

Node* find(Node* root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data < root->data) {
        return find(root->left, data);
    } else if (data > root->data) {
        return find(root->right, data);
    } else {
        return root;
    }
}

int main() {
    Node* root = NULL;

    printf("Welcome to the future of Binary Search Trees!\n");

    int response = 0;
    int data = 0;

    do {
        printf("\nWhat do you want to do?\n");
        printf("1. Insert data\n");
        printf("2. Find data\n");
        printf("3. Exit\n");
        scanf("%d", &response);

        switch(response) {
            case 1:
                printf("Enter data\n");
                scanf("%d", &data);
                root = insertNode(root, data);
                printf("%d inserted successfully!\n", data);
                break;
            case 2:
                printf("Enter data\n");
                scanf("%d", &data);
                if (find(root, data) != NULL) {
                    printf("%d found in the tree!\n", data);
                } else {
                    printf("%d not found in the tree!\n", data);
                }
                break;
            case 3:
                printf("Exiting program..\n");
                break;
            default:
                printf("Invalid response\n");
        }
    } while (response != 3);

    return 0;
}