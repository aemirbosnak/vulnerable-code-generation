//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Node structure for queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function prototypes
Queue* createQueue();
int isEmpty(Queue* queue);
void enqueue(Queue* queue, int value);
int dequeue(Queue* queue);
void displayQueue(Node* node);
void recursiveDisplayQueue(Node* node);

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Recursive function to enqueue
void enqueueRecursive(Node** node, int value) {
    if (*node == NULL) {
        // Create new node if end of list is reached
        *node = (Node*)malloc(sizeof(Node));
        (*node)->data = value;
        (*node)->next = NULL;
    } else {
        // Call recursively to find the end of the queue
        enqueueRecursive(&(*node)->next, value);
    }
}

// Wrapper function for enqueue
void enqueue(Queue* queue, int value) {
    if (isEmpty(queue)) {
        // If queue is empty, both front and rear will point to the new node
        queue->front = (Node*)malloc(sizeof(Node));
        queue->front->data = value;
        queue->front->next = NULL;
        queue->rear = queue->front;
    } else {
        // Call recursive enqueue on the next node
        enqueueRecursive(&queue->rear->next, value);
        // Update the rear pointer to the new last node
        queue->rear = queue->rear->next;
    }
}

// Recursive function to dequeue
int dequeueRecursive(Node** node, int* value) {
    if (*node == NULL) {
        return 0; // Queue is empty
    }

    *value = (*node)->data; // Retrieve the data
    Node* temp = *node;
    *node = (*node)->next; // Move to the next node
    free(temp); // Free the old node
    return 1; // Success
}

// Wrapper function for dequeue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue.\n");
        return -1;
    }

    int value;
    if (dequeueRecursive(&queue->front, &value)) {
        if (queue->front == NULL) {
            queue->rear = NULL; // If queue becomes empty
        }
        return value;
    }
    return -1; // Dequeuing failed
}

// Function to display the queue
void displayQueue(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    displayQueue(node->next);
}

// Recursive function to display queue elements
void recursiveDisplayQueue(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    recursiveDisplayQueue(node->next);
}

// Main function
int main() {
    Queue* queue = createQueue();

    // Enqueue elements
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    // Display elements in the queue
    printf("Queue elements: ");
    recursiveDisplayQueue(queue->front);
    printf("\n");

    // Dequeue elements
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    // Display elements in the queue after dequeue
    printf("Queue elements after dequeue: ");
    recursiveDisplayQueue(queue->front);
    printf("\n");

    // Clean up remaining elements
    while (!isEmpty(queue)) {
        printf("Dequeued: %d\n", dequeue(queue));
    }

    // Free the queue structure
    free(queue);

    return 0;
}