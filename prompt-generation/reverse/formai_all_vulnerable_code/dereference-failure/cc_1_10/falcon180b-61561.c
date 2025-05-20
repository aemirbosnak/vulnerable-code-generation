//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
} Queue;

void init(Queue *q) {
    q->arr = (int *)malloc(MAX_SIZE * sizeof(int));
    if (!q->arr) {
        printf("Memory error\n");
        exit(1);
    }
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

int isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

void enqueue(Queue *q, int x) {
    if (isFull(q)) {
        printf("Queue overflow\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    } else {
        q->rear++;
    }
    q->arr[++q->rear] = x;
    q->size++;
}

int dequeue(Queue *q) {
    int x;
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    if (q->front == q->rear) {
        x = q->arr[q->front];
        q->front = -1;
        q->rear = -1;
    } else {
        x = q->arr[q->front];
        q->front++;
    }
    q->size--;
    return x;
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    enqueue(&q, 40);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    if (isEmpty(&q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }
    return 0;
}