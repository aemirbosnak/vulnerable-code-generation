//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
typedef struct Queue {
    int *items;
    int front;
    int rear;
    int size;
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

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->front == -1;
}

// Check if the queue is full
int isFull(Queue *queue) {
    return queue->rear == queue->size - 1;
}

// Add an element to the queue
void enqueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = item;
        printf("%d added to the queue!\n", item);
    }
}

// Remove an element from the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        int item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        printf("%d removed from the queue!\n", item);
        return item;
    }
}

// Print the queue
void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
        printf("\n");
    }
}

// Drive code
int main() {
    // Create a queue of size 5
    Queue *queue = createQueue(5);

    // Enqueue some elements
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the queue
    printQueue(queue);

    // Dequeue some elements
    dequeue(queue);
    dequeue(queue);

    // Print the queue again
    printQueue(queue);

    return 0;
}