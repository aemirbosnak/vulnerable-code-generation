//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define the Queue structure
typedef struct Queue {
    int *arr;      // Array to store the queue elements
    int front;     // Front index of the queue
    int rear;      // Rear index of the queue
    int capacity;  // Capacity of the queue
} Queue;

// Create a new queue with a given capacity
Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (int *)malloc(sizeof(int) * capacity);
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return (queue->front == -1);
}

// Check if the queue is full
int isFull(Queue *queue) {
    return (queue->rear == queue->capacity - 1);
}

// Add an element to the rear of the queue
void enqueue(Queue *queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full!");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->arr[queue->rear] = element;
}

// Remove an element from the front of the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!");
        return -1;
    }
    int element = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    return element;
}

// Print the elements of the queue
void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!");
        return;
    }
    int i;
    for (i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

// Test the Queue implementation
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
    dequeue(queue);
    printQueue(queue);
    enqueue(queue, 6);
    enqueue(queue, 7);
    printQueue(queue);
    return 0;
}