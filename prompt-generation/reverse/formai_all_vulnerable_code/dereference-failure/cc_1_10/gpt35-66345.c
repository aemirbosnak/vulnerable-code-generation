//FormAI DATASET v1.0 Category: Queue ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct _queue {
    int front, rear;
    int size;
    int data[MAX_QUEUE_SIZE];
} Queue;

Queue* newQueue() {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

int isQueueEmpty(Queue *queue) {
    return queue->size == 0;
}

int isQueueFull(Queue *queue) {
    return queue->size == MAX_QUEUE_SIZE;
}

void enqueue(Queue *queue, int value) {
    if (isQueueFull(queue)) {
        printf("Queue overflow!\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->data[queue->rear] = value;
    ++queue->size;
    if (queue->front == -1) {
        queue->front = 0;
    }
}

int dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue underflow!\n");
        return -1;
    }
    int value = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    --queue->size;
    if (queue->size == 0) {
        queue->front = -1;
        queue->rear = -1;
    }
    return value;
}

int main() {
    Queue *queue = newQueue();
    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 15);
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    return 0;
}