//FormAI DATASET v1.0 Category: Queue Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct queue {
    int front;
    int rear;
    int size;
    int* arr;
} Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->size = 0;
    q->rear = size - 1;
    q->arr = (int*)malloc(size * sizeof(int));
    return q;
}

int isFull(Queue* q) {
    return q->size == MAX_QUEUE_SIZE;
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

void enqueue(Queue* q, int item) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->arr[q->rear] = item;
    q->size++;
    printf("Enqueued %d\n", item);
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int item = q->arr[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->size--;
    printf("Dequeued %d\n", item);
    return item;
}

int main() {
    Queue* q = createQueue(MAX_QUEUE_SIZE);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    dequeue(q);
    dequeue(q);

    enqueue(q, 60);
    enqueue(q, 70);

    while (!isEmpty(q)) {
        dequeue(q);
    }

    free(q->arr);
    free(q);
    return 0;
}