//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct Queue {
    int front, rear, capacity;
    int *array;
} Queue;

Queue *createQueue(int capacity) {
    Queue *queue = malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(Queue *queue) {
    return queue->rear == queue->capacity - 1;
}

int isEmpty(Queue *queue) {
    return queue->front == -1;
}

void enQueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }

    if (queue->front == -1) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear++;
    }

    queue->array[queue->rear] = item;
}

int deQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int item = queue->array[queue->front];

    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }

    return item;
}

void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    int i;
    for (i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }

    printf("\n");
}

void freeQueue(Queue *queue) {
    free(queue->array);
    free(queue);
}

int main() {
    Queue *queue = createQueue(10);

    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);
    enQueue(queue, 5);

    printQueue(queue);

    deQueue(queue);
    deQueue(queue);

    printQueue(queue);

    enQueue(queue, 6);
    enQueue(queue, 7);

    printQueue(queue);

    freeQueue(queue);

    return 0;
}