//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5 // Max size of the queue

// Structure to represent the queue
typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Check if the queue is full
bool isFull(Queue* queue) {
    return (queue->rear + 1) % MAX == queue->front;
}

// Add an element to the queue
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->items[queue->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Remove an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Queue is empty
    }
    int dequeuedValue = queue->items[queue->front];
    if (queue->front == queue->rear) {
        // Queue has only one element, reset to empty
        queue->front = -1;
        queue->rear = -1;
    } else {
        // Move front to the next position
        queue->front = (queue->front + 1) % MAX;
    }
    printf("Dequeued: %d\n", dequeuedValue);
    return dequeuedValue;
}

// Display elements of the queue
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = queue->front;
    while (true) {
        printf("%d ", queue->items[i]);
        if (i == queue->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Free allocated memory for queue
void freeQueue(Queue* queue) {
    free(queue);
}

// Main function to demonstrate queue implementation
int main() {
    Queue* queue = createQueue();
    
    // Perform enqueue operations
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60); // This should give an error since the queue is full

    // Display the current state of the queue
    display(queue);

    // Perform dequeue operations
    dequeue(queue);
    dequeue(queue);
    
    // Display the queue after dequeuing
    display(queue);

    // More enqueue operations
    enqueue(queue, 60);
    enqueue(queue, 70); // Another enqueue operation

    // Display final state of the queue
    display(queue);
    
    // Cleanup
    freeQueue(queue);
    return 0;
}