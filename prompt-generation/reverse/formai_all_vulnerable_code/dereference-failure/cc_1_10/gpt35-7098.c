//FormAI DATASET v1.0 Category: Queue ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int front, rear;
    int data[MAX_QUEUE_SIZE];
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(Queue* q, int val) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    q->data[++q->rear] = val;
    if (q->front == -1) {
        q->front = 0;
    }
}

int dequeue(Queue* q) {
    if (q->front == -1) {
        printf("Queue Underflow\n");
        return -1;
    }
    int val = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    }
    else {
        q->front++;
    }
    return val;
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    printf("Dequeued Element: %d\n", dequeue(q));
    printf("Dequeued Element: %d\n", dequeue(q));
    printf("Dequeued Element: %d\n", dequeue(q));
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
    enqueue(q, 9);
    enqueue(q, 10);
    printf("Dequeued Element: %d\n", dequeue(q));
    printf("Dequeued Element: %d\n", dequeue(q));
    printf("Dequeued Element: %d\n", dequeue(q));
    printf("Dequeued Element: %d\n", dequeue(q));
    printf("Dequeued Element: %d\n", dequeue(q));
    dequeue(q);
    return 0;
}