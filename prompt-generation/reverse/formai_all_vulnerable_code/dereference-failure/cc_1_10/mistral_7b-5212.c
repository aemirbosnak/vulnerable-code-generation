//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }

    return node;
}

Node* search(Node* node, int data) {
    if (node == NULL || node->data == data) {
        return node;
    }

    if (data < node->data) {
        return search(node->left, data);
    }

    return search(node->right, data);
}

void display(Node* node) {
    if (node != NULL) {
        display(node->left);
        printf("%d ", node->data);
        display(node->right);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    printf("Displaying the tree: ");
    display(root);
    printf("\n");

    Node* searchNode = search(root, 6);
    if (searchNode != NULL) {
        printf("Found node with data %d\n", searchNode->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}