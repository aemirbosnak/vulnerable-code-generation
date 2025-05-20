//FormAI DATASET v1.0 Category: Data structures visualization ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Node structure for binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// Function to insert a node in the binary tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return(createNode(data));
    }
    else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return(root);
}

// Function to print the binary tree in level order
void printLevelOrder(struct Node* root) {
    if (root == NULL) return;

    // Create a queue for level order traversal
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * 1000);
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        // Dequeue the front node and print it
        struct Node* node = queue[front++];
        printf("%d ", node->data);

        // Enqueue the left child
        if (node->left != NULL) {
            queue[rear++] = node->left;
        }

        // Enqueue the right child
        if (node->right != NULL) {
            queue[rear++] = node->right;
        }
    }
}

int main() {
    struct Node* root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    printf("Binary Tree visualization in Level Order Traversal:\n");
    printLevelOrder(root);

    return 0;
}