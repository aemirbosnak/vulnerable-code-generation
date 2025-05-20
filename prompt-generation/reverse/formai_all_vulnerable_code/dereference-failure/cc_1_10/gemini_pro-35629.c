//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int *arr;
    int front, rear, size;
} Queue;

Queue *createQueue(int size) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->arr = (int *)malloc(sizeof(int) * size);
    q->front = q->rear = -1;
    q->size = size;
    return q;
}

void enqueue(Queue *q, int data) {
    if ((q->rear + 1) % q->size == q->front) {
        printf("Queue is full\n");
        return;
    } else if (q->front == -1) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->size;
    }
    q->arr[q->rear] = data;
}

int dequeue(Queue *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return -1;
    } else if (q->front == q->rear) {
        q->front = q->rear = -1;
        return q->arr[q->front];
    } else {
        int data = q->arr[q->front];
        q->front = (q->front + 1) % q->size;
        return data;
    }
}

void displayQueue(Queue *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        int i = q->front;
        while (i != q->rear) {
            printf("%d ", q->arr[i]);
            i = (i + 1) % q->size;
        }
        printf("%d\n", q->arr[i]);
    }
}

int main() {
    Queue *q = createQueue(5);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    displayQueue(q);
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    enqueue(q, 60);
    enqueue(q, 70);
    displayQueue(q);
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    return 0;
}