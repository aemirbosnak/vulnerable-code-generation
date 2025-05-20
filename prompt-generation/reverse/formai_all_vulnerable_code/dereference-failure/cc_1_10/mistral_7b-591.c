//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

typedef struct CQueue {
    int front;
    int rear;
    int capacity;
    int *queue;
} CQueue;

CQueue *createQueue() {
    CQueue *queue = (CQueue *) malloc(sizeof(CQueue));
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = MAX_QUEUE_SIZE;
    queue->queue = (int *) calloc(MAX_QUEUE_SIZE, sizeof(int));
    return queue;
}

int isFull(CQueue *queue) {
    return queue->rear == queue->capacity - 1;
}

int isEmpty(CQueue *queue) {
    return queue->front == -1 && queue->rear == -1;
}

void enqueue(CQueue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d.\n", data);
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear++;
    queue->queue[queue->rear] = data;
}

int dequeue(CQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int data = queue->queue[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return data;
}

void printQueue(CQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    int i = queue->front;
    printf("Queue: ");
    do {
        printf("%d ", queue->queue[i]);
        i = (i + 1) % queue->capacity;
    } while (i != queue->rear);
    printf("\n");
}

int main() {
    CQueue *queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printQueue(queue);

    dequeue(queue);
    dequeue(queue);

    printQueue(queue);

    free(queue->queue);
    free(queue);

    return 0;
}