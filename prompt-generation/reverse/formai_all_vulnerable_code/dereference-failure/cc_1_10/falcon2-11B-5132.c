//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front;
    int rear;
    int capacity;
    int *queue;
};

void enqueue(struct Queue *q, int value) {
    if (q->rear == q->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->queue[q->rear] = value;
}

int dequeue(struct Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->queue[q->front];
    q->front = (q->front + 1) % q->capacity;
    return value;
}

void display(struct Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return;
    }
    int i = q->front;
    while (i!= q->rear) {
        printf("%d ", q->queue[i]);
        i = (i + 1) % q->capacity;
    }
    printf("%d\n", q->queue[i]);
}

int main() {
    struct Queue q;
    q.front = 0;
    q.rear = 0;
    q.capacity = 5;
    q.queue = (int *)malloc(q.capacity * sizeof(int));

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    display(&q);

    dequeue(&q);
    display(&q);

    dequeue(&q);
    display(&q);

    dequeue(&q);
    display(&q);

    dequeue(&q);
    display(&q);

    dequeue(&q);
    display(&q);

    dequeue(&q);
    display(&q);

    return 0;
}