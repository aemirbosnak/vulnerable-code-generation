//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

typedef struct Queue {
    int front, rear;
    int arr[QUEUE_SIZE];
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(Queue* q, int x) {
    if (q->rear == QUEUE_SIZE - 1) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = x;
    }
}

int dequeue(Queue* q) {
    int x;
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
        return -1;
    } else {
        x = q->arr[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return x;
    }
}

void displayQueue(Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    displayQueue(q);
    dequeue(q);
    dequeue(q);
    displayQueue(q);
    enqueue(q, 60);
    enqueue(q, 70);
    displayQueue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    displayQueue(q);
    return 0;
}