//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_SIZE 10

typedef struct Queue {
    int front;
    int rear;
    int capacity;
    int *queueArray;
} Queue;

void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = QUEUE_SIZE;
    queue->queueArray = (int *)calloc(QUEUE_SIZE, sizeof(int));
}

int isFull(Queue *queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}

int isEmpty(Queue *queue) {
    return queue->front == -1 && queue->rear == -1;
}

void enqueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->queueArray[queue->rear] = item;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = queue->queueArray[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return item;
}

void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue->front, j = 0; i != queue->rear; i = (i + 1) % queue->capacity, j++) {
        printf("%d ", queue->queueArray[i]);
    }
    printf("%d\n", queue->queueArray[queue->rear]);
}

int main() {
    Queue myQueue;
    initializeQueue(&myQueue);

    enqueue(&myQueue, 5);
    enqueue(&myQueue, 10);
    enqueue(&myQueue, 15);

    printQueue(&myQueue);

    dequeue(&myQueue);
    printQueue(&myQueue);

    enqueue(&myQueue, 20);
    printQueue(&myQueue);

    return 0;
}