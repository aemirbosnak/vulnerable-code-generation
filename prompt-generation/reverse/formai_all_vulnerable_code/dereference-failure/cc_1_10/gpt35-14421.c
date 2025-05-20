//FormAI DATASET v1.0 Category: Queue Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct Queue {
    int front, rear;
    int arr[MAX_QUEUE_SIZE];
} Queue;

Queue* createQueue() {
    Queue* newQueue = (Queue*) malloc(sizeof(Queue));
    newQueue->front = -1;
    newQueue->rear = -1;
    return newQueue;
}

int isEmpty(Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int isFull(Queue* queue) {
    return (queue->rear+1)%MAX_QUEUE_SIZE == queue->front;
}

void enQueue(Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    else if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    }
    else {
        queue->rear = (queue->rear+1)%MAX_QUEUE_SIZE;
    }
    queue->arr[queue->rear] = data;
    printf("Enqueued %d\n", data);
}

int deQueue(Queue* queue) {
    int data;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    else if (queue->front == queue->rear) {
        data = queue->arr[queue->front];
        queue->front = -1;
        queue->rear = -1;
    }
    else {
        data = queue->arr[queue->front];
        queue->front = (queue->front+1)%MAX_QUEUE_SIZE;
    }
    printf("Dequeued %d\n", data);
    return data;
}

void displayQueue(Queue* queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue: ");
        for (i = queue->front; i != queue->rear; i = (i+1)%MAX_QUEUE_SIZE) {
            printf("%d ", queue->arr[i]);
        }
        printf("%d\n", queue->arr[i]);
    }
}

int main() {
    Queue* queue = createQueue();
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);
    enQueue(queue, 5);
    displayQueue(queue);
    deQueue(queue);
    deQueue(queue);
    displayQueue(queue);
    enQueue(queue, 6);
    enQueue(queue, 7);
    displayQueue(queue);
    return 0;
}