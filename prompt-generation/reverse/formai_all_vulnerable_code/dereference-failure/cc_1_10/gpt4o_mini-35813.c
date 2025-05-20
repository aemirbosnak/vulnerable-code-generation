//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a node in a binary tree
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Define a struct for a queue to use for level-order traversal
struct Queue {
    struct TreeNode** items;
    int front;
    int rear;
    int maxSize;
};

// Function declarations
struct TreeNode* createNode(int data);
struct Queue* createQueue(int size);
void enqueue(struct Queue* q, struct TreeNode* node);
struct TreeNode* dequeue(struct Queue* q);
int isEmpty(struct Queue* q);
void levelOrderTraversal(struct TreeNode* root);
void freeTree(struct TreeNode* root);

// Create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Create a queue
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->items = (struct TreeNode**)malloc(size * sizeof(struct TreeNode*));
    q->front = 0;
    q->rear = -1;
    q->maxSize = size;
    return q;
}

// Enqueue operation
void enqueue(struct Queue* q, struct TreeNode* node) {
    if ((q->rear + 1) % q->maxSize == q->front) {
        printf("Queue is full!\n");
        return;
    }
    q->rear = (q->rear + 1) % q->maxSize;
    q->items[q->rear] = node;
}

// Dequeue operation
struct TreeNode* dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return NULL;
    }
    struct TreeNode* node = q->items[q->front];
    q->front = (q->front + 1) % q->maxSize;
    return node;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == (q->rear + 1) % q->maxSize;
}

// Level-order traversal
void levelOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    struct Queue* q = createQueue(100);
    enqueue(q, root);

    printf("Level-order Traversal: ");
    while (!isEmpty(q)) {
        struct TreeNode* current = dequeue(q);
        printf("%d ", current->data);

        if (current->left != NULL) {
            enqueue(q, current->left);
        }
        if (current->right != NULL) {
            enqueue(q, current->right);
        }
    }
    printf("\n");

    free(q->items);
    free(q);
}

// Free the entire tree
void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function
int main() {
    // Create a sample binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Perform level-order traversal
    levelOrderTraversal(root);

    // Free the allocated memory for the tree
    freeTree(root);

    return 0;
}