//FormAI DATASET v1.0 Category: Queue Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct queue {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void enqueue(Queue* q, int item) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }

    if (q->front == -1) {
        q->front = 0;
    }

    q->rear++;
    q->items[q->rear] = item;
    printf("%d enqueued to the queue.\n", item);
}

int dequeue(Queue* q) {
    int item;

    if (q->front == -1 || q->front > q->rear) {
        printf("Queue Underflow\n");
        return -1;
    }

    item = q->items[q->front];
    q->front++;

    return item;
}

void display(Queue* q) {
    int i;
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }

    for (i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    display(q);

    dequeue(q);
    dequeue(q);
    display(q);

    return 0;
}