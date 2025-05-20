//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10

typedef struct Queue_tag {
    int size;
    int capacity;
    int *buffer;
} Queue;

void initQueue(Queue *q) {
    q->size = 0;
    q->capacity = MAX_QUEUE_SIZE;
    q->buffer = malloc(MAX_QUEUE_SIZE * sizeof(int));
}

int isFull(Queue *q) {
    return q->size == q->capacity;
}

int isEmpty(Queue *q) {
    return q->size == 0;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        fprintf(stderr, "Queue Overflow!\n");
        return;
    }

    q->buffer[q->size++] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        fprintf(stderr, "Queue Underflow!\n");
        return -1;
    }

    return q->buffer[--q->size];
}

void printQueue(Queue *q) {
    printf("Queue: [");
    for (int i = 0; i < q->size; ++i) {
        printf("%d, ", q->buffer[i]);
    }
    printf("\b\b]");
}

int main() {
    Queue myQueue;
    initQueue(&myQueue);

    enqueue(&myQueue, 5);
    enqueue(&myQueue, 10);
    enqueue(&myQueue, 15);

    printQueue(&myQueue);
    printf("\n");

    int value = dequeue(&myQueue);
    printf("Dequeued value: %d\n", value);
    printQueue(&myQueue);
    printf("\n");

    enqueue(&myQueue, 20);
    printQueue(&myQueue);
    printf("\n");

    return 0;
}