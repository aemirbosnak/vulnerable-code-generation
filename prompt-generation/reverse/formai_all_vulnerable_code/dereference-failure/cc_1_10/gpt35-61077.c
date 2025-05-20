//FormAI DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

/* This is a futuristic style queue implementation using a circular buffer */

typedef struct {
    int front;
    int rear;
    int size;
    int* elements;
} queue;

queue* createQueue() {
    queue* q = (queue*) malloc(sizeof(queue));
    q->front = 0;
    q->rear = MAX_SIZE-1;
    q->size = 0;
    q->elements = (int*) malloc(MAX_SIZE*sizeof(int));
    return q;
}

int isFull(queue* q) {
    return q->size == MAX_SIZE;
}

int isEmpty(queue* q) {
    return q->size == 0;
}

void enqueue(queue* q, int item) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->elements[q->rear] = item;
    q->size++;
    printf("%d enqueued to queue\n", item);
}

int dequeue(queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->elements[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return item;
}

int main() {
    queue* q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
    enqueue(q, 9);

    // Dequeue all elements
    while (!isEmpty(q)) {
        printf("%d dequeued from queue\n", dequeue(q));
    }

    // Enqueue more elements to test circular behavior of the buffer
    enqueue(q, 10);
    enqueue(q, 11);
    enqueue(q, 12);

    // Dequeue all elements again
    while (!isEmpty(q)) {
        printf("%d dequeued from queue\n", dequeue(q));
    }

    free(q->elements);
    free(q);

    return 0;
}