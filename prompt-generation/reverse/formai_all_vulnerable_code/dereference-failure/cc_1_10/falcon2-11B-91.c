//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node* newNode(int key) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return newNode(key);
    } else if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

void preOrder(struct Node* root) {
    if (root!= NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, key, n;

    printf("Welcome to the Cyberpunk Binary Search Tree!\n");
    printf("1. Insert a new key\n");
    printf("2. Print all keys in pre-order traversal\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice!= 3) {
        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                preOrder(root);
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &n);
        if (n!= 'y') {
            break;
        }
    }

    printf("Goodbye, and stay safe out there!\n");

    return 0;
}