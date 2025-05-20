//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue {
    int *data;
    int front;
    int rear;
    int size;
} queue;

queue *createQueue(int size) {
    queue *q = (queue *)malloc(sizeof(queue));
    q->data = (int *)malloc(sizeof(int) * size);
    q->front = q->rear = -1;
    q->size = size;
    return q;
}

void enqueue(queue *q, int data) {
    if ((q->rear + 1) % q->size == q->front) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->size;
    }
    q->data[q->rear] = data;
}

int dequeue(queue *q) {
    if (q->front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    return data;
}

int peek(queue *q) {
    if (q->front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->data[q->front];
}

int isEmpty(queue *q) {
    return q->front == -1;
}

int isFull(queue *q) {
    return (q->rear + 1) % q->size == q->front;
}

void displayQueue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->data[i]);
        i = (i + 1) % q->size;
    }
    printf("%d\n", q->data[i]);
}

int main() {
    queue *q = createQueue(5);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    displayQueue(q);
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    displayQueue(q);
    enqueue(q, 6);
    displayQueue(q);
    return 0;
}