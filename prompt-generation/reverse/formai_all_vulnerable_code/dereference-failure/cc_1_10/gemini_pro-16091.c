//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

typedef struct Queue {
    int front;
    int rear;
    int size;
    int *arr;
} Queue;

Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    q->size = QUEUE_SIZE;
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
    } else {
        if (q->front == -1) {
            q->front = q->rear = 0;
        } else {
            q->rear = (q->rear + 1) % q->size;
        }
        q->arr[q->rear] = data;
    }
}

int dequeue(Queue *q) {
    int data;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        data = q->arr[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front = (q->front + 1) % q->size;
        }
    }
    return data;
}

void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        int i;
        for (i = q->front; i != q->rear; i = (i + 1) % q->size) {
            printf("%d ", q->arr[i]);
        }
        printf("%d\n", q->arr[i]);
    }
}

int main() {
    Queue *q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    printQueue(q);

    dequeue(q);
    dequeue(q);

    printQueue(q);

    return 0;
}