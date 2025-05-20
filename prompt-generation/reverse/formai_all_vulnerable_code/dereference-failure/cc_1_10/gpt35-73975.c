//FormAI DATASET v1.0 Category: Data structures visualization ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Struct for a Binary Search Tree node
struct BSTNode {
    int value;
    struct BSTNode* left;
    struct BSTNode* right;
};

// Struct for a Stack using an array
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Struct for a Queue using an array
struct Queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

// Initialize a BSTNode with the given value
struct BSTNode* createBSTNode(int value) {
    struct BSTNode* node = (struct BSTNode*) malloc(sizeof(struct BSTNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Push an element onto the Stack
void push(struct Stack* stack, int value) {
    if(stack->top == MAX_SIZE-1) {
        printf("Error: Stack Overflow\n");
        return;
    }

    stack->arr[++stack->top] = value;
}

// Pop an element from the Stack
int pop(struct Stack* stack) {
    if(stack->top == -1) {
        printf("Error: Stack Underflow\n");
        return -1;
    }

    return stack->arr[stack->top--];
}

// Enqueue an element into the Queue
void enqueue(struct Queue* queue, int value) {
    if(queue->rear == MAX_SIZE-1) {
        printf("Error: Queue Overflow\n");
        return;
    }

    queue->arr[++queue->rear] = value;

    if(queue->front == -1) {
        queue->front = 0;
    }
}

// Dequeue an element from the Queue
int dequeue(struct Queue* queue) {
    if(queue->front == -1) {
        printf("Error: Queue Underflow\n");
        return -1;
    }

    int value = queue->arr[queue->front++];

    if(queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }

    return value;
}

// Recursive function to insert a value into the BST
struct BSTNode* insertBSTNode(struct BSTNode* root, int value) {
    if(root == NULL) {
        root = createBSTNode(value);
        return root;
    }

    if(value < root->value) {
        root->left = insertBSTNode(root->left, value);
    } else if(value > root->value) {
        root->right = insertBSTNode(root->right, value);
    }

    return root;
}

// Print the BST using an in-order traversal
void printBSTInOrder(struct BSTNode* root) {
    if(root == NULL) {
        return;
    }

    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;

    while(1) {
        while(root != NULL) {
            push(stack, root->value);
            root = root->left;
        }

        if(stack->top == -1) {
            break;
        }

        int value = pop(stack);
        printf("%d ", value);

        root = createBSTNode(value);
        root = root->right;
    }

    free(stack);
}

// Print the Queue from front to rear
void printQueue(struct Queue* queue) {
    if(queue->front == -1) {
        return;
    }

    struct Queue* tempQueue = (struct Queue*) malloc(sizeof(struct Queue));
    tempQueue->front = -1;
    tempQueue->rear = -1;

    while(queue->front != -1) {
        int value = dequeue(queue);
        printf("%d ", value);
        enqueue(tempQueue, value);
    }

    while(tempQueue->front != -1) {
        enqueue(queue, dequeue(tempQueue));
    }

    free(tempQueue);
}

int main() {
    // Initialize empty BST
    struct BSTNode* root = NULL;

    // Insert values into the BST
    root = insertBSTNode(root, 8);
    root = insertBSTNode(root, 3);
    root = insertBSTNode(root, 10);
    root = insertBSTNode(root, 1);
    root = insertBSTNode(root, 6);
    root = insertBSTNode(root, 14);
    root = insertBSTNode(root, 4);
    root = insertBSTNode(root, 7);
    root = insertBSTNode(root, 13);

    // Print the BST using an in-order traversal
    printf("Binary Search Tree: ");
    printBSTInOrder(root);
    printf("\n");

    // Initialize empty Queue
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;

    // Enqueue values into the Queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the Queue
    printf("Queue: ");
    printQueue(queue);
    printf("\n");

    free(queue);

    return 0;
}