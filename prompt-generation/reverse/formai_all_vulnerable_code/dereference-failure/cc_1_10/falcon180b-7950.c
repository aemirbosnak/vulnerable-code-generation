//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->data = (int*)malloc(MAX_SIZE * sizeof(int));
    newQueue->front = -1;
    newQueue->rear = -1;
    newQueue->size = 0;
    return newQueue;
}

void enqueue(Queue* queue, int value) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }

    if (queue->front == -1) {
        queue->front = 0;
    }

    queue->rear++;
    queue->data[queue->rear] = value;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int removedValue = queue->data[queue->front];
    queue->front++;

    if (queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }

    queue->size--;
    return removedValue;
}

int peek(Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty. Cannot peek.\n");
        return -1;
    }

    return queue->data[queue->front];
}

bool isEmpty(Queue* queue) {
    return queue->front == -1;
}

int main() {
    Queue* myQueue = createQueue();

    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);

    printf("Peek: %d\n", peek(myQueue));

    int removedValue = dequeue(myQueue);
    printf("Removed value: %d\n", removedValue);

    printf("Peek: %d\n", peek(myQueue));

    removedValue = dequeue(myQueue);
    printf("Removed value: %d\n", removedValue);

    removedValue = dequeue(myQueue);
    printf("Removed value: %d\n", removedValue);

    if (isEmpty(myQueue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }

    free(myQueue->data);
    free(myQueue);
    return 0;
}