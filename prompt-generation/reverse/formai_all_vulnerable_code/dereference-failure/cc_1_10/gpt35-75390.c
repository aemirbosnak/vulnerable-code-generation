//FormAI DATASET v1.0 Category: Queue Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

Queue* initQueue() {
    Queue* newQueue = malloc(sizeof(Queue));
    newQueue->front = -1;
    newQueue->rear = -1;
    return newQueue;
}

int isQueueFull(Queue* queue) {
    return (queue->rear == MAX_QUEUE_SIZE - 1);
}

int isQueueEmpty(Queue* queue) {
    return (queue->front == -1 || queue->front > queue->rear);
}

void enqueue(Queue* queue, int value) {
    if(isQueueFull(queue)) {
        printf("Queue Overflow Error!");
        return;
    }
    if(queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->data[queue->rear] = value;
}

int dequeue(Queue* queue) {
    if(isQueueEmpty(queue)) {
        printf("Queue Underflow Error!");
        return -1;
    }
    int dequeuedValue = queue->data[queue->front];
    queue->front++;
    if(queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return dequeuedValue;
}

int main() {
    Queue* queue = initQueue();
    printf("Empty Queue Created.\n");

    printf("Enqueueing Elements in Queue:\n");
    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 15);
    printf("Enqueueing Complete.\n");

    printf("Trying to Enqueue on Full Queue:\n");
    enqueue(queue, 20);
    printf("Done.\n");

    printf("Dequeueing Elements from Queue:\n");
    printf("Dequeued Value: %d\n", dequeue(queue));
    printf("Dequeued Value: %d\n", dequeue(queue));
    printf("Dequeued Value: %d\n", dequeue(queue));
    printf("Dequeueing Complete.\n");

    printf("Trying to Dequeue on Empty Queue:\n");
    dequeue(queue);
    printf("Done.\n");

    free(queue);
    printf("Queue Destroyed.\n");
    return 0;
}