//FormAI DATASET v1.0 Category: Queue Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 50

typedef struct queue {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* newQueue = (Queue*) malloc(sizeof(Queue));
    newQueue->front = -1;
    newQueue->rear = -1;

    return newQueue;
}

int isQueueEmpty(Queue* queue) {
    return (queue->front == -1);
}

int isQueueFull(Queue* queue) {
    return ((queue->rear + 1) % MAX_QUEUE_SIZE == queue->front);
}

void enqueue(Queue* queue, int item) {
    if (isQueueFull(queue)) {
        printf("Queue is full\n");
        return;
    }

    if (isQueueEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    }
    else {
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    }

    queue->data[queue->rear] = item;
}

int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }

    int item = queue->data[queue->front];

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    else {
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    }

    return item;
}

int main() {
    Queue* myQueue = createQueue();

    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    enqueue(myQueue, 40);

    printf("Dequeued item: %d\n", dequeue(myQueue));
    printf("Dequeued item: %d\n", dequeue(myQueue));

    enqueue(myQueue, 50);
    enqueue(myQueue, 60);

    printf("Dequeued item: %d\n", dequeue(myQueue));
    printf("Dequeued item: %d\n", dequeue(myQueue));
    printf("Dequeued item: %d\n", dequeue(myQueue));

    return 0;
}