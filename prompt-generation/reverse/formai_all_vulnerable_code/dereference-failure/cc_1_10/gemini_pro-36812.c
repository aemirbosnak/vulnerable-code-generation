//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: introspective
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

// Check if the queue is full
int isFull(Queue *queue) {
    if (queue->rear == queue->size - 1) {
        return 1;
    } else {
        return 0;
    }
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    if (queue->front == -1) {
        return 1;
    } else {
        return 0;
    }
}

// Add an element to the queue
void enQueue(Queue *queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
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
int deQueue(Queue *queue) {
    int element;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
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
void printQueue(Queue *queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        for (i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
        printf("\n");
    }
}

// Destroy the queue
void destroyQueue(Queue *queue) {
    free(queue->items);
    free(queue);
}

// Main function to test the queue
int main() {
    // Create a queue of size 5
    Queue *queue = createQueue(5);

    // Enqueue some elements
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);
    enQueue(queue, 5);

    // Print the queue
    printQueue(queue);

    // Dequeue some elements
    deQueue(queue);
    deQueue(queue);

    // Print the queue
    printQueue(queue);

    // Destroy the queue
    destroyQueue(queue);

    return 0;
}