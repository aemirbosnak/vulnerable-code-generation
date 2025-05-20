//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *arr;
    int front, rear;
    int capacity;
}Queue;

Queue *createQueue(int capacity) {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->arr = (int *) malloc(sizeof(int) * capacity);
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

void enqueue(Queue *queue, int data) {
    if(queue->front == -1) {
        queue->front = 0;
        queue->rear = 0;
        queue->arr[queue->rear] = data;
        return;
    }
    if((queue->rear + 1) % queue->capacity == queue->front) {
        printf("Queue is full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = data;
}

int dequeue(Queue *queue) {
    if(queue->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    if(queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    }
    return data;
}

int main() {
    Queue *queue = createQueue(5);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    return 0;
}