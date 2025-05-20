//FormAI DATASET v1.0 Category: Binary search trees ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct Node** head, int value) {
    struct Node* node = createNode(value);
    if (*head == NULL) {
        *head = node;
        return;
    }
    struct Node* current = *head;
    while (1) {
        if (value < current->data) {
            if (current->left == NULL) {
                current->left = node;
                break;
            }
            current = current->left;
        } else {
            if (current->right == NULL) {
                current->right = node;
                break;
            }
            current = current->right;
        }
    }
}

struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int minValue(struct Node* node) {
    int min = node->data;
    while (node->left != NULL) {
        min = node->left->data;
        node = node->left;
    }
    return min;
}

struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        int min = minValue(root->right);
        root->data = min;
        root->right = deleteNode(root->right, min);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d -> ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;

    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    printf("Inorder traversal:\n");
    inorder(root);

    printf("\nSearching for 60 in the tree...");
    if (search(root, 60) == NULL) {
        printf("\nNode with value 60 not found.\n");
    } else {
        printf("\nNode with value 60 found.\n");
    }

    printf("Deleting node with value 40...\n");
    root = deleteNode(root, 40);

    printf("Inorder traversal after deleting node:\n");
    inorder(root);

    return 0;
}