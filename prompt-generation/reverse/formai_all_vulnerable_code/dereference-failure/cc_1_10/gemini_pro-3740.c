//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the queue structure
typedef struct Queue {
    int *arr;
    int front, rear, capacity;
} Queue;

// Create a new queue
Queue* createQueue(int capacity) {
    Queue *queue = malloc(sizeof(Queue));
    queue->arr = malloc(sizeof(int) * capacity);
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

// Check if the queue is full
int isFull(Queue *queue) {
    return (queue->rear == queue->capacity - 1);
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return (queue->front == -1);
}

// Add an element to the queue
void enqueue(Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->arr[queue->rear] = data;
}

// Remove an element from the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    return data;
}

// Print the queue
void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    int i = queue->front;
    while (i <= queue->rear) {
        printf("%d ", queue->arr[i]);
        i++;
    }
    printf("\n");
}

// Driver code
int main() {
    Queue *queue = createQueue(5);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    printQueue(queue);
    dequeue(queue);
    dequeue(queue);
    enqueue(queue, 6);
    enqueue(queue, 7);
    printQueue(queue);
    return 0;
}