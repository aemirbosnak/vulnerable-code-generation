//FormAI DATASET v1.0 Category: Queue Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

struct queue {
    int front, rear;
    int capacity;
    int* arr;
};

struct queue* createQueue(int capacity) {
    struct queue* q = (struct queue*) malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->front = q->rear = -1;
    q->arr = (int*) malloc(q->capacity * sizeof(int));
    return q;
}

int isFull(struct queue* q) {
    return (q->rear == q->capacity - 1);
}

int isEmpty(struct queue* q) {
    return (q->front == -1);
}

void enQueue(struct queue* q, int item) {
    if (isFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->arr[++q->rear] = item;
    printf("%d enqueued to Queue.\n", item);
}

int deQueue(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return data;
}

int main() {
    struct queue* q = createQueue(5);

    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    enQueue(q, 40);
    enQueue(q, 50);
    enQueue(q, 60);

    printf("%d dequeued from Queue.\n", deQueue(q));
    printf("%d dequeued from Queue.\n", deQueue(q));
    printf("%d dequeued from Queue.\n", deQueue(q));
    printf("%d dequeued from Queue.\n", deQueue(q));
    printf("%d dequeued from Queue.\n", deQueue(q));
    printf("%d dequeued from Queue.\n", deQueue(q));

    return 0;
}