//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_NODES 10

typedef struct Node {
    int id;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int id) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

typedef struct {
    Node* node;
    int delay;
} ThreadData;

void* visualizeNode(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    Node* node = data->node;
    int delay = data->delay;

    sleep(delay);
    printf("Node ID: %d at delay: %d seconds\n", node->id, delay);
    
    free(data); // Clean up heap-allocated memory
    return NULL;
}

void createAndVisualize(Node* root, int delay) {
    if (root == NULL) return;

    pthread_t threads[2];
    ThreadData* leftData = (ThreadData*)malloc(sizeof(ThreadData));
    ThreadData* rightData = (ThreadData*)malloc(sizeof(ThreadData));

    leftData->node = root->left;
    leftData->delay = delay + 1;
    rightData->node = root->right;
    rightData->delay = delay + 1;

    // Create visualization threads for left and right child
    if (root->left) {
        pthread_create(&threads[0], NULL, visualizeNode, leftData);
    } else {
        free(leftData); // Clean up if there is no left child
    }

    if (root->right) {
        pthread_create(&threads[1], NULL, visualizeNode, rightData);
    } else {
        free(rightData); // Clean up if there is no right child
    }

    // Visualize the current node
    printf("Visualizing node: %d\n", root->id);
    sleep(delay); // Simulate processing delay

    // Join the threads to wait for their completion
    if (root->left) {
        pthread_join(threads[0], NULL);
    }
    if (root->right) {
        pthread_join(threads[1], NULL);
    }
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    // Create a binary tree for visualization
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Start the visualization process on the root node
    printf("Starting visualization of the binary tree...\n");
    createAndVisualize(root, 0);

    // Free allocated memory for the tree
    freeTree(root);

    return 0;
}