//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int front;
    int rear;
    int* arr;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    q->arr = (int*)malloc(MAX_QUEUE_SIZE * sizeof(int));
    return q;
}

void enqueue(Queue* q, int data) {
    if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->arr[q->rear] = data;
}

int dequeue(Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }
    return data;
}

void display(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    display(q);
    int data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    display(q);
    data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    display(q);
    data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    display(q);
    data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    display(q);
    return 0;
}