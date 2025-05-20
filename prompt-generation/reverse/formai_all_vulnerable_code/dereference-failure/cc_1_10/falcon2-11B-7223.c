//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
} Queue;

void createQueue(Queue *queue, int size) {
    queue->data = (int *)malloc(size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
}

void enqueue(Queue *queue, int data) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->data[++queue->rear] = data;
}

int dequeue(Queue *queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue->data[++queue->front];
    return data;
}

void displayQueue(Queue *queue) {
    if (queue->front == -1 && queue->rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

int main() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    createQueue(queue, 10);

    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 15);

    displayQueue(queue);

    printf("%d\n", dequeue(queue));

    displayQueue(queue);

    printf("%d\n", dequeue(queue));

    printf("Size of queue: %d\n", queue->size);

    return 0;
}