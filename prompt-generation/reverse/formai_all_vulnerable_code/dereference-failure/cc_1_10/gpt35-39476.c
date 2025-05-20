//FormAI DATASET v1.0 Category: Queue Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10  // Define the maximum size of the queue.

typedef struct queue {
    int arr[MAX_SIZE];
    int rear, front;
} Queue;

Queue *createQueue() {
    Queue *q = malloc(sizeof(Queue));  // Allocate memory for the queue.
    q->rear = -1;
    q->front = -1;
    return q;
}

int isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is Full!\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = data;
    if (q->front == -1) {
        q->front++;
    }
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return -1;
    }
    int data = q->arr[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return data;
}

int main() {
    Queue *q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    printf("Dequeued Element: %d\n", dequeue(q));
    printf("Dequeued Element: %d\n", dequeue(q));
    printf("Dequeued Element: %d\n", dequeue(q));
    printf("Dequeued Element: %d\n", dequeue(q));
    printf("Dequeued Element: %d\n", dequeue(q));
    printf("Dequeued Element: %d\n", dequeue(q));
    return 0;
}