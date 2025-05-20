//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct {
    int size;
    int front;
    int rear;
    int* queue;
} Queue;

Queue* createQueue() {
    Queue* newQueue = (Queue*) malloc(sizeof(Queue));
    newQueue->size = 0;
    newQueue->front = -1;
    newQueue->rear = -1;
    newQueue->queue = (int*) malloc(MAX_SIZE * sizeof(int));
    return newQueue;
}

void destroyQueue(Queue* q) {
    free(q->queue);
    free(q);
}

bool isQueueEmpty(Queue* q) {
    return (q->size == 0);
}

void enqueue(Queue* q, int value) {
    if (q->size == MAX_SIZE) {
        printf("Queue is full.\n");
        return;
    }

    if (isQueueEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }

    q->queue[q->rear] = value;
    q->size++;
    printf("Element %d added to the queue.\n", value);
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }

    int value = q->queue[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }

    q->size--;
    printf("Element %d removed from the queue.\n", value);
    return value;
}

int peek(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }

    return q->queue[q->front];
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printf("Queue size: %d\n", q->size);
    printf("Front element: %d\n", peek(q));
    printf("Rear element: %d\n", peek(q));
    dequeue(q);
    printf("Queue size: %d\n", q->size);
    printf("Front element: %d\n", peek(q));
    printf("Rear element: %d\n", peek(q));
    destroyQueue(q);
    return 0;
}