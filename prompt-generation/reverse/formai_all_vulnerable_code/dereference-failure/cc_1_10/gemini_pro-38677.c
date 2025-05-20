//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

// Define the queue data structure
typedef struct Queue {
    int front, rear;
    int size;
    int capacity;
    int *array;
} Queue;

// Create a new queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->size = 0;
    queue->capacity = capacity;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Check if the queue is full
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Add an element to the queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

// Remove an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Get the front element of the queue
int front(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    return queue->array[queue->front];
}

// Get the rear element of the queue
int rear(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    return queue->array[queue->rear];
}

// Print the queue
void printQueue(Queue* queue) {
    if (isEmpty(queue))
        printf("Queue is empty\n");
    else {
        int i;
        printf("Queue: ");
        for (i = queue->front; i != queue->rear; i = (i + 1) % queue->capacity) {
            printf("%d ", queue->array[i]);
        }
        printf("%d\n", queue->array[queue->rear]);
    }
}

// Driver program to test the queue
int main() {
    Queue* queue = createQueue(10);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    printQueue(queue);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    printQueue(queue);

    enqueue(queue, 6);
    enqueue(queue, 7);
    enqueue(queue, 8);
    enqueue(queue, 9);
    enqueue(queue, 10);

    printQueue(queue);

    return 0;
}