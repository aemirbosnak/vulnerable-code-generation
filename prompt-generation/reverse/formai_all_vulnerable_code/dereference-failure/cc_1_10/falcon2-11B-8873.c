//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int front;
    int rear;
    int *data;
} Queue;

void enqueue(Queue *q, int data) {
    if (q->rear == MAX_SIZE) {
        printf("Queue is full\n");
        return;
    }

    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = data;
}

int dequeue(Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    return data;
}

void print_queue(Queue *q) {
    if (q->front > q->rear) {
        printf("Queue is empty\n");
        return;
    }

    int i;
    for (i = q->front; i!= q->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    q.front = 0;
    q.rear = -1;
    q.data = malloc(MAX_SIZE * sizeof(int));

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    print_queue(&q);
    dequeue(&q);
    print_queue(&q);

    return 0;
}