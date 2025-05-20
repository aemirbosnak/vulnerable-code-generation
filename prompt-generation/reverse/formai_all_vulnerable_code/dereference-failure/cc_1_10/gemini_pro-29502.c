//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: minimalist
#include <stdlib.h>
#include <stdio.h>

typedef struct Queue {
    int front, rear, size;
    int *arr;
} Queue;

Queue* createQueue(int size) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    q->size = size;
    q->arr = (int*)malloc(q->size * sizeof(int));
    return q;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

int isFull(Queue *q) {
    return (q->rear + 1) % q->size == q->front;
}

void enqueue(Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = data;
    if (q->front == -1) {
        q->front = q->rear;
    }
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    return data;
}

int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->arr[q->front];
}

void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    }
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("%d\n", q->arr[q->rear]);
}

int main() {
    Queue *q = createQueue(5);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    printQueue(q);
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    enqueue(q, 6);
    printQueue(q);
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    return 0;
}