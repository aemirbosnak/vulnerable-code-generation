//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define the Queue structure
typedef struct Queue {
    int *items;
    int front, rear, size;
} Queue;

// Create a new queue
Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->items = (int *)malloc(sizeof(int) * size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

// Check if the queue is full
int isFull(Queue *queue) {
    if (queue->rear == queue->size - 1) {
        return 1;
    }
    return 0;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    if (queue->front == -1) {
        return 1;
    }
    return 0;
}

// Add an element to the queue
void enqueue(Queue *queue, int element) {
    if (isFull(queue)) {
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = element;
}

// Remove an element from the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    int element = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return element;
}

// Print the queue
void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d  ", queue->items[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    // Create a queue of size 5
    Queue *queue = createQueue(5);

    // Enqueue elements into the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the queue
    printQueue(queue);

    // Dequeue elements from the queue
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));

    // Print the queue
    printQueue(queue);

    return 0;
}