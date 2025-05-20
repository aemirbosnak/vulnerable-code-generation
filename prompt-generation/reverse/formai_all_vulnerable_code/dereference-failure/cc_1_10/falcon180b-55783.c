//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
} Queue;

Queue *createQueue() {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Error: Could not allocate memory for queue.\n");
        exit(1);
    }

    q->data = (int *) malloc(MAX_QUEUE_SIZE * sizeof(int));
    if (q->data == NULL) {
        printf("Error: Could not allocate memory for queue data.\n");
        exit(1);
    }

    q->front = -1;
    q->rear = -1;
    q->size = 0;

    return q;
}

int isEmpty(Queue *q) {
    return q->front == -1 && q->rear == -1;
}

int isFull(Queue *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(Queue *q, int data) {
    if (isFull(q)) {
        printf("Error: Queue is full.\n");
        exit(1);
    }

    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    }

    q->data[q->rear] = data;
    q->size++;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Error: Queue is empty.\n");
        exit(1);
    }

    int data = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->size--;

    return data;
}

int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Error: Queue is empty.\n");
        exit(1);
    }

    return q->data[q->front];
}

int main() {
    Queue *q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("Front element is: %d\n", peek(q));

    dequeue(q);
    dequeue(q);

    printf("Front element is: %d\n", peek(q));

    return 0;
}