//FormAI DATASET v1.0 Category: Data structures visualization ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct Queue {
    int arr[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = q->rear = -1;
    return q;
}

int isFull(Queue* q) {
    return (q->rear == MAX_QUEUE_SIZE-1);
}

int isEmpty(Queue* q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(Queue* q, int data) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->arr[q->rear] = data;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = q->arr[q->front];
    q->front++;
    return item;
}

void visualizeQueue(Queue* q) {
    printf(" Queue [ ");
    int i = 0;
    for (i = 0; i <= MAX_QUEUE_SIZE-1; i++) {
        if (q->front <= i && i <= q->rear)
            printf(" %d ", q->arr[i]);
        else 
            printf(" - ");
    }
    printf("]\n");
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);
    enqueue(q, 70);
    visualizeQueue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    visualizeQueue(q);
    enqueue(q, 80);
    visualizeQueue(q);
    dequeue(q);
    visualizeQueue(q);

    return 0;
}