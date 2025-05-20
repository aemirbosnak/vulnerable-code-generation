//FormAI DATASET v1.0 Category: Binary search trees ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
};

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->leftChild = NULL;
        new_node->rightChild = NULL;
        return new_node;
    } else if (data < node->data) {
        node->leftChild = insert(node->leftChild, data);
    } else if (data > node->data) {
        node->rightChild = insert(node->rightChild, data);
    }
    return node;
}

struct Node* minValue(struct Node* node) {
    struct Node* current = node;
    while (current->leftChild != NULL) {
        current = current->leftChild;
    }
    return current;
}

struct Node* delete(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    } else if (data < root->data) {
        root->leftChild = delete(root->leftChild, data);
    } else if (data > root->data) {
        root->rightChild = delete(root->rightChild, data);
    } else {
        if (root->leftChild == NULL) {
            struct Node* temp = root->rightChild;
            free(root);
            return temp;
        } else if (root->rightChild == NULL) {
            struct Node* temp = root->leftChild;
            free(root);
            return temp;
        }
        struct Node* temp = minValue(root->rightChild);
        root->data = temp->data;
        root->rightChild = delete(root->rightChild, temp->data);
    }
    return root;
}

void printTree(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printTree(node->leftChild);
    printf("%d ", node->data);
    printTree(node->rightChild);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 1);
    insert(root, 6);
    insert(root, 7);
    insert(root, 10);
    insert(root, 14);
    insert(root, 4);
    printf("Binary search tree: ");
    printTree(root);
    printf("\nDeleting node with data 3.\n");
    root = delete(root, 3);
    printf("Binary search tree: ");
    printTree(root);
    printf("\nDeleting node with data 8.\n");
    root = delete(root, 8);
    printf("Binary search tree: ");
    printTree(root);
    return 0;
}