//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int capacity;
    int front;
    int rear;
} Queue;

Queue* createQueue(int capacity) {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(capacity * sizeof(int));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

bool isEmpty(Queue *queue) {
    return (queue->front == queue->rear);
}

bool isFull(Queue *queue) {
    return ((queue->rear + 1) % queue->capacity == queue->front);
}

void enqueue(Queue *queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = element;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int element = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return element;
}

void display(Queue *queue) {
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i = (i + 1) % queue->capacity) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
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
    dequeue(queue);
    display(queue);
    return 0;
}