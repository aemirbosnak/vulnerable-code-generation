//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue {
    int front;
    int rear;
    int size;
    int *data;
};

typedef struct Queue Queue;

Queue *createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    queue->data = (int *)malloc(size * sizeof(int));
    return queue;
}

void enqueue(Queue *queue, int data) {
    if (queue->rear == queue->size - 1) {
        fprintf(stderr, "Queue is full.\n");
        return;
    }
    queue->data[++queue->rear] = data;
}

int dequeue(Queue *queue) {
    if (queue->front == -1) {
        fprintf(stderr, "Queue is empty.\n");
        return -1;
    }
    int data = queue->data[queue->front];
    queue->data[queue->front] = -1;
    queue->front = (queue->front + 1) % queue->size;
    return data;
}

int main() {
    Queue *queue = createQueue(5);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    free(queue->data);
    free(queue);

    return 0;
}