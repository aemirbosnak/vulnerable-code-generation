//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int front;
    int rear;
    int size;
    int *queue;
} Queue;

void init_queue(Queue *q) {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    q->queue = (int *)malloc(MAX_SIZE * sizeof(int));
}

void enqueue(Queue *q, int data) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->queue[q->rear] = data;
    q->size++;
}

void dequeue(Queue *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Dequeued element is %d\n", q->queue[q->front]);
    q->front++;
    q->size--;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
}

void display(Queue q) {
    if (q.front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.queue[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    init_queue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(q);
    dequeue(&q);
    dequeue(&q);
    display(q);
    return 0;
}