//FormAI DATASET v1.0 Category: Binary search trees ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* root = NULL;

void insert(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL) {
        root = newNode;
    } else {
        Node* current = root;

        while (true) {
            if (data == current->data) {
                return;
            }

            if (data < current->data) {
                if (current->left == NULL) {
                    current->left = newNode;
                    return;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == NULL) {
                    current->right = newNode;
                    return;
                } else {
                    current = current->right;
                }
            }
        }
    }
}

void inOrderTraversal(Node* node) {
    if (node != NULL) {
        inOrderTraversal(node->left);
        printf("%d ", node->data);
        inOrderTraversal(node->right);
    }
}

int main() {
    // Insert some numbers into the tree
    insert(5);
    insert(3);
    insert(7);
    insert(1);
    insert(9);

    // Print the contents of the tree using in-order-traversal
    inOrderTraversal(root);

    return 0;
}