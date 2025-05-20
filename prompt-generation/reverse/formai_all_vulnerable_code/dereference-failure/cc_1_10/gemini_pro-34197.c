//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100

typedef struct {
    int front, rear;
    int size;
    int *arr;
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->size = QUEUE_SIZE;
    queue->arr = (int *)malloc(queue->size * sizeof(int));
    return queue;
}

int isEmpty(Queue *queue) {
    return queue->front == -1;
}

int isFull(Queue *queue) {
    return queue->rear == queue->size - 1;
}

void enqueue(Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }

    if (queue->front == -1) {
        queue->front = 0;
    }

    queue->rear++;
    queue->arr[queue->rear] = data;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int data = queue->arr[queue->front];
    queue->front++;

    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }

    return data;
}

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

int main() {
    Queue *queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    printQueue(queue);

    dequeue(queue);
    dequeue(queue);

    printQueue(queue);

    enqueue(queue, 6);
    enqueue(queue, 7);
    enqueue(queue, 8);

    printQueue(queue);

    return 0;
}