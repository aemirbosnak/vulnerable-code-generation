//FormAI DATASET v1.0 Category: Queue Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int *arr;
    int rear, front;
} Queue;

Queue* createQueue() {
    Queue *Q = (Queue*) malloc(sizeof(Queue));
    Q->arr = (int*) malloc(sizeof(int) * MAX_QUEUE_SIZE);
    Q->front = -1;
    Q->rear = -1;
    return Q;
}

int isQueueEmpty(Queue *Q) {
    return (Q->front == -1);
}

int isQueueFull(Queue *Q) {
    return ((Q->rear + 1) % MAX_QUEUE_SIZE == Q->front);
}

void push(Queue *Q, int val) {
    if (isQueueFull(Q)) {
        printf("Queue is full, cannot push more elements.\n");
        return;
    }
    if (isQueueEmpty(Q)) {
        Q->front = 0;
        Q->rear = 0;
    } else {
        Q->rear = (Q->rear + 1) % MAX_QUEUE_SIZE;
    }
    Q->arr[Q->rear] = val;
}

int pop(Queue *Q) {
    if (isQueueEmpty(Q)) {
        printf("Queue is empty, cannot pop elements.\n");
        return -1;
    }
    int val = Q->arr[Q->front];
    if (Q->front == Q->rear) {
        Q->front = -1;
        Q->rear = -1;
    } else {
        Q->front = (Q->front + 1) % MAX_QUEUE_SIZE;
    }
    return val;
}

void display(Queue *Q) {
    if (isQueueEmpty(Q)) {
        printf("Queue is empty, nothing to display.\n");
        return;
    }
    printf("Queue contents: ");
    int i = Q->front;
    while (i != Q->rear) {
        printf("%d ", Q->arr[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
    printf("%d\n", Q->arr[Q->rear]);
}

int main() {
    Queue *Q = createQueue();

    push(Q, 10);
    push(Q, 20);
    push(Q, 30);
    push(Q, 40);
    push(Q, 50);
    display(Q);

    printf("Popped element: %d\n", pop(Q));
    display(Q);

    push(Q, 60);
    push(Q, 70);
    push(Q, 80);
    push(Q, 90);
    push(Q, 100);
    display(Q);

    push(Q, 110);

    return 0;
}