//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct Node {
    int key;
    char name[20];
    struct Node *left, *right;
} Node;

Node* createNode(int key, char *name) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->key = key;
    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node *root, int key, char *name) {
    if (root == NULL) {
        root = createNode(key, name);
    } else {
        if (key < root->key) {
            root->left = insertNode(root->left, key, name);
        } else if (key > root->key) {
            root->right = insertNode(root->right, key, name);
        } else {
            printf("Key already exists.\n");
            return root;
        }
    }
    return root;
}

void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("\nKey: %d, Name: %s", root->key, root->name);
        inorderTraversal(root->right);
    }
}

int main() {
    Node *root = NULL;
    int choice, key;
    char name[20];

    while (true) {
        printf("\n1. Insert\n2. Traverse Inorder\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter name: ");
                scanf("%s", name);
                root = insertNode(root, key, name);
                break;

            case 2:
                printf("\nInorder Traversal:\n");
                inorderTraversal(root);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}