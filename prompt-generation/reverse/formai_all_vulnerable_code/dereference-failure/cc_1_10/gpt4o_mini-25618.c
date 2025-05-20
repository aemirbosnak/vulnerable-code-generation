//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a queue node
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

// Define a structure for the queue
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
    int size;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        perror("Failed to create queue");
        exit(EXIT_FAILURE);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Function to add an element to the queue
void enqueue(Queue* queue, int value) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (!newNode) {
        perror("Failed to enqueue element");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    queue->size++;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        fprintf(stderr, "Queue Underflow: Attempt to dequeue from an empty queue\n");
        exit(EXIT_FAILURE);
    }

    QueueNode* temp = queue->front;
    int value = temp->data;
    queue->front = queue->front->next;
    free(temp);
    
    if (queue->front == NULL) {
        queue->rear = NULL; // Queue is now empty
    }
    queue->size--;
    printf("Dequeued: %d\n", value);
    return value;
}

// Function to peek at the front item of the queue without dequeueing
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        fprintf(stderr, "Queue is empty. Cannot peek\n");
        exit(EXIT_FAILURE);
    }
    return queue->front->data;
}

// Function to free the queue
void freeQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

// Main function demonstrating queue usage
int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    
    printf("Front element: %d\n", peek(queue));

    while (!isEmpty(queue)) {
        dequeue(queue);
    }

    // Cleanup
    freeQueue(queue);
    return 0;
}