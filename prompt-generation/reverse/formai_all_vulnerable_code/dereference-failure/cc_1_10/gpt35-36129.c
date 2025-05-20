//FormAI DATASET v1.0 Category: Queue ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

typedef struct {
    int* items;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->items = (int*) malloc(sizeof(int) * MAX_SIZE);
    queue->front = -1;
    queue->rear = -1;
    queue->size = MAX_SIZE;
    return queue;
}

int isFull(Queue* queue) {
    return queue->rear == queue->size - 1;
}

int isEmpty(Queue* queue) {
    return queue->front == -1;
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = item;
        printf("%d enqueued to queue.\n", item);
    }
}

int dequeue(Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        item = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        printf("%d dequeued from queue.\n", item);
    }
    return item;
}

int main() {
    Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    dequeue(queue);
    enqueue(queue, 50);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    return 0;
}