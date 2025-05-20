//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct queue {
    int front, rear;
    int *arr;
};

void init(struct queue *q) {
    q->front = -1;
    q->rear = -1;
    q->arr = (int*)malloc(MAX * sizeof(int));
}

int isEmpty(struct queue *q) {
    if (q->front == -1 && q->rear == -1)
        return 1;
    else
        return 0;
}

int isFull(struct queue *q) {
    if ((q->rear + 1) % MAX == q->front)
        return 1;
    else
        return 0;
}

void enqueue(struct queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    else if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
        q->arr[q->rear] = value;
    }
    else {
        q->rear = (q->rear + 1) % MAX;
        q->arr[q->rear] = value;
    }
}

int dequeue(struct queue *q) {
    int value = -1;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return value;
    }
    else if (q->front == q->rear) {
        value = q->arr[q->front];
        q->front = -1;
        q->rear = -1;
    }
    else {
        value = q->arr[q->front];
        q->front = (q->front + 1) % MAX;
    }
    return value;
}

void display(struct queue *q) {
    int i = q->front;
    if (isEmpty(q))
        printf("Queue is empty!\n");
    else
        printf("Queue elements are: ");
    while (i!= q->rear) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", q->arr[i]);
}

int main() {
    struct queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    display(&q);
    printf("Dequeued element is: %d\n", dequeue(&q));
    display(&q);
    printf("Dequeued element is: %d\n", dequeue(&q));
    display(&q);
    printf("Dequeued element is: %d\n", dequeue(&q));
    display(&q);
    printf("Dequeued element is: %d\n", dequeue(&q));
    display(&q);
    printf("Dequeued element is: %d\n", dequeue(&q));
    display(&q);
    return 0;
}