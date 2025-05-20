//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
    int *data;
    int head, tail, size;
} Queue;

Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->data = (int *)malloc(sizeof(int) * size);
    queue->head = queue->tail = 0;
    queue->size = size;
    return queue;
}

void enqueue(Queue *queue, int value) {
    if ((queue->tail + 1) % queue->size == queue->head) {
        printf("Queue is full\n");
        return;
    }
    queue->data[queue->tail] = value;
    queue->tail = (queue->tail + 1) % queue->size;
}

int dequeue(Queue *queue) {
    if (queue->head == queue->tail) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = queue->data[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    return value;
}

int peek(Queue *queue) {
    if (queue->head == queue->tail) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->data[queue->head];
}

int main() {
    Queue *queue = createQueue(10);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    dequeue(queue);
    dequeue(queue);
    enqueue(queue, 60);
    enqueue(queue, 70);
    enqueue(queue, 80);
    enqueue(queue, 90);
    enqueue(queue, 100);
    while (!queue->head == queue->tail) {
        printf("%d\n", dequeue(queue));
    }
    return 0;
}