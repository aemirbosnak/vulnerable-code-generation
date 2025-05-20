//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// A node in a binary tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// A queue to store nodes
struct queue {
    struct node *front;
    struct node *rear;
};

// Create a new node
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Create a new queue
struct queue *create_queue() {
    struct queue *new_queue = (struct queue *)malloc(sizeof(struct queue));
    new_queue->front = NULL;
    new_queue->rear = NULL;
    return new_queue;
}

// Enqueue a node
void enqueue(struct queue *queue, struct node *node) {
    if (queue->rear == NULL) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->right = node;
        queue->rear = node;
    }
}

// Dequeue a node
struct node *dequeue(struct queue *queue) {
    if (queue->front == NULL) {
        return NULL;
    } else {
        struct node *temp = queue->front;
        queue->front = queue->front->right;
        if (queue->front == NULL) {
            queue->rear = NULL;
        }
        return temp;
    }
}

// Perform a breadth-first search on a tree
void bfs(struct node *root) {
    struct queue *queue = create_queue();
    enqueue(queue, root);
    while (queue->front != NULL) {
        struct node *node = dequeue(queue);
        printf("%d ", node->data);
        if (node->left != NULL) {
            enqueue(queue, node->left);
        }
        if (node->right != NULL) {
            enqueue(queue, node->right);
        }
    }
    printf("\n");
}

// Main function
int main() {
    // Create a binary tree
    struct node *root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    root->right->left = create_node(6);
    root->right->right = create_node(7);

    // Perform a breadth-first search on the tree
    bfs(root);

    return 0;
}