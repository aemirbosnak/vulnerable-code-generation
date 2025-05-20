//FormAI DATASET v1.0 Category: Queue Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 10

typedef struct Queue {
    int front;
    int rear;
    int size;
    int* arr;
} Queue;

void init_queue(Queue* q) {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    q->arr = (int*)malloc(MAX_QUEUE_SIZE * sizeof(int));
}

bool is_empty(Queue* q) {
    return q->size == 0;
}

bool is_full(Queue* q) {
    return q->size == MAX_QUEUE_SIZE;
}

void enqueue(Queue* q, int val) {
    if (is_full(q)) {
        printf("Queue is full!\n");
        return;
    }

    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->arr[q->rear] = val;
    q->size++;

    if (q->front == -1) {
        q->front = 0;
    }
}

int dequeue(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int val = q->arr[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->size--;

    if (q->size == 0) {
        q->front = -1;
        q->rear = -1;
    }

    return val;
}

void print_queue(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    int i;
    for (i = q->front; i != q->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("%d ", q->arr[i]);
    }
    printf("%d\n", q->arr[i]);
}

int main() {
    Queue q;
    init_queue(&q);
    printf("Queue initialized!\n");

    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);
    print_queue(&q);

    int val = dequeue(&q);
    printf("%d dequeued!\n", val);
    print_queue(&q);

    enqueue(&q, 20);
    enqueue(&q, 25);
    enqueue(&q, 30);
    enqueue(&q, 35);
    print_queue(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    print_queue(&q);

    enqueue(&q, 40);
    enqueue(&q, 45);
    printf("Enqueued 40 and 45\n");
    print_queue(&q);

    return 0;
}