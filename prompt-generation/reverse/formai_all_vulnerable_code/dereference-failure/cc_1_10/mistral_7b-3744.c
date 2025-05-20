//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_SIZE 10

typedef struct queue {
    int front;
    int rear;
    int arr[QUEUE_SIZE];
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = q->rear = -1;
    return q;
}

int isFull(Queue* q) {
    return q->rear == QUEUE_SIZE - 1;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int data) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    }
    q->rear++;
    q->arr[q->rear] = data;
}

int dequeue(Queue* q) {
    int data;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    data = q->arr[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return data;
}

int main() {
    Queue* q = createQueue();
    char str[10];
    int i;

    printf("Welcome to the Enigma Queue!\n");

    for (i = 0; i < 12; i++) {
        if (i % 2 == 0) {
            enqueue(q, i);
            printf("Enqueued: %d\n", i);
        } else {
            printf("Dequeued: %d\n", dequeue(q));
        }
    }

    printf("Queue is full! Can't enqueue %d\n", 13);

    printf("Peek at the last enqueued element: %d\n", q->arr[q->rear]);

    free(q);

    return 0;
}