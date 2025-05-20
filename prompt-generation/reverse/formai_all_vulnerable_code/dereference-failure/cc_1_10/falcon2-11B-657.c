//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: inquisitive
#include <stdio.h>

// Define the node structure
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node in BST
void insert(struct Node* node, int data) {
    if (node == NULL) {
        node = newNode(data);
    } else if (data < node->data) {
        insert(node->left, data);
    } else {
        insert(node->right, data);
    }
}

// Function to search for a value in BST
int search(struct Node* node, int data) {
    if (node == NULL || node->data == data) {
        return 1;
    } else if (data < node->data) {
        return search(node->left, data);
    } else {
        return search(node->right, data);
    }
}

int main() {
    struct Node* root = NULL;

    // Insert elements in BST
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Search for elements in BST
    printf("50: %d\n", search(root, 50));
    printf("30: %d\n", search(root, 30));
    printf("20: %d\n", search(root, 20));
    printf("40: %d\n", search(root, 40));
    printf("70: %d\n", search(root, 70));
    printf("60: %d\n", search(root, 60));
    printf("80: %d\n", search(root, 80));

    return 0;
}