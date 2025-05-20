//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Queue {
    int front, rear;
    int size;
    int *arr;
} Queue;

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    q->size = 0;
    q->arr = (int *)malloc(sizeof(int) * MAX_SIZE);
    return q;
}

void enqueue(Queue *q, int data) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = data;
    q->size++;
}

int dequeue(Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    q->front++;
    int data = q->arr[q->front];
    q->size--;
    return data;
}

void displayQueue(Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return;
    }
    int i;
    printf("Queue: ");
    for (i = q->front + 1; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue *q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    displayQueue(q);
    dequeue(q);
    displayQueue(q);
    enqueue(q, 50);
    enqueue(q, 60);
    displayQueue(q);
    return 0;
}