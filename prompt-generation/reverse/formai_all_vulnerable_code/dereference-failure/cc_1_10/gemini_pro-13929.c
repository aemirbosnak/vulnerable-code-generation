//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

typedef struct Queue {
    int items[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Create a new queue
Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Check if the queue is full
int isFull(Queue *queue) {
    return (queue->rear == QUEUE_SIZE - 1);
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return (queue->front == -1);
}

// Add an element to the queue
void enQueue(Queue *queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }

    if (queue->front == -1) {
        queue->front = 0;
    }

    queue->rear++;
    queue->items[queue->rear] = element;
    printf("%d inserted\n", element);
}

// Remove an element from the queue
int deQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return (-1);
    }

    int element = queue->items[queue->front];
    queue->front++;

    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }

    printf("%d deleted\n", element);
    return (element);
}

// Print the queue
void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

// Free the queue
void freeQueue(Queue *queue) {
    free(queue);
}

// Driver program to test the queue functions
int main() {
    Queue *queue = createQueue();

    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);
    enQueue(queue, 5);

    printQueue(queue);

    deQueue(queue);
    deQueue(queue);
    printQueue(queue);

    enQueue(queue, 6);
    enQueue(queue, 7);
    enQueue(queue, 8);
    enQueue(queue, 9);
    enQueue(queue, 10);

    printQueue(queue);

    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);

    printQueue(queue);

    freeQueue(queue);
    return 0;
}