//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int *queueArray;
    int front, rear;
    int currentSize;
} Queue;

void initQueue(Queue *q) {
    q->queueArray = (int *)malloc(MAX_SIZE * sizeof(int));
    q->front = q->rear = -1;
    q->currentSize = 0;
}

int isEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

int isFull(Queue *q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    }
    else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->queueArray[q->rear] = value;
    q->currentSize++;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->queueArray[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    }
    else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    q->currentSize--;
    return value;
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    int i;
    for (i = q->front; i <= q->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", q->queueArray[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    display(&q);
    int value = dequeue(&q);
    printf("Dequeued value is %d\n", value);
    display(&q);
    return 0;
}