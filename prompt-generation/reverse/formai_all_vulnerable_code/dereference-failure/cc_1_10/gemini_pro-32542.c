//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
typedef struct Queue {
    int *arr;
    int front;
    int rear;
    int size;
} Queue;

// Create a new queue
Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (int *)malloc(sizeof(int) * size);
    queue->front = queue->rear = -1;
    queue->size = size;
    return queue;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->front == -1;
}

// Check if the queue is full
int isFull(Queue *queue) {
    return (queue->rear + 1) % queue->size == queue->front;
}

// Enqueue an element into the queue
void enqueue(Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }

    if (queue->front == -1) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % queue->size;
    }

    queue->arr[queue->rear] = data;
}

// Dequeue an element from the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int data = queue->arr[queue->front];

    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->size;
    }

    return data;
}

// Print the elements of the queue
void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    int i = queue->front;

    while (i != queue->rear) {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % queue->size;
    }

    printf("%d\n", queue->arr[i]);
}

// Main function
int main() {
    // Initialize the queue
    Queue *queue = createQueue(5);

    // Enqueue some elements into the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the elements of the queue
    printf("Elements of the queue: ");
    printQueue(queue);

    // Dequeue an element from the queue
    int data = dequeue(queue);
    printf("Dequeued element: %d\n", data);

    // Print the elements of the queue
    printf("Elements of the queue: ");
    printQueue(queue);

    return 0;
}