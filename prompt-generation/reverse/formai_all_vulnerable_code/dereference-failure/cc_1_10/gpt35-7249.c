//FormAI DATASET v1.0 Category: Queue ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

typedef struct queue {
    int front, rear, size;
    int items[MAX_QUEUE_SIZE];
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    q->size = 0;
    return q;
}

int isFull(Queue* q) {
    return q->rear == MAX_QUEUE_SIZE - 1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int item) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = item;
    q->size++;
    printf("%d enqueued\n", item);
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    q->size--;
    printf("%d dequeued\n", item);
    return item;
}

void printQueue(Queue* q) {
    int i;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contains:\n");
    for (i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    printf("***Bold C Example: Queue using Array***\n");

    Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);
    printQueue(q);

    dequeue(q);
    dequeue(q);
    printQueue(q);

    enqueue(q, 70);
    printQueue(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    printQueue(q);

    dequeue(q);

    return 0;
}