//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->arr = (int*)malloc(MAX_SIZE * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    return q;
}

void enqueue(Queue *q, int value) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = value;
    q->size++;
}

int dequeue(Queue *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    q->size--;
    return value;
}

int peek(Queue *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front];
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

int isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

int main() {
    Queue *q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printf("%d\n", peek(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    return 0;
}