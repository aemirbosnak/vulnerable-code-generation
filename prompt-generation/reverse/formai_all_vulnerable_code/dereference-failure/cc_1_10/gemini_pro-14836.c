//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: imaginative
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
    queue->data = malloc(sizeof(int) * size);
    queue->head = 0;
    queue->tail = 0;
    queue->size = size;
    return queue;
}

void destroyQueue(Queue *queue) {
    free(queue->data);
    free(queue);
}

int isEmpty(Queue *queue) {
    return queue->head == queue->tail;
}

int isFull(Queue *queue) {
    return (queue->tail + 1) % queue->size == queue->head;
}

void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    queue->data[queue->tail] = value;
    queue->tail = (queue->tail + 1) % queue->size;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = queue->data[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    return value;
}

void printQueue(Queue *queue) {
    printf("Queue: ");
    int i = queue->head;
    while (i != queue->tail) {
        printf("%d ", queue->data[i]);
        i = (i + 1) % queue->size;
    }
    printf("\n");
}

int main() {
    Queue *queue = createQueue(5);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    printQueue(queue);
    dequeue(queue);
    dequeue(queue);
    enqueue(queue, 6);
    printQueue(queue);
    destroyQueue(queue);
    return 0;
}