//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
typedef struct Queue {
    int front, rear, size;
    int *arr;
} Queue;

// Create a new queue
Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->size = size;
    queue->arr = (int*)malloc(queue->size * sizeof(int));
    return queue;
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Check if the queue is full
int isFull(Queue* queue) {
    return (queue->rear + 1) % queue->size == queue->front;
}

// Enqueue an element
void enqueue(Queue* queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % queue->size;
        queue->arr[queue->rear] = element;
    }
}

// Dequeue an element
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    else {
        int element = queue->arr[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        }
        else {
            queue->front = (queue->front + 1) % queue->size;
        }
        return element;
    }
}

// Peek at the front of the queue
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    else {
        return queue->arr[queue->front];
    }
}

// Print the queue
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    }
    else {
        int i = queue->front;
        while (i != queue->rear) {
            printf("%d ", queue->arr[i]);
            i = (i + 1) % queue->size;
        }
        printf("%d\n", queue->arr[queue->rear]);
    }
}

// Destroy the queue
void destroyQueue(Queue* queue) {
    free(queue->arr);
    free(queue);
}

// Driver code
int main() {
    Queue* queue = createQueue(5);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printQueue(queue);

    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));

    enqueue(queue, 50);

    printQueue(queue);

    destroyQueue(queue);

    return 0;
}