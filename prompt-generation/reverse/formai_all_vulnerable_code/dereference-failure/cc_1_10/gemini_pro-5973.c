//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

// Queue structure
typedef struct Queue {
    int items[QUEUE_SIZE];
    int front, rear;
} Queue;

// Create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Check if the queue is full
int isFull(Queue* queue) {
    return (queue->rear == QUEUE_SIZE - 1);
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == -1);
}

// Add an element to the queue
void enqueue(Queue* queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = element;
        printf("%d inserted\n", element);
    }
}

// Remove an element from the queue
int dequeue(Queue* queue) {
    int element;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return (-1);
    } else {
        element = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        printf("%d deleted\n", element);
        return (element);
    }
}

// Print the queue
void printQueue(Queue* queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for (i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
        printf("\n");
    }
}

// Drive code
int main() {
    Queue* queue = createQueue();

    // Insert some elements
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    // Print the queue
    printQueue(queue);

    // Remove some elements
    dequeue(queue);
    dequeue(queue);

    // Print the queue
    printQueue(queue);

    return 0;
}