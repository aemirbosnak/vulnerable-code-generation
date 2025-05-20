//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define the queue
typedef struct Queue {
    int *items;
    int front;
    int rear;
    int size;
} Queue;

// Create a new queue
Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->items = (int *)malloc(size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

// Check if the queue is full
int isFull(Queue *queue) {
    return (queue->rear == queue->size - 1);
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return (queue->front == -1);
}

// Add an element to the queue
void enqueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = item;
    }
}

// Remove an element from the queue
int dequeue(Queue *queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return (-1);
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        return (item);
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

int main() {
    // Create a queue of size 5
    Queue *queue = createQueue(5);

    // Enqueue some elements into the queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    // Print the queue
    printf("Queue: ");
    printQueue(queue);

    // Dequeue some elements from the queue
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    // Print the queue
    printf("Queue: ");
    printQueue(queue);

    // Destroy the queue
    destroyQueue(queue);

    return 0;
}