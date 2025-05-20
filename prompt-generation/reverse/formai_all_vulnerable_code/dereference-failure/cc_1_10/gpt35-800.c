//FormAI DATASET v1.0 Category: Queue Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_CAPACITY 100

typedef struct Queue {
    int items[QUEUE_CAPACITY];
    int rear;
    int front;
} Queue;

Queue* createQueue() {
    Queue* queue = malloc(sizeof(Queue));
    queue->rear = -1;
    queue->front = -1;
    return queue;
}

void enqueue(Queue* queue, int item) {
    if (queue->rear == QUEUE_CAPACITY - 1) {
        printf("Queue is full\n");
        return;
    }

    if (queue->front == -1) {
        queue->front = 0;
    }

    queue->rear++;
    queue->items[queue->rear] = item;
}

int dequeue(Queue* queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Queue is empty\n");
        return -1;
    }

    int item = queue->items[queue->front];
    queue->front++;
    return item;
}

void printQueue(Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

int main() {
    Queue* queue = createQueue();

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

    printQueue(queue);

    return 0;
}