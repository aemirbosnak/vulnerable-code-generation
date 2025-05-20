//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

typedef struct queue {
    int front;
    int rear;
    int capacity;
    int *array;
} queue;

queue *createQueue() {
    queue *q = (queue *) malloc(sizeof(queue));
    q->capacity = MAX_QUEUE_SIZE;
    q->front = -1;
    q->rear = -1;
    q->array = (int *) calloc(q->capacity, sizeof(int));
    return q;
}

int isFull(queue *q) {
    return (q->rear + 1) % q->capacity == q->front;
}

int isEmpty(queue *q) {
    return q->front == -1 && q->rear == -1;
}

void enqueue(queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is Full. Cannot enqueue %d\n", data);
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear] = data;
}

int dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty. Cannot dequeue\n");
        return -1;
    }

    int data = q->array[q->front];

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->capacity;
    }

    return data;
}

void printQueue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = q->front, len = q->rear - q->front + 1; i != q->rear; i = (i + 1) % q->capacity) {
        printf("%d ", q->array[i]);
    }
    printf("%d\n", q->array[q->rear]);
}

void destroyQueue(queue *q) {
    free(q->array);
    free(q);
}

int main() {
    queue *q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printQueue(q);

    dequeue(q);

    printQueue(q);

    destroyQueue(q);

    return 0;
}