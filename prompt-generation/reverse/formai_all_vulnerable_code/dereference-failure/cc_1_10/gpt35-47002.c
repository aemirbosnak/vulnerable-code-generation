//FormAI DATASET v1.0 Category: Queue Implementation ; Style: dynamic
#include <stdlib.h>
#include <stdio.h>

#define MAX_QUEUE_SIZE 10

typedef struct Queue {
    int *arr;
    int front, rear, size;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->arr = (int*) malloc(MAX_QUEUE_SIZE * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    return q;
}

int isFull(Queue* q) {
    return q->size == MAX_QUEUE_SIZE;
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

void enqueue(Queue* q, int val) {
    if (isFull(q)) {
        printf("Queue is Full!\n");
        return;
    }

    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->arr[q->rear] = val;
    
    if (q->front == -1)
        q->front = 0;
    
    q->size++;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return;
    }

    int val = q->arr[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->size--;

    printf("Dequeued: %d\n", val);
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Queue: ");
    int count = 0;
    for (int i=q->front; count<q->size; count++) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
    enqueue(q, 9);
    enqueue(q, 10);
    enqueue(q, 11); // Queue is Full!

    display(q); // Queue: 1 2 3 4 5 6 7 8 9 10

    dequeue(q);
    dequeue(q);
    dequeue(q);

    display(q); // Queue: 4 5 6 7 8 9 10

    enqueue(q, 11);

    display(q); // Queue: 4 5 6 7 8 9 10 11

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    dequeue(q); // Queue is Empty!

    return 0;
}