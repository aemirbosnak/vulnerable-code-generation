//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

typedef struct Queue {
    int front, rear;
    int size;
    int *arr;
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->size = MAX_QUEUE_SIZE;
    queue->arr = (int *)malloc(queue->size * sizeof(int));
    return queue;
}

int isEmpty(Queue *queue) {
    return queue->front == -1;
}

int isFull(Queue *queue) {
    return (queue->rear + 1) % queue->size == queue->front;
}

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

void displayQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % queue->size;
    }
    printf("%d\n", queue->arr[queue->rear]);
}

int main() {
    Queue *queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    displayQueue(queue);
    dequeue(queue);
    dequeue(queue);
    displayQueue(queue);
    enqueue(queue, 60);
    enqueue(queue, 70);
    displayQueue(queue);
    return 0;
}