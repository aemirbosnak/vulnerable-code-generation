//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: secure
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Queue {
    int *items;
    int front, rear, capacity;
} Queue;

Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->items = (int *)malloc(sizeof(int) * capacity);
    return queue;
}

bool isEmpty(Queue *queue) {
    return (queue->front == -1);
}

bool isFull(Queue *queue) {
    return ((queue->rear + 1) % queue->capacity == queue->front);
}

void enqueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % queue->capacity;
    }
    queue->items[queue->rear] = item;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return item;
}

void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue:\n");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->items[i]);
        i = (i + 1) % queue->capacity;
    }
    printf("%d\n", queue->items[i]);
}

void destroyQueue(Queue *queue) {
    free(queue->items);
    free(queue);
}

int main() {
    Queue *queue = createQueue(5);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    display(queue);
    dequeue(queue);
    display(queue);
    dequeue(queue);
    display(queue);
    enqueue(queue, 60);
    display(queue);
    destroyQueue(queue);
    return 0;
}