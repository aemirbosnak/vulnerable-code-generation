//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int front;
    int rear;
    int *queue;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    q->front = -1;
    q->rear = -1;
    q->queue = (int*)malloc(MAX_QUEUE_SIZE * sizeof(int));
    if (q->queue == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    return q;
}

void destroyQueue(Queue* q) {
    free(q->queue);
    free(q);
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->queue[q->rear] = value;
}

int dequeue(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->queue[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

void display(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->queue[i]);
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    int value = dequeue(q);
    printf("Dequeued value: %d\n", value);
    display(q);
    destroyQueue(q);
    return 0;
}