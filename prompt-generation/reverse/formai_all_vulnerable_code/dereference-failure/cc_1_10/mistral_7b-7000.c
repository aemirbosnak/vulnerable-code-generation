//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 10

typedef struct queue_tag {
    int items[MAX_QUEUE_SIZE];
    int head;
    int tail;
} queue_t;

void initQueue(queue_t *queue) {
    queue->head = 0;
    queue->tail = 0;
}

int isFull(queue_t *queue) {
    return (queue->tail + 1) % MAX_QUEUE_SIZE == queue->head;
}

void enqueue(queue_t *queue, int item) {
    if (isFull(queue)) {
        printf("Error: Queue is full.\n");
        return;
    }
    queue->items[queue->tail] = item;
    queue->tail = (queue->tail + 1) % MAX_QUEUE_SIZE;
}

int dequeue(queue_t *queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty.\n");
        return -1;
    }
    int item = queue->items[queue->head];
    queue->head = (queue->head + 1) % MAX_QUEUE_SIZE;
    return item;
}

int isEmpty(queue_t *queue) {
    return queue->head == queue->tail;
}

int main() {
    queue_t myQueue;
    initQueue(&myQueue);

    char str[10];
    for (int i = 0; i < 10; i++) {
        sprintf(str, "Item %d", i + 1);
        enqueue(&myQueue, atoi(str));
        printf("Enqueued %s\n", str);
    }

    printf("Queue is full. Size: %d\n", MAX_QUEUE_SIZE);

    int dequeued;
    for (int i = 0; i < 5; i++) {
        dequeued = dequeue(&myQueue);
        printf("Dequeued %d\n", dequeued);
    }

    while (!isEmpty(&myQueue)) {
        dequeued = dequeue(&myQueue);
        printf("Dequeued %d\n", dequeued);
    }

    printf("Queue is empty.\n");

    return 0;
}