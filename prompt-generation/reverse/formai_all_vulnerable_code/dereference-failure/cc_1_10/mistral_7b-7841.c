//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node {
    int key;
    float weight;
    char symbol;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key, float weight, char symbol) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->weight = weight;
    newNode->symbol = symbol;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int key, float weight, char symbol) {
    if (root == NULL) {
        root = createNode(key, weight, symbol);
    } else {
        if (key < root->key) {
            root->left = insert(root->left, key, weight, symbol);
        } else if (key > root->key) {
            root->right = insert(root->right, key, weight, symbol);
        } else {
            printf("Duplicate key detected: %d\n", key);
        }
    }
    return root;
}

void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("Key: %d, Weight: %.2f, Symbol: %c\n", root->key, root->weight, root->symbol);
        inOrderTraversal(root->right);
    }
}

Node* findMin(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* removeNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = removeNode(root->left, key);
    } else if (key > root->key) {
        root->right = removeNode(root->right, key);
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

        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->weight = temp->weight;
        root->symbol = temp->symbol;
        root->right = removeNode(root->right, temp->key);
    }
    return root;
}

int main() {
    Node* root = NULL;

    int keys[] = {3, 5, 1, 7, 2, 8, 4, 6};
    float weights[] = {1.5, 2.8, 0.5, 3.2, 1.9, 4.5, 2.1, 5.3};
    char symbols[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    for (int i = 0; i < 8; i++) {
        root = insert(root, keys[i], weights[i], symbols[i]);
    }

    printf("Binary Search Tree:\n");
    inOrderTraversal(root);

    int keyToRemove = 5;
    root = removeNode(root, keyToRemove);

    printf("\nBinary Search Tree after removing key %d:\n", keyToRemove);
    inOrderTraversal(root);

    return 0;
}