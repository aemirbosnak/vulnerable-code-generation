//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: paranoid
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *data;
    int head;
    int tail;
    int size;
} Queue;

Queue *createQueue(int size) {
    Queue *queue = malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL;
    }

    queue->data = malloc(sizeof(int) * size);
    if (queue->data == NULL) {
        free(queue);
        return NULL;
    }

    queue->head = 0;
    queue->tail = 0;
    queue->size = size;

    return queue;
}

int enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        return -1;
    }

    queue->data[queue->tail] = value;
    queue->tail++;
    queue->tail %= queue->size;

    return 0;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        return -1;
    }

    int value = queue->data[queue->head];
    queue->head++;
    queue->head %= queue->size;

    return value;
}

int peek(Queue *queue) {
    if (isEmpty(queue)) {
        return -1;
    }

    return queue->data[queue->head];
}

int isEmpty(Queue *queue) {
    return queue->head == queue->tail;
}

int isFull(Queue *queue) {
    return (queue->tail + 1) % queue->size == queue->head;
}

int main() {
    Queue *queue = createQueue(5);

    printf("Enqueueing 1\n");
    enqueue(queue, 1);

    printf("Enqueueing 2\n");
    enqueue(queue, 2);

    printf("Enqueueing 3\n");
    enqueue(queue, 3);

    printf("Enqueueing 4\n");
    enqueue(queue, 4);

    printf("Enqueueing 5\n");
    enqueue(queue, 5);

    printf("Queue is full: %s\n", isFull(queue) ? "true" : "false");

    printf("Dequeueing: %d\n", dequeue(queue));
    printf("Dequeueing: %d\n", dequeue(queue));

    printf("Queue is empty: %s\n", isEmpty(queue) ? "true" : "false");

    printf("Peek: %d\n", peek(queue));

    printf("Enqueueing 6\n");
    enqueue(queue, 6);

    printf("Queue is full: %s\n", isFull(queue) ? "true" : "false");

    printf("Dequeueing all remaining elements:\n");
    while (!isEmpty(queue)) {
        printf("Dequeueing: %d\n", dequeue(queue));
    }

    printf("Queue is empty: %s\n", isEmpty(queue) ? "true" : "false");

    return 0;
}