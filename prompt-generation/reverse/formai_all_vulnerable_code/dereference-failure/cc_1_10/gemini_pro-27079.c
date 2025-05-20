//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

typedef struct {
    int *items;
    int head;
    int tail;
    int count;
} Queue;

Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->items = (int *)malloc(sizeof(int) * QUEUE_SIZE);
    queue->head = 0;
    queue->tail = 0;
    queue->count = 0;
    return queue;
}

void enqueue(Queue *queue, int item) {
    if (queue->count == QUEUE_SIZE) {
        printf("The queue is full.\n");
        return;
    }

    queue->items[queue->tail] = item;
    queue->tail = (queue->tail + 1) % QUEUE_SIZE;
    queue->count++;
}

int dequeue(Queue *queue) {
    if (queue->count == 0) {
        printf("The queue is empty.\n");
        return -1;
    }

    int item = queue->items[queue->head];
    queue->head = (queue->head + 1) % QUEUE_SIZE;
    queue->count--;
    return item;
}

int peek(Queue *queue) {
    if (queue->count == 0) {
        printf("The queue is empty.\n");
        return -1;
    }

    return queue->items[queue->head];
}

int isQueueEmpty(Queue *queue) {
    return queue->count == 0;
}

int isQueueFull(Queue *queue) {
    return queue->count == QUEUE_SIZE;
}

void printQueue(Queue *queue) {
    if (queue->count == 0) {
        printf("The queue is empty.\n");
        return;
    }

    for (int i = queue->head; i < queue->head + queue->count; i++) {
        printf("%d ", queue->items[i % QUEUE_SIZE]);
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
    enqueue(queue, 9);
    enqueue(queue, 10);

    printQueue(queue);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    printQueue(queue);

    return 0;
}