//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
struct queue {
    int *arr;
    int front;
    int rear;
    int size;
};

// Create a new queue
struct queue* createQueue(int size) {
    struct queue* queue = (struct queue*)malloc(sizeof(struct queue));
    queue->size = size;
    queue->arr = (int*)malloc(sizeof(int) * size);
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Enqueue an element
void enqueue(struct queue* queue, int value) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % queue->size;
    }
    queue->arr[queue->rear] = value;
}

// Dequeue an element
int dequeue(struct queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->size;
    }
    return value;
}

// Print the queue
void printQueue(struct queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i!= -1; i = (i + 1) % queue->size) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int size = 5;
    struct queue* queue = createQueue(size);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    printQueue(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    printQueue(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    printQueue(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    printQueue(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    printQueue(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    printQueue(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    printQueue(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    printQueue(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    printQueue(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    printQueue(queue);
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Queue is empty\n");
    return 0;
}