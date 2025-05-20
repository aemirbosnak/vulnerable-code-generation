//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int *queue;
    int front;
    int rear;
    int size;
} Queue;

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Error: Could not allocate memory for queue.\n");
        exit(1);
    }
    q->queue = (int *)malloc(MAX_QUEUE_SIZE * sizeof(int));
    if (q->queue == NULL) {
        printf("Error: Could not allocate memory for queue elements.\n");
        exit(1);
    }
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    return q;
}

void enqueue(Queue *q, int value) {
    if (q->size == MAX_QUEUE_SIZE) {
        printf("Error: Queue is full.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->queue[q->rear] = value;
    q->size++;
}

int dequeue(Queue *q) {
    if (q->front == -1) {
        printf("Error: Queue is empty.\n");
        return -1;
    }
    int value = q->queue[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    q->size--;
    return value;
}

int peek(Queue *q) {
    if (q->front == -1) {
        printf("Error: Queue is empty.\n");
        return -1;
    }
    return q->queue[q->front];
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

int isFull(Queue *q) {
    return q->size == MAX_QUEUE_SIZE;
}

void destroyQueue(Queue *q) {
    free(q->queue);
    free(q);
}

int main() {
    Queue *q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printf("Front element: %d\n", peek(q));
    printf("Queue size: %d\n", q->size);
    dequeue(q);
    printf("Front element after dequeue: %d\n", peek(q));
    printf("Queue size after dequeue: %d\n", q->size);
    enqueue(q, 4);
    printf("Front element after enqueue: %d\n", peek(q));
    printf("Queue size after enqueue: %d\n", q->size);
    destroyQueue(q);
    return 0;
}