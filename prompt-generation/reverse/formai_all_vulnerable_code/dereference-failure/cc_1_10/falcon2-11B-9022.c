//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
} Queue;

Queue createQueue() {
    Queue newQueue;
    newQueue.front = 0;
    newQueue.rear = -1;
    newQueue.size = 0;
    newQueue.data = (int *) malloc(MAX_SIZE * sizeof(int));
    return newQueue;
}

void enqueue(Queue *q, int data) {
    if (q->size == MAX_SIZE) {
        printf("Queue is full.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = data;
    q->size++;
}

int dequeue(Queue *q) {
    if (q->size == 0) {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return data;
}

int peek(Queue *q) {
    if (q->size == 0) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->data[q->front];
}

void printQueue(Queue *q) {
    if (q->size == 0) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front: %d, Rear: %d, Size: %d, Data: ", q->front, q->rear, q->size);
    for (int i = q->front; i!= q->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    Queue q = createQueue();

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printQueue(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    printQueue(&q);

    printf("Peek: %d\n", peek(&q));
    printQueue(&q);

    return 0;
}