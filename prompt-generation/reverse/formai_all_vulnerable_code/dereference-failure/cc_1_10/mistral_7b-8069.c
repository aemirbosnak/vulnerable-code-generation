//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 10

typedef struct Queue {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isFull(Queue* q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

int isEmpty(Queue* q) {
    return q->front == -1 && q->rear == -1;
}

void enqueue(Queue* q, int data) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d.\n", data);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->items[q->rear] = data;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int data = q->items[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    }
    return data;
}

int main() {
    Queue* q = createQueue();
    int i;

    for (i = 0; i < 11; i++) {
        enqueue(q, i);
        printf("Enqueued %d.\n", i);
    }

    printf("Queue is full. Cannot enqueue %d.\n", i);

    for (i = 0; i < 6; i++) {
        printf("Dequeued %d. Size = %d\n", dequeue(q), (q->rear + 1) % MAX_QUEUE_SIZE - q->front);
    }

    printf("Queue is empty. Cannot dequeue.\n");

    free(q);
    return 0;
}