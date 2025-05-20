//FormAI DATASET v1.0 Category: Binary search trees ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    } else if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

Node* find(Node* root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    } else if (value < root->value) {
        return find(root->left, value);
    } else {
        return find(root->right, value);
    }
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* delete(Node* root, int value) {
    if (root == NULL) {
        return root;
    } else if (value < root->value) {
        root->left = delete(root->left, value);
    } else if (value > root->value) {
        root->right = delete(root->right, value);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        } else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            free(temp);
        } else {
            Node* temp = findMin(root->right);
            root->value = temp->value;
            root->right = delete(root->right, temp->value);
        }
    }
    return root;
}

void printInOrder(Node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->value);
        printInOrder(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 7);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 5);
    root = insert(root, 9);
    root = insert(root, 12);

    printf("In order traversal: ");
    printInOrder(root);
    printf("\n");

    int deleteValue = 3;
    root = delete(root, deleteValue);
    printf("Deleted value: %d\n", deleteValue);
    printf("In order traversal: ");
    printInOrder(root);
    printf("\n");

    return 0;
}