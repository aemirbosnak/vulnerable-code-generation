//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define the Queue structure
typedef struct Queue {
    int front, rear, size;
    int *array;
} Queue;

// Create a new queue
Queue* createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->size = size;
    queue->array = (int *)malloc(queue->size * sizeof(int));
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
void enqueue(Queue *queue, int element) {
    if (isFull(queue))
        return;
    if (queue->front == -1)
        queue->front = 0;
    queue->rear++;
    queue->array[queue->rear] = element;
}

// Remove an element from the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue))
        return -1;
    int element = queue->array[queue->front];
    if (queue->front >= queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front++;
    return element;
}

// Print the queue
void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++)
        printf("%d ", queue->array[i]);
    printf("\n");
}

// Test the queue
int main() {
    Queue *queue = createQueue(5);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printQueue(queue);

    dequeue(queue);
    dequeue(queue);

    printQueue(queue);

    return 0;
}