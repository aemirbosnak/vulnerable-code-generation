//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isFull(Queue *queue) {
    if (queue->front == 0 && queue->rear == MAX_SIZE-1) {
        return 1;
    }
    if (queue->front == queue->rear + 1) {
        return 1;
    }
    return 0;
}

int isEmpty(Queue *queue) {
    if (queue->front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->items[queue->rear] = item;
        printf("Enqueued: %d\n", item);
    }
}

int dequeue(Queue *queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
    }
    printf("Dequeued: %d\n", item);
    return item;
}

void main() {
    Queue *queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);
    enqueue(queue, 7);
    enqueue(queue, 8);
    enqueue(queue, 9);
    enqueue(queue, 10);
    enqueue(queue, 11); // Queue is full

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    enqueue(queue, 11);
    enqueue(queue, 12);
    enqueue(queue, 13);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue); // Queue is empty
}