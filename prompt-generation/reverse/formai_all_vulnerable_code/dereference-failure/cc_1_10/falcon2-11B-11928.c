//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int* data;
    int front;
    int rear;
    int size;
} Queue;

void enqueue(Queue* q, int data) {
    if (q->rear == q->size - 1) {
        printf("Queue is full\n");
        return;
    }

    q->rear++;
    q->data[q->rear] = data;
}

int dequeue(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = q->data[q->front];
    q->front++;
    return data;
}

int main() {
    Queue q;
    q.data = (int*)malloc(sizeof(int));
    q.front = -1;
    q.rear = 0;
    q.size = 10;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);

    printf("Front: %d\n", dequeue(&q));
    printf("Front: %d\n", dequeue(&q));
    printf("Front: %d\n", dequeue(&q));
    printf("Front: %d\n", dequeue(&q));
    printf("Front: %d\n", dequeue(&q));

    free(q.data);
    return 0;
}