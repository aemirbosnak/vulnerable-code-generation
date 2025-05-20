//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Queue {
    int front, rear;
    int size;
    int *arr;
} Queue;

Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->size = size;
    queue->arr = (int*)malloc(queue->size * sizeof(int));
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->front == -1;
}

int isFull(Queue* queue) {
    return queue->rear == queue->size - 1;
}

void enqueue(Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->arr[queue->rear] = data;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue->arr[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return data;
}

void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

void peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", queue->arr[queue->front]);
}

int main() {
    Queue* queue = createQueue(MAX);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    display(queue);
    dequeue(queue);
    dequeue(queue);
    display(queue);
    peek(queue);
    return 0;
}