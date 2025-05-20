//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data;
    int priority;
} QueueNode;

typedef struct {
    QueueNode *queue;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->queue = (QueueNode*)malloc(MAX_QUEUE_SIZE * sizeof(QueueNode));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

int isEmpty(Queue* q) {
    return (q->front == q->rear);
}

int isFull(Queue* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(Queue* q, int data, int priority) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    }
    q->queue[q->rear].data = data;
    q->queue[q->rear].priority = priority;
    q->size++;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Dequeued element: %d\n", q->queue[q->front].data);
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->size--;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("%d ", q->queue[i].data);
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10, 1);
    enqueue(q, 20, 2);
    enqueue(q, 30, 3);
    display(q);
    dequeue(q);
    dequeue(q);
    display(q);
    return 0;
}