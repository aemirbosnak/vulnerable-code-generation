//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: light-weight
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
    queue->arr = (int *)malloc(size * sizeof(int));
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
    return queue->rear == queue->size - 1;
}

// Add an element to the queue
void enqueue(Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear++;
    }
    queue->arr[queue->rear] = data;
}

// Remove an element from the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return data;
}

// Print the queue
void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

// Driver code
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

    enqueue(queue, 60);
    enqueue(queue, 70);

    printQueue(queue);

    return 0;
}